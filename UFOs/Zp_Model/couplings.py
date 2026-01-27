# This file was automatically created by FeynRules 2.3.49
# Mathematica version: 12.3.1 for Microsoft Windows (64-bit) (June 24, 2021)
# Date: Tue 20 Jan 2026 16:04:30


from object_library import all_couplings, Coupling

from function_library import complexconjugate, re, im, csc, sec, acsc, asec, cot



GC_1 = Coupling(name = 'GC_1',
                value = '-(complex(0,1)*G)',
                order = {'QCD':1})

GC_2 = Coupling(name = 'GC_2',
                value = 'G',
                order = {'QCD':1})

GC_3 = Coupling(name = 'GC_3',
                value = 'complex(0,1)*G**2',
                order = {'QCD':2})

GC_4 = Coupling(name = 'GC_4',
                value = '-((complex(0,1)*gw)/cmath.sqrt(2))',
                order = {'QED':1})

GC_5 = Coupling(name = 'GC_5',
                value = '-((CKM1x1*complex(0,1)*gw)/cmath.sqrt(2))',
                order = {'QED':1})

GC_6 = Coupling(name = 'GC_6',
                value = '-((CKM1x2*complex(0,1)*gw)/cmath.sqrt(2))',
                order = {'QED':1})

GC_7 = Coupling(name = 'GC_7',
                value = '-((CKM1x3*complex(0,1)*gw)/cmath.sqrt(2))',
                order = {'QED':1})

GC_8 = Coupling(name = 'GC_8',
                value = '-((CKM2x1*complex(0,1)*gw)/cmath.sqrt(2))',
                order = {'QED':1})

GC_9 = Coupling(name = 'GC_9',
                value = '-((CKM2x2*complex(0,1)*gw)/cmath.sqrt(2))',
                order = {'QED':1})

GC_10 = Coupling(name = 'GC_10',
                 value = '-((CKM2x3*complex(0,1)*gw)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_11 = Coupling(name = 'GC_11',
                 value = '-((CKM3x1*complex(0,1)*gw)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_12 = Coupling(name = 'GC_12',
                 value = '-((CKM3x2*complex(0,1)*gw)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_13 = Coupling(name = 'GC_13',
                 value = '-((CKM3x3*complex(0,1)*gw)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_14 = Coupling(name = 'GC_14',
                 value = '(complex(0,1)*gw**2)/2.',
                 order = {'QED':2})

GC_15 = Coupling(name = 'GC_15',
                 value = '-(complex(0,1)*gw**2)',
                 order = {'QED':2})

GC_16 = Coupling(name = 'GC_16',
                 value = '(complex(0,1)*g1**2*gw**2)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_17 = Coupling(name = 'GC_17',
                 value = '(-2*cc*complex(0,1)*g1*gw**3)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_18 = Coupling(name = 'GC_18',
                 value = '(cc**2*complex(0,1)*gw**4)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_19 = Coupling(name = 'GC_19',
                 value = '(complex(0,1)*g1*gw)/(3.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_20 = Coupling(name = 'GC_20',
                 value = '(-2*complex(0,1)*g1*gw)/(3.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_21 = Coupling(name = 'GC_21',
                 value = '-((complex(0,1)*g1*gw)/cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_22 = Coupling(name = 'GC_22',
                 value = '(complex(0,1)*g1*gw)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_23 = Coupling(name = 'GC_23',
                 value = '-((cc*complex(0,1)*gw**2)/cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_24 = Coupling(name = 'GC_24',
                 value = '-6*complex(0,1)*lam',
                 order = {'QED':2})

GC_25 = Coupling(name = 'GC_25',
                 value = '(2*complex(0,1)*g1*gw**3*ss)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_26 = Coupling(name = 'GC_26',
                 value = '-((cc*complex(0,1)*gw**4*ss)/(g1**2 + gw**2))',
                 order = {'QED':2})

GC_27 = Coupling(name = 'GC_27',
                 value = '(complex(0,1)*gw**2*ss)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_28 = Coupling(name = 'GC_28',
                 value = '(complex(0,1)*gw**4*ss**2)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_29 = Coupling(name = 'GC_29',
                 value = '(cc**2*complex(0,1)*g1**2)/2. + (cc**2*complex(0,1)*gw**2)/2. + (beta**2*complex(0,1)*g1**2*ss**2)/2. - (beta*cc*complex(0,1)*g1**3*ss)/cmath.sqrt(g1**2 + gw**2) - (beta*cc*complex(0,1)*g1*gw**2*ss)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':2})

GC_30 = Coupling(name = 'GC_30',
                 value = '(beta**2*cc**2*complex(0,1)*g1**2)/2. + (complex(0,1)*g1**2*ss**2)/2. + (complex(0,1)*gw**2*ss**2)/2. + (beta*cc*complex(0,1)*g1**3*ss)/cmath.sqrt(g1**2 + gw**2) + (beta*cc*complex(0,1)*g1*gw**2*ss)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':2})

GC_31 = Coupling(name = 'GC_31',
                 value = '-0.5*(cc*complex(0,1)*g1**2*ss) + (beta**2*cc*complex(0,1)*g1**2*ss)/2. - (cc*complex(0,1)*gw**2*ss)/2. - (beta*cc**2*complex(0,1)*g1**3)/(2.*cmath.sqrt(g1**2 + gw**2)) - (beta*cc**2*complex(0,1)*g1*gw**2)/(2.*cmath.sqrt(g1**2 + gw**2)) + (beta*complex(0,1)*g1**3*ss**2)/(2.*cmath.sqrt(g1**2 + gw**2)) + (beta*complex(0,1)*g1*gw**2*ss**2)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':2})

GC_32 = Coupling(name = 'GC_32',
                 value = '(complex(0,1)*gw**2*vev)/2.',
                 order = {'QED':1})

GC_33 = Coupling(name = 'GC_33',
                 value = '-6*complex(0,1)*lam*vev',
                 order = {'QED':1})

GC_34 = Coupling(name = 'GC_34',
                 value = '(cc**2*complex(0,1)*g1**2*vev)/2. + (cc**2*complex(0,1)*gw**2*vev)/2. + (beta**2*complex(0,1)*g1**2*ss**2*vev)/2. - (beta*cc*complex(0,1)*g1**3*ss*vev)/cmath.sqrt(g1**2 + gw**2) - (beta*cc*complex(0,1)*g1*gw**2*ss*vev)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_35 = Coupling(name = 'GC_35',
                 value = '(beta**2*cc**2*complex(0,1)*g1**2*vev)/2. + (complex(0,1)*g1**2*ss**2*vev)/2. + (complex(0,1)*gw**2*ss**2*vev)/2. + (beta*cc*complex(0,1)*g1**3*ss*vev)/cmath.sqrt(g1**2 + gw**2) + (beta*cc*complex(0,1)*g1*gw**2*ss*vev)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_36 = Coupling(name = 'GC_36',
                 value = '-0.5*(cc*complex(0,1)*g1**2*ss*vev) + (beta**2*cc*complex(0,1)*g1**2*ss*vev)/2. - (cc*complex(0,1)*gw**2*ss*vev)/2. - (beta*cc**2*complex(0,1)*g1**3*vev)/(2.*cmath.sqrt(g1**2 + gw**2)) - (beta*cc**2*complex(0,1)*g1*gw**2*vev)/(2.*cmath.sqrt(g1**2 + gw**2)) + (beta*complex(0,1)*g1**3*ss**2*vev)/(2.*cmath.sqrt(g1**2 + gw**2)) + (beta*complex(0,1)*g1*gw**2*ss**2*vev)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_37 = Coupling(name = 'GC_37',
                 value = '-((complex(0,1)*yb)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_38 = Coupling(name = 'GC_38',
                 value = '-((complex(0,1)*yc)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_39 = Coupling(name = 'GC_39',
                 value = '-(beta*cc*complex(0,1)*g1*Yd) + (complex(0,1)*g1**2*ss)/(3.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_40 = Coupling(name = 'GC_40',
                 value = '-(beta*complex(0,1)*g1*ss*Yd) - (cc*complex(0,1)*g1**2)/(3.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_41 = Coupling(name = 'GC_41',
                 value = '-((complex(0,1)*ydo)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_42 = Coupling(name = 'GC_42',
                 value = '-((complex(0,1)*ye)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_43 = Coupling(name = 'GC_43',
                 value = '-(beta*cc*complex(0,1)*g1*Ye) + (complex(0,1)*g1**2*ss)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_44 = Coupling(name = 'GC_44',
                 value = '-(beta*complex(0,1)*g1*ss*Ye) - (cc*complex(0,1)*g1**2)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_45 = Coupling(name = 'GC_45',
                 value = '-(beta*cc*complex(0,1)*g1*YL) + (complex(0,1)*g1**2*ss)/(2.*cmath.sqrt(g1**2 + gw**2)) - (complex(0,1)*gw**2*ss)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_46 = Coupling(name = 'GC_46',
                 value = '-(beta*cc*complex(0,1)*g1*YL) + (complex(0,1)*g1**2*ss)/(2.*cmath.sqrt(g1**2 + gw**2)) + (complex(0,1)*gw**2*ss)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_47 = Coupling(name = 'GC_47',
                 value = '-(beta*complex(0,1)*g1*ss*YL) - (cc*complex(0,1)*g1**2)/(2.*cmath.sqrt(g1**2 + gw**2)) - (cc*complex(0,1)*gw**2)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_48 = Coupling(name = 'GC_48',
                 value = '-(beta*complex(0,1)*g1*ss*YL) - (cc*complex(0,1)*g1**2)/(2.*cmath.sqrt(g1**2 + gw**2)) + (cc*complex(0,1)*gw**2)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_49 = Coupling(name = 'GC_49',
                 value = '-((complex(0,1)*ym)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_50 = Coupling(name = 'GC_50',
                 value = '-(beta*cc*complex(0,1)*g1*YQ) - (complex(0,1)*g1**2*ss)/(6.*cmath.sqrt(g1**2 + gw**2)) - (complex(0,1)*gw**2*ss)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_51 = Coupling(name = 'GC_51',
                 value = '-(beta*cc*complex(0,1)*g1*YQ) - (complex(0,1)*g1**2*ss)/(6.*cmath.sqrt(g1**2 + gw**2)) + (complex(0,1)*gw**2*ss)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_52 = Coupling(name = 'GC_52',
                 value = '-(beta*complex(0,1)*g1*ss*YQ) + (cc*complex(0,1)*g1**2)/(6.*cmath.sqrt(g1**2 + gw**2)) - (cc*complex(0,1)*gw**2)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_53 = Coupling(name = 'GC_53',
                 value = '-(beta*complex(0,1)*g1*ss*YQ) + (cc*complex(0,1)*g1**2)/(6.*cmath.sqrt(g1**2 + gw**2)) + (cc*complex(0,1)*gw**2)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_54 = Coupling(name = 'GC_54',
                 value = '-((complex(0,1)*ys)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_55 = Coupling(name = 'GC_55',
                 value = '-((complex(0,1)*yt)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_56 = Coupling(name = 'GC_56',
                 value = '-((complex(0,1)*ytau)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_57 = Coupling(name = 'GC_57',
                 value = '-(beta*cc*complex(0,1)*g1*Yu) - (2*complex(0,1)*g1**2*ss)/(3.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_58 = Coupling(name = 'GC_58',
                 value = '-(beta*complex(0,1)*g1*ss*Yu) + (2*cc*complex(0,1)*g1**2)/(3.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_59 = Coupling(name = 'GC_59',
                 value = '-((complex(0,1)*yup)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_60 = Coupling(name = 'GC_60',
                 value = '-((complex(0,1)*gw*complexconjugate(CKM1x1))/cmath.sqrt(2))',
                 order = {'QED':1})

GC_61 = Coupling(name = 'GC_61',
                 value = '-((complex(0,1)*gw*complexconjugate(CKM1x2))/cmath.sqrt(2))',
                 order = {'QED':1})

GC_62 = Coupling(name = 'GC_62',
                 value = '-((complex(0,1)*gw*complexconjugate(CKM1x3))/cmath.sqrt(2))',
                 order = {'QED':1})

GC_63 = Coupling(name = 'GC_63',
                 value = '-((complex(0,1)*gw*complexconjugate(CKM2x1))/cmath.sqrt(2))',
                 order = {'QED':1})

GC_64 = Coupling(name = 'GC_64',
                 value = '-((complex(0,1)*gw*complexconjugate(CKM2x2))/cmath.sqrt(2))',
                 order = {'QED':1})

GC_65 = Coupling(name = 'GC_65',
                 value = '-((complex(0,1)*gw*complexconjugate(CKM2x3))/cmath.sqrt(2))',
                 order = {'QED':1})

GC_66 = Coupling(name = 'GC_66',
                 value = '-((complex(0,1)*gw*complexconjugate(CKM3x1))/cmath.sqrt(2))',
                 order = {'QED':1})

GC_67 = Coupling(name = 'GC_67',
                 value = '-((complex(0,1)*gw*complexconjugate(CKM3x2))/cmath.sqrt(2))',
                 order = {'QED':1})

GC_68 = Coupling(name = 'GC_68',
                 value = '-((complex(0,1)*gw*complexconjugate(CKM3x3))/cmath.sqrt(2))',
                 order = {'QED':1})

