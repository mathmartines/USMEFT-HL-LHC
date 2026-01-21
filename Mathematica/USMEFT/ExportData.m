(* ::Package:: *)

Package["USMEFT`"]


(* ::Section::GrayLevel[0]:: *)
(*Export*)


PackageExport["CreateJSONData"]
PackageExport["CreateJSONInverseCovMatrix"]
PackageExport["CreateJSONTheory"]
PackageExport["JSONFileName"]
PackageExport["relabelObs"]


(* Dictionary to relabel the observables names *)
labelObs = <|
	"\[CapitalGamma]Z" -> "GammaZ", "\[Sigma]h" -> "sigmahad", "Al(\[Tau])" -> "Al(tau)", "s\[Theta]w" -> "sinethetaw", "\[CapitalGamma]W" -> "GammaW"
|>;

relabelObs[name:Alternatives@@Keys[labelObs]] := labelObs[name];
relabelObs[name_] := name;


(* ::Section::GrayLevel[0]::Closed:: *)
(*Export experimental data*)


CreateJSONData::usage = "Exports the experimental data in a .json file";


Options[CreateJSONData] = {
	JSONFileName -> FileNameJoin[{NotebookDirectory[], "DataEWPO.json"}],
	ObservablesList -> Join[ZPoleObservablesList[], WPoleObservablesList[]]
}


CreateJSONData[OptionsPattern[]] := Module[
	{
		obsnames, centralvalues, uncertainties, 
		jsonfile, SM, \[Sigma]SM
	},
	(* Names of the observables we need to store *)
	obsnames = OptionValue[ObservablesList];
	
	(* Central values *)
	centralvalues = Observables[#]["Data"]["Value"] & /@ obsnames;

	(* SM prediction *)
	SM = Observables[#]["SM"]["Value"] & /@ obsnames; 
	
	(* All info needed to construct the json file *)
	jsonfile = <|
		"observables_names" -> relabelObs /@ obsnames,
		"data" -> centralvalues,
		"SM" -> SM	
	|>;
	
	(* Saves the information on the data *)
	Export[OptionValue[JSONFileName], jsonfile];
];


(* ::Section::GrayLevel[0]::Closed:: *)
(*Export inverse of the covariance matrix*)


CreateJSONInverseCovMatrix::usage = "Builds the inverse of the covariance matrix"


Options[CreateJSONInverseCovMatrix] = {
	JSONFileName -> FileNameJoin[{NotebookDirectory[], "InvCovMatrixEWPO.json"}],
	ObservablesList -> Join[ZPoleObservablesList[], WPoleObservablesList[]]
}


CreateJSONInverseCovMatrix[OptionsPattern[]] := Module[
	{
		observablesList, \[Sigma]Data, \[Sigma]Th, covmatrix, invcov, jsonfile
	},
	(* Names of the observables we need to store *)
	observablesList = OptionValue[ObservablesList];
	
	(* Experimental uncertainties *)
	\[Sigma]Data = AssociationMap[Observables[#]["\[Sigma]Data"] &, observablesList];
	
	(* Theory uncertainties *)
	\[Sigma]Th = AssociationMap[Observables[#]["\[Sigma]SM"] &, observablesList];
	
	(* Creates the covariance matrix *)
	covmatrix = Table[
		Correlations[obs1, obs2]\[Sigma]Data[obs1]\[Sigma]Data[obs2] + \[Sigma]Th[obs1]\[Sigma]Th[obs2], 
		{obs1, observablesList}, 
		{obs2, observablesList}
	];
	invcov = Inverse[covmatrix];
	
	(* Saves the information on the data *)
	jsonfile = <|
		"observables_names" -> relabelObs /@ observablesList,
		"inv_cov_matrix" -> invcov
	|>;
	
	Export[OptionValue[JSONFileName], jsonfile];
];


(* ::Section::GrayLevel[0]::Closed:: *)
(*Export anomalous contributions*)


(* Map of the coefs names *)
renameCoef = <|
	"\[CapitalDelta]4F" -> "Delta4F", "BW" -> "CBW", "\[Phi],1" -> "Cphi1",
	"3W2H4" -> "C3W2H4", "2\[Psi]4D2" -> "C2psi4D2", "3\[Psi]4D2" -> "C3psi4D2"
|>;


CreateJSONTheory::usage = "Builds the anomalous predictions for the analysis";


Options[CreateJSONTheory] = {
	JSONFileName -> FileNameJoin[{NotebookDirectory[], "EWPOTheory.json"}],
	ObservablesList -> Join[ZPoleObservablesList[], WPoleObservablesList[]],
	EFTScale -> GetEFTScale[],
	EFTOrder -> GetEFTOrder[],
	OperatorDimension -> GetOperatorDimension[],
	WilsonCoefficients -> Join[$dimSixCoefs, $dimEightCoefs]
}


CreateJSONTheory[OptionsPattern[]] := Module[
	{
		observablesList, NPCont, faux, eftTerms, d6sqterms,
		anomTerms, prodCoefs, nameTerm, jsonfile
	},
	(* Names of the observables we need to store *)
	observablesList = OptionValue[ObservablesList];
	
	(* NP contribution to each of the observables *)
	NPCont = NPExpansion[
	   Observables[#]["NP"], 
	   EFTOrder -> OptionValue[EFTOrder], 
	   EFTScale -> OptionValue[EFTScale], 
	   OperatorDimension -> OptionValue[OperatorDimension]
	] & /@ observablesList;
	
	(* All EFT terms we need to include in the list *)
	faux[a_, b_] := {a, b};
	SetAttributes[faux, Orderless];
	d6sqterms = DeleteDuplicates[Flatten[Outer[faux[#1, #2]&, $dimSixCoefs, $dimSixCoefs], 1]];
	eftTerms = Join[{#} &/@ $dimSixCoefs, d6sqterms, {#} &/@ $dimEightCoefs];
	
	(* Computes the product of WCs *)
	prodCoefs = Times @@ WC /@ # &;
	
	(* Names the EFT term *)
	nameTerm = StringRiffle[renameCoef /@ #, "-"] &;
	
	(* Computes the anomalous prediction for each EFT term *)
	anomTerms = Association @ (nameTerm[#] -> Coefficient[NPCont, prodCoefs[#]]/.WC[___] -> 0 & /@ eftTerms) ;
	
	jsonfile = <|"observables_names" -> relabelObs /@ observablesList|>;
	jsonfile = AppendTo[jsonfile, anomTerms];
	
	(* Saves the JSON file *)
	Export[OptionValue[JSONFileName], jsonfile];
]
