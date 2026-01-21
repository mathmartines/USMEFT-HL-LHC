(* ::Package:: *)

Package["USMEFT`"]


(* ::Section::GrayLevel[0]:: *)
(*Private*)


PackageExport["GetZCouplingsShifts"]
PackageExport["GetWCouplingsShifts"]


(* ::Chapter::RGBColor[1, 0, 0]:: *)
(*Corrections to the Z couplings *)


(* Corrections to the Z couplings without the inclusion of the v^n/\[CapitalLambda]^n factors *) 

(* Linear dimension-six corrections *)
\[CapitalDelta]g1Six = -(1/4) (2 WC["\[CapitalDelta]4F"] + WC["\[Phi],1"]);
\[CapitalDelta]g2Six = -(SMParam["s2\[Theta]"] /(8 SMParam["c2\[Theta]"]))(SMParam["s2\[Theta]"] (2 WC["\[CapitalDelta]4F"] + WC["\[Phi],1"]) + 4 WC["BW"]);

(* Dimension-six squared corrections *)
\[CapitalDelta]g1SixSq = (1/32) (1/SMParam["c2\[Theta]"]) (16 SMParam["s\[Theta]"]^2 WC["\[CapitalDelta]4F"]^2 + 3 SMParam["c2\[Theta]"] (4 WC["\[CapitalDelta]4F"]^2 + WC["\[Phi],1"]^2) + 4 WC["\[CapitalDelta]4F"] WC["\[Phi],1"] + 16 SMParam["s2\[Theta]"] WC["\[CapitalDelta]4F"] WC["BW"]);
\[CapitalDelta]g2SixSq = (SMParam["s2\[Theta]"]^2 / (128 * SMParam["c2\[Theta]"]^3)) * (32 SMParam["s\[Theta]"]^2 SMParam["c2\[Theta]"] WC["\[CapitalDelta]4F"]^2 + (1 + 3 SMParam["c4\[Theta]"])(4 WC["\[CapitalDelta]4F"]^2 + WC["\[Phi],1"]^2) - 32 WC["BW"]^2) 
           + (SMParam["s2\[Theta]"]/(8 * SMParam["c2\[Theta]"]^3))*( 4 * (-1 + SMParam["c\[Theta]"]^2 SMParam["s2\[Theta]"]^2) WC["\[CapitalDelta]4F"] WC["BW"] - SMParam["s2\[Theta]"]^2 WC["\[Phi],1"] WC["BW"] - SMParam["s\[Theta]"]^2 SMParam["s2\[Theta]"]WC["\[CapitalDelta]4F"]WC["\[Phi],1"]);
           
(* Direct dimension-eight corrections *)           
\[CapitalDelta]g1Eight = (SMParam["ee"]^4 / (8 * SMParam["c\[Theta]"]^4 * SMParam["s\[Theta]"]^4)) * (SMParam["s\[Theta]"]^2 WC["2\[Psi]4D2"] + SMParam["c\[Theta]"]^2 WC["3\[Psi]4D2"]);
\[CapitalDelta]g2Eight = (SMParam["ee"]^4 / (8 * SMParam["c\[Theta]"]^4 * SMParam["s\[Theta]"]^2)) * (WC["3\[Psi]4D2"] - WC["2\[Psi]4D2"]);


GetZCouplingsShifts::usage = "Returns the replacement of the shifts of the Z couplings"


Options[GetZCouplingsShifts] := {
	EFTScale          -> GetEFTScale[],
	EFTOrder          -> GetEFTOrder[],
	OperatorDimension -> GetOperatorDimension[]
}


GetZCouplingsShifts[OptionsPattern[]] := Module[{\[Epsilon], \[CapitalDelta]g1Aux, \[CapitalDelta]g2Aux, d6 = 1, d6sq = 0, d8 = 0},
	(* Check options for the arguments *)
	CheckOption[#, OptionValue[#]] & /@ {EFTScale, EFTOrder, OperatorDimension};
	
	(* Value of the vev/Lambda *)
	\[Epsilon] = SMParam["vev"] / OptionValue[EFTScale];
	
	If[OptionValue[EFTOrder] === 4, d6sq = 1, d6sq = 0];
	If[OptionValue[OperatorDimension] === 8, d8 = 1, d8 = 0];
	
	(* Shifts *)
	\[CapitalDelta]g1Aux = \[Epsilon]^2 * d6 * \[CapitalDelta]g1Six + \[Epsilon]^4 (d6sq * \[CapitalDelta]g1SixSq + d8 * \[CapitalDelta]g1Eight);
	\[CapitalDelta]g2Aux = \[Epsilon]^2 * d6 * \[CapitalDelta]g2Six + \[Epsilon]^4 (d6sq * \[CapitalDelta]g2SixSq + d8 * \[CapitalDelta]g2Eight);
	
	Return [{\[CapitalDelta]g1 -> \[CapitalDelta]g1Aux, \[CapitalDelta]g2 -> \[CapitalDelta]g2Aux}]
];


(* ::Chapter::RGBColor[1, 0, 0]:: *)
(*Corrections to the W couplings *)


(* Corrections to the W couplings without the factors vev/Lambda *)

(* Dimension-six corrections *)
\[CapitalDelta]gwSix = (-1/(4 * SMParam["c2\[Theta]"]))*(2 SMParam["s2\[Theta]"] WC["BW"] + 2 SMParam["c\[Theta]"]^2 WC["\[CapitalDelta]4F"] + SMParam["c\[Theta]"]^2 WC["\[Phi],1"]);
\[CapitalDelta]MWSix = (-1/(4 * SMParam["c2\[Theta]"]))*(2 SMParam["s2\[Theta]"] WC["BW"] + 2 SMParam["s\[Theta]"]^2 WC["\[CapitalDelta]4F"] + SMParam["c\[Theta]"]^2 WC["\[Phi],1"]);

(* Dimension-six squared corrections *)
\[CapitalDelta]gwSixSq = (1/(32*SMParam["c2\[Theta]"]^3)) * (4 SMParam["s2\[Theta]"]^2 SMParam["c2\[Theta]"] WC["\[CapitalDelta]4F"]^2 + SMParam["c\[Theta]"]^4 (5 SMParam["c2\[Theta]"] - 2) * (4 WC["\[CapitalDelta]4F"]^2 + WC["\[Phi],1"]^2) 
            + 4 (-3 SMParam["c2\[Theta]"]^3 + (SMParam["c2\[Theta]"] - 2)) WC["BW"]^2 + 8 SMParam["s\[Theta]"] (SMParam["c2\[Theta]"] - 2) WC["\[CapitalDelta]4F"]WC["BW"] - 4 SMParam["s\[Theta]"]^2 SMParam["s2\[Theta]"](SMParam["c2\[Theta]"] + 2) WC["BW"] WC["\[Phi],1"] 
            + (SMParam["c2\[Theta]"] + 1)((5 SMParam["c2\[Theta]"] - 2) - SMParam["c2\[Theta]"]^2) WC["\[CapitalDelta]4F"]WC["\[Phi],1"]);
\[CapitalDelta]MWSixSq = (1/(32*SMParam["c2\[Theta]"]^3)) * ( 16 SMParam["s\[Theta]"]^4 SMParam["c2\[Theta]"]WC["\[CapitalDelta]4F"]^2 - 4 SMParam["s\[Theta]"]^4 (3 SMParam["c2\[Theta]"] + 2) WC["\[CapitalDelta]4F"]^2 + SMParam["c\[Theta]"]^4 (5 SMParam["c2\[Theta]"] - 2) WC["\[Phi],1"]^2  
            + 4 (-3 SMParam["c2\[Theta]"]^3 + (SMParam["c2\[Theta]"] - 2))WC["BW"]^2 - 4 SMParam["s\[Theta]"]^2 SMParam["s2\[Theta]"] (SMParam["c2\[Theta]"] + 2)WC["BW"] WC["\[Phi],1"] 
            - 4 SMParam["c\[Theta]"]^2 (7 - 19 SMParam["c\[Theta]"]^2 + 14 SMParam["c\[Theta]"]^4)WC["\[CapitalDelta]4F"]WC["\[Phi],1"] - 8 SMParam["s2\[Theta]"] (6 - 17 SMParam["c\[Theta]"]^2 + 14 SMParam["c\[Theta]"]^4) WC["\[CapitalDelta]4F"]WC["BW"]);

(* Dimension-eight effects *)
\[CapitalDelta]gwEight = (-1/2) WC["3W2H4"] + (SMParam["ee"]^4 / (8 * SMParam["s\[Theta]"]^4)) WC["3\[Psi]4D2"];
\[CapitalDelta]MWEight = (-1/2) WC["3W2H4"];


GetWCouplingsShifts::usage = "Returns the replacement of the shifts of the W couplings"


Options[GetWCouplingsShifts] := {
	EFTScale          -> GetEFTScale[],
	EFTOrder          -> GetEFTOrder[],
	OperatorDimension -> GetOperatorDimension[]
}


GetWCouplingsShifts[OptionsPattern[]] := Module[{\[Epsilon], \[CapitalDelta]gwAux, \[CapitalDelta]MWAux, d6 = 1, d6sq = 0, d8 = 0},
	(* Check options for the arguments *)
	CheckOption[#, OptionValue[#]] & /@ {EFTScale, EFTOrder, OperatorDimension};
	
	(* Value of the vev/Lambda *)
	\[Epsilon] = SMParam["vev"] / OptionValue[EFTScale];
	
	If[OptionValue[EFTOrder] === 4, d6sq = 1, d6sq = 0];
	If[OptionValue[OperatorDimension] === 8, d8 = 1, d8 = 0];
	
	(* Shifts *)
	\[CapitalDelta]gwAux = \[Epsilon]^2 * d6 * \[CapitalDelta]gwSix + \[Epsilon]^4 (d6sq * \[CapitalDelta]gwSixSq + d8 * \[CapitalDelta]gwEight);
	\[CapitalDelta]MWAux = \[Epsilon]^2 * d6 * \[CapitalDelta]MWSix + \[Epsilon]^4 (d6sq * \[CapitalDelta]MWSixSq + d8 * \[CapitalDelta]MWEight);
	
	Return [{\[CapitalDelta]gW -> \[CapitalDelta]gwAux, \[CapitalDelta]MW -> \[CapitalDelta]MWAux}]
];
