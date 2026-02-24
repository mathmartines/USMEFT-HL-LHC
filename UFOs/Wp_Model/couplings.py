# This file was automatically created by FeynRules 2.3.49
# Mathematica version: 12.3.1 for Microsoft Windows (64-bit) (June 24, 2021)
# Date: Wed 4 Feb 2026 13:46:10


from object_library import all_couplings, Coupling

from function_library import complexconjugate, re, im, csc, sec, acsc, asec, cot



GC_1 = Coupling(name = 'GC_1',
                value = '-G',
                order = {'QCD':1})

GC_2 = Coupling(name = 'GC_2',
                value = 'complex(0,1)*G',
                order = {'QCD':1})

GC_3 = Coupling(name = 'GC_3',
                value = 'complex(0,1)*G**2',
                order = {'QCD':2})

GC_4 = Coupling(name = 'GC_4',
                value = '(ccw**2*complex(0,1)*g1**2*gw**2)/(g1**2 + gw**2)',
                order = {'QED':2})

GC_5 = Coupling(name = 'GC_5',
                value = '(-2*cc*ccw**2*complex(0,1)*g1*gw**3)/(g1**2 + gw**2)',
                order = {'QED':2})

GC_6 = Coupling(name = 'GC_6',
                value = '(cc*complex(0,1)*g1**2)/(3.*cmath.sqrt(g1**2 + gw**2))',
                order = {'QED':1})

GC_7 = Coupling(name = 'GC_7',
                value = '(-2*cc*complex(0,1)*g1**2)/(3.*cmath.sqrt(g1**2 + gw**2))',
                order = {'QED':1})

GC_8 = Coupling(name = 'GC_8',
                value = '(cc*complex(0,1)*g1**2)/cmath.sqrt(g1**2 + gw**2)',
                order = {'QED':1})

GC_9 = Coupling(name = 'GC_9',
                value = '-0.3333333333333333*(complex(0,1)*g1*gw)/cmath.sqrt(g1**2 + gw**2)',
                order = {'QED':1})

GC_10 = Coupling(name = 'GC_10',
                 value = '(2*complex(0,1)*g1*gw)/(3.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_11 = Coupling(name = 'GC_11',
                 value = '-((complex(0,1)*g1*gw)/cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_12 = Coupling(name = 'GC_12',
                 value = '(ccw**2*complex(0,1)*g1*gw)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_13 = Coupling(name = 'GC_13',
                 value = '-6*complex(0,1)*lam',
                 order = {'QED':2})

GC_14 = Coupling(name = 'GC_14',
                 value = '(2*ccw**2*complex(0,1)*g1*gw**3*ss)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_15 = Coupling(name = 'GC_15',
                 value = '-0.3333333333333333*(complex(0,1)*g1**2*ss)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_16 = Coupling(name = 'GC_16',
                 value = '(2*complex(0,1)*g1**2*ss)/(3.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_17 = Coupling(name = 'GC_17',
                 value = '-((complex(0,1)*g1**2*ss)/cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_18 = Coupling(name = 'GC_18',
                 value = '-0.5*(beta*complex(0,1)*gw*ss) - (cc*complex(0,1)*g1**2)/(6.*cmath.sqrt(g1**2 + gw**2)) + (cc*complex(0,1)*gw**2)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_19 = Coupling(name = 'GC_19',
                 value = '-0.5*(beta*complex(0,1)*gw*ss) + (cc*complex(0,1)*g1**2)/(2.*cmath.sqrt(g1**2 + gw**2)) + (cc*complex(0,1)*gw**2)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_20 = Coupling(name = 'GC_20',
                 value = '(beta*complex(0,1)*gw*ss)/2. - (cc*complex(0,1)*g1**2)/(6.*cmath.sqrt(g1**2 + gw**2)) - (cc*complex(0,1)*gw**2)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_21 = Coupling(name = 'GC_21',
                 value = '(beta*complex(0,1)*gw*ss)/2. + (cc*complex(0,1)*g1**2)/(2.*cmath.sqrt(g1**2 + gw**2)) - (cc*complex(0,1)*gw**2)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_22 = Coupling(name = 'GC_22',
                 value = '-0.5*(beta*cc*complex(0,1)*gw) + (complex(0,1)*g1**2*ss)/(6.*cmath.sqrt(g1**2 + gw**2)) - (complex(0,1)*gw**2*ss)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_23 = Coupling(name = 'GC_23',
                 value = '-0.5*(beta*cc*complex(0,1)*gw) - (complex(0,1)*g1**2*ss)/(2.*cmath.sqrt(g1**2 + gw**2)) - (complex(0,1)*gw**2*ss)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_24 = Coupling(name = 'GC_24',
                 value = '(beta*cc*complex(0,1)*gw)/2. + (complex(0,1)*g1**2*ss)/(6.*cmath.sqrt(g1**2 + gw**2)) + (complex(0,1)*gw**2*ss)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_25 = Coupling(name = 'GC_25',
                 value = '(beta*cc*complex(0,1)*gw)/2. - (complex(0,1)*g1**2*ss)/(2.*cmath.sqrt(g1**2 + gw**2)) + (complex(0,1)*gw**2*ss)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_26 = Coupling(name = 'GC_26',
                 value = '(beta**2*cc**2*complex(0,1)*gw**2)/2. + (complex(0,1)*g1**2*ss**2)/2. + (complex(0,1)*gw**2*ss**2)/2. + (beta*cc*complex(0,1)*g1**2*gw*ss)/cmath.sqrt(g1**2 + gw**2) + (beta*cc*complex(0,1)*gw**3*ss)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':2})

GC_27 = Coupling(name = 'GC_27',
                 value = '(cc**2*complex(0,1)*g1**2)/2. + (cc**2*complex(0,1)*gw**2)/2. + (beta**2*complex(0,1)*gw**2*ss**2)/2. - (beta*cc*complex(0,1)*g1**2*gw*ss)/cmath.sqrt(g1**2 + gw**2) - (beta*cc*complex(0,1)*gw**3*ss)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':2})

GC_28 = Coupling(name = 'GC_28',
                 value = '-0.5*(cc*complex(0,1)*g1**2*ss) - (cc*complex(0,1)*gw**2*ss)/2. + (beta**2*cc*complex(0,1)*gw**2*ss)/2. - (beta*cc**2*complex(0,1)*g1**2*gw)/(2.*cmath.sqrt(g1**2 + gw**2)) - (beta*cc**2*complex(0,1)*gw**3)/(2.*cmath.sqrt(g1**2 + gw**2)) + (beta*complex(0,1)*g1**2*gw*ss**2)/(2.*cmath.sqrt(g1**2 + gw**2)) + (beta*complex(0,1)*gw**3*ss**2)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':2})

GC_29 = Coupling(name = 'GC_29',
                 value = '-((ccw*complex(0,1)*g1**2*gw**2*ssw)/(g1**2 + gw**2))',
                 order = {'QED':2})

GC_30 = Coupling(name = 'GC_30',
                 value = '(2*cc*ccw*complex(0,1)*g1*gw**3*ssw)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_31 = Coupling(name = 'GC_31',
                 value = '-((ccw*complex(0,1)*g1*gw*ssw)/cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_32 = Coupling(name = 'GC_32',
                 value = '(ccw*complex(0,1)*g1*gw*ssw)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_33 = Coupling(name = 'GC_33',
                 value = '(ccw*complex(0,1)*g1*gw**3*ss*ssw)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_34 = Coupling(name = 'GC_34',
                 value = '(-2*ccw*complex(0,1)*g1*gw**3*ss*ssw)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_35 = Coupling(name = 'GC_35',
                 value = '(complex(0,1)*g1**2*gw**2*ssw**2)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_36 = Coupling(name = 'GC_36',
                 value = '(-2*cc*complex(0,1)*g1*gw**3*ssw**2)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_37 = Coupling(name = 'GC_37',
                 value = '(complex(0,1)*g1*gw*ssw**2)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_38 = Coupling(name = 'GC_38',
                 value = '-((complex(0,1)*g1*gw**3*ss*ssw**2)/(g1**2 + gw**2))',
                 order = {'QED':2})

GC_39 = Coupling(name = 'GC_39',
                 value = '-((beta*ccw*complex(0,1)*gw)/cmath.sqrt(2)) - (complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_40 = Coupling(name = 'GC_40',
                 value = '(ccw*complex(0,1)*gw)/cmath.sqrt(2) - (beta*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_41 = Coupling(name = 'GC_41',
                 value = '-((beta*ccw*CKM1x1*complex(0,1)*gw)/cmath.sqrt(2)) - (CKM1x1*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_42 = Coupling(name = 'GC_42',
                 value = '(ccw*CKM1x1*complex(0,1)*gw)/cmath.sqrt(2) - (beta*CKM1x1*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_43 = Coupling(name = 'GC_43',
                 value = '-((beta*ccw*CKM1x2*complex(0,1)*gw)/cmath.sqrt(2)) - (CKM1x2*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_44 = Coupling(name = 'GC_44',
                 value = '(ccw*CKM1x2*complex(0,1)*gw)/cmath.sqrt(2) - (beta*CKM1x2*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_45 = Coupling(name = 'GC_45',
                 value = '-((beta*ccw*CKM1x3*complex(0,1)*gw)/cmath.sqrt(2)) - (CKM1x3*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_46 = Coupling(name = 'GC_46',
                 value = '(ccw*CKM1x3*complex(0,1)*gw)/cmath.sqrt(2) - (beta*CKM1x3*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_47 = Coupling(name = 'GC_47',
                 value = '-((beta*ccw*CKM2x1*complex(0,1)*gw)/cmath.sqrt(2)) - (CKM2x1*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_48 = Coupling(name = 'GC_48',
                 value = '(ccw*CKM2x1*complex(0,1)*gw)/cmath.sqrt(2) - (beta*CKM2x1*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_49 = Coupling(name = 'GC_49',
                 value = '-((beta*ccw*CKM2x2*complex(0,1)*gw)/cmath.sqrt(2)) - (CKM2x2*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_50 = Coupling(name = 'GC_50',
                 value = '(ccw*CKM2x2*complex(0,1)*gw)/cmath.sqrt(2) - (beta*CKM2x2*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_51 = Coupling(name = 'GC_51',
                 value = '-((beta*ccw*CKM2x3*complex(0,1)*gw)/cmath.sqrt(2)) - (CKM2x3*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_52 = Coupling(name = 'GC_52',
                 value = '(ccw*CKM2x3*complex(0,1)*gw)/cmath.sqrt(2) - (beta*CKM2x3*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_53 = Coupling(name = 'GC_53',
                 value = '-((beta*ccw*CKM3x1*complex(0,1)*gw)/cmath.sqrt(2)) - (CKM3x1*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_54 = Coupling(name = 'GC_54',
                 value = '(ccw*CKM3x1*complex(0,1)*gw)/cmath.sqrt(2) - (beta*CKM3x1*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_55 = Coupling(name = 'GC_55',
                 value = '-((beta*ccw*CKM3x2*complex(0,1)*gw)/cmath.sqrt(2)) - (CKM3x2*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_56 = Coupling(name = 'GC_56',
                 value = '(ccw*CKM3x2*complex(0,1)*gw)/cmath.sqrt(2) - (beta*CKM3x2*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_57 = Coupling(name = 'GC_57',
                 value = '-((beta*ccw*CKM3x3*complex(0,1)*gw)/cmath.sqrt(2)) - (CKM3x3*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_58 = Coupling(name = 'GC_58',
                 value = '(ccw*CKM3x3*complex(0,1)*gw)/cmath.sqrt(2) - (beta*CKM3x3*complex(0,1)*gw*ssw)/cmath.sqrt(2)',
                 order = {'QED':1})

GC_59 = Coupling(name = 'GC_59',
                 value = '-(beta*ccw*complex(0,1)*gw*ss*ssw) + (cc*ccw*complex(0,1)*gw**2*ssw)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_60 = Coupling(name = 'GC_60',
                 value = 'beta*ccw*complex(0,1)*gw*ss*ssw - (cc*ccw*complex(0,1)*gw**2*ssw)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_61 = Coupling(name = 'GC_61',
                 value = '(beta**2*cc*ccw*complex(0,1)*g1**2*gw**2*ss*ssw)/(g1**2 + gw**2) + (cc*ccw*complex(0,1)*gw**4*ss*ssw)/(g1**2 + gw**2) + (beta**2*cc*ccw*complex(0,1)*gw**4*ss*ssw)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_62 = Coupling(name = 'GC_62',
                 value = '-(beta*cc*ccw*complex(0,1)*gw*ssw) - (ccw*complex(0,1)*gw**2*ss*ssw)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_63 = Coupling(name = 'GC_63',
                 value = '(beta**2*cc**2*ccw*complex(0,1)*g1**2*gw**2*ssw)/(g1**2 + gw**2) + (beta**2*cc**2*ccw*complex(0,1)*gw**4*ssw)/(g1**2 + gw**2) - (ccw*complex(0,1)*gw**4*ss**2*ssw)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_64 = Coupling(name = 'GC_64',
                 value = '(-2*beta**2*cc**2*ccw*complex(0,1)*g1**2*gw**2*ssw)/(g1**2 + gw**2) - (2*beta**2*cc**2*ccw*complex(0,1)*gw**4*ssw)/(g1**2 + gw**2) + (2*ccw*complex(0,1)*gw**4*ss**2*ssw)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_65 = Coupling(name = 'GC_65',
                 value = '-((cc**2*ccw*complex(0,1)*gw**4*ssw)/(g1**2 + gw**2)) + (beta**2*ccw*complex(0,1)*g1**2*gw**2*ss**2*ssw)/(g1**2 + gw**2) + (beta**2*ccw*complex(0,1)*gw**4*ss**2*ssw)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_66 = Coupling(name = 'GC_66',
                 value = 'beta*cc*complex(0,1)*gw*ssw**2 - (ccw**2*complex(0,1)*gw**2*ss)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_67 = Coupling(name = 'GC_67',
                 value = '(beta**2*ccw**2*complex(0,1)*gw**2)/2. + beta*ccw*complex(0,1)*gw**2*ssw + (complex(0,1)*gw**2*ssw**2)/2.',
                 order = {'QED':2})

GC_68 = Coupling(name = 'GC_68',
                 value = '-0.5*(beta*ccw**2*complex(0,1)*gw**2) - (ccw*complex(0,1)*gw**2*ssw)/2. + (beta**2*ccw*complex(0,1)*gw**2*ssw)/2. + (beta*complex(0,1)*gw**2*ssw**2)/2.',
                 order = {'QED':2})

GC_69 = Coupling(name = 'GC_69',
                 value = '(ccw**2*complex(0,1)*gw**2)/2. - beta*ccw*complex(0,1)*gw**2*ssw + (beta**2*complex(0,1)*gw**2*ssw**2)/2.',
                 order = {'QED':2})

GC_70 = Coupling(name = 'GC_70',
                 value = '-(ccw**2*complex(0,1)*gw**2*ssw**2) - beta**2*ccw**2*complex(0,1)*gw**2*ssw**2',
                 order = {'QED':2})

GC_71 = Coupling(name = 'GC_71',
                 value = '(beta**2*ccw**2*complex(0,1)*g1**2*gw**2*ss**2)/(g1**2 + gw**2) + (beta**2*ccw**2*complex(0,1)*gw**4*ss**2)/(g1**2 + gw**2) + (cc**2*complex(0,1)*gw**4*ssw**2)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_72 = Coupling(name = 'GC_72',
                 value = '(ccw**2*complex(0,1)*gw**4*ss**2)/(g1**2 + gw**2) + (beta**2*cc**2*complex(0,1)*g1**2*gw**2*ssw**2)/(g1**2 + gw**2) + (beta**2*cc**2*complex(0,1)*gw**4*ssw**2)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_73 = Coupling(name = 'GC_73',
                 value = 'beta*ccw**2*complex(0,1)*gw*ss + (cc*complex(0,1)*gw**2*ssw**2)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_74 = Coupling(name = 'GC_74',
                 value = 'beta*complex(0,1)*gw*ss*ssw**2 + (cc*ccw**2*complex(0,1)*gw**2)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_75 = Coupling(name = 'GC_75',
                 value = '(beta**2*cc*ccw**2*complex(0,1)*g1**2*gw**2*ss)/(g1**2 + gw**2) + (beta**2*cc*ccw**2*complex(0,1)*gw**4*ss)/(g1**2 + gw**2) - (cc*complex(0,1)*gw**4*ss*ssw**2)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_76 = Coupling(name = 'GC_76',
                 value = '-((cc*ccw**2*complex(0,1)*gw**4*ss)/(g1**2 + gw**2)) + (beta**2*cc*complex(0,1)*g1**2*gw**2*ss*ssw**2)/(g1**2 + gw**2) + (beta**2*cc*complex(0,1)*gw**4*ss*ssw**2)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_77 = Coupling(name = 'GC_77',
                 value = '-(beta*cc*ccw**2*complex(0,1)*gw) + (complex(0,1)*gw**2*ss*ssw**2)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_78 = Coupling(name = 'GC_78',
                 value = '(-2*beta**2*cc**2*ccw**2*complex(0,1)*g1**2*gw**2)/(g1**2 + gw**2) - (2*beta**2*cc**2*ccw**2*complex(0,1)*gw**4)/(g1**2 + gw**2) - (2*complex(0,1)*gw**4*ss**2*ssw**2)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_79 = Coupling(name = 'GC_79',
                 value = '(cc**2*ccw**2*complex(0,1)*gw**4)/(g1**2 + gw**2) + (beta**2*complex(0,1)*g1**2*gw**2*ss**2*ssw**2)/(g1**2 + gw**2) + (beta**2*complex(0,1)*gw**4*ss**2*ssw**2)/(g1**2 + gw**2)',
                 order = {'QED':2})

GC_80 = Coupling(name = 'GC_80',
                 value = '-(beta**2*ccw**3*complex(0,1)*gw**2*ssw) + ccw*complex(0,1)*gw**2*ssw**3',
                 order = {'QED':2})

GC_81 = Coupling(name = 'GC_81',
                 value = '2*beta**2*ccw**3*complex(0,1)*gw**2*ssw - 2*ccw*complex(0,1)*gw**2*ssw**3',
                 order = {'QED':2})

GC_82 = Coupling(name = 'GC_82',
                 value = 'ccw**3*complex(0,1)*gw**2*ssw - beta**2*ccw*complex(0,1)*gw**2*ssw**3',
                 order = {'QED':2})

GC_83 = Coupling(name = 'GC_83',
                 value = '-2*ccw**3*complex(0,1)*gw**2*ssw + 2*beta**2*ccw*complex(0,1)*gw**2*ssw**3',
                 order = {'QED':2})

GC_84 = Coupling(name = 'GC_84',
                 value = '-(beta**2*ccw**4*complex(0,1)*gw**2) - complex(0,1)*gw**2*ssw**4',
                 order = {'QED':2})

GC_85 = Coupling(name = 'GC_85',
                 value = '-(ccw**4*complex(0,1)*gw**2) - beta**2*complex(0,1)*gw**2*ssw**4',
                 order = {'QED':2})

GC_86 = Coupling(name = 'GC_86',
                 value = '-6*complex(0,1)*lam*vev',
                 order = {'QED':1})

GC_87 = Coupling(name = 'GC_87',
                 value = '(beta**2*cc**2*complex(0,1)*gw**2*vev)/2. + (complex(0,1)*g1**2*ss**2*vev)/2. + (complex(0,1)*gw**2*ss**2*vev)/2. + (beta*cc*complex(0,1)*g1**2*gw*ss*vev)/cmath.sqrt(g1**2 + gw**2) + (beta*cc*complex(0,1)*gw**3*ss*vev)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_88 = Coupling(name = 'GC_88',
                 value = '(cc**2*complex(0,1)*g1**2*vev)/2. + (cc**2*complex(0,1)*gw**2*vev)/2. + (beta**2*complex(0,1)*gw**2*ss**2*vev)/2. - (beta*cc*complex(0,1)*g1**2*gw*ss*vev)/cmath.sqrt(g1**2 + gw**2) - (beta*cc*complex(0,1)*gw**3*ss*vev)/cmath.sqrt(g1**2 + gw**2)',
                 order = {'QED':1})

GC_89 = Coupling(name = 'GC_89',
                 value = '-0.5*(cc*complex(0,1)*g1**2*ss*vev) - (cc*complex(0,1)*gw**2*ss*vev)/2. + (beta**2*cc*complex(0,1)*gw**2*ss*vev)/2. - (beta*cc**2*complex(0,1)*g1**2*gw*vev)/(2.*cmath.sqrt(g1**2 + gw**2)) - (beta*cc**2*complex(0,1)*gw**3*vev)/(2.*cmath.sqrt(g1**2 + gw**2)) + (beta*complex(0,1)*g1**2*gw*ss**2*vev)/(2.*cmath.sqrt(g1**2 + gw**2)) + (beta*complex(0,1)*gw**3*ss**2*vev)/(2.*cmath.sqrt(g1**2 + gw**2))',
                 order = {'QED':1})

GC_90 = Coupling(name = 'GC_90',
                 value = '(beta**2*ccw**2*complex(0,1)*gw**2*vev)/2. + beta*ccw*complex(0,1)*gw**2*ssw*vev + (complex(0,1)*gw**2*ssw**2*vev)/2.',
                 order = {'QED':1})

GC_91 = Coupling(name = 'GC_91',
                 value = '-0.5*(beta*ccw**2*complex(0,1)*gw**2*vev) - (ccw*complex(0,1)*gw**2*ssw*vev)/2. + (beta**2*ccw*complex(0,1)*gw**2*ssw*vev)/2. + (beta*complex(0,1)*gw**2*ssw**2*vev)/2.',
                 order = {'QED':1})

GC_92 = Coupling(name = 'GC_92',
                 value = '(ccw**2*complex(0,1)*gw**2*vev)/2. - beta*ccw*complex(0,1)*gw**2*ssw*vev + (beta**2*complex(0,1)*gw**2*ssw**2*vev)/2.',
                 order = {'QED':1})

GC_93 = Coupling(name = 'GC_93',
                 value = '-((complex(0,1)*yb)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_94 = Coupling(name = 'GC_94',
                 value = '-((complex(0,1)*yc)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_95 = Coupling(name = 'GC_95',
                 value = '-((complex(0,1)*ydo)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_96 = Coupling(name = 'GC_96',
                 value = '-((complex(0,1)*ye)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_97 = Coupling(name = 'GC_97',
                 value = '-((complex(0,1)*ym)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_98 = Coupling(name = 'GC_98',
                 value = '-((complex(0,1)*ys)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_99 = Coupling(name = 'GC_99',
                 value = '-((complex(0,1)*yt)/cmath.sqrt(2))',
                 order = {'QED':1})

GC_100 = Coupling(name = 'GC_100',
                  value = '-((complex(0,1)*ytau)/cmath.sqrt(2))',
                  order = {'QED':1})

GC_101 = Coupling(name = 'GC_101',
                  value = '-((complex(0,1)*yup)/cmath.sqrt(2))',
                  order = {'QED':1})

GC_102 = Coupling(name = 'GC_102',
                  value = '-((beta*ccw*complex(0,1)*gw*complexconjugate(CKM1x1))/cmath.sqrt(2)) - (complex(0,1)*gw*ssw*complexconjugate(CKM1x1))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_103 = Coupling(name = 'GC_103',
                  value = '(ccw*complex(0,1)*gw*complexconjugate(CKM1x1))/cmath.sqrt(2) - (beta*complex(0,1)*gw*ssw*complexconjugate(CKM1x1))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_104 = Coupling(name = 'GC_104',
                  value = '-((beta*ccw*complex(0,1)*gw*complexconjugate(CKM1x2))/cmath.sqrt(2)) - (complex(0,1)*gw*ssw*complexconjugate(CKM1x2))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_105 = Coupling(name = 'GC_105',
                  value = '(ccw*complex(0,1)*gw*complexconjugate(CKM1x2))/cmath.sqrt(2) - (beta*complex(0,1)*gw*ssw*complexconjugate(CKM1x2))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_106 = Coupling(name = 'GC_106',
                  value = '-((beta*ccw*complex(0,1)*gw*complexconjugate(CKM1x3))/cmath.sqrt(2)) - (complex(0,1)*gw*ssw*complexconjugate(CKM1x3))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_107 = Coupling(name = 'GC_107',
                  value = '(ccw*complex(0,1)*gw*complexconjugate(CKM1x3))/cmath.sqrt(2) - (beta*complex(0,1)*gw*ssw*complexconjugate(CKM1x3))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_108 = Coupling(name = 'GC_108',
                  value = '-((beta*ccw*complex(0,1)*gw*complexconjugate(CKM2x1))/cmath.sqrt(2)) - (complex(0,1)*gw*ssw*complexconjugate(CKM2x1))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_109 = Coupling(name = 'GC_109',
                  value = '(ccw*complex(0,1)*gw*complexconjugate(CKM2x1))/cmath.sqrt(2) - (beta*complex(0,1)*gw*ssw*complexconjugate(CKM2x1))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_110 = Coupling(name = 'GC_110',
                  value = '-((beta*ccw*complex(0,1)*gw*complexconjugate(CKM2x2))/cmath.sqrt(2)) - (complex(0,1)*gw*ssw*complexconjugate(CKM2x2))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_111 = Coupling(name = 'GC_111',
                  value = '(ccw*complex(0,1)*gw*complexconjugate(CKM2x2))/cmath.sqrt(2) - (beta*complex(0,1)*gw*ssw*complexconjugate(CKM2x2))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_112 = Coupling(name = 'GC_112',
                  value = '-((beta*ccw*complex(0,1)*gw*complexconjugate(CKM2x3))/cmath.sqrt(2)) - (complex(0,1)*gw*ssw*complexconjugate(CKM2x3))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_113 = Coupling(name = 'GC_113',
                  value = '(ccw*complex(0,1)*gw*complexconjugate(CKM2x3))/cmath.sqrt(2) - (beta*complex(0,1)*gw*ssw*complexconjugate(CKM2x3))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_114 = Coupling(name = 'GC_114',
                  value = '-((beta*ccw*complex(0,1)*gw*complexconjugate(CKM3x1))/cmath.sqrt(2)) - (complex(0,1)*gw*ssw*complexconjugate(CKM3x1))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_115 = Coupling(name = 'GC_115',
                  value = '(ccw*complex(0,1)*gw*complexconjugate(CKM3x1))/cmath.sqrt(2) - (beta*complex(0,1)*gw*ssw*complexconjugate(CKM3x1))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_116 = Coupling(name = 'GC_116',
                  value = '-((beta*ccw*complex(0,1)*gw*complexconjugate(CKM3x2))/cmath.sqrt(2)) - (complex(0,1)*gw*ssw*complexconjugate(CKM3x2))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_117 = Coupling(name = 'GC_117',
                  value = '(ccw*complex(0,1)*gw*complexconjugate(CKM3x2))/cmath.sqrt(2) - (beta*complex(0,1)*gw*ssw*complexconjugate(CKM3x2))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_118 = Coupling(name = 'GC_118',
                  value = '-((beta*ccw*complex(0,1)*gw*complexconjugate(CKM3x3))/cmath.sqrt(2)) - (complex(0,1)*gw*ssw*complexconjugate(CKM3x3))/cmath.sqrt(2)',
                  order = {'QED':1})

GC_119 = Coupling(name = 'GC_119',
                  value = '(ccw*complex(0,1)*gw*complexconjugate(CKM3x3))/cmath.sqrt(2) - (beta*complex(0,1)*gw*ssw*complexconjugate(CKM3x3))/cmath.sqrt(2)',
                  order = {'QED':1})

