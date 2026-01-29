(* ::Package:: *)

Package["USMEFT`"]


(* ::Section::GrayLevel[0]::Closed:: *)
(*Export*)


PackageExport["\[Chi]2LHC"]
PackageExport["GetChannnelsLHC"]
PackageExport["LoadZprimeBenchmark"]
PackageExport["mxxvalue"]
PackageExport["\[Beta]value"]


GetChannelsLHC::usage = "Returns a list with all possible channels that can be included in the LHC \[Chi]2";


GetChannelsLHC[] := {"NCDY", "CCDY"};


(* ::Section::GrayLevel[0]::Closed:: *)
(*Internal*)


PackageScope["LoadData"]


(* ::Section::GrayLevel[0]::Closed:: *)
(*Load Data*)


LoadData::usage = "Loads the simulation and data file";


LoadData[SimulationFile_, DataFile_, ObsNames_] := Module[
	{
		simulations, expdata, eftterms, index, relabelCoefs, relabelCoefsFunc
	},
	(* Map to convert the WCs convention from the simulation to the one used in Mathematica *)
	relabelCoefs = Association@{
		"C2JB" -> "2JB", "Delta4F" -> "\[CapitalDelta]4F", "Cphi1" -> "\[Phi],1", 
		"CBW" -> "BW", "C3W2H4" -> "3W2H4", "C7psi4H2" -> "7\[Psi]4H2", 
		"C2psi4D2" -> "2\[Psi]4D2", "C3psi4D2" -> "3\[Psi]4D2"
	};
	relabelCoefsFunc = WC[relabelCoefs[#]] & ;
	
	(* Loads the .json file that contains the simulations *)	
	simulations = Import[SimulationFile];
	
	(* Loads the .json file that contains the data *)
	expdata = Association@Import[DataFile];
	
	(* Constructs the EFT terms for each bin of the distribution *)
	eftterms = Total[(#2 * Times @@ (relabelCoefsFunc /@ StringSplit[#1, "-"])) & @@@ simulations]; 
	
	(* Updates Observables *)
	For[index=1, index <= Length[ObsNames], index++,
		Observables[ObsNames[[index]]]["SM"] = expdata["SM"][[index]];
		Observables[ObsNames[[index]]]["Data"] = expdata["data"][[index]];
		Observables[ObsNames[[index]]]["NP"] = eftterms[[index]];
	];

];


DataFolderPath = FileNameJoin[{DirectoryName[$InputFileName, 3], "Data"}];


(* ::Chapter::RGBColor[1, 0, 0]:: *)
(*NC DY *)


(* Path to the File *)
DirNCDY= FileNameJoin[{DataFolderPath, "NCDY"}];


(* Name of the NCDY bins *)
NCDYbins = Table["NCDY-" <> ToString[ii], {ii, 1, 13}];

(* Loads the data files *)
LoadData[
	FileNameJoin[{DirNCDY, "USMEFT-NCDY-HLLHC.json"}],
	FileNameJoin[{DirNCDY, "pseudo_data_Zprime", "NCDY-Zprime-beta_3E-01-MXX_4-TeV.json"}],
	NCDYbins
];


(* Central values of the bins *)
centralValuesBins["NCDY"] = {625.,    875.,   1125.,   1375.,   1625.,   1875.,   2125., 2375.,   2625.,   2875.,   3125.,   3375., 3500};
SetSysNC[] := (Observables["NCDY-" <> ToString[#]]["\[Sigma]Sys"] = 0.001 * 0.05 * centralValuesBins["NCDY"][[#]]) & /@ Table[ii, {ii, 1, 13}];
SetSysNC[];


(* ::Section::GrayLevel[0]:: *)
(*Load Zprime benchmark*)


LoadZprimeBenchmark::usage = "Loads a new pseudo data for a given benchmark (\[Beta], M)";


Options[LoadZprimeBenchmark] = {
    \[Beta]value -> 0.1, 
    mxxvalue -> 4
}


LoadZprimeBenchmark[OptionsPattern[]] := Module[
	{
		filename, expdata, index, datafile
	},
	(* Name of the file that contains the benchmark data *)
	filename = ToString@StringForm["NCDY-Zprime-beta_``E-01-MXX_``-TeV.json", IntegerPart[OptionValue[\[Beta]value] * 10], OptionValue[mxxvalue]];
	datafile = FileNameJoin[{DirNCDY, "pseudo_data_Zprime", filename}];
	
	(* Loads the .json file that contains the data *)
	expdata = Association@Import[datafile];
	
	(* Updates Observables *)
	For[index=1, index <= Length[NCDYbins], index++,
		Observables[NCDYbins[[index]]]["SM"] = expdata["SM"][[index]];
		Observables[NCDYbins[[index]]]["Data"] = expdata["data"][[index]];
	];
];


(* ::Chapter::RGBColor[1, 0, 0]::Closed:: *)
(*CC DY*)


(* Path to the File *)
DirCCDY= FileNameJoin[{DataFolderPath, "CCDY"}];


(* Name of the CCDY bins *)
CCDYbins = Table["CCDY-" <> ToString[ii], {ii, 1, 8}];

(* Loads the data files *)
LoadData[
	FileNameJoin[{DirCCDY, "USMEFT-CCDY-HLLHC.json"}],
	FileNameJoin[{DirCCDY, "CCDY_pseudo_data_Zprime.json"}],
	CCDYbins
];


centralValuesBins["CCDY"] = {  625.,    875.,   1125.,   1375.,   1750.,   2500.,   3250., 3500.};
SetSysCC[] := (Observables["CCDY-" <> ToString[#]]["\[Sigma]Sys"] = 0.001 * 0.05 * centralValuesBins["CCDY"][[#]]) & /@ Table[ii, {ii, 1, 8}];
SetSysCC[];


(* ::Chapter::RGBColor[1, 0, 0]:: *)
(*LHC \[Chi]2*)


\[Chi]2LHC::usage = "\[Chi]2 with the LHC observables"


Options[\[Chi]2LHC] = {
	ObservablesList -> All, 
	WilsonCoefficients -> All,
	EFTScale -> GetEFTScale[],
	EFTOrder -> GetEFTOrder[],
	OperatorDimension -> GetOperatorDimension[],
	MatchingRelations -> None
}


WCs = Flatten@Table[WC[name], {name, Join[$dimSixCoefs, $dimEightCoefs]}];


LHCBins = <|"NCDY" -> NCDYbins, "CCDY" -> CCDYbins|>;


\[Chi]2LHC[OptionsPattern[]] := Module[
	{
		\[Sigma]stSq, \[Sigma]sys, data, theory, observablesList, WCsList, diff, NPCont, \[CapitalLambda]
	},
	(* List with all the observables that must be included in the construction of the \[Chi]2 *)
	observablesList = If[
		OptionValue[ObservablesList] === All, Join[NCDYbins[[;;10]], CCDYbins], Flatten[LHCBins /@ OptionValue[ObservablesList]]
	];
	
	(* List with the WCs that must be included in the \[Chi]2 *)
	WCsList = If[
		OptionValue[WilsonCoefficients] === All, WCs, OptionValue[WilsonCoefficients]
	];
	
	(* Changes the cutoff *)
	(* Simulations are in TeV^-2 *)
	\[CapitalLambda] = OptionValue[EFTScale] * 0.001;
	
	(* NPs contribution *)
	 NPCont = Association @ (# -> NPExpansion[
	   (* Rescale the coefs if needed *)
	   Observables[#]["NP"] /. WC[name_] :> If[MemberQ[$dimSixCoefs, name], \[CapitalLambda]^{-2}, \[CapitalLambda]^{-4}] WC[name], 
	   EFTOrder -> OptionValue[EFTOrder],
	   OperatorDimension -> OptionValue[OperatorDimension],
	   MatchingRelations -> OptionValue[MatchingRelations]
	 ] & /@ observablesList);
	 
	(* Experimental data - Theory prediction  - THE DATA IS IN fb and not in number of events *)
	diff = (Observables[#]["Data"] - Observables[#]["SM"] - NPCont[#][[1]]) & /@ observablesList;
	(* Sets to zero WCs that were not specified *)
	diff = diff/. wc:WC[__]/;!MemberQ[WCsList, wc]:>0;
	
	(* Statistical uncertainty L = 3000 fb^-1 *)
	\[Sigma]stSq = Observables[#]["Data"]/3000  & /@ observablesList;
	
	(* Systematic uncertainties *)
	\[Sigma]sys = Observables[#]["\[Sigma]Sys"] * Observables[#]["Data"] & /@ observablesList;
	
	(* \[Chi]2 *)
	Total @ (diff^2 / (\[Sigma]stSq + \[Sigma]sys^2))
]
