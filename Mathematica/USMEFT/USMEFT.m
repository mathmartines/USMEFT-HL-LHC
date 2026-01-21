(* ::Package:: *)

Package["USMEFT`"]


(* ::Section::GrayLevel[0]::Closed:: *)
(*Export*)


PackageExport["WC"]
PackageExport["Observables"]
PackageExport["Correlations"]
PackageExport["SMParam"]
PackageExport["SetEFTScale"]
PackageExport["GetEFTScale"]
PackageExport["SetEFTOrder"]
PackageExport["GetEFTOrder"]
PackageExport["SetOperatorDimension"]
PackageExport["GetOperatorDimension"]


Observables::usage = "Experimental and theory info about observables considered in the analysis"


Correlations::usage = "Correlations between the observables in the analysis";


(* Symmetry correlation matrix *)
Correlations[i_, i_] := 1
Correlations[i_, j_] := 0
SetAttributes[Correlations, Orderless]


(* ::Section::GrayLevel[0]::Closed:: *)
(*Private*)


PackageScope["NPExpansion"]
PackageScope["\[CapitalDelta]g1"]
PackageScope["\[CapitalDelta]g2"]
PackageScope["\[CapitalDelta]gW"]
PackageScope["\[CapitalDelta]MW"]
PackageScope["gZ\[Psi]"]
PackageScope["$dimSixCoefs"]
PackageScope["$dimEightCoefs"]
PackageScope["$EFTscale"]
PackageScope["$EFTorder"]
PackageScope["$OperatorDimension"]
PackageScope["CheckOption"]
PackageExport["EFTScale"]
PackageExport["EFTOrder"]
PackageExport["OperatorDimension"]
PackageExport["GetD6Coefs"]
PackageExport["GetD8Coefs"]


$EFTscale::usage = "EFT cutoff scale"


$EFTscale = 1000 (* Defaullt value: 1 TeV *)


$EFTorder::usage = "Defines the truncation at cross-section level"


$EFTorder = 2 (* Default value: only linear dimension-six effects *)


$OperatorDimension::usage = "Defines up to each class of operators we must include";


$OperatorDimension = 6 (* Default value: only dimension-six operators are included *)


(* ::Section::GrayLevel[0]::Closed:: *)
(*Setters and Getters*)


SetEFTScale[\[CapitalLambda]_?Real] := ($EFTscale = \[CapitalLambda]);


SetEFTOrder[Order:Alternatives[2, 4]] := ($EFTorder = Order);


SetOperatorDimension[dim:Alternatives[6, 8]] := ($OperatorDimension = dim);


GetEFTScale[] := $EFTscale;


GetEFTOrder[] := $EFTorder;


GetOperatorDimension[] := $OperatorDimension;


(* ::Section::GrayLevel[0]::Closed:: *)
(*Check options*)


$OptionValueAssociation = <|
	EFTOrder -> 2 | 4,
	OperatorDimension -> 6 | 8,
	EFTScale -> _?((NumericQ[#]&&Positive[#])&) | _Symbol
|>;


CheckOption[opt_, optValue_] := If[!MatchQ[optValue, $OptionValueAssociation[opt]],
	Message[CheckOption::optionvalue, opt, optValue, $OptionValueAssociation[opt]];
	Abort[]
];


CheckOption::optionvalue= "Invalid OptionValue specified: `1`\[Rule]`2`, the allowed values for `1` must match `3`.";


(* ::Section::GrayLevel[0]::Closed:: *)
(*Wilson coefficients*)


WC::usage = "WC[\"label\"] Wilson coefficient associated with the operators given in label";


(* ::Subsection::GrayLevel[0]:: *)
(*Formatting*)


(* List of all WCs *)
$dimSixCoefs = List["\[CapitalDelta]4F", "\[Phi],1", "BW", "2JB"];
GetD6Coefs[] := $dimSixCoefs;
$dimEightCoefs = List["3W2H4", "2\[Psi]4D2", "3\[Psi]4D2", "7\[Psi]4H2"];
GetD8Coefs[] := $dimEightCoefs;


Format[WC[label:Alternatives@@$dimSixCoefs]] := If[label === "\[CapitalDelta]4F", DisplayForm@Subscript["\[CapitalDelta]","4F"], DisplayForm@Subscript["c", ToString[label]]]


Format[WC[label:"3W2H4"]] := DisplayForm@Subsuperscript["c", "\!\(\*SuperscriptBox[\(W\), \(2\)]\)\!\(\*SuperscriptBox[\(H\), \(4\)]\)", "(3)"]


Format[WC[label:"2\[Psi]4D2"]] := DisplayForm@Subsuperscript["c", "\!\(\*SuperscriptBox[\(\[Psi]\), \(4\)]\)\!\(\*SuperscriptBox[\(D\), \(2\)]\)", "(2)"]


Format[WC[label:"3\[Psi]4D2"]] := DisplayForm@Subsuperscript["c", "\!\(\*SuperscriptBox[\(\[Psi]\), \(4\)]\)\!\(\*SuperscriptBox[\(D\), \(2\)]\)", "(3)"]


Format[WC[label:"7\[Psi]4H2"]] := DisplayForm@Subsuperscript["c", "\!\(\*SuperscriptBox[\(\[Psi]\), \(4\)]\)\!\(\*SuperscriptBox[\(H\), \(2\)]\)", "(7)"]


(* Check WC *)
WC::unknownWClabel= "The label `1` is not an allowed label for Wilson coefficients (WC)."


WC[l:Except[Alternatives@@Join[$dimSixCoefs, $dimEightCoefs, {_Pattern, _Blank, _Except, _BlankNullSequence, _BlankSequence}]]]:=(
	Message[WC::unknownWClabel,l];
	Abort[]
)


(* ::Section::GrayLevel[0]::Closed:: *)
(*SM parameters*)


SMParam["Gf"] = 1.1663787/10^5
SMParam["\[Alpha]EWM1"] = 128.951
SMParam["\[Alpha]EM"] = 1/SMParam["\[Alpha]EWM1"]
SMParam["MZ"] = 91.1876 (* in GeV *)
SMParam["ee"] = Sqrt[4 Pi SMParam["\[Alpha]EM"]]
SMParam["vev"] = 1/Sqrt[Sqrt[2] SMParam["Gf"]] (* in GeV *)
SMParam["s\[Theta]"] = Sqrt[(1/2)*(1 - Sqrt[1 - (SMParam["ee"]^2 * SMParam["vev"]^2)/SMParam["MZ"]^2])]
SMParam["c\[Theta]"] = Sqrt[1 - SMParam["s\[Theta]"]^2]
SMParam["s2\[Theta]"] = 2 SMParam["s\[Theta]"] SMParam["c\[Theta]"]
SMParam["c2\[Theta]"] = SMParam["c\[Theta]"]^2 - SMParam["s\[Theta]"]^2
SMParam["c4\[Theta]"] = SMParam["c2\[Theta]"]^2 - SMParam["s2\[Theta]"]^2
SMParam["MW"] = SMParam["ee"] SMParam["vev"]/ (2 SMParam["s\[Theta]"]) (* in GeV *)


(* ::Section::GrayLevel[0]::Closed:: *)
(*Extracts the NPs contribution*)


Options[NPExpansion] := {
	EFTOrder          -> GetEFTOrder[]
}


NPExpansion[theory_, OptionsPattern[]] := Module[{opts, NPCont, \[Xi], series},
  (* Shifts in terms of the WCs *)
  opts = # -> OptionValue[#]&/@{EFTOrder};
  
  (* Computes the observables *)
  NPCont = theory /. WC[name_] :> If[MemberQ[$dimSixCoefs, name], \[Xi]^2, \[Xi]^4] WC[name];
  
  (* Removes the SM prediction *)
  NPCont = Series[NPCont, {\[Xi], 0, OptionValue[EFTOrder]}];
  NPCont = Normal[NPCont] - (Normal[NPCont] /. \[Xi] -> 0); 
  NPCont /. \[Xi]->1
]


(* ::Section::GrayLevel[0]::Closed:: *)
(*Z couplings*)


(* Z coupling to fermions *)
gZ\[Psi][T3_, Q_] := (T3 - SMParam["s\[Theta]"]^2 Q)(1 + \[CapitalDelta]g1) + Q \[CapitalDelta]g2;
