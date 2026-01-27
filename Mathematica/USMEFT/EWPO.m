(* ::Package:: *)

Package["USMEFT`"]


(* ::Section::GrayLevel[0]::Closed:: *)
(*Export*)


PackageExport["ZPoleObservablesList"]
PackageExport["WPoleObservablesList"]
PackageExport["ObservablesList"]
PackageExport["WilsonCoefficients"]
PackageExport["\[Chi]2EWPO"]
PackageExport["ConfidenceInterval"]
PackageExport["LoadZprimeBenchmarkEW"]


ZPoleObservablesList::usage = "Returns a list of all Z pole observables we considered";


ZPoleObs = {
  "\[CapitalGamma]Z", "\[Sigma]h", "Rl", "AFBl", "Al(SLD)", "Al(\[Tau])", "Rb", "Rc", "AFBb", "AFBc", "Ab", "Ac" ,"s\[Theta]w" 
}


ZPoleObservablesList[] := ZPoleObs;


WPoleObservablesList::usage = "Returns a list of all W pole observables we considered";


WPoleObs = {
	"\[CapitalGamma]W", "MW", "MW(CMS)"
}


WPoleObservablesList[] := WPoleObs;


(* ::Chapter::RGBColor[1, 0, 0]:: *)
(*Z pole observables*)


(* ::Section::GrayLevel[0]::Closed:: *)
(*Analytical expressions for the observables*)


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*\[CapitalGamma]Z*)


\[CapitalGamma]Z[Nc_, gL_, gR_] := Module[{gA, gV}, 
	(* Axial and vector couplings *)
	gA = gR - gL;
	gV = gL + gR;
	(* Final expression for the decay width *)
	Nc (SMParam["Gf"] SMParam["MZ"]^3)/(6 Sqrt[2] \[Pi]) (gA^2 + gV^2)
];


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*Asymmetries *)


Af[gL_, gR_] := Module[{gV, gA}, 
	gV = gL + gR;
	gA = gL - gR;
	2 gV gA / (gV^2 + gA^2)
];


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*Subscript[A, FB]*)


AFB[glL_, glR_, gfL_, gfR_] := Block[{Al, Aq}, 
	Al = Af[glL, glR];
	Aq = Af[gfL, gfR];
	3/4 Al Aq
];


(* ::Section::GrayLevel[0]::Closed:: *)
(*Definitions of the observables*)


(* ::Subsection::GrayLevel[0]::Closed:: *)
(* \[CapitalGamma]Z [GeV]*)


(* SM prediction *)
Observables["\[CapitalGamma]Z"]["SM"] = Around[2.49397,  0.00068];


(* Data *)
Observables["\[CapitalGamma]Z"]["Data"] = Around[2.4955,  0.0023];


(* Uncertainty *)
Observables["\[CapitalGamma]Z"]["\[Sigma]Data"] = 0.0023;
Observables["\[CapitalGamma]Z"]["\[Sigma]SM"] = 0.00068;


(* Hadronic decay width *)
\[CapitalGamma]ZhadEFT = 2 \[CapitalGamma]Z[3, gZ\[Psi][1/2, 2/3], gZ\[Psi][0, 2/3]] + 3 \[CapitalGamma]Z[3, gZ\[Psi][-1/2, -1/3], gZ\[Psi][0, -1/3]];

(* Leptonic decay *)
\[CapitalGamma]ZLep = 3 \[CapitalGamma]Z[1, gZ\[Psi][-1/2, -1], gZ\[Psi][0, -1]];

(* Invisibles *)
\[CapitalGamma]ZInv = 3 \[CapitalGamma]Z[1, gZ\[Psi][1/2, 0], gZ\[Psi][0, 0]];

(* EFT decay width *)
\[CapitalGamma]ZEFT = \[CapitalGamma]ZLep + \[CapitalGamma]ZInv + \[CapitalGamma]ZhadEFT;


(* NP contribution *)
Observables["\[CapitalGamma]Z"]["NP"] = \[CapitalGamma]ZEFT;


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*\[Sigma]had [nb]*)


GeVtonb = (0.389379 10^6);


(* SM prediction *)
Observables["\[Sigma]h"]["SM"] = Around[41.4914, 0.0080];


(* Data *)
Observables["\[Sigma]h"]["Data"] = Around[41.480, 0.033];


(* Uncertainty *)
Observables["\[Sigma]h"]["\[Sigma]Data"] = 0.033;
Observables["\[Sigma]h"]["\[Sigma]SM"] = 0.0080;


\[Sigma]hEFT = GeVtonb (12\[Pi])/SMParam["MZ"]^2 (\[CapitalGamma]Z[1, gZ\[Psi][-1/2, -1], gZ\[Psi][0, -1]] \[CapitalGamma]ZhadEFT)/\[CapitalGamma]ZEFT^2;


(* NP contribution *)
Observables["\[Sigma]h"]["NP"] = \[Sigma]hEFT;


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*Rl*)


(* SM prediction *)
Observables["Rl"]["SM"] = Around[20.7451, 0.0087];


(* Data *)
Observables["Rl"]["Data"] = Around[20.767,  0.025];


(* Uncertainty *)
Observables["Rl"]["\[Sigma]Data"] = 0.025;
Observables["Rl"]["\[Sigma]SM"] = 0.0087;


RlEFT = \[CapitalGamma]ZhadEFT/\[CapitalGamma]Z[1, gZ\[Psi][-1/2, -1], gZ\[Psi][0, -1]] ;


(* NP contribution *)
Observables["Rl"]["NP"] = RlEFT;


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*AFBl*)


(* SM prediction *)
Observables["AFBl"]["SM"] = Around[0.016291, 0.000096];


(* Data *)
Observables["AFBl"]["Data"] = Around[0.0171,  0.0010];


(* Uncertainty *)
Observables["AFBl"]["\[Sigma]Data"] = 0.0010;
Observables["AFBl"]["\[Sigma]SM"] = 0.000096;


AFBl = AFB[gZ\[Psi][-1/2, -1], gZ\[Psi][0, -1], gZ\[Psi][-1/2, -1], gZ\[Psi][0, -1]] ;


(* NP contribution *)
Observables["AFBl"]["NP"] = AFBl;


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*Al(SLD)*)


(* SM prediction *)
Observables["Al(SLD)"]["SM"] = Around[0.14744, 0.00045];


(* Data *)
Observables["Al(SLD)"]["Data"] = Around[0.1513,  0.0021];


(* Uncertainty *)
Observables["Al(SLD)"]["\[Sigma]Data"] = 0.0021;
Observables["Al(SLD)"]["\[Sigma]SM"] = 0.00045;


AlSLD = Af[gZ\[Psi][-1/2, -1], gZ\[Psi][0, -1]] ;


(* NP contribution *)
Observables["Al(SLD)"]["NP"] = AlSLD;


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*Al(tau)*)


(* SM prediction *)
Observables["Al(\[Tau])"]["SM"] = Around[0.14744, 0.00044];


(* Data *)
Observables["Al(\[Tau])"]["Data"] = Around[0.1465, 0.0033];


(* Uncertainty *)
Observables["Al(\[Tau])"]["\[Sigma]Data"] = 0.0033;
Observables["Al(\[Tau])"]["\[Sigma]SM"] = 0.00044;


(* NP contribution *)
Observables["Al(\[Tau])"]["NP"] = AlSLD;


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*Rb*)


(* SM prediction *)
Observables["Rb"]["SM"] = Around[0.215886, 0.000102];


(* Data *)
Observables["Rb"]["Data"] = Around[0.21629,  0.00066];


(* Uncertainty *)
Observables["Rb"]["\[Sigma]Data"] = 0.00066;
Observables["Rb"]["\[Sigma]SM"] = 0.000102;


RbEFT = \[CapitalGamma]Z[3, gZ\[Psi][-1/2, -1/3], gZ\[Psi][0, -1/3]] / \[CapitalGamma]ZhadEFT;


(* NP contribution *)
Observables["Rb"]["NP"] = RbEFT;


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*Rc*)


(* SM prediction *)
Observables["Rc"]["SM"] = Around[0.172197, 0.000054];


(* Data *)
Observables["Rc"]["Data"] = Around[0.1721,  0.0030];


(* Uncertainty *)
Observables["Rc"]["\[Sigma]Data"] = 0.0030;
Observables["Rc"]["\[Sigma]SM"] = 0.000054;


RcEFT = \[CapitalGamma]Z[3, gZ\[Psi][1/2, 2/3], gZ\[Psi][0, 2/3]] / \[CapitalGamma]ZhadEFT;


(* NP contribution *)
Observables["Rc"]["NP"] = RcEFT;


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*AFBb*)


(* SM prediction *)
Observables["AFBb"]["SM"] = Around[0.10337,  0.00032];


(* Data *)
Observables["AFBb"]["Data"] = Around[0.0992,  0.0016];


(* Uncertainty *)
Observables["AFBb"]["\[Sigma]Data"] = 0.0016;
Observables["AFBb"]["\[Sigma]SM"] = 0.00032;


AFBb = AFB[gZ\[Psi][-1/2, -1], gZ\[Psi][0, -1], gZ\[Psi][-1/2, -1/3], gZ\[Psi][0, -1/3]];


(* NP contribution *)
Observables["AFBb"]["NP"] = AFBb;


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*AFBc*)


(* SM prediction *)
Observables["AFBc"]["SM"] = Around[0.07387, 0.00023];


(* Data *)
Observables["AFBc"]["Data"] = Around[0.0707,  0.0035];


(* Uncertainty *)
Observables["AFBc"]["\[Sigma]Data"] = 0.0035;
Observables["AFBc"]["\[Sigma]SM"] = 0.00023;


AFBc = AFB[gZ\[Psi][-1/2, -1], gZ\[Psi][0, -1], gZ\[Psi][1/2, 2/3], gZ\[Psi][0, 2/3]];


(* NP contribution *)
Observables["AFBc"]["NP"] = AFBc;


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*Ab*)


(* SM prediction *)
Observables["Ab"]["SM"] = Around[0.934772, 0.00004];


(* Data *)
Observables["Ab"]["Data"] = Around[0.923,  0.020];


(* Uncertainty *)
Observables["Ab"]["\[Sigma]Data"] = 0.020;
Observables["Ab"]["\[Sigma]SM"] = 0.00004;


Ab = Af[gZ\[Psi][-1/2, -1/3], gZ\[Psi][0, -1/3]];


(* NP contribution *)
Observables["Ab"]["NP"] = Ab;


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*Ac*)


(* SM prediction *)
Observables["Ac"]["SM"] = Around[0.66797, 0.00021];


(* Data *)
Observables["Ac"]["Data"] = Around[0.670,  0.027];


(* Uncertainty *)
Observables["Ac"]["\[Sigma]Data"] = 0.027;
Observables["Ac"]["\[Sigma]SM"] = 0.00021;


Ac = Af[gZ\[Psi][1/2, 2/3], gZ\[Psi][0, 2/3]];


(* NP contribution *)
Observables["Ac"]["NP"] = Ac;


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*sin\[Theta]w*)


(* SM prediction *)
Observables["s\[Theta]w"]["SM"] = Around[0.23155, 0.000062];


(* Data *)
Observables["s\[Theta]w"]["Data"] = Around[0.23152,  0.00031];


(* Uncertainty *)
Observables["s\[Theta]w"]["\[Sigma]Data"] = 0.00031;
Observables["s\[Theta]w"]["\[Sigma]SM"] = 0.000062;


(* NP contribution *)
Observables["s\[Theta]w"]["NP"] = -\[CapitalDelta]g2;


(* ::Section::GrayLevel[0]::Closed:: *)
(*Correlations between the Z pole observables*)


(* From Table B.13 of 1912.02067 *)
Correlations["\[CapitalGamma]Z", "\[Sigma]h"] = -0.297;
Correlations["\[CapitalGamma]Z", "Rl"] = 0.004;
Correlations["\[CapitalGamma]Z", "AFBl"] = 0.003;
Correlations["\[Sigma]h", "Rl"] = 0.183;
Correlations["\[Sigma]h", "AFBl"] = 0.006;
Correlations["Rl", "AFBl"] = \[Minus]0.056;

(* From Table 5.11 of hep-ex/0509008 *)
Correlations["Rb", "Rc"] = -0.18;
Correlations["Rb", "AFBb"] = \[Minus]0.10;
Correlations["Rb", "AFBc"] = 0.07;
Correlations["Rb", "Ab"] = -0.08;
Correlations["Rb", "Ac"] = 0.04;
Correlations["Rc", "AFBb"] = 0.04;
Correlations["Rc", "AFBc"] = \[Minus]0.06;
Correlations["Rc", "Ab"] = 0.04;
Correlations["Rc", "Ac"] = -0.06;
Correlations["AFBb", "AFBc"] = 0.15;
Correlations["AFBb", "Ab"] = 0.06;
Correlations["AFBb", "Ac"] = 0.01;
Correlations["AFBc", "Ab"] = -0.02;
Correlations["AFBc", "Ac"] = 0.04;
Correlations["Ab", "Ac"] = 0.11;


(* ::Chapter::RGBColor[1, 0, 0]:: *)
(*W pole observables*)


(* ::Text:: *)
(*Experimental measurements extracted from https://journals.aps.org/prd/pdf/10.1103/PhysRevD.110.030001, https://arxiv.org/pdf/1302.3415*)
(*SM predictions https://arxiv.org/pdf/2204.04204*)


(* ::Section::GrayLevel[0]::Closed:: *)
(*Analytical expressions for the observables*)


(* ::Subsection::GrayLevel[0]:: *)
(*\[CapitalGamma]W*)


\[CapitalGamma]W[Nc_] := Nc Sqrt[2] SMParam["Gf"] SMParam["MW"]^3 (1 + \[CapitalDelta]gW)^2 / (12 \[Pi]); 


(* ::Section::GrayLevel[0]::Closed:: *)
(*Definitions of the observables*)


(* ::Subsection::GrayLevel[0]:: *)
(*\[CapitalGamma]W [GeV]*)


(* SM prediction *)
Observables["\[CapitalGamma]W"]["SM"] = Around[2.08902, 0.00052];


(* Data *)
Observables["\[CapitalGamma]W"]["Data"] = Around[2.085,  0.042];


(* Uncertainty *)
Observables["\[CapitalGamma]W"]["\[Sigma]Data"] = 0.042;
Observables["\[CapitalGamma]W"]["\[Sigma]SM"] = 0.00052;


\[CapitalGamma]WEFT = 3 \[CapitalGamma]W[1] (* leptons *) + 2 \[CapitalGamma]W[3] (* quarks *);


(* NP contribution *)
Observables["\[CapitalGamma]W"]["NP"] = \[CapitalGamma]WEFT;


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*MW [GeV]*)


(* SM prediction *)
Observables["MW"]["SM"] = Around[80.350, 0.0056];


(* Data *)
Observables["MW"]["Data"] = Around[80.3692,  0.0133];


(* Uncertainty *)
Observables["MW"]["\[Sigma]Data"] = 0.0133;
Observables["MW"]["\[Sigma]SM"] = 0.0056;


MWEFT = SMParam["MW"](1 + \[CapitalDelta]MW);


(* NP contribution *)
Observables["MW"]["NP"] = MWEFT;


(* ::Subsection::GrayLevel[0]::Closed:: *)
(*MW [GeV] (CMS)*)


(* SM prediction *)
Observables["MW(CMS)"]["SM"] = Around[80.350, 0.0056];


(* Data *)
Observables["MW(CMS)"]["Data"] = Around[80.3602,  0.0099];


(* Uncertainty *)
Observables["MW(CMS)"]["\[Sigma]Data"] = 0.0133;
Observables["MW(CMS)"]["\[Sigma]SM"] = 0.0056;


(* NP contribution *)
Observables["MW(CMS)"]["NP"] = Observables["MW"]["NP"];


(* ::Section::GrayLevel[0]::Closed:: *)
(*Correlations between the W pole observables*)


Correlations["MW", "MW(CMS)"] = 0.5;


(* ::Chapter::RGBColor[1, 0, 0]::Closed:: *)
(*Generates the EW pseudo-data*)


LoadZprimeBenchmarkEW::usage = "Generates the pseudo-data for the EW pole observables. Once this function is called the real data is lost";


Options[LoadZprimeBenchmarkEW] = {
	EFTOrder -> GetEFTOrder[],
	OperatorDimension -> GetOperatorDimension[]
}


LoadZprimeBenchmarkEW[matchingRelations_, benchmarkValues_, OptionsPattern[]] := Module[
	{
		NPs, NPFunc, EWobs, subs, UpdateObservables		
	},
	(* List with all EW observables *)
	EWobs = Join[ZPoleObservablesList[], WPoleObservablesList[]];
	
	(* Replacement rules *)
	subs = Join[
		GetZCouplingsShifts[EFTScale -> GetEFTScale[], EFTOrder -> OptionValue[EFTOrder], OperatorDimension -> OptionValue[OperatorDimension]],
		GetWCouplingsShifts[EFTScale -> GetEFTScale[], EFTOrder -> OptionValue[EFTOrder], OperatorDimension -> OptionValue[OperatorDimension]]
	];
	
	(* NPs contribution *)
	NPFunc = # -> NPExpansion[
			Observables[#]["NP"]/.subs, 
			EFTOrder -> OptionValue[EFTOrder], 
			OperatorDimension -> OptionValue[OperatorDimension],
			MatchingRelations -> matchingRelations
		]/.benchmarkValues &;
		
	NPs = Association @ ( NPFunc /@ EWobs );
	
	(* Updates the observables with the SM + NP *)
	UpdateObservables[] = (Observables[#]["Data"] = Around[Observables[#]["SM"]["Value"] + NPs[#] , Observables[#]["\[Sigma]Data"]]) & /@ EWobs;
	UpdateObservables[]
]


(* ::Chapter::RGBColor[1, 0, 0]:: *)
(*EWPO \[Chi]2*)


(* ::Section::GrayLevel[0]::Closed:: *)
(*\[Chi]2 function*)


\[Chi]2EWPO::usage = "\[Chi]2 with the W and Z pole observables"


Options[\[Chi]2EWPO] = {
	ObservablesList -> All, 
	WilsonCoefficients -> All,
	EFTScale -> GetEFTScale[],
	EFTOrder -> GetEFTOrder[],
	OperatorDimension -> GetOperatorDimension[],
	MatchingRelations -> None
}


WCs = Flatten@Table[WC[name], {name, Join[$dimSixCoefs, $dimEightCoefs]}];


\[Chi]2EWPO[OptionsPattern[]] := Module[
	{
		listWCs,
		observablesList,
		\[Sigma]Data, \[Sigma]Th, covmatrix, invcov,
		NPCont, diffvec, subs
	},
	(* Which observables to include *)
	observablesList = If[OptionValue[ObservablesList] === All, Join[ZPoleObservablesList[], WPoleObservablesList[]], OptionValue[ObservablesList]];
	
	(* List of All WCs in the SMEFT *)
	listWCs = If[OptionValue[WilsonCoefficients] === All, WCs, OptionValue[WilsonCoefficients]];
	
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
	
	(* Replacement rules *)
	subs = Join[
		GetZCouplingsShifts[EFTScale -> OptionValue[EFTScale], EFTOrder -> OptionValue[EFTOrder], OperatorDimension -> OptionValue[OperatorDimension]],
		GetWCouplingsShifts[EFTScale -> OptionValue[EFTScale], EFTOrder -> OptionValue[EFTOrder], OperatorDimension -> OptionValue[OperatorDimension]]
	];
	
	(* NPs contribution *)
	 NPCont = Association @ (# -> NPExpansion[
	   Observables[#]["NP"] /. subs, 
	   EFTOrder -> OptionValue[EFTOrder],
	   MatchingRelations -> OptionValue[MatchingRelations]
	 ] & /@ observablesList);
	 
	(* ExpData - Theory *)
	diffvec = (Observables[#]["Data"]["Value"] - Observables[#]["SM"]["Value"] - NPCont[#]) & /@ observablesList;
	
	(* Sets to zero all unwanted WCs *)
	diffvec = diffvec/. wc:WC[__]/;!MemberQ[listWCs, wc]:>0;
	
	(* \[Chi]2 *)
	diffvec . invcov . diffvec
]; 


(* ::Section::GrayLevel[0]::Closed:: *)
(*Confidence Interval*)


\[CapitalDelta]\[Chi]2Limit[dof_Integer, confLevel_?NumberQ]:= InverseCDF[ChiSquareDistribution[dof], confLevel];


ConfidenceInterval::usage = "Computes the confidence interval";


ConfidenceInterval[\[Chi]2_, coefName_, confLevel_] := Module[{\[Chi]2values, \[Chi]2min},
\[Chi]2min = First@Minimize[\[Chi]2, coefName];
 Flatten[Solve[\[Chi]2 == \[Chi]2min + \[CapitalDelta]\[Chi]2Limit[1,confLevel], coefName, Reals]]
];
