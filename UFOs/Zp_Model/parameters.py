# This file was automatically created by FeynRules 2.3.49
# Mathematica version: 12.3.1 for Microsoft Windows (64-bit) (June 24, 2021)
# Date: Tue 20 Jan 2026 16:04:30



from object_library import all_parameters, Parameter


from function_library import complexconjugate, re, im, csc, sec, acsc, asec, cot

# This is a default parameter object representing 0.
ZERO = Parameter(name = 'ZERO',
                 nature = 'internal',
                 type = 'real',
                 value = '0.0',
                 texname = '0')

# User-defined parameters.
cabi = Parameter(name = 'cabi',
                 nature = 'external',
                 type = 'real',
                 value = 0.227736,
                 texname = '\\text{cabi}',
                 lhablock = 'CKMBLOCK',
                 lhacode = [ 1 ])

MXX = Parameter(name = 'MXX',
                nature = 'external',
                type = 'real',
                value = 1000.,
                texname = '\\text{MXX}',
                lhablock = 'NP',
                lhacode = [ 1 ])

beta = Parameter(name = 'beta',
                 nature = 'external',
                 type = 'real',
                 value = 1.,
                 texname = '\\beta',
                 lhablock = 'NP',
                 lhacode = [ 2 ])

aEWM1 = Parameter(name = 'aEWM1',
                  nature = 'external',
                  type = 'real',
                  value = 127.9,
                  texname = '\\text{aEWM1}',
                  lhablock = 'SMINPUTS',
                  lhacode = [ 1 ])

GFhat = Parameter(name = 'GFhat',
                  nature = 'external',
                  type = 'real',
                  value = 0.0000116637,
                  texname = '\\text{GFhat}',
                  lhablock = 'SMINPUTS',
                  lhacode = [ 2 ])

aS = Parameter(name = 'aS',
               nature = 'external',
               type = 'real',
               value = 0.1184,
               texname = '\\text{aS}',
               lhablock = 'SMINPUTS',
               lhacode = [ 3 ])

ymdo = Parameter(name = 'ymdo',
                 nature = 'external',
                 type = 'real',
                 value = 0.00504,
                 texname = '\\text{ymdo}',
                 lhablock = 'YUKAWA',
                 lhacode = [ 1 ])

ymup = Parameter(name = 'ymup',
                 nature = 'external',
                 type = 'real',
                 value = 0.00255,
                 texname = '\\text{ymup}',
                 lhablock = 'YUKAWA',
                 lhacode = [ 2 ])

yms = Parameter(name = 'yms',
                nature = 'external',
                type = 'real',
                value = 0.101,
                texname = '\\text{yms}',
                lhablock = 'YUKAWA',
                lhacode = [ 3 ])

ymc = Parameter(name = 'ymc',
                nature = 'external',
                type = 'real',
                value = 1.27,
                texname = '\\text{ymc}',
                lhablock = 'YUKAWA',
                lhacode = [ 4 ])

ymb = Parameter(name = 'ymb',
                nature = 'external',
                type = 'real',
                value = 4.7,
                texname = '\\text{ymb}',
                lhablock = 'YUKAWA',
                lhacode = [ 5 ])

ymt = Parameter(name = 'ymt',
                nature = 'external',
                type = 'real',
                value = 172,
                texname = '\\text{ymt}',
                lhablock = 'YUKAWA',
                lhacode = [ 6 ])

yme = Parameter(name = 'yme',
                nature = 'external',
                type = 'real',
                value = 0.000511,
                texname = '\\text{yme}',
                lhablock = 'YUKAWA',
                lhacode = [ 11 ])

ymm = Parameter(name = 'ymm',
                nature = 'external',
                type = 'real',
                value = 0.10566,
                texname = '\\text{ymm}',
                lhablock = 'YUKAWA',
                lhacode = [ 13 ])

ymtau = Parameter(name = 'ymtau',
                  nature = 'external',
                  type = 'real',
                  value = 1.777,
                  texname = '\\text{ymtau}',
                  lhablock = 'YUKAWA',
                  lhacode = [ 15 ])

MZ = Parameter(name = 'MZ',
               nature = 'external',
               type = 'real',
               value = 91.1876,
               texname = '\\text{MZ}',
               lhablock = 'MASS',
               lhacode = [ 23 ])

Me = Parameter(name = 'Me',
               nature = 'external',
               type = 'real',
               value = 0.000511,
               texname = '\\text{Me}',
               lhablock = 'MASS',
               lhacode = [ 11 ])

MMU = Parameter(name = 'MMU',
                nature = 'external',
                type = 'real',
                value = 0.10566,
                texname = '\\text{MMU}',
                lhablock = 'MASS',
                lhacode = [ 13 ])

MTA = Parameter(name = 'MTA',
                nature = 'external',
                type = 'real',
                value = 1.777,
                texname = '\\text{MTA}',
                lhablock = 'MASS',
                lhacode = [ 15 ])

MU = Parameter(name = 'MU',
               nature = 'external',
               type = 'real',
               value = 0.00255,
               texname = 'M',
               lhablock = 'MASS',
               lhacode = [ 2 ])

MC = Parameter(name = 'MC',
               nature = 'external',
               type = 'real',
               value = 1.27,
               texname = '\\text{MC}',
               lhablock = 'MASS',
               lhacode = [ 4 ])

MT = Parameter(name = 'MT',
               nature = 'external',
               type = 'real',
               value = 172,
               texname = '\\text{MT}',
               lhablock = 'MASS',
               lhacode = [ 6 ])

MD = Parameter(name = 'MD',
               nature = 'external',
               type = 'real',
               value = 0.00504,
               texname = '\\text{MD}',
               lhablock = 'MASS',
               lhacode = [ 1 ])

MS = Parameter(name = 'MS',
               nature = 'external',
               type = 'real',
               value = 0.101,
               texname = '\\text{MS}',
               lhablock = 'MASS',
               lhacode = [ 3 ])

MB = Parameter(name = 'MB',
               nature = 'external',
               type = 'real',
               value = 4.7,
               texname = '\\text{MB}',
               lhablock = 'MASS',
               lhacode = [ 5 ])

MH = Parameter(name = 'MH',
               nature = 'external',
               type = 'real',
               value = 125,
               texname = '\\text{MH}',
               lhablock = 'MASS',
               lhacode = [ 25 ])

WZ = Parameter(name = 'WZ',
               nature = 'external',
               type = 'real',
               value = 2.4952,
               texname = '\\text{WZ}',
               lhablock = 'DECAY',
               lhacode = [ 23 ])

WW = Parameter(name = 'WW',
               nature = 'external',
               type = 'real',
               value = 2.085,
               texname = '\\text{WW}',
               lhablock = 'DECAY',
               lhacode = [ 24 ])

WX = Parameter(name = 'WX',
               nature = 'external',
               type = 'real',
               value = 1.,
               texname = '\\text{WX}',
               lhablock = 'DECAY',
               lhacode = [ 9000001 ])

WT = Parameter(name = 'WT',
               nature = 'external',
               type = 'real',
               value = 1.50833649,
               texname = '\\text{WT}',
               lhablock = 'DECAY',
               lhacode = [ 6 ])

WH = Parameter(name = 'WH',
               nature = 'external',
               type = 'real',
               value = 0.00407,
               texname = '\\text{WH}',
               lhablock = 'DECAY',
               lhacode = [ 25 ])

aEW = Parameter(name = 'aEW',
                nature = 'internal',
                type = 'real',
                value = '1/aEWM1',
                texname = '\\text{aEW}')

MZhat = Parameter(name = 'MZhat',
                  nature = 'internal',
                  type = 'real',
                  value = 'MZ',
                  texname = '\\text{MZhat}')

MXX2 = Parameter(name = 'MXX2',
                 nature = 'internal',
                 type = 'real',
                 value = 'MXX**2',
                 texname = '\\text{MXX2}')

G = Parameter(name = 'G',
              nature = 'internal',
              type = 'real',
              value = '2*cmath.sqrt(aS)*cmath.sqrt(cmath.pi)',
              texname = 'G')

vev = Parameter(name = 'vev',
                nature = 'internal',
                type = 'real',
                value = 'cmath.sqrt(1/GFhat)/2**0.25',
                texname = '\\text{vev}')

YL = Parameter(name = 'YL',
               nature = 'internal',
               type = 'real',
               value = '-0.5',
               texname = '\\text{YL}')

YQ = Parameter(name = 'YQ',
               nature = 'internal',
               type = 'real',
               value = '0.16666666666666666',
               texname = '\\text{YQ}')

Ye = Parameter(name = 'Ye',
               nature = 'internal',
               type = 'real',
               value = '-1',
               texname = '\\text{Ye}')

Yd = Parameter(name = 'Yd',
               nature = 'internal',
               type = 'real',
               value = '-0.3333333333333333',
               texname = '\\text{Yd}')

Yu = Parameter(name = 'Yu',
               nature = 'internal',
               type = 'real',
               value = '0.6666666666666666',
               texname = '\\text{Yu}')

CKM1x1 = Parameter(name = 'CKM1x1',
                   nature = 'internal',
                   type = 'complex',
                   value = 'cmath.cos(cabi)',
                   texname = '\\text{CKM1x1}')

CKM1x2 = Parameter(name = 'CKM1x2',
                   nature = 'internal',
                   type = 'complex',
                   value = 'cmath.sin(cabi)',
                   texname = '\\text{CKM1x2}')

CKM1x3 = Parameter(name = 'CKM1x3',
                   nature = 'internal',
                   type = 'complex',
                   value = '0',
                   texname = '\\text{CKM1x3}')

CKM2x1 = Parameter(name = 'CKM2x1',
                   nature = 'internal',
                   type = 'complex',
                   value = '-cmath.sin(cabi)',
                   texname = '\\text{CKM2x1}')

CKM2x2 = Parameter(name = 'CKM2x2',
                   nature = 'internal',
                   type = 'complex',
                   value = 'cmath.cos(cabi)',
                   texname = '\\text{CKM2x2}')

CKM2x3 = Parameter(name = 'CKM2x3',
                   nature = 'internal',
                   type = 'complex',
                   value = '0',
                   texname = '\\text{CKM2x3}')

CKM3x1 = Parameter(name = 'CKM3x1',
                   nature = 'internal',
                   type = 'complex',
                   value = '0',
                   texname = '\\text{CKM3x1}')

CKM3x2 = Parameter(name = 'CKM3x2',
                   nature = 'internal',
                   type = 'complex',
                   value = '0',
                   texname = '\\text{CKM3x2}')

CKM3x3 = Parameter(name = 'CKM3x3',
                   nature = 'internal',
                   type = 'complex',
                   value = '1',
                   texname = '\\text{CKM3x3}')

eehat = Parameter(name = 'eehat',
                  nature = 'internal',
                  type = 'real',
                  value = '2*cmath.sqrt(aEW)*cmath.sqrt(cmath.pi)',
                  texname = '\\text{eehat}')

lam = Parameter(name = 'lam',
                nature = 'internal',
                type = 'real',
                value = 'MH**2/(2.*vev**2)',
                texname = '\\text{lam}')

yb = Parameter(name = 'yb',
               nature = 'internal',
               type = 'real',
               value = '(ymb*cmath.sqrt(2))/vev',
               texname = '\\text{yb}')

yc = Parameter(name = 'yc',
               nature = 'internal',
               type = 'real',
               value = '(ymc*cmath.sqrt(2))/vev',
               texname = '\\text{yc}')

ydo = Parameter(name = 'ydo',
                nature = 'internal',
                type = 'real',
                value = '(ymdo*cmath.sqrt(2))/vev',
                texname = '\\text{ydo}')

ye = Parameter(name = 'ye',
               nature = 'internal',
               type = 'real',
               value = '(yme*cmath.sqrt(2))/vev',
               texname = '\\text{ye}')

ym = Parameter(name = 'ym',
               nature = 'internal',
               type = 'real',
               value = '(ymm*cmath.sqrt(2))/vev',
               texname = '\\text{ym}')

ys = Parameter(name = 'ys',
               nature = 'internal',
               type = 'real',
               value = '(yms*cmath.sqrt(2))/vev',
               texname = '\\text{ys}')

yt = Parameter(name = 'yt',
               nature = 'internal',
               type = 'real',
               value = '(ymt*cmath.sqrt(2))/vev',
               texname = '\\text{yt}')

ytau = Parameter(name = 'ytau',
                 nature = 'internal',
                 type = 'real',
                 value = '(ymtau*cmath.sqrt(2))/vev',
                 texname = '\\text{ytau}')

yup = Parameter(name = 'yup',
                nature = 'internal',
                type = 'real',
                value = '(ymup*cmath.sqrt(2))/vev',
                texname = '\\text{yup}')

muH = Parameter(name = 'muH',
                nature = 'internal',
                type = 'real',
                value = 'cmath.sqrt(lam*vev**2)',
                texname = '\\text{muH}')

swhat = Parameter(name = 'swhat',
                  nature = 'internal',
                  type = 'real',
                  value = 'cmath.sqrt(1 - cmath.sqrt(1 - eehat**2/(GFhat*MZhat**2*cmath.sqrt(2))))/cmath.sqrt(2)',
                  texname = '\\text{swhat}')

cwhat = Parameter(name = 'cwhat',
                  nature = 'internal',
                  type = 'real',
                  value = 'cmath.sqrt(1 - swhat**2)',
                  texname = '\\text{cwhat}')

g1 = Parameter(name = 'g1',
               nature = 'internal',
               type = 'real',
               value = 'eehat/cwhat - (beta**2*eehat**3*swhat**2*vev**2)/(8*cwhat**7*MXX2 - 8*cwhat**3*MXX2*swhat**4) + (beta**2*eehat**5*(-32*(1 + cwhat**4 - 6*cwhat**2*swhat**2 + swhat**4) + beta**2*(-8 + cwhat**6 - 23*swhat**2 - 16*swhat**4 - swhat**6 - cwhat**4*(16 + 15*swhat**2) + cwhat**2*(23 + 96*swhat**2 + 15*swhat**4)))*vev**4)/(2048.*cwhat**5*MXX2**2*(cwhat**2 - swhat**2)**3)',
               texname = '\\text{g1}')

gw = Parameter(name = 'gw',
               nature = 'internal',
               type = 'real',
               value = 'eehat/swhat + (beta**2*eehat**3*vev**2)/(8*cwhat**4*MXX2*swhat - 8*MXX2*swhat**5) + (beta**2*eehat**5*(32*(1 + cwhat**4 - 6*cwhat**2*swhat**2 + swhat**4) + beta**2*(-4 - cwhat**6 - swhat**2 + 4*swhat**4 + swhat**6 + cwhat**4*(4 + 15*swhat**2) + cwhat**2*(1 - 24*swhat**2 - 15*swhat**4)))*vev**4)/(2048.*cwhat**2*MXX2**2*swhat**3*(cwhat**2 - swhat**2)**3)',
               texname = '\\text{gw}')

cc = Parameter(name = 'cc',
               nature = 'internal',
               type = 'real',
               value = '1/(cmath.sqrt(2)*cmath.sqrt(cmath.sqrt((4*MXX**2 + beta**2*g1**2*vev**2)**2/16. + (beta**2*g1**2*vev**4*(g1**2/cmath.sqrt(g1**2 + gw**2) + gw**2/cmath.sqrt(g1**2 + gw**2))**2)/4. - (vev**2*(4*MXX**2 + beta**2*g1**2*vev**2)*(g1**2/cmath.sqrt(g1**2 + gw**2) + gw**2/cmath.sqrt(g1**2 + gw**2))**2)/8. + (vev**4*(g1**2/cmath.sqrt(g1**2 + gw**2) + gw**2/cmath.sqrt(g1**2 + gw**2))**4)/16.)/((4*MXX**2 + beta**2*g1**2*vev**2)/4. - (vev**2*(g1**2/cmath.sqrt(g1**2 + gw**2) + gw**2/cmath.sqrt(g1**2 + gw**2))**2)/4. + cmath.sqrt((4*MXX**2 + beta**2*g1**2*vev**2)**2/16. + (beta**2*g1**2*vev**4*(g1**2/cmath.sqrt(g1**2 + gw**2) + gw**2/cmath.sqrt(g1**2 + gw**2))**2)/4. - (vev**2*(4*MXX**2 + beta**2*g1**2*vev**2)*(g1**2/cmath.sqrt(g1**2 + gw**2) + gw**2/cmath.sqrt(g1**2 + gw**2))**2)/8. + (vev**4*(g1**2/cmath.sqrt(g1**2 + gw**2) + gw**2/cmath.sqrt(g1**2 + gw**2))**4)/16.))))',
               texname = '\\text{cc}')

cw = Parameter(name = 'cw',
               nature = 'internal',
               type = 'real',
               value = 'gw/cmath.sqrt(g1**2 + gw**2)',
               texname = '\\text{cw}')

MW = Parameter(name = 'MW',
               nature = 'internal',
               type = 'real',
               value = '(gw*vev)/2.',
               texname = '\\text{MW}')

MX = Parameter(name = 'MX',
               nature = 'internal',
               type = 'real',
               value = 'cmath.sqrt(((4*MXX2 + beta**2*g1**2*vev**2)*(4*MXX2 - g1**2*vev**2 + beta**2*g1**2*vev**2 - gw**2*vev**2 + cmath.sqrt(16*MXX2**2 + 8*((-1 + beta**2)*g1**2 - gw**2)*MXX2*vev**2 + ((1 + beta**2)*g1**2 + gw**2)**2*vev**4)))/cmath.sqrt(16*MXX2**2 + 8*((-1 + beta**2)*g1**2 - gw**2)*MXX2*vev**2 + ((1 + beta**2)*g1**2 + gw**2)**2*vev**4) + ((g1**2 + gw**2)*vev**2*(-4*MXX2 + g1**2*vev**2 - beta**2*g1**2*vev**2 + gw**2*vev**2 + cmath.sqrt(16*MXX2**2 + 8*((-1 + beta**2)*g1**2 - gw**2)*MXX2*vev**2 + ((1 + beta**2)*g1**2 + gw**2)**2*vev**4)))/cmath.sqrt(16*MXX2**2 + 8*((-1 + beta**2)*g1**2 - gw**2)*MXX2*vev**2 + ((1 + beta**2)*g1**2 + gw**2)**2*vev**4) + (2*beta*g1*vev**2*cmath.sqrt(((g1**2 + gw**2)*(-4*MXX2 + g1**2*vev**2 - beta**2*g1**2*vev**2 + gw**2*vev**2 + cmath.sqrt(16*MXX2**2 + 8*((-1 + beta**2)*g1**2 - gw**2)*MXX2*vev**2 + ((1 + beta**2)*g1**2 + gw**2)**2*vev**4)))/cmath.sqrt(16*MXX2**2 + 8*((-1 + beta**2)*g1**2 - gw**2)*MXX2*vev**2 + ((1 + beta**2)*g1**2 + gw**2)**2*vev**4)))/cmath.sqrt(cmath.sqrt(16*MXX2**2 + 8*((-1 + beta**2)*g1**2 - gw**2)*MXX2*vev**2 + ((1 + beta**2)*g1**2 + gw**2)**2*vev**4)/(4*MXX2 - g1**2*vev**2 + beta**2*g1**2*vev**2 - gw**2*vev**2 + cmath.sqrt(16*MXX2**2 + 8*((-1 + beta**2)*g1**2 - gw**2)*MXX2*vev**2 + ((1 + beta**2)*g1**2 + gw**2)**2*vev**4))))/(2.*cmath.sqrt(2))',
               texname = '\\text{MX}')

sw = Parameter(name = 'sw',
               nature = 'internal',
               type = 'real',
               value = 'g1/cmath.sqrt(g1**2 + gw**2)',
               texname = '\\text{sw}')

ss = Parameter(name = 'ss',
               nature = 'internal',
               type = 'real',
               value = 'cmath.sqrt(1 - cc**2)',
               texname = '\\text{ss}')

