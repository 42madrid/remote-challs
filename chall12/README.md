<h1 align="center"><code>AB Aurigae (Chall12) / Reverse Parenthesis</code></h1>

<div align="center">
  <sub>Created by <a href="https://github.com/abguimba">Abraham Guimbao (lincoln)</a>, <a href="https://github.com/vesta-nna">Anna Dominguez (analogia)</a>, <a href="https://github.com/clafoutis42">Charles Labourier (pistache)</a></sub>
</div>
<div align="center">
  <sub>From <a href="https://42madrid.com">42 Madrid</a> for all the 42 Network</sub>
</div>

---

### Instructions
<sub>**Turn-in directory:** `chall12/`</sub><br />
<sub>**Files to turn in:** `<xlogin>.c`</sub><br />
<sub>**Language:** `C`</sub><br />
<sub>**Prototype:** `char *ft_reverse_parenthesis(const char *str);`</sub><br />

<sub>**Deadline:** 26.05.2020 - 11:42am</sub>
<br /><br />

### Subject

<p align="center">
  <img src="https://i.imgur.com/UbydyDP.gif">
  <img src="https://i.imgur.com/N6anjEZ.gif">
</p>
<br></br>

You will be given a string of text and valid parentheses, such as "h(el)lo".
You must return the string, with only the text inside parentheses reversed, so "h(el)lo" becomes "h(le)lo".

However, if said parenthesized text contains parenthesized text itself, then that too must reversed back, so it faces the original direction.

When parentheses are reversed, they should switch directions, so they remain syntactically correct (i.e. "h((el)l)o" becomes "h(l(el))o").
This pattern should repeat for however many layers of parentheses.

If the input is invalid, return `NULL`.

> NOTE: There may be multiple groups of parentheses at any level (i.e. "(1) (2 (3) (4(5)))"), so be sure to account for these.

### Examples
For:
```C
const char *str = "one (ruof ((rht)ee) owt)"
```
You should return:
```C
"one (two ((thr)ee) four)"
```

<br></br>
For:
```C
const char *str = "one two three four"
```
You should return:
```C
"one two three four"
```

<br></br>
For:
```C
const char *str = "one (ruof (((rht)ee) owt)"
```
You should return:
```C
NULL
```

<br></br>
For:
```C
const char *str = "p(C(KFF(a(Pq(Nd(DsM(zdv(K(rQGHS)KlP(kvtwk)vsC)prd(ih(cemIM)kn(tjQzB)tB(zXgFd)MEK)s(XwMUM)S)s(StM(tugkZ)jhY(BvkyG)uIS(SvUfa)VS(MVMXH)YZA(jsCsC)C)Op(HnieZ)QTt)YOs(GwE(sdF(Oak(rwdYv)RqH(HuoEf)ocS(Nhraf)Z(rbdPm)j(bKqPu)j)V)eK(AhQ(jMTIG)Y(jZfII)YZ)i(kBk(veurK)w)o(OpLrV)VB)wxF(NL(dClFq)DhW(jYlVQ)Fk(WjjXe)YH)bgY(cOuwa)LH(gT(DepcD)zW(NLUsz)ig)le)Dw)ogF(RUA(ON(oCT(E(uhpST)izL)u(lyF(zRKVR)bwi(Uyziu)AYi(jFcpt)H(gutND)W)b(Xnaky)zc(JnxLj)Zfc(dh(WzwNO)Kxz)cau)fod(cUeZL)ukp(V(yKUbk)RZ(kXXOf)jh(WEKpZ)hc(Efopr)RQ)p(GXDXT)zo)xdR(aNL(Y(vK(BvjFj)Oh(DNayy)t)Px)XI(Zz(h(ivVEg)O)se)B(odt(mFLGk)lpa(jegAF)su)iGt(nv(Eiphk)dVz(dmQes)FN(jjKde)Ey(Ocedr)F(Aknwz)iM)tN)tfV(EuN(M(XQU(KBtKr)kqY)w(ZFvNP)R(RKy(DbsRL)x(riZaR)Ru(fUVus)sj(XJsuG)c(unUVW)aN)Gj(ujTTe)mbB(Gwt(UvguJ)Vii(UpxNi)m(jlJeS)Cy(rBRGd)p(ndJSD)n)KU)JCV(F(qzT(iYIZM)LJ(RmuyN)a)dC)qzy(ilXdq)RM)vNJ)gEP)hdr(OARJl)CMw)Cs(G(dX(jC(L(gxy(gMl(MdBJQ)g(CeNLZ)Ki(aUldD)J(arUJY)Czf)t(lXXJD)Rij(LRKUQ)X(yVfoj)ax)N(Sv(oDDkZ)z)lu(Bm(wTTdo)CK(IJNnb)bcb(cmwPK)Z)Cp)hoo)hnP(jXsqo)rPd(wU(bFB(lzk(narjL)fg)MM(BNeri)s)K(sBDrc)w(YEdqC)N)vp)uy(Iu(geJ(sQTcA)S(PONGe)K(TWCsE)jdp)oTi)Kq)LrW)yPU(DeqPR)c(RG(b(IQe(L(YxeZY)p(mzLNp)q(UqMIj)uS)qb(fn(WSYzA)et(cdFYD)DkE)oUJ)g(b(Ibu(dhbEE)UDq(jISmF)v(nvTeY)v(EUXjD)WfN)h(Qxo(WUmFw)hvy)jtF(Epozm)jG)bgf(p(iEtYh)kTI)ENS(xMlaC)qQE(I(i(MaeZO)NZ(DUIEZ)xm(GMwvR)nyT(VLxol)t(WeYvk)QhR)ijL(cOhgM)f(dyCjY)SCH(UELTZ)ItP(xIv(pkPys)CGB)QKI)l)a)K(qN(R(XT(OIG(Fb(Tz(Gx(TZFch)TML(FfNtn)n)ul(nGtVi)U(Oa(kGcuk)JWy(pZPAo)KX(IDMyJ)sW(ROepV)z(TnMVI)OGs)X)W)iq(k(j(WcMGz)Bc(XCiXf)Jfo(wBxUF)vce(liecR)NSo(duSjQ)Z)W(ESJXY)UNN(fHDpR)H(StZUL)y(Ad(nvxRY)bO(GNntY)V(hltqu)P(ujRtO)Wtf(XxczN)b)l)Z(wLW(mpWLf)ax(fucPK)CAe(ZiDSn)yS(hJhiP)Yf(zpUeD)B)Jk(IM(OnWTA)OM(zzXJC)mk(XMAWb)JY(QvuhR)SS(QXAsy)Cmp)fDd(V(gKqcw)SIl(iBcnU)O(FTFwW)B(Ugffx)D(lLCOH)p)avP)se(gCjZc)oTo(CQ(hfwoD)LB(aVIYe)t(SQhMN)kTp)z(yyX(bHj(FXtSU)q(uXqBB)Jw)JW(MXxLk)gf(eiO(cHzzy)SI(hvAna)I)rZ(VVlaX)Hrb)iR)Sf(ap(F(h(O(vGGcU)dZR(FUZum)V(EfuTv)ect(PzPyA)CQQ(bFvfd)E)YFv(DvhKF)Tq(ZFe(SessB)JCg(wkhZR)RXZ(pqLer)zsA(iDItZ)Ge(nOxrT)I)D)iBe(gp(K(WJdpq)lBv(KCzuH)Ari(kCqVC)dK(sFifC)l)Pz(bGKiH)ItT(EqoNb)gWI)fe)r(D(a(NlLJQ)uo)yCb(YE(ERoIE)kQa(cpZoy)zLD(inZDW)l(SekIR)j)VhV(sfVMQ)p(D(AmOLe)qP(DlynI)N(SwqWc)bLJ(IPANN)V(hPQLq)nGu)MHv(g(CgwMA)gdR(ARUDg)am)rOY)CY(x(qqL(jdnPX)N(DAdJI)Yo(BxtJG)tfY(sEaEv)ZNG)N(KVAhg)X(BuPYS)ZP(p(VffRU)K(vgPFW)IZ)vY(HcdGd)Gp)NTA)F(uTxRb)unL(hcG(O(xo(sSiqN)mDZ(qIuvx)J(LhjVz)Xf)OzU(VmfUh)bLv(WHjXC)rwE(P(VhORM)ab)v(trliP)p)dIt(J(AB(HMOFz)MQe(bOMvx)ow)g(Tl(EoxSG)DO(KlvSY)lK(OokCI)du)hQQ(nN(BbLyX)bqh(wQaGf)G(xcXfu)Bj)Lz(k(gIHdW)lj(QRCwE)ot)h(H(RKBvP)AN(RuHBK)Tqa(bJeSU)N)U)eC(f(gPeNj)YlD(XvlrB)Krj(DZZfS)W(LUYLO)DI(aEWOA)bh)j(IPXTv)sg)aaG(ijX(Lai(gjR(fUh(KwlOo)J(PUvmK)sT(WGKtp)UGJ(SVFNg)lg(BTRnD)EJR)En(CTEJJ)OK)Ee)Rk(Cv(Asj(DoWbS)btO(drcMX)suT(fBGxH)iy(Fwqfx)YDh(GTJJc)y)f)Ndm(G(Tf(n(zsnnc)h)LdO(oGMYc)Er(GIqLO)WI(KJFln)c(zPhrq)v)Cl(lMB(xYG(bAVod)HV)P(Rd(ZpOce)XS(gNcCk)Df(bVuIc)uR(BHkrg)x)hOT(ZkTuZ)Nw(an(ADRBj)Xw(IDfYy)z)GS(pTWun)m)wL)oF(KLNFg)p(DShjh)SDz)GO)Xu(fra(Md(OmIHV)D(GLiUT)Jle(vxPKy)eM(GzriV)O)GY(unY(efjVU)fuo(yKupd)F)OXV)La(dmh(HC(a(xxC(QCP(mL(LGTfq)Mmc(OOvla)h(rOAsd)d)b(LALxO)E(m(WBqji)a(jlTXQ)bm(LVYhI)Yrz(gdNIu)zUp(NotjM)zlv)vUu)oJi(q(CUZPu)Xa(eTSOL)EPV(lgqcU)j(WvFyk)pj(zZUqd)HLb)v(VgdGV)RfT(k(odO(SfRbU)eV(iLByG)wa(fZcsO)zZY(FJRxE)ri)Gi(zirgS)rU(zDcKx)XU(hr(BotaI)v)Izu)npa)cVb(Sv(fS(FL(HfOti)pbk(yAJlE)ma(uTWom)Wk)a)AkY(WHgUc)aX)uz(Nd(m(KjDrk)l)VBz(Ye(gNZhJ)Eu(VlaSZ)XR(glqak)Px(PFGHY)Tnd)Olm(Ziamr)p(MOPFh)V)DeM(S(k(bd(gRkjL)Uwc(SdrSH)t(olrwq)M(INrlV)Lin(JTfer)ffU)Aq)c(z(yEqCJ)okK(IKcFE)F(UCiXU)OK)yib(U(loS(aDlRG)KS(ntCTs)g(TskXm)FF)boZ)F(wErfY)t(LyunE)r)LJ)Hca(vle(l(t(CJDgN)N(FNcrY)f(tSUUu)c(WxfrD)IT)h(cq(ZnSLC)Jx)y(HUKFA)IiP)TU(NK(kqKcf)ql)ytK(vEB(I(AUWPQ)Wb(YEiPn)VHi(JBhVH)RZ(GHOvJ)M(qLghZ)Da)e(VDsVL)dj(tg(uUVUj)O)Llm(bYE(EaTLo)q(sSLZQ)CmD)Sqv)XuJ)c(SHqqJ)P(ox(m(o(BE(nYoYw)Lkc(IrXlf)gAt(UJGdV)ka(EZFGz)s(NbkrD)tDZ)hZj)c(Y(Mywaf)Ks(WsYiI)D(SjKRo)Ka)zH(PL(P(elEGx)Bj(AfqKm)s(zzUzB)HrY(kKlYS)p)G(dvkOk)ITm)fA(KK(LDwMp)H(gnZmK)NPX(ANNJD)dC)e)K(Vn(UKa(LtpiQ)Aj(TyAtA)QjU)f)vwq(R(xIdaT)Gik(gkKYb)U)d)ISO)B(z(eyZ(ahfES)W(vdUzs)pYH(pvtQS)UT(QfRiN)M)vX(UGoid)h(c(lQSCM)VA(nfGeT)Rb(lGojr)p)XWi(sS(kpImf)Rk(GQuTA)NP)u(dihgJ)m)XLa(lbc(x(zz(E(V(Tdjxv)u)zb)GHT(AqiVq)HvO(z(G(HueFT)wP)Q(JBllG)XkA(oga(cOfXb)IzD(HSZET)zD(PiQqG)PP)ge(zUqpb)jmW)LWS)eVj(I(LcTDD)FO(JmDfk)E(EeqXB)A(eNera)kA(wpskY)By)IJG(ZV(PxT(nmkIj)wbB(STQWG)m)q(CKDKS)w(uS(Mqnpi)gm(qchGw)bdc(UbDXL)vJd(mVySB)x(lmiMI)VS)E(euoYM)CU(dkzYR)LIE)f)fpe)Z(aoG(RVz(fDY(aR(yVD(sDbhv)Mvs(MqlTQ)BoJ(RBRfQ)bu(wIGqB)tqC(NmpLB)fJ)wof(qRuKu)Dr(A(sEhJh)h(RYVln)m(leWNb)y(AlgRE)UdA)VSs(cUKvX)vZ(wwGQQ)TQk)uVj)NnV)ng(xS(IqUoU)LTP(htcYa)Df(JKYfa)vZ(ZNxPT)f)aI(Kf(FUD(e(a(HPpNS)H(BscNI)a(WfoGx)RT(zZNvn)tzU(OCdqY)Az)YwP(ZSvcj)MGX(I(nhkFW)Ib(dMWDq)x)Vr(eIiyA)O)y)h(mEV(waVgJ)w(RhXrK)gLT)Spa(BCCzK)SKi(E(NFv(LhZIV)Xm(VOhrr)b(EGWIG)Zh(HKVIB)v)kR(Vqmuq)eQN(XXXly)Q(LBl(KbcrA)kN(vYGKp)JT)BvZ(HcO(GHDbd)Hn(PzILr)A(XSqNg)hlh)lIK)O)cHp(dw(Yxe(dhzod)J(ihRLP)U(MSBtg)mlG(Brtxy)iK)prT(tFBhQ)dFu)ND(f(V(vqJ(N(drzLH)Ie(NzFpw)C(yldUi)WIz(OwHTQ)lY)MD(mMF(aUvES)BNs(dPfAm)jHf(IaEEb)hay(qcziX)F(CYqqS)Lx)qp(SRrkO)I)DM(yb(BR(pMsbZ)Xn(xqklv)wU(BLWnI)AWS(ZMWIE)uAT(qyofQ)Vj)GRG)H)pdF(dpvKl)R)bl)Q(UAwLQ)YB)Y(pN(Jj(Nk(O(j(IY(QSruf)EFD(mcpNa)EM(nBELU)r(CZaEm)Ze(rWZnC)G)G(Xqebk)Qvu)MlA)Zq(PF(IG(pu(bXVVn)ket(QcMrH)QY)xR(iAlLC)w)Bq(VvlCX)WzC(T(ko(IqSmi)L)LJ)F)iC)Y(H(pD(IgCNm)myI)d(fBlTA)lU)IW)y)i(b(OkW(RA(Ye(Ze(DMcZY)l(bhmKj)hZs)W(EXYEY)Cw)Fu(Ph(IuFRz)Tki(lptEx)y)ug(qBe(G(ilkWn)Tx)Oal(NCg(CNJZw)oh(FOzOo)zk(bfaOF)DfN(OOtqf)N(TpEfO)r)mpC)wLM)G(Cz(Y(rRocg)M(aMpDo)gX(quiyP)dMP)iMj(V(ZpTjr)y(kUTxM)Xl(vRRGy)AQb)F)hJS(A(HaDes)N(QwkVE)AU(bFETG)uzZ(sxXna)Vn(UoUSg)YWP)bQ(y(z(NVrZe)Q(vMVVr)he(SyXXR)tCf(dfEwW)ZC(aoaac)Q)R(XIThP)LwN(jfjJU)PxY(JEXZU)K)r)GG(C(i(qF(TIrlR)tjL(vCCdk)e(gDECh)o(WTfkD)MK)wjg(EOorT)IG(PNdai)QF)XJ)rL(Q(n(cjRDw)eO(uRkuX)Y)gTs(jhkqA)AZb)eUT(MYZ(k(r(f(yzDXo)KDr(ZomrZ)yOF(JsiBQ)o(XhmDu)E)g(Tmwvz)ow(f(kOcKR)cq(eivfP)CE(lNTxF)qk(dcfzp)yQr)sk(U(MTRbw)xWv(GBmJP)dvv(UOJor)bdE)d)Llw)Mk(znD(Z(WB(eguXH)xu(uSJYD)bh(aUWQG)ti)wYF(cyYnM)yKT)TU)E(iaP(NaIHI)d(Dfijj)S(iRFwW)Bn(jgHHq)Jyz)WDc(A(K(RNkGr)Py(QyrMz)pPB(DFVXR)P(GUvId)oEd(vpOBr)U)Diu(XjUJz)BT(WjyKj)aaM(SYATb)fD(SH(ZglDB)oi(fWbrW)F)O)j(dwU(at(yZkLD)H)JFs(paTUV)Z(WRGqF)Xmt(SOvTi)M)DxJ)ua)pq)R"
```
You should return:
```C
"p(WrL(G(pv(wU(s(BNeri)MM(lzk(Ljran)fg)BFb)K(crDBs)w(CqdEY)N)dPr(jXsqo)Pnh(jC(pC(Bm(odTTw)CK(bnNJI)bcb(KPwmc)Z)ul(Sv(ZkDDo)z)N(gxy(fzC(arUJY)J(aUldD)iK(CeNLZ)g(MdBJQ)lMg)t(DJXXl)Rij(QUKRL)X(jofVy)ax)L)hoo)Xd)uy(iTo(geJ(AcTQs)S(eGNOP)K(EsCWT)jdp)uI)Kq)sC(KFF(PEg(RUA(oz(GXDXT)p(V(kbUKy)RZ(fOXXk)jh(ZpKEW)hc(rpofE)RQ)pku(cUeZL)dof(oCT(Lzi(uhpST)E)u(W(gutND)H(jFcpt)iYA(Uyziu)iwb(zRKVR)Fyl)b(ykanX)zc(jLxnJ)Zfc(zxK(WzwNO)hd)cau)NO)xdR(Nt(nv(khpiE)dVz(seQmd)FN(edKjj)Ey(rdecO)F(zwnkA)iM)tGi(odt(kGLFm)lpa(FAgej)su)B(Zz(O(ivVEg)h)se)IX(Y(t(DNayy)hO(BvjFj)Kv)Px)LNa)tfV(MR(ilXdq)yzq(F(a(RmuyN)JL(iYIZM)Tzq)dC)VCJ(M(Yqk(KBtKr)UQX)w(PNvFZ)R(Na(unUVW)c(XJsuG)js(fUVus)uR(riZaR)x(DbsRL)yKR)Gj(eTTju)mbB(n(ndJSD)p(rBRGd)yC(jlJeS)m(UpxNi)iiV(UvguJ)twG)KU)NuE)vNJ)Fgo(Pq(el(gT(DcpeD)zW(zsULN)ig)HL(cOuwa)Ygb(NL(qFlCd)DhW(QVlYj)Fk(eXjjW)YH)Fxw(GwE(V(Oak(vYdwr)RqH(fEouH)ocS(farhN)Z(mPdbr)j(uPqKb)j)Fds)eK(ZY(jZfII)Y(jMTIG)QhA)i(w(veurK)kBk)o(VrLpO)VB)sOY(DsM(S(XwMUM)s(ih(MImec)kn(BzQjt)tB(dFgXz)MEK)drp(K(SHGQr)KlP(kwtvk)vsC)vdz)s(C(jsCsC)AZY(MVMXH)SV(SvUfa)SIu(BvkyG)Yhj(tugkZ)MtS)Op(ZeinH)QTt)dN)Dw)a)hdr(lJRAO)CMw)C)yPU(RPqeD)c(a(b(JUo(fn(AzYSW)et(DYFdc)DkE)bq(L(YZexY)p(pNLzm)q(jIMqU)uS)eQI)g(Gj(Epozm)Ftj(Qxo(wFmUW)hvy)h(Ibu(EEbhd)UDq(FmSIj)v(YeTvn)v(DjXUE)WfN)b)bgf(ITk(iEtYh)p)ENS(CalMx)qQE(IKQ(xIv(syPkp)CGB)PtI(UELTZ)HCS(dyCjY)f(cOhgM)Lji(i(OZeaM)NZ(ZEIUD)xm(RvwMG)nyT(loxLV)t(kvYeW)QhR)I)l)GR)K(qp(b(r(y(Q(aoaac)CZ(dfEwW)fCt(SyXXR)eh(vMVVr)Q(NVrZe)z)R(PhTIX)LwN(UJjfj)PxY(UZXEJ)K)Qb(A(seDaH)N(EVkwQ)AU(GTEFb)uzZ(anXxs)Vn(gSUoU)YWP)SJh(Cz(PMd(quiyP)Xg(aMpDo)M(rRocg)Y)iMj(bQA(vRRGy)lX(kUTxM)y(ZpTjr)V)F)G(RA(wC(EXYEY)W(Ze(YZcMD)l(jKmhb)hZs)eY)Fu(y(lptEx)ikT(IuFRz)hP)ug(Cpm(NCg(wZJNC)oh(oOzOF)zk(FOafb)DfN(fqtOO)N(OfEpT)r)laO(G(nWkli)Tx)eBq)wLM)WkO)GG(JX(i(KM(WTfkD)o(gDECh)e(vCCdk)Ljt(TIrlR)Fq)wjg(TroOE)IG(iadNP)QF)C)rL(bZA(jhkqA)sTg(n(wDRjc)eO(XukRu)Y)Q)eUT(JxD(dwU(H(yZkLD)ta)JFs(VUTap)Z(FqGRW)Xmt(iTvOS)M)j(A(U(vpOBr)dEo(GUvId)P(DFVXR)BPp(QyrMz)yP(RNkGr)K)Diu(zJUjX)BT(jKyjW)aaM(bTAYS)fD(F(fWbrW)io(ZglDB)HS)O)cDW(iaP(IHIaN)d(jjifD)S(WwFRi)Bn(qHHgj)Jyz)E(znD(TKy(cyYnM)FYw(WB(HXuge)xu(DYJSu)bh(GQWUa)ti)Z)TU)kM(k(d(U(wbRTM)xWv(PJmBG)dvv(roJOU)bdE)ks(f(RKcOk)cq(Pfvie)CE(FxTNl)qk(pzfcd)yQr)wo(Tmwvz)g(f(oXDzy)KDr(ZrmoZ)yOF(QBisJ)o(uDmhX)E)r)Llw)ZYM)ua)i(pN(WI(H(Iym(IgCNm)Dp)d(ATlBf)lU)Y(Nk(AlM(j(G(rWZnC)eZ(CZaEm)r(nBELU)ME(mcpNa)DFE(QSruf)YI)G(kbeqX)Qvu)O)Zq(F(T(L(IqSmi)ok)LJ)CzW(VvlCX)qB(IG(YQ(QcMrH)tek(bXVVn)up)xR(CLlAi)w)FP)iC)jJ)y)Y(dmh(OSI(ox(e(KK(pMwDL)H(KmZng)NPX(DJNNA)dC)Af(PL(p(kKlYS)YrH(zzUzB)s(AfqKm)jB(elEGx)P)G(kOkvd)ITm)Hz(Y(fawyM)Ks(IiYsW)D(oRKjS)Ka)c(o(ZDt(NbkrD)s(EZFGz)ak(UJGdV)tAg(IrXlf)ckL(nYoYw)EB)hZj)m)K(f(UKa(QiptL)Aj(AtAyT)QjU)nV)vwq(U(gkKYb)kiG(xIdaT)R)d)P(SHqqJ)c(vle(PiI(HUKFA)y(cq(CLSnZ)Jx)h(t(NgDJC)N(YrcNF)f(uUUSt)c(DrfxW)IT)l)TU(lq(kqKcf)KN)ytK(vqS(bYE(oLTaE)q(QZLSs)CmD)mlL(tg(jUVUu)O)jd(VDsVL)e(I(QPWUA)Wb(nPiEY)VHi(HVhBJ)RZ(JvOHG)M(ZhgLq)Da)BEv)XuJ)acH(a(apn(k(ir(FJRxE)YZz(fZcsO)aw(iLByG)Ve(SfRbU)Odo)Gi(Sgriz)rU(xKcDz)XU(v(BotaI)rh)Izu)TfR(VgdGV)v(q(uPZUC)Xa(LOSTe)EPV(Ucqgl)j(kyFvW)pj(dqUZz)HLb)iJo(QCP(d(rOAsd)h(OOvla)cmM(LGTfq)Lm)b(OxLAL)E(vlz(NotjM)pUz(gdNIu)zrY(LVYhI)mb(jlTXQ)a(WBqji)m)vUu)Cxx)cVb(Xa(WHgUc)YkA(fS(kW(uTWom)am(yAJlE)kbp(HfOti)LF)a)vS)uz(V(MOPFh)p(Ziamr)mlO(Ye(JhZNg)Eu(ZSalV)XR(kaqlg)Px(YHGFP)Tnd)zBV(m(krDjK)l)dN)DeM(r(LyunE)t(wErfY)F(U(FF(TskXm)g(ntCTs)SK(aDlRG)Sol)boZ)biy(z(JCqEy)okK(EFcKI)F(UXiCU)OK)c(k(Uff(JTfer)niL(INrlV)M(olrwq)t(SdrSH)cwU(gRkjL)db)Aq)S)LJ)CH)B(m(dihgJ)u(sS(fmIpk)Rk(ATuQG)NP)iWX(c(MCSQl)VA(TeGfn)Rb(rjoGl)p)h(UGoid)Xv(eyZ(SEfha)W(szUdv)pYH(SQtvp)UT(NiRfQ)M)z)XLa(epf(x(SWL(z(Pw(HueFT)G)Q(GllBJ)XkA(PP(PiQqG)Dz(HSZET)DzI(cOfXb)ago)ge(bpqUz)jmW)OvH(AqiVq)THG(E(u(Tdjxv)V)zb)zz)eVj(yB(wpskY)Ak(eNera)A(EeqXB)E(JmDfk)OF(LcTDD)I)IJG(EIL(dkzYR)UC(euoYM)E(uS(ipnqM)gm(wGhcq)bdc(LXDbU)vJd(BSyVm)x(IMiml)VS)w(CKDKS)q(PxT(jIkmn)wbB(GWQTS)m)VZ)f)cbl)Z(lb(f(H(yb(jV(qyofQ)TAu(ZMWIE)SWA(BLWnI)Uw(xqklv)nX(pMsbZ)RB)GRG)MD(vqJ(Yl(OwHTQ)zIW(yldUi)C(NzFpw)eI(drzLH)N)MD(xL(CYqqS)F(qcziX)yah(IaEEb)fHj(dPfAm)sNB(aUvES)FMm)qp(OkrRS)I)V)pdF(lKvpd)R)DN(dw(Ki(Brtxy)Glm(MSBtg)U(ihRLP)J(dhzod)exY)prT(QhBFt)dFu)pHc(Kf(y(e(zA(OCdqY)Uzt(zZNvn)TR(WfoGx)a(BscNI)H(HPpNS)a)YwP(jcvSZ)MGX(x(dMWDq)bI(nhkFW)I)Vr(AyiIe)O)DUF)h(TLg(RhXrK)w(waVgJ)VEm)Spa(KzCCB)SKi(KIl(HcO(dbDHG)Hn(rLIzP)A(gNqSX)hlh)ZvB(LBl(ArcbK)kN(pKGYv)JT)Q(XXXly)NQe(Vqmuq)Rk(NFv(VIZhL)Xm(rrhOV)b(GIWGE)Zh(BIVKH)v)E)O)Ia(xS(UoUqI)LTP(aYcth)Df(afYKJ)vZ(TPxNZ)f)gn(RVz(jVu(aR(Jf(NmpLB)Cqt(wIGqB)ub(RBRfQ)JoB(MqlTQ)svM(sDbhv)DVy)wof(uKuRq)Dr(AdU(AlgRE)y(leWNb)m(RYVln)h(sEhJh)A)VSs(XvKUc)vZ(QQGww)TQk)YDf)NnV)Goa)Q(QLwAU)YB)aL(fra(O(GzriV)Me(vxPKy)elJ(GLiUT)D(OmIHV)dM)GY(F(yKupd)ouf(efjVU)Ynu)OXV)uX(R(Ri(yyX(wJ(uXqBB)q(FXtSU)jHb)JW(kLxXM)gf(I(hvAna)IS(cHzzy)Oie)rZ(XalVV)Hrb)z(CQ(Dowfh)LB(eYIVa)t(NMhQS)kTp)oTo(gCjZc)es(OIG(W(Tz(n(FfNtn)LMT(TZFch)xG)ul(iVtGn)U(sGO(TnMVI)z(ROepV)Ws(IDMyJ)XK(pZPAo)yWJ(kGcuk)aO)X)bF)iq(l(Ad(YRxvn)bO(YtnNG)V(uqtlh)P(OtRju)Wtf(NzcxX)b)y(StZUL)H(fHDpR)NNU(ESJXY)W(j(zGMcW)Bc(fXiCX)Jfo(FUxBw)vce(Rceil)NSo(QjSud)Z)k)Z(B(zpUeD)fY(hJhiP)Sy(ZiDSn)eAC(fucPK)xa(mpWLf)WLw)Jk(pmC(QXAsy)SS(QvuhR)YJ(XMAWb)km(zzXJC)MO(OnWTA)MI)fDd(p(lLCOH)D(Ugffx)B(FTFwW)O(iBcnU)lIS(gKqcw)V)avP)TX)Sf(ATN(x(GNZ(sEaEv)Yft(BxtJG)oY(DAdJI)N(jdnPX)Lqq)N(ghAVK)X(SYPuB)ZP(ZI(vgPFW)K(VffRU)p)vY(dGdcH)Gp)YC(D(ou(NlLJQ)a)yCb(j(SekIR)l(inZDW)DLz(cpZoy)aQk(ERoIE)EY)VhV(QMVfs)p(uGn(hPQLq)V(IPANN)JLb(SwqWc)N(DlynI)Pq(AmOLe)D)MHv(ma(ARUDg)Rdg(CgwMA)g)rOY)r(F(D(ZFe(BsseS)JCg(RZhkw)RXZ(reLqp)zsA(ZtIDi)Ge(TrxOn)I)qT(DvhKF)vFY(O(UcGGv)dZR(muZUF)V(vTufE)ect(AyPzP)CQQ(dfvFb)E)h)iBe(IWg(EqoNb)TtI(bGKiH)zP(K(qpdJW)lBv(HuzCK)Ari(CVqCk)dK(CfiFs)l)pg)fe)pa)F(bRxTu)unL(gs(IPXTv)j(f(jNePg)YlD(BrlvX)Krj(SfZZD)W(OLYUL)DI(AOWEa)bh)Ce(J(wo(bOMvx)eQM(HMOFz)BA)g(ud(OokCI)Kl(KlvSY)OD(EoxSG)lT)hQQ(jB(xcXfu)G(wQaGf)hqb(BbLyX)Nn)Lz(to(QRCwE)jl(gIHdW)k)h(N(bJeSU)aqT(RuHBK)NA(RKBvP)H)U)tId(O(fX(LhjVz)J(qIuvx)ZDm(sSiqN)ox)OzU(hUfmV)bLv(CXjHW)rwE(ba(VhORM)P)v(Pilrt)p)Gch)aaG(zDS(DShjh)p(KLNFg)Fo(G(v(zPhrq)c(KJFln)IW(GIqLO)rE(oGMYc)OdL(n(cnnsz)h)fT)Cl(m(pTWun)SG(an(jBRDA)Xw(yYfDI)z)wN(ZkTuZ)TOh(Rd(ecOpZ)XS(kCcNg)Df(cIuVb)uR(grkHB)x)P(xYG(doVAb)HV)BMl)wL)mdN(Cv(y(GTJJc)hDY(Fwqfx)yi(fBGxH)Tus(drcMX)Otb(DoWbS)jsA)f)kR(Lai(KO(CTEJJ)nE(fUh(oOlwK)J(KmvUP)sT(ptKGW)UGJ(gNFVS)lg(DnRTB)EJR)Rjg)Ee)Xji)GO)Nq)R"
```

### Reward

 - The first one to submit a working solution will earn `420` points for their coalition.
 - Everyone else submitting a working solution *(not yet submitted)* will earn `126` points for their coalition.
 - Every participant that tried to solve the challenge and pushed a solution will earn `84` points for their coalition.

<br></br>
Good luck!
<br />
<sub>About the title: <a href="https://www.xataka.com/espacio/consiguen-capturar-que-probablemente-sea-nacimiento-nuevo-planeta-particular-proceso-que-se-forman">AB Aurigae</a></sub>