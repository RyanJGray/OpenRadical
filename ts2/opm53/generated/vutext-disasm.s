
generated/SLUS_999.99:     file format elf32-littlemips

Disassembly of section .vutext:

0036a6a0 <ucode_loadstart>:
  36a6a0:	00 00 00 00 	vifnop
  36a6a4:	00 00 00 4a 	mpg 0x0,0x100

0036a6a8 <_$START_NORMAL>:
  36a6a8:	bc 06 02 80 d8 ff e0 01 	mulx.xyzw vf31xyzw,vf31xyzw,vf00x 	xtop vi02
  36a6b0:	e1 10 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi02,0xe1
  36a6b8:	01 10 e7 01 ff 02 00 00 	nop 	lq.xyzw vf07xyzw,1(vi02)
  36a6c0:	02 10 e8 01 ff 02 00 00 	nop 	lq.xyzw vf08xyzw,2(vi02)
  36a6c8:	03 10 e9 01 ff 02 00 00 	nop 	lq.xyzw vf09xyzw,3(vi02)
  36a6d0:	04 10 ea 01 ff 02 00 00 	nop 	lq.xyzw vf10xyzw,4(vi02)
  36a6d8:	05 10 eb 01 ff 02 00 00 	nop 	lq.xyzw vf11xyzw,5(vi02)
  36a6e0:	06 10 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,6(vi02)
  36a6e8:	7d 3b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf07xyzw,(vi04++)
  36a6f0:	7d 43 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf08xyzw,(vi04++)
  36a6f8:	7d 4b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf09xyzw,(vi04++)
  36a700:	7d 53 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf10xyzw,(vi04++)
  36a708:	7d 5b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf11xyzw,(vi04++)
  36a710:	7d 63 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf12xyzw,(vi04++)
  36a718:	08 10 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi02,8
  36a720:	00 30 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,0(vi06)
  36a728:	00 10 fd 01 ff 02 00 00 	nop 	lq.xyzw vf29xyzw,0(vi02)
  36a730:	00 10 0b 09 ff 02 00 00 	nop 	ilw.x vi11,0(vi02)x
  36a738:	00 00 00 22 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	fcset 0
  36a740:	fc 63 63 80 bc 08 ec 01 	maddax.xyzw accxyzw,vf01xyzw,vf12x 	mtir vi03,vf12w
  36a748:	ff 07 e1 11 bd 10 ec 01 	madday.xyzw accxyzw,vf02xyzw,vf12y 	iaddiu vi01,vi00,0x7fff
  36a750:	7d eb e4 81 8a 1a ec 01 	maddz.xyzw vf10xyzw,vf03xyzw,vf12z 	sqi.xyzw vf29xyzw,(vi04++)
  36a758:	f4 5a 01 80 ff 02 00 00 	nop 	iand vi11,vi11,vi01
  36a760:	f0 5a 06 80 ff 02 00 00 	nop 	iadd vi11,vi11,vi06
  36a768:	01 30 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,1(vi06)
  36a770:	bc 03 ea 81 ff 51 ca 01 	clipw.xyz vf10xyz,vf10w 	div q,vf00w,vf00x
  36a778:	3c 03 00 80 ea 51 c5 01 	mul.xyz vf07xyz,vf10xyz,vf05xyz 	nop
  36a780:	01 30 06 10 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	iaddiu vi06,vi06,1
  36a788:	47 30 ee 01 bc 08 ec 01 	maddax.xyzw accxyzw,vf01xyzw,vf12x 	lq.xyzw vf14xyzw,71(vi06)
  36a790:	3c 03 00 80 bd 10 ec 01 	madday.xyzw accxyzw,vf02xyzw,vf12y 	nop
  36a798:	fd 1b 3d 80 8a 1a ec 01 	maddz.xyzw vf10xyzw,vf03xyzw,vf12z 	mfir.w vf29w,vi03
  36a7a0:	8f 30 ed 01 3c 30 e0 01 	addax.xyzw accxyzw,vf06xyzw,vf00x 	lq.xyzw vf13xyzw,143(vi06)
  36a7a8:	3c 03 00 80 61 3f e0 01 	maddq.xyzw vf29xyzw,vf07xyzw,q 	nop
  36a7b0:	3c 03 00 80 9c 73 e0 01 	mulq.xyzw vf14xyzw,vf14xyzw,q 	nop

0036a7b8 <_$OLOOP1>:
  36a7b8:	fc 63 63 80 ff 51 ca 01 	clipw.xyz vf10xyz,vf10w 	mtir vi03,vf12w
  36a7c0:	bc 03 ea 81 ea 51 c5 01 	mul.xyz vf07xyz,vf10xyz,vf05xyz 	div q,vf00w,vf00x
  36a7c8:	01 68 e4 03 7d e9 dd 01 	ftoi4.xyz vf29xyz,vf29xyz 	sq.xyzw vf13xyzw,1(vi04)
  36a7d0:	00 70 e4 03 ff 02 00 00 	nop 	sq.xyzw vf14xyzw,0(vi04)
  36a7d8:	01 30 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,1(vi06)
  36a7e0:	01 30 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi06,1
  36a7e8:	02 e8 e4 03 ff 02 00 00 	nop 	sq.xyzw vf29xyzw,2(vi04)
  36a7f0:	ef fb 02 24 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	fcand vi01,0x2fbef
  36a7f8:	47 30 ee 01 bc 08 ec 01 	maddax.xyzw accxyzw,vf01xyzw,vf12x 	lq.xyzw vf14xyzw,71(vi06)
  36a800:	0d 00 01 52 bd 10 ec 01 	madday.xyzw accxyzw,vf02xyzw,vf12y 	ibne vi01,vi00,36a870 <_$OXYZ3>
  36a808:	fd 1b 3d 80 8a 1a ec 01 	maddz.xyzw vf10xyzw,vf03xyzw,vf12z 	mfir.w vf29w,vi03

0036a810 <_$ONEXTV>:
  36a810:	8f 30 ed 01 3c 30 e0 01 	addax.xyzw accxyzw,vf06xyzw,vf00x 	lq.xyzw vf13xyzw,143(vi06)
  36a818:	f3 5f 06 52 61 3f c0 01 	maddq.xyz vf29xyz,vf07xyz,q 	ibne vi06,vi11,36a7b8 <_$OLOOP1>
  36a820:	03 20 04 10 9c 73 e0 01 	mulq.xyzw vf14xyzw,vf14xyzw,q 	iaddiu vi04,vi04,3
  36a828:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36a830:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36a838:	01 68 e4 03 7d e9 dd 01 	ftoi4.xyz vf29xyz,vf29xyz 	sq.xyzw vf13xyzw,1(vi04)
  36a840:	00 70 e4 03 ff 02 00 00 	nop 	sq.xyzw vf14xyzw,0(vi04)
  36a848:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36a850:	e1 10 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi02,0xe1
  36a858:	02 e8 e4 03 ff 02 00 00 	nop 	sq.xyzw vf29xyzw,2(vi04)
  36a860:	fc 1e 00 80 ff 02 00 40 	nop[e] 	xgkick vi03
  36a868:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036a870 <_$OXYZ3>:
  36a870:	f3 1f 00 58 ff 02 00 00 	nop 	ibltz vi03,36a810 <_$ONEXTV>
  36a878:	7d df ff 26 ff 02 00 00 	nop 	fcor vi01,0xffdf7d
  36a880:	25 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36a9b0 <_$OCULL>
  36a888:	be ef ff 26 ff 02 00 00 	nop 	fcor vi01,0xffefbe
  36a890:	23 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36a9b0 <_$OCULL>
  36a898:	df f7 fd 26 ff 02 00 00 	nop 	fcor vi01,0xfdf7df
  36a8a0:	21 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36a9b0 <_$OCULL>
  36a8a8:	ef fb fe 26 ff 02 00 00 	nop 	fcor vi01,0xfefbef
  36a8b0:	1f 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36a9b0 <_$OCULL>
  36a8b8:	f7 7d ff 26 ff 02 00 00 	nop 	fcor vi01,0xff7df7
  36a8c0:	1d 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36a9b0 <_$OCULL>
  36a8c8:	fb be ff 26 ff 02 00 00 	nop 	fcor vi01,0xffbefb
  36a8d0:	1b 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36a9b0 <_$OCULL>
  36a8d8:	62 00 82 0a ff 02 00 00 	nop 	isw.y vi02,98(vi00)y
  36a8e0:	62 00 24 0a ff 02 00 00 	nop 	isw.w vi04,98(vi00)w
  36a8e8:	60 00 4b 0a ff 02 00 00 	nop 	isw.z vi11,96(vi00)z
  36a8f0:	1a 00 0f 42 ff 02 00 00 	nop 	bal vi15,36a9c8 <_$OCLIPPEDPOLY>
  36a8f8:	61 00 86 0a ff 02 00 00 	nop 	isw.y vi06,97(vi00)y
  36a900:	61 00 86 08 ff 02 00 00 	nop 	ilw.y vi06,97(vi00)y
  36a908:	60 00 4b 08 ff 02 00 00 	nop 	ilw.z vi11,96(vi00)z
  36a910:	62 00 24 08 ff 02 00 00 	nop 	ilw.w vi04,98(vi00)w
  36a918:	62 00 82 08 ff 02 00 00 	nop 	ilw.y vi02,98(vi00)y
  36a920:	ff 37 e9 01 ff 02 00 00 	nop 	lq.xyzw vf09xyzw,-1(vi06)
  36a928:	fe 37 e8 01 ff 02 00 00 	nop 	lq.xyzw vf08xyzw,-2(vi06)
  36a930:	00 30 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,0(vi06)
  36a938:	3c 03 00 80 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	nop
  36a940:	3c 03 00 80 bc 08 e9 01 	maddax.xyzw accxyzw,vf01xyzw,vf09x 	nop
  36a948:	3c 03 00 80 bd 10 e9 01 	madday.xyzw accxyzw,vf02xyzw,vf09y 	nop
  36a950:	3c 03 00 80 4a 1a e9 01 	maddz.xyzw vf09xyzw,vf03xyzw,vf09z 	nop
  36a958:	3c 03 00 80 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	nop
  36a960:	3c 03 00 80 bc 08 e8 01 	maddax.xyzw accxyzw,vf01xyzw,vf08x 	nop
  36a968:	3c 03 00 80 bd 10 e8 01 	madday.xyzw accxyzw,vf02xyzw,vf08y 	nop
  36a970:	3c 03 00 80 0a 1a e8 01 	maddz.xyzw vf08xyzw,vf03xyzw,vf08z 	nop
  36a978:	bc 03 e9 81 ea 49 c5 01 	mul.xyz vf07xyz,vf09xyz,vf05xyz 	div q,vf00w,vf00x
  36a980:	3c 03 00 80 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	nop
  36a988:	3c 03 00 80 bc 08 ec 01 	maddax.xyzw accxyzw,vf01xyzw,vf12x 	nop
  36a990:	01 00 01 12 bd 10 ec 01 	madday.xyzw accxyzw,vf02xyzw,vf12y 	isubiu vi01,vi00,1
  36a998:	47 30 ee 01 8a 1a ec 01 	maddz.xyzw vf10xyzw,vf03xyzw,vf12z 	lq.xyzw vf14xyzw,71(vi06)
  36a9a0:	cd 07 00 40 ff 49 c9 01 	clipw.xyz vf09xyz,vf09w 	b 36a810 <_$ONEXTV>
  36a9a8:	fd 0b 3d 80 ff 41 c8 01 	clipw.xyz vf08xyz,vf08w 	mfir.w vf29w,vi01

0036a9b0 <_$OCULL>:
  36a9b0:	01 00 01 12 ff 02 00 00 	nop 	isubiu vi01,vi00,1
  36a9b8:	ca 07 00 40 ff 02 00 00 	nop 	b 36a810 <_$ONEXTV>
  36a9c0:	fd 0b 3d 80 ff 02 00 00 	nop 	mfir.w vf29w,vi01

0036a9c8 <_$OCLIPPEDPOLY>:
  36a9c8:	ff 37 f0 01 ff 02 00 00 	nop 	lq.xyzw vf16xyzw,-1(vi06)
  36a9d0:	fe 37 ef 01 ff 02 00 00 	nop 	lq.xyzw vf15xyzw,-2(vi06)
  36a9d8:	fd 37 ee 01 ff 02 00 00 	nop 	lq.xyzw vf14xyzw,-3(vi06)
  36a9e0:	2b 00 09 10 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	iaddiu vi09,vi00,0x2b
  36a9e8:	3c 03 00 80 bc 08 f0 01 	maddax.xyzw accxyzw,vf01xyzw,vf16x 	nop
  36a9f0:	3c 03 00 80 bd 10 f0 01 	madday.xyzw accxyzw,vf02xyzw,vf16y 	nop
  36a9f8:	3c 03 00 80 0a 1c f0 01 	maddz.xyzw vf16xyzw,vf03xyzw,vf16z 	nop
  36aa00:	3c 03 00 80 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	nop
  36aa08:	3c 03 00 80 bc 08 ef 01 	maddax.xyzw accxyzw,vf01xyzw,vf15x 	nop
  36aa10:	3c 03 00 80 bd 10 ef 01 	madday.xyzw accxyzw,vf02xyzw,vf15y 	nop
  36aa18:	3c 03 00 80 ca 1b ef 01 	maddz.xyzw vf15xyzw,vf03xyzw,vf15z 	nop
  36aa20:	3c 03 00 80 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	nop
  36aa28:	3c 03 00 80 bc 08 ee 01 	maddax.xyzw accxyzw,vf01xyzw,vf14x 	nop
  36aa30:	8d 30 f2 01 bd 10 ee 01 	madday.xyzw accxyzw,vf02xyzw,vf14y 	lq.xyzw vf18xyzw,141(vi06)
  36aa38:	8e 30 f3 01 8a 1b ee 01 	maddz.xyzw vf14xyzw,vf03xyzw,vf14z 	lq.xyzw vf19xyzw,142(vi06)
  36aa40:	8f 30 f4 01 2c 78 f0 01 	sub.xyzw vf00xyzw,vf15xyzw,vf16xyzw 	lq.xyzw vf20xyzw,143(vi06)
  36aa48:	40 00 02 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x40
  36aa50:	45 30 eb 01 3c 91 f2 01 	itof0.xyzw vf18xyzw,vf18xyzw 	lq.xyzw vf11xyzw,69(vi06)
  36aa58:	46 30 ec 01 3c 99 f3 01 	itof0.xyzw vf19xyzw,vf19xyzw 	lq.xyzw vf12xyzw,70(vi06)
  36aa60:	00 10 01 34 2c 70 ef 01 	sub.xyzw vf00xyzw,vf14xyzw,vf15xyzw 	fmand vi01,vi02
  36aa68:	0b 08 02 52 3c a1 f4 01 	itof0.xyzw vf20xyzw,vf20xyzw 	ibne vi02,vi01,36aac8 <_$NOSWP1>
  36aa70:	47 30 ed 01 ff 02 00 00 	nop 	lq.xyzw vf13xyzw,71(vi06)

0036aa78 <_$SWP1>:
  36aa78:	3c 7b f1 81 ff 02 00 00 	nop 	move.xyzw vf17xyzw,vf15xyzw
  36aa80:	3c 83 ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf16xyzw
  36aa88:	3c 63 f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf12xyzw
  36aa90:	3c 6b ec 81 ff 02 00 00 	nop 	move.xyzw vf12xyzw,vf13xyzw
  36aa98:	3c 9b ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf19xyzw
  36aaa0:	3c a3 f3 81 ff 02 00 00 	nop 	move.xyzw vf19xyzw,vf20xyzw
  36aaa8:	3c 6b f4 81 ff 02 00 00 	nop 	move.xyzw vf20xyzw,vf13xyzw
  36aab0:	3c 83 ed 81 2c 70 ef 01 	sub.xyzw vf00xyzw,vf14xyzw,vf15xyzw 	move.xyzw vf13xyzw,vf16xyzw
  36aab8:	3c 8b f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf17xyzw
  36aac0:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036aac8 <_$NOSWP1>:
  36aac8:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36aad0:	00 10 01 34 ff 02 00 00 	nop 	fmand vi01,vi02
  36aad8:	0b 08 02 52 2c 78 f0 01 	sub.xyzw vf00xyzw,vf15xyzw,vf16xyzw 	ibne vi02,vi01,36ab38 <_$NOSWP2>
  36aae0:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036aae8 <_$SWP2>:
  36aae8:	3c 7b f1 81 ff 02 00 00 	nop 	move.xyzw vf17xyzw,vf15xyzw
  36aaf0:	3c 73 ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf14xyzw
  36aaf8:	3c 63 ee 81 ff 02 00 00 	nop 	move.xyzw vf14xyzw,vf12xyzw
  36ab00:	3c 5b ec 81 ff 02 00 00 	nop 	move.xyzw vf12xyzw,vf11xyzw
  36ab08:	3c 9b eb 81 ff 02 00 00 	nop 	move.xyzw vf11xyzw,vf19xyzw
  36ab10:	3c 93 f3 81 ff 02 00 00 	nop 	move.xyzw vf19xyzw,vf18xyzw
  36ab18:	3c 5b f2 81 ff 02 00 00 	nop 	move.xyzw vf18xyzw,vf11xyzw
  36ab20:	3c 73 eb 81 ff 02 00 00 	nop 	move.xyzw vf11xyzw,vf14xyzw
  36ab28:	3c 8b ee 81 2c 78 f0 01 	sub.xyzw vf00xyzw,vf15xyzw,vf16xyzw 	move.xyzw vf14xyzw,vf17xyzw
  36ab30:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036ab38 <_$NOSWP2>:
  36ab38:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36ab40:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36ab48:	00 10 01 34 ff 02 00 00 	nop 	fmand vi01,vi02
  36ab50:	09 08 02 52 ff 02 00 00 	nop 	ibne vi02,vi01,36aba0 <_$NOSWP3>

0036ab58 <_$SWP3>:
  36ab58:	3c 7b f1 81 ff 02 00 00 	nop 	move.xyzw vf17xyzw,vf15xyzw
  36ab60:	3c 83 ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf16xyzw
  36ab68:	3c 63 f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf12xyzw
  36ab70:	3c 6b ec 81 ff 02 00 00 	nop 	move.xyzw vf12xyzw,vf13xyzw
  36ab78:	3c 9b ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf19xyzw
  36ab80:	3c a3 f3 81 ff 02 00 00 	nop 	move.xyzw vf19xyzw,vf20xyzw
  36ab88:	3c 6b f4 81 ff 02 00 00 	nop 	move.xyzw vf20xyzw,vf13xyzw
  36ab90:	3c 83 ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf16xyzw
  36ab98:	3c 8b f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf17xyzw

0036aba0 <_$NOSWP3>:
  36aba0:	00 70 e9 03 ff 02 00 00 	nop 	sq.xyzw vf14xyzw,0(vi09)
  36aba8:	01 90 e9 03 ff 02 00 00 	nop 	sq.xyzw vf18xyzw,1(vi09)
  36abb0:	02 58 e9 03 ff 02 00 00 	nop 	sq.xyzw vf11xyzw,2(vi09)
  36abb8:	03 78 e9 03 ff 02 00 00 	nop 	sq.xyzw vf15xyzw,3(vi09)
  36abc0:	04 98 e9 03 ff 02 00 00 	nop 	sq.xyzw vf19xyzw,4(vi09)
  36abc8:	05 60 e9 03 ff 02 00 00 	nop 	sq.xyzw vf12xyzw,5(vi09)
  36abd0:	06 80 e9 03 ff 02 00 00 	nop 	sq.xyzw vf16xyzw,6(vi09)
  36abd8:	07 a0 e9 03 ff 02 00 00 	nop 	sq.xyzw vf20xyzw,7(vi09)
  36abe0:	08 68 e9 03 ff 02 00 00 	nop 	sq.xyzw vf13xyzw,8(vi09)
  36abe8:	09 70 e9 03 ff 02 00 00 	nop 	sq.xyzw vf14xyzw,9(vi09)
  36abf0:	0a 90 e9 03 ff 02 00 00 	nop 	sq.xyzw vf18xyzw,10(vi09)
  36abf8:	0b 58 e9 03 ff 02 00 00 	nop 	sq.xyzw vf11xyzw,11(vi09)

0036ac00 <_$OSTARTCLIP>:
  36ac00:	00 00 22 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x800
  36ac08:	20 00 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi00,0x20
  36ac10:	02 00 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi00,2
  36ac18:	2b 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x2b
  36ac20:	43 00 0a 10 ff 02 00 00 	nop 	iaddiu vi10,vi00,0x43
  36ac28:	02 00 05 10 ff 02 00 00 	nop 	iaddiu vi05,vi00,2
  36ac30:	00 00 06 10 87 07 00 01 	subw.x vf30x,vf00x,vf00w 	iaddiu vi06,vi00,0
  36ac38:	7c 4b f2 81 ff 02 00 00 	nop 	lqi.xyzw vf18xyzw,(vi09++)
  36ac40:	7c 4b f3 81 ff 02 00 00 	nop 	lqi.xyzw vf19xyzw,(vi09++)
  36ac48:	7c 4b f4 81 ff 02 00 00 	nop 	lqi.xyzw vf20xyzw,(vi09++)

0036ac50 <_$OLOOPZ1>:
  36ac50:	61 00 0e 42 68 95 ff 01 	add.xyzw vf21xyzw,vf18xyzw,vf31xyzw 	bal vi14,36af60 <_$ONODRAW+0x8>
  36ac58:	7c 4b f2 81 a8 9d ff 01 	add.xyzw vf22xyzw,vf19xyzw,vf31xyzw 	lqi.xyzw vf18xyzw,(vi09++)
  36ac60:	fd 07 05 52 ff 02 00 00 	nop 	ibne vi05,vi00,36ac50 <_$OLOOPZ1>
  36ac68:	01 28 05 12 ff 02 00 00 	nop 	isubiu vi05,vi05,1
  36ac70:	5b 00 06 50 ff 02 00 00 	nop 	ibeq vi06,vi00,36af50 <_$OLOOPX2+0x68>
  36ac78:	43 00 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,67(vi00)
  36ac80:	44 00 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,68(vi00)
  36ac88:	45 00 f4 01 ff 02 00 00 	nop 	lq.xyzw vf20xyzw,69(vi00)
  36ac90:	00 01 02 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x100
  36ac98:	7d 93 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf18xyzw,(vi10++)
  36aca0:	7d 9b ea 81 ff 02 00 00 	nop 	sqi.xyzw vf19xyzw,(vi10++)
  36aca8:	7d a3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf20xyzw,(vi10++)
  36acb0:	04 00 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi00,4
  36acb8:	01 00 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi00,1
  36acc0:	43 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x43
  36acc8:	2b 00 0a 10 ff 02 00 00 	nop 	iaddiu vi10,vi00,0x2b
  36acd0:	f2 37 05 80 ff 02 00 00 	nop 	iaddi vi05,vi06,-1
  36acd8:	00 00 06 10 83 07 00 01 	addw.x vf30x,vf00x,vf00w 	iaddiu vi06,vi00,0
  36ace0:	7c 4b f2 81 ff 02 00 00 	nop 	lqi.xyzw vf18xyzw,(vi09++)
  36ace8:	7c 4b f3 81 ff 02 00 00 	nop 	lqi.xyzw vf19xyzw,(vi09++)
  36acf0:	7c 4b f4 81 ff 02 00 00 	nop 	lqi.xyzw vf20xyzw,(vi09++)

0036acf8 <_$OLOOPY2>:
  36acf8:	4c 00 0e 42 68 95 ff 01 	add.xyzw vf21xyzw,vf18xyzw,vf31xyzw 	bal vi14,36af60 <_$ONODRAW+0x8>
  36ad00:	7c 4b f2 81 a8 9d ff 01 	add.xyzw vf22xyzw,vf19xyzw,vf31xyzw 	lqi.xyzw vf18xyzw,(vi09++)
  36ad08:	fd 07 05 52 ff 02 00 00 	nop 	ibne vi05,vi00,36acf8 <_$OLOOPY2>
  36ad10:	01 28 05 12 ff 02 00 00 	nop 	isubiu vi05,vi05,1
  36ad18:	46 00 06 50 ff 02 00 00 	nop 	ibeq vi06,vi00,36af50 <_$OLOOPX2+0x68>
  36ad20:	2b 00 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,43(vi00)
  36ad28:	2c 00 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,44(vi00)
  36ad30:	2d 00 f4 01 ff 02 00 00 	nop 	lq.xyzw vf20xyzw,45(vi00)
  36ad38:	00 02 02 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x200
  36ad40:	7d 93 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf18xyzw,(vi10++)
  36ad48:	7d 9b ea 81 ff 02 00 00 	nop 	sqi.xyzw vf19xyzw,(vi10++)
  36ad50:	7d a3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf20xyzw,(vi10++)
  36ad58:	08 00 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi00,8
  36ad60:	2b 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x2b
  36ad68:	43 00 0a 10 ff 02 00 00 	nop 	iaddiu vi10,vi00,0x43
  36ad70:	f2 37 05 80 ff 02 00 00 	nop 	iaddi vi05,vi06,-1
  36ad78:	00 00 06 10 87 07 00 01 	subw.x vf30x,vf00x,vf00w 	iaddiu vi06,vi00,0
  36ad80:	7c 4b f2 81 ff 02 00 00 	nop 	lqi.xyzw vf18xyzw,(vi09++)
  36ad88:	7c 4b f3 81 ff 02 00 00 	nop 	lqi.xyzw vf19xyzw,(vi09++)
  36ad90:	7c 4b f4 81 ff 02 00 00 	nop 	lqi.xyzw vf20xyzw,(vi09++)

0036ad98 <_$OLOOPY1>:
  36ad98:	38 00 0e 42 68 95 ff 01 	add.xyzw vf21xyzw,vf18xyzw,vf31xyzw 	bal vi14,36af60 <_$ONODRAW+0x8>
  36ada0:	7c 4b f2 81 a8 9d ff 01 	add.xyzw vf22xyzw,vf19xyzw,vf31xyzw 	lqi.xyzw vf18xyzw,(vi09++)
  36ada8:	fd 07 05 52 ff 02 00 00 	nop 	ibne vi05,vi00,36ad98 <_$OLOOPY1>
  36adb0:	01 28 05 12 ff 02 00 00 	nop 	isubiu vi05,vi05,1
  36adb8:	32 00 06 50 ff 02 00 00 	nop 	ibeq vi06,vi00,36af50 <_$OLOOPX2+0x68>
  36adc0:	43 00 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,67(vi00)
  36adc8:	44 00 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,68(vi00)
  36add0:	45 00 f4 01 ff 02 00 00 	nop 	lq.xyzw vf20xyzw,69(vi00)
  36add8:	80 00 02 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x80
  36ade0:	7d 93 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf18xyzw,(vi10++)
  36ade8:	7d 9b ea 81 ff 02 00 00 	nop 	sqi.xyzw vf19xyzw,(vi10++)
  36adf0:	7d a3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf20xyzw,(vi10++)
  36adf8:	02 00 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi00,2
  36ae00:	00 00 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi00,0
  36ae08:	43 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x43
  36ae10:	2b 00 0a 10 ff 02 00 00 	nop 	iaddiu vi10,vi00,0x2b
  36ae18:	f2 37 05 80 ff 02 00 00 	nop 	iaddi vi05,vi06,-1
  36ae20:	00 00 06 10 87 07 00 01 	subw.x vf30x,vf00x,vf00w 	iaddiu vi06,vi00,0
  36ae28:	7c 4b f2 81 ff 02 00 00 	nop 	lqi.xyzw vf18xyzw,(vi09++)
  36ae30:	7c 4b f3 81 ff 02 00 00 	nop 	lqi.xyzw vf19xyzw,(vi09++)
  36ae38:	7c 4b f4 81 ff 02 00 00 	nop 	lqi.xyzw vf20xyzw,(vi09++)

0036ae40 <_$OLOOPX1>:
  36ae40:	23 00 0e 42 68 95 ff 01 	add.xyzw vf21xyzw,vf18xyzw,vf31xyzw 	bal vi14,36af60 <_$ONODRAW+0x8>
  36ae48:	7c 4b f2 81 a8 9d ff 01 	add.xyzw vf22xyzw,vf19xyzw,vf31xyzw 	lqi.xyzw vf18xyzw,(vi09++)
  36ae50:	fd 07 05 52 ff 02 00 00 	nop 	ibne vi05,vi00,36ae40 <_$OLOOPX1>
  36ae58:	01 28 05 12 ff 02 00 00 	nop 	isubiu vi05,vi05,1
  36ae60:	1d 00 06 50 ff 02 00 00 	nop 	ibeq vi06,vi00,36af50 <_$OLOOPX2+0x68>
  36ae68:	2b 00 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,43(vi00)
  36ae70:	2c 00 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,44(vi00)
  36ae78:	2d 00 f4 01 ff 02 00 00 	nop 	lq.xyzw vf20xyzw,45(vi00)
  36ae80:	40 00 02 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x40
  36ae88:	7d 93 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf18xyzw,(vi10++)
  36ae90:	7d 9b ea 81 ff 02 00 00 	nop 	sqi.xyzw vf19xyzw,(vi10++)
  36ae98:	7d a3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf20xyzw,(vi10++)
  36aea0:	01 00 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi00,1

0036aea8 <.vif.20>:
  36aea8:	00 00 00 00 	vifnop
  36aeac:	00 01 8d 4a 	mpg 0x100,0x8d

0036aeb0 <.vu.23>:
  36aeb0:	2b 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x2b
  36aeb8:	43 00 0a 10 ff 02 00 00 	nop 	iaddiu vi10,vi00,0x43
  36aec0:	f2 37 05 80 ff 02 00 00 	nop 	iaddi vi05,vi06,-1
  36aec8:	00 00 06 10 83 07 00 01 	addw.x vf30x,vf00x,vf00w 	iaddiu vi06,vi00,0
  36aed0:	7c 4b f2 81 ff 02 00 00 	nop 	lqi.xyzw vf18xyzw,(vi09++)
  36aed8:	7c 4b f3 81 ff 02 00 00 	nop 	lqi.xyzw vf19xyzw,(vi09++)
  36aee0:	7c 4b f4 81 ff 02 00 00 	nop 	lqi.xyzw vf20xyzw,(vi09++)

0036aee8 <_$OLOOPX2>:
  36aee8:	0f 00 0e 42 68 95 ff 01 	add.xyzw vf21xyzw,vf18xyzw,vf31xyzw 	bal vi14,36af68 <_$ODOCLIP>
  36aef0:	7c 4b f2 81 a8 9d ff 01 	add.xyzw vf22xyzw,vf19xyzw,vf31xyzw 	lqi.xyzw vf18xyzw,(vi09++)
  36aef8:	fd 07 05 52 ff 02 00 00 	nop 	ibne vi05,vi00,36aee8 <_$OLOOPX2>
  36af00:	01 28 05 12 ff 02 00 00 	nop 	isubiu vi05,vi05,1
  36af08:	09 00 06 50 ff 02 00 00 	nop 	ibeq vi06,vi00,36af58 <_$ONODRAW>
  36af10:	43 00 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,67(vi00)
  36af18:	44 00 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,68(vi00)
  36af20:	45 00 f4 01 ff 02 00 00 	nop 	lq.xyzw vf20xyzw,69(vi00)
  36af28:	43 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x43
  36af30:	7d 93 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf18xyzw,(vi10++)
  36af38:	7d 9b ea 81 ff 02 00 00 	nop 	sqi.xyzw vf19xyzw,(vi10++)
  36af40:	7d a3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf20xyzw,(vi10++)
  36af48:	53 00 00 40 ff 02 00 00 	nop 	b 36b1e8 <_$ODRAWPOLY>
  36af50:	70 01 06 80 ff 02 00 00 	nop 	iadd vi05,vi00,vi06

0036af58 <_$ONODRAW>:
  36af58:	00 78 00 48 ff 02 00 00 	nop 	jr vi15
  36af60:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036af68 <_$ODOCLIP>:
  36af68:	7c 4b f3 81 e8 a5 ff 01 	add.xyzw vf23xyzw,vf20xyzw,vf31xyzw 	lqi.xyzw vf19xyzw,(vi09++)
  36af70:	7c 4b f4 81 ff 02 00 00 	nop 	lqi.xyzw vf20xyzw,(vi09++)
  36af78:	3c 03 00 80 ff a9 d5 01 	clipw.xyz vf21xyz,vf21w 	nop
  36af80:	3c 03 00 80 ff 91 d2 01 	clipw.xyz vf18xyz,vf18w 	nop
  36af88:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36af90:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36af98:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36afa0:	00 00 01 38 ff 02 00 00 	nop 	fcget vi01
  36afa8:	f4 0a 02 80 ff 02 00 00 	nop 	iand vi11,vi01,vi02
  36afb0:	34 0b 03 80 ff 02 00 00 	nop 	iand vi12,vi01,vi03
  36afb8:	0b 00 0b 50 ff 02 00 00 	nop 	ibeq vi11,vi00,36b018 <_$OFIRSTIN>
  36afc0:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036afc8 <_$OFIRSTOUT>:
  36afc8:	03 00 0c 50 ff 02 00 00 	nop 	ibeq vi12,vi00,36afe8 <_$OOUT_TO_IN>
  36afd0:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036afd8 <_$OOUT_TO_OUT>:
  36afd8:	00 70 00 48 ff 02 00 00 	nop 	jr vi14
  36afe0:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036afe8 <_$OOUT_TO_IN>:
  36afe8:	15 00 0c 42 ff 02 00 00 	nop 	bal vi12,36b098 <_$OINTERPOLATE1>
  36aff0:	01 30 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi06,1
  36aff8:	7d c3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf24xyzw,(vi10++)
  36b000:	7d cb ea 81 ff 02 00 00 	nop 	sqi.xyzw vf25xyzw,(vi10++)
  36b008:	00 70 00 48 ff 02 00 00 	nop 	jr vi14
  36b010:	7d d3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf26xyzw,(vi10++)

0036b018 <_$OFIRSTIN>:
  36b018:	0a 00 0c 50 ff 02 00 00 	nop 	ibeq vi12,vi00,36b070 <_$OIN_TO_IN>
  36b020:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036b028 <_$OIN_TO_OUT>:
  36b028:	22 00 0c 42 ff 02 00 00 	nop 	bal vi12,36b140 <_$OINTERPOLATE2>
  36b030:	02 30 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi06,2
  36b038:	7d ab ea 81 ff 02 00 00 	nop 	sqi.xyzw vf21xyzw,(vi10++)
  36b040:	7d b3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf22xyzw,(vi10++)
  36b048:	7d bb ea 81 ff 02 00 00 	nop 	sqi.xyzw vf23xyzw,(vi10++)
  36b050:	7d c3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf24xyzw,(vi10++)
  36b058:	7d cb ea 81 ff 02 00 00 	nop 	sqi.xyzw vf25xyzw,(vi10++)
  36b060:	00 70 00 48 ff 02 00 00 	nop 	jr vi14
  36b068:	7d d3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf26xyzw,(vi10++)

0036b070 <_$OIN_TO_IN>:
  36b070:	7d ab ea 81 ff 02 00 00 	nop 	sqi.xyzw vf21xyzw,(vi10++)
  36b078:	7d b3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf22xyzw,(vi10++)
  36b080:	7d bb ea 81 ff 02 00 00 	nop 	sqi.xyzw vf23xyzw,(vi10++)
  36b088:	00 70 00 48 ff 02 00 00 	nop 	jr vi14
  36b090:	01 30 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi06,1

0036b098 <_$OINTERPOLATE1>:
  36b098:	f0 02 04 80 18 af 3e 00 	mulx.w vf28w,vf21w,vf30x 	iadd vi11,vi00,vi04
  36b0a0:	3c 03 00 80 58 97 3e 00 	mulx.w vf29w,vf18w,vf30x 	nop
  36b0a8:	3c 03 00 80 07 af fc 01 	subw.xyzw vf28xyzw,vf21xyzw,vf28w 	nop
  36b0b0:	3c 03 00 80 47 97 fd 01 	subw.xyzw vf29xyzw,vf18xyzw,vf29w 	nop
  36b0b8:	04 00 0b 50 ff 02 00 00 	nop 	ibeq vi11,vi00,36b0e0 <_$OENDR>

0036b0c0 <_$OLOOPR>:
  36b0c0:	01 58 0b 12 ff 02 00 00 	nop 	isubiu vi11,vi11,1
  36b0c8:	3d e3 fc 81 ff 02 00 00 	nop 	mr32.xyzw vf28xyzw,vf28xyzw
  36b0d0:	fd 07 0b 52 ff 02 00 00 	nop 	ibne vi11,vi00,36b0c0 <_$OLOOPR>
  36b0d8:	3d eb fd 81 ff 02 00 00 	nop 	mr32.xyzw vf29xyzw,vf29xyzw

0036b0e0 <_$OENDR>:
  36b0e0:	3c 03 00 80 ec e6 dd 01 	sub.xyz vf27xyz,vf28xyz,vf29xyz 	nop
  36b0e8:	bc e3 1b 80 ff 02 00 00 	nop 	div q,vf28x,vf00x
  36b0f0:	bf 03 00 80 e0 06 00 01 	addq.x vf27x,vf00x,q 	waitq
  36b0f8:	3c 03 00 80 2c 96 f5 01 	sub.xyzw vf24xyzw,vf18xyzw,vf21xyzw 	nop
  36b100:	3c 03 00 80 6c 9e f6 01 	sub.xyzw vf25xyzw,vf19xyzw,vf22xyzw 	nop
  36b108:	3c 03 00 80 ac a6 f7 01 	sub.xyzw vf26xyzw,vf20xyzw,vf23xyzw 	nop
  36b110:	3c 03 00 80 18 c6 fb 01 	mulx.xyzw vf24xyzw,vf24xyzw,vf27x 	nop
  36b118:	3c 03 00 80 58 ce fb 01 	mulx.xyzw vf25xyzw,vf25xyzw,vf27x 	nop
  36b120:	3c 03 00 80 98 d6 fb 01 	mulx.xyzw vf26xyzw,vf26xyzw,vf27x 	nop
  36b128:	3c 03 00 80 28 c6 f5 01 	add.xyzw vf24xyzw,vf24xyzw,vf21xyzw 	nop
  36b130:	00 60 00 48 68 ce f6 01 	add.xyzw vf25xyzw,vf25xyzw,vf22xyzw 	jr vi12
  36b138:	3c 03 00 80 a8 d6 f7 01 	add.xyzw vf26xyzw,vf26xyzw,vf23xyzw 	nop

0036b140 <_$OINTERPOLATE2>:
  36b140:	f0 02 04 80 18 97 3e 00 	mulx.w vf28w,vf18w,vf30x 	iadd vi11,vi00,vi04
  36b148:	3c 03 00 80 58 af 3e 00 	mulx.w vf29w,vf21w,vf30x 	nop
  36b150:	3c 03 00 80 07 97 fc 01 	subw.xyzw vf28xyzw,vf18xyzw,vf28w 	nop
  36b158:	3c 03 00 80 47 af fd 01 	subw.xyzw vf29xyzw,vf21xyzw,vf29w 	nop
  36b160:	04 00 0b 50 ff 02 00 00 	nop 	ibeq vi11,vi00,36b188 <_$OENDR2>

0036b168 <_$OLOOPR2>:
  36b168:	01 58 0b 12 ff 02 00 00 	nop 	isubiu vi11,vi11,1
  36b170:	3d e3 fc 81 ff 02 00 00 	nop 	mr32.xyzw vf28xyzw,vf28xyzw
  36b178:	fd 07 0b 52 ff 02 00 00 	nop 	ibne vi11,vi00,36b168 <_$OLOOPR2>
  36b180:	3d eb fd 81 ff 02 00 00 	nop 	mr32.xyzw vf29xyzw,vf29xyzw

0036b188 <_$OENDR2>:
  36b188:	3c 03 00 80 ec e6 dd 01 	sub.xyz vf27xyz,vf28xyz,vf29xyz 	nop
  36b190:	bc e3 1b 80 ff 02 00 00 	nop 	div q,vf28x,vf00x
  36b198:	bf 03 00 80 e0 06 00 01 	addq.x vf27x,vf00x,q 	waitq
  36b1a0:	3c 03 00 80 2c ae f2 01 	sub.xyzw vf24xyzw,vf21xyzw,vf18xyzw 	nop
  36b1a8:	3c 03 00 80 6c b6 f3 01 	sub.xyzw vf25xyzw,vf22xyzw,vf19xyzw 	nop
  36b1b0:	3c 03 00 80 ac be f4 01 	sub.xyzw vf26xyzw,vf23xyzw,vf20xyzw 	nop
  36b1b8:	3c 03 00 80 18 c6 fb 01 	mulx.xyzw vf24xyzw,vf24xyzw,vf27x 	nop
  36b1c0:	3c 03 00 80 58 ce fb 01 	mulx.xyzw vf25xyzw,vf25xyzw,vf27x 	nop
  36b1c8:	3c 03 00 80 98 d6 fb 01 	mulx.xyzw vf26xyzw,vf26xyzw,vf27x 	nop
  36b1d0:	3c 03 00 80 28 c6 f2 01 	add.xyzw vf24xyzw,vf24xyzw,vf18xyzw 	nop
  36b1d8:	00 60 00 48 68 ce f3 01 	add.xyzw vf25xyzw,vf25xyzw,vf19xyzw 	jr vi12
  36b1e0:	3c 03 00 80 a8 d6 f4 01 	add.xyzw vf26xyzw,vf26xyzw,vf20xyzw 	nop

0036b1e8 <_$ODRAWPOLY>:
  36b1e8:	fc 06 00 80 ff 02 00 00 	nop 	xgkick vi00
  36b1f0:	0f 00 01 10 ff 02 00 00 	nop 	iaddiu vi01,vi00,15
  36b1f8:	bc 06 02 80 ff 02 00 00 	nop 	xtop vi02
  36b200:	01 10 f5 01 ff 02 00 00 	nop 	lq.xyzw vf21xyzw,1(vi02)
  36b208:	02 10 f6 01 ff 02 00 00 	nop 	lq.xyzw vf22xyzw,2(vi02)
  36b210:	03 10 f7 01 ff 02 00 00 	nop 	lq.xyzw vf23xyzw,3(vi02)
  36b218:	04 10 f8 01 ff 02 00 00 	nop 	lq.xyzw vf24xyzw,4(vi02)
  36b220:	05 10 f9 01 ff 02 00 00 	nop 	lq.xyzw vf25xyzw,5(vi02)
  36b228:	06 10 fa 01 ff 02 00 00 	nop 	lq.xyzw vf26xyzw,6(vi02)
  36b230:	7d ab e1 81 ff 02 00 00 	nop 	sqi.xyzw vf21xyzw,(vi01++)
  36b238:	7d b3 e1 81 ff 02 00 00 	nop 	sqi.xyzw vf22xyzw,(vi01++)
  36b240:	7d bb e1 81 ff 02 00 00 	nop 	sqi.xyzw vf23xyzw,(vi01++)
  36b248:	7d c3 e1 81 ff 02 00 00 	nop 	sqi.xyzw vf24xyzw,(vi01++)
  36b250:	7d cb e1 81 ff 02 00 00 	nop 	sqi.xyzw vf25xyzw,(vi01++)
  36b258:	7d d3 e1 81 ff 02 00 00 	nop 	sqi.xyzw vf26xyzw,(vi01++)
  36b260:	01 00 fd 01 ff 02 00 00 	nop 	lq.xyzw vf29xyzw,1(vi00)
  36b268:	00 28 02 11 ff 02 00 00 	nop 	iaddiu vi02,vi05,0x4000
  36b270:	00 10 02 11 ff 02 00 00 	nop 	iaddiu vi02,vi02,0x4000
  36b278:	7d eb e1 81 ff 02 00 00 	nop 	sqi.xyzw vf29xyzw,(vi01++)
  36b280:	ff 0f 02 0b ff 02 00 00 	nop 	isw.x vi02,-1(vi01)x

0036b288 <_$OLOOPP1>:
  36b288:	7c 4b fd 81 ff 02 00 00 	nop 	lqi.xyzw vf29xyzw,(vi09++)
  36b290:	7c 4b fc 81 ff 02 00 00 	nop 	lqi.xyzw vf28xyzw,(vi09++)
  36b298:	7c 4b fb 81 ff 02 00 00 	nop 	lqi.xyzw vf27xyzw,(vi09++)
  36b2a0:	03 08 01 10 ff 02 00 00 	nop 	iaddiu vi01,vi01,3
  36b2a8:	bc 03 fd 81 ff 02 00 00 	nop 	div q,vf00w,vf00x
  36b2b0:	3c 03 00 80 7c e1 fc 01 	ftoi0.xyzw vf28xyzw,vf28xyzw 	nop
  36b2b8:	bf 03 00 80 5c ef e0 01 	mulq.xyzw vf29xyzw,vf29xyzw,q 	waitq
  36b2c0:	3c 03 00 80 dc de e0 01 	mulq.xyzw vf27xyzw,vf27xyzw,q 	nop
  36b2c8:	3c 03 00 80 3c 30 e0 01 	addax.xyzw accxyzw,vf06xyzw,vf00x 	nop
  36b2d0:	3c 03 00 80 69 ef e5 01 	madd.xyzw vf29xyzw,vf29xyzw,vf05xyzw 	nop
  36b2d8:	01 28 05 12 7d e9 fd 01 	ftoi4.xyzw vf29xyzw,vf29xyzw 	isubiu vi05,vi05,1
  36b2e0:	fe e7 e1 03 ff 02 00 00 	nop 	sq.xyzw vf28xyzw,-2(vi01)
  36b2e8:	fd df e1 03 ff 02 00 00 	nop 	sq.xyzw vf27xyzw,-3(vi01)
  36b2f0:	f2 07 05 52 ff 02 00 00 	nop 	ibne vi05,vi00,36b288 <_$OLOOPP1>
  36b2f8:	ff ef e1 03 ff 02 00 00 	nop 	sq.xyzw vf29xyzw,-1(vi01)
  36b300:	0f 00 01 10 ff 02 00 00 	nop 	iaddiu vi01,vi00,15
  36b308:	00 78 00 48 ff 02 00 00 	nop 	jr vi15
  36b310:	fc 0e 00 80 ff 02 00 00 	nop 	xgkick vi01

0036b318 <.vif.41>:
  36b318:	00 00 00 00 	vifnop
  36b31c:	c8 05 39 4a 	mpg 0x5c8,0x39

0036b320 <_$START_NORMAL_NC>:
  36b320:	bc 06 02 80 d8 ff e0 01 	mulx.xyzw vf31xyzw,vf31xyzw,vf00x 	xtop vi02
  36b328:	e1 10 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi02,0xe1
  36b330:	01 10 e7 01 ff 02 00 00 	nop 	lq.xyzw vf07xyzw,1(vi02)
  36b338:	02 10 e8 01 ff 02 00 00 	nop 	lq.xyzw vf08xyzw,2(vi02)
  36b340:	03 10 e9 01 ff 02 00 00 	nop 	lq.xyzw vf09xyzw,3(vi02)
  36b348:	04 10 ea 01 ff 02 00 00 	nop 	lq.xyzw vf10xyzw,4(vi02)
  36b350:	05 10 eb 01 ff 02 00 00 	nop 	lq.xyzw vf11xyzw,5(vi02)
  36b358:	06 10 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,6(vi02)
  36b360:	7d 3b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf07xyzw,(vi04++)
  36b368:	7d 43 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf08xyzw,(vi04++)
  36b370:	7d 4b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf09xyzw,(vi04++)
  36b378:	7d 53 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf10xyzw,(vi04++)
  36b380:	7d 5b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf11xyzw,(vi04++)
  36b388:	7d 63 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf12xyzw,(vi04++)
  36b390:	08 10 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi02,8
  36b398:	00 30 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,0(vi06)
  36b3a0:	00 10 fd 01 ff 02 00 00 	nop 	lq.xyzw vf29xyzw,0(vi02)
  36b3a8:	00 10 0b 09 ff 02 00 00 	nop 	ilw.x vi11,0(vi02)x
  36b3b0:	00 00 00 22 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	fcset 0
  36b3b8:	fc 63 63 80 bc 08 ec 01 	maddax.xyzw accxyzw,vf01xyzw,vf12x 	mtir vi03,vf12w
  36b3c0:	ff 07 e1 11 bd 10 ec 01 	madday.xyzw accxyzw,vf02xyzw,vf12y 	iaddiu vi01,vi00,0x7fff
  36b3c8:	7d eb e4 81 8a 1a ec 01 	maddz.xyzw vf10xyzw,vf03xyzw,vf12z 	sqi.xyzw vf29xyzw,(vi04++)
  36b3d0:	f4 5a 01 80 ff 02 00 00 	nop 	iand vi11,vi11,vi01
  36b3d8:	f0 5a 06 80 ff 02 00 00 	nop 	iadd vi11,vi11,vi06
  36b3e0:	01 30 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,1(vi06)
  36b3e8:	bc 03 ea 81 ff 02 00 00 	nop 	div q,vf00w,vf00x
  36b3f0:	3c 03 00 80 ea 51 c5 01 	mul.xyz vf07xyz,vf10xyz,vf05xyz 	nop
  36b3f8:	01 30 06 10 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	iaddiu vi06,vi06,1
  36b400:	47 30 ee 01 bc 08 ec 01 	maddax.xyzw accxyzw,vf01xyzw,vf12x 	lq.xyzw vf14xyzw,71(vi06)
  36b408:	3c 03 00 80 bd 10 ec 01 	madday.xyzw accxyzw,vf02xyzw,vf12y 	nop
  36b410:	fd 1b 3d 80 8a 1a ec 01 	maddz.xyzw vf10xyzw,vf03xyzw,vf12z 	mfir.w vf29w,vi03
  36b418:	8f 30 ed 01 3c 30 e0 01 	addax.xyzw accxyzw,vf06xyzw,vf00x 	lq.xyzw vf13xyzw,143(vi06)
  36b420:	3c 03 00 80 61 3f e0 01 	maddq.xyzw vf29xyzw,vf07xyzw,q 	nop
  36b428:	3c 03 00 80 9c 73 e0 01 	mulq.xyzw vf14xyzw,vf14xyzw,q 	nop

0036b430 <_$OLOOP1_NC>:
  36b430:	fc 63 63 80 ff 02 00 00 	nop 	mtir vi03,vf12w
  36b438:	bc 03 ea 81 ea 51 c5 01 	mul.xyz vf07xyz,vf10xyz,vf05xyz 	div q,vf00w,vf00x
  36b440:	01 68 e4 03 7d e9 dd 01 	ftoi4.xyz vf29xyz,vf29xyz 	sq.xyzw vf13xyzw,1(vi04)
  36b448:	00 70 e4 03 ff 02 00 00 	nop 	sq.xyzw vf14xyzw,0(vi04)
  36b450:	01 30 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,1(vi06)
  36b458:	01 30 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi06,1
  36b460:	02 e8 e4 03 ff 02 00 00 	nop 	sq.xyzw vf29xyzw,2(vi04)
  36b468:	3c 03 00 80 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	nop
  36b470:	47 30 ee 01 bc 08 ec 01 	maddax.xyzw accxyzw,vf01xyzw,vf12x 	lq.xyzw vf14xyzw,71(vi06)
  36b478:	3c 03 00 80 bd 10 ec 01 	madday.xyzw accxyzw,vf02xyzw,vf12y 	nop
  36b480:	fd 1b 3d 80 8a 1a ec 01 	maddz.xyzw vf10xyzw,vf03xyzw,vf12z 	mfir.w vf29w,vi03

0036b488 <_$ONEXTV_NC>:
  36b488:	8f 30 ed 01 3c 30 e0 01 	addax.xyzw accxyzw,vf06xyzw,vf00x 	lq.xyzw vf13xyzw,143(vi06)
  36b490:	f3 5f 06 52 61 3f c0 01 	maddq.xyz vf29xyz,vf07xyz,q 	ibne vi06,vi11,36b430 <_$OLOOP1_NC>
  36b498:	03 20 04 10 9c 73 e0 01 	mulq.xyzw vf14xyzw,vf14xyzw,q 	iaddiu vi04,vi04,3
  36b4a0:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36b4a8:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36b4b0:	01 68 e4 03 7d e9 dd 01 	ftoi4.xyz vf29xyz,vf29xyz 	sq.xyzw vf13xyzw,1(vi04)
  36b4b8:	00 70 e4 03 ff 02 00 00 	nop 	sq.xyzw vf14xyzw,0(vi04)
  36b4c0:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36b4c8:	e1 10 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi02,0xe1
  36b4d0:	02 e8 e4 03 ff 02 00 00 	nop 	sq.xyzw vf29xyzw,2(vi04)
  36b4d8:	fc 1e 00 80 ff 02 00 40 	nop[e] 	xgkick vi03
  36b4e0:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036b4e8 <.vif.47>:
  36b4e8:	00 00 00 00 	vifnop
  36b4ec:	b8 01 00 4a 	mpg 0x1b8,0x100

0036b4f0 <_$START_REFLECT>:
  36b4f0:	bc 06 02 80 d8 ff e0 01 	mulx.xyzw vf31xyzw,vf31xyzw,vf00x 	xtop vi02
  36b4f8:	e1 10 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi02,0xe1
  36b500:	01 10 e7 01 ff 02 00 00 	nop 	lq.xyzw vf07xyzw,1(vi02)
  36b508:	02 10 e8 01 ff 02 00 00 	nop 	lq.xyzw vf08xyzw,2(vi02)
  36b510:	03 10 e9 01 ff 02 00 00 	nop 	lq.xyzw vf09xyzw,3(vi02)
  36b518:	04 10 ea 01 ff 02 00 00 	nop 	lq.xyzw vf10xyzw,4(vi02)
  36b520:	05 10 eb 01 ff 02 00 00 	nop 	lq.xyzw vf11xyzw,5(vi02)
  36b528:	06 10 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,6(vi02)
  36b530:	7d 3b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf07xyzw,(vi04++)
  36b538:	7d 43 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf08xyzw,(vi04++)
  36b540:	7d 4b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf09xyzw,(vi04++)
  36b548:	7d 53 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf10xyzw,(vi04++)
  36b550:	7d 5b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf11xyzw,(vi04++)
  36b558:	7d 63 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf12xyzw,(vi04++)
  36b560:	06 00 f0 01 ff 02 00 00 	nop 	lq.xyzw vf16xyzw,6(vi00)
  36b568:	07 00 f1 01 ff 02 00 00 	nop 	lq.xyzw vf17xyzw,7(vi00)
  36b570:	08 00 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,8(vi00)
  36b578:	08 10 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi02,8
  36b580:	00 10 fd 01 ff 02 00 00 	nop 	lq.xyzw vf29xyzw,0(vi02)
  36b588:	00 10 0b 09 ff 02 00 00 	nop 	ilw.x vi11,0(vi02)x
  36b590:	ff 07 e1 11 ff 02 00 00 	nop 	iaddiu vi01,vi00,0x7fff
  36b598:	7d eb e4 81 ff 02 00 00 	nop 	sqi.xyzw vf29xyzw,(vi04++)
  36b5a0:	f4 5a 01 80 ff 02 00 00 	nop 	iand vi11,vi11,vi01
  36b5a8:	f0 5a 06 80 ff 02 00 00 	nop 	iadd vi11,vi11,vi06
  36b5b0:	00 30 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,0(vi06)
  36b5b8:	90 30 ed 01 ff 02 00 00 	nop 	lq.xyzw vf13xyzw,144(vi06)
  36b5c0:	3c 03 e9 81 ff 02 00 00 	nop 	move.xyzw vf09xyzw,vf00xyzw
  36b5c8:	3c 03 ea 81 ff 02 00 00 	nop 	move.xyzw vf10xyzw,vf00xyzw
  36b5d0:	00 00 00 22 bc 09 ec 01 	mulax.xyzw accxyzw,vf01xyzw,vf12x 	fcset 0
  36b5d8:	3c 03 00 80 bd 10 ec 01 	madday.xyzw accxyzw,vf02xyzw,vf12y 	nop
  36b5e0:	3c 4b e8 81 be 18 ec 01 	maddaz.xyzw accxyzw,vf03xyzw,vf12z 	move.xyzw vf08xyzw,vf09xyzw

0036b5e8 <_$RLOOP1>:
  36b5e8:	3c 53 e9 81 8b 22 e0 01 	maddw.xyzw vf10xyzw,vf04xyzw,vf00w 	move.xyzw vf09xyzw,vf10xyzw
  36b5f0:	01 68 e4 03 ff 02 00 00 	nop 	sq.xyzw vf13xyzw,1(vi04)
  36b5f8:	48 30 ee 01 58 ef e0 01 	mulx.xyzw vf29xyzw,vf29xyzw,vf00x 	lq.xyzw vf14xyzw,72(vi06)
  36b600:	3c 03 00 80 ff 41 c8 01 	clipw.xyz vf08xyz,vf08w 	nop
  36b608:	bc 03 ea 81 ea 51 c5 01 	mul.xyz vf07xyz,vf10xyz,vf05xyz 	div q,vf00w,vf00x
  36b610:	3c 03 00 80 ff 49 c9 01 	clipw.xyz vf09xyz,vf09w 	nop
  36b618:	3c 03 00 80 bc 81 ce 01 	mulax.xyz accxyz,vf16xyz,vf14x 	nop
  36b620:	fc 63 63 80 bd 88 ce 01 	madday.xyz accxyz,vf17xyz,vf14y 	mtir vi03,vf12w
  36b628:	3c 63 27 80 8a 93 ce 01 	maddz.xyz vf14xyz,vf18xyz,vf14z 	move.w vf07w,vf12w
  36b630:	03 20 04 10 ff 51 ca 01 	clipw.xyz vf10xyz,vf10w 	iaddiu vi04,vi04,3
  36b638:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36b640:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36b648:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36b650:	3c 03 00 80 68 07 8e 01 	add.xy vf29xy,vf00xy,vf14xy 	nop
  36b658:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36b660:	01 30 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,1(vi06)
  36b668:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36b670:	00 00 00 3f 43 ef c0 81 	addw[i].xyz vf29xyz,vf29xyz,vf00w 	loi 0.5
  36b678:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36b680:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36b688:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36b690:	3c 03 00 80 5e ef 80 01 	muli.xy vf29xy,vf29xy,i 	nop
  36b698:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36b6a0:	ef fb 02 24 3c 30 e0 01 	addax.xyzw accxyzw,vf06xyzw,vf00x 	fcand vi01,0x2fbef
  36b6a8:	3c 03 00 80 e1 39 c0 01 	maddq.xyz vf07xyz,vf07xyz,q 	nop
  36b6b0:	01 30 06 10 5c ef e0 01 	mulq.xyzw vf29xyzw,vf29xyzw,q 	iaddiu vi06,vi06,1
  36b6b8:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36b6c0:	90 30 ed 01 ff 02 00 00 	nop 	lq.xyzw vf13xyzw,144(vi06)
  36b6c8:	07 08 00 5a 7d 39 c7 01 	ftoi4.xyz vf07xyz,vf07xyz 	ibgtz vi01,36b708 <_$RXYZ3>
  36b6d0:	fd ef e4 03 ff 02 00 00 	nop 	sq.xyzw vf29xyzw,-3(vi04)

0036b6d8 <_$RNEXTV>:
  36b6d8:	3c 4b e8 81 bc 09 ec 01 	mulax.xyzw accxyzw,vf01xyzw,vf12x 	move.xyzw vf08xyzw,vf09xyzw
  36b6e0:	e0 5f 06 52 bd 10 ec 01 	madday.xyzw accxyzw,vf02xyzw,vf12y 	ibne vi06,vi11,36b5e8 <_$RLOOP1>
  36b6e8:	ff 3f e4 03 be 18 ec 01 	maddaz.xyzw accxyzw,vf03xyzw,vf12z 	sq.xyzw vf07xyzw,-1(vi04)
  36b6f0:	e1 10 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi02,0xe1
  36b6f8:	fc 1e 00 80 ff 02 00 40 	nop[e] 	xgkick vi03
  36b700:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036b708 <_$RXYZ3>:
  36b708:	f9 1f 00 58 ff 02 00 00 	nop 	ibltz vi03,36b6d8 <_$RNEXTV>
  36b710:	7d df ff 26 ff 02 00 00 	nop 	fcor vi01,0xffdf7d
  36b718:	19 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36b7e8 <_$RCULL>
  36b720:	be ef ff 26 ff 02 00 00 	nop 	fcor vi01,0xffefbe
  36b728:	17 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36b7e8 <_$RCULL>
  36b730:	df f7 fd 26 ff 02 00 00 	nop 	fcor vi01,0xfdf7df
  36b738:	15 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36b7e8 <_$RCULL>
  36b740:	ef fb fe 26 ff 02 00 00 	nop 	fcor vi01,0xfefbef
  36b748:	13 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36b7e8 <_$RCULL>
  36b750:	f7 7d ff 26 ff 02 00 00 	nop 	fcor vi01,0xff7df7
  36b758:	11 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36b7e8 <_$RCULL>
  36b760:	fb be ff 26 ff 02 00 00 	nop 	fcor vi01,0xffbefb
  36b768:	0f 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36b7e8 <_$RCULL>
  36b770:	62 00 82 0a ff 02 00 00 	nop 	isw.y vi02,98(vi00)y
  36b778:	62 00 24 0a ff 02 00 00 	nop 	isw.w vi04,98(vi00)w
  36b780:	61 00 86 0a ff 02 00 00 	nop 	isw.y vi06,97(vi00)y
  36b788:	0e 00 0f 42 ff 02 00 00 	nop 	bal vi15,36b800 <_$RCLIPPEDPOLY>
  36b790:	60 00 4b 0a ff 02 00 00 	nop 	isw.z vi11,96(vi00)z
  36b798:	60 00 4b 08 ff 02 00 00 	nop 	ilw.z vi11,96(vi00)z
  36b7a0:	61 00 86 08 ff 02 00 00 	nop 	ilw.y vi06,97(vi00)y
  36b7a8:	62 00 24 08 ff 02 00 00 	nop 	ilw.w vi04,98(vi00)w
  36b7b0:	62 00 82 08 ff 02 00 00 	nop 	ilw.y vi02,98(vi00)y
  36b7b8:	00 30 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,0(vi06)
  36b7c0:	90 30 ed 01 ff 02 00 00 	nop 	lq.xyzw vf13xyzw,144(vi06)
  36b7c8:	48 30 ee 01 ff 02 00 00 	nop 	lq.xyzw vf14xyzw,72(vi06)
  36b7d0:	06 00 f0 01 ff 02 00 00 	nop 	lq.xyzw vf16xyzw,6(vi00)
  36b7d8:	07 00 f1 01 ff 02 00 00 	nop 	lq.xyzw vf17xyzw,7(vi00)
  36b7e0:	08 00 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,8(vi00)

0036b7e8 <_$RCULL>:
  36b7e8:	01 00 01 12 ff 02 00 00 	nop 	isubiu vi01,vi00,1
  36b7f0:	dc 07 00 40 ff 02 00 00 	nop 	b 36b6d8 <_$RNEXTV>
  36b7f8:	fd 0b 27 80 ff 02 00 00 	nop 	mfir.w vf07w,vi01

0036b800 <_$RCLIPPEDPOLY>:
  36b800:	2b 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x2b
  36b808:	3c 53 f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf10xyzw
  36b810:	3c 4b ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf09xyzw
  36b818:	3c 43 ee 81 ff 02 00 00 	nop 	move.xyzw vf14xyzw,vf08xyzw
  36b820:	f8 27 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,-8(vi04)
  36b828:	fb 27 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,-5(vi04)
  36b830:	fe 27 f4 01 6c 7c f0 01 	sub.xyzw vf17xyzw,vf15xyzw,vf16xyzw 	lq.xyzw vf20xyzw,-2(vi04)
  36b838:	40 00 02 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x40
  36b840:	f7 27 eb 01 3c 91 f2 01 	itof0.xyzw vf18xyzw,vf18xyzw 	lq.xyzw vf11xyzw,-9(vi04)
  36b848:	fa 27 ec 01 3c 99 f3 01 	itof0.xyzw vf19xyzw,vf19xyzw 	lq.xyzw vf12xyzw,-6(vi04)
  36b850:	00 10 01 34 3c a1 f4 01 	itof0.xyzw vf20xyzw,vf20xyzw 	fmand vi01,vi02
  36b858:	0b 08 02 52 6c 74 ef 01 	sub.xyzw vf17xyzw,vf14xyzw,vf15xyzw 	ibne vi02,vi01,36b8b8 <_$RNOSWP1>
  36b860:	fd 27 ed 01 ff 02 00 00 	nop 	lq.xyzw vf13xyzw,-3(vi04)

0036b868 <_$RSWP1>:
  36b868:	3c 7b f1 81 ff 02 00 00 	nop 	move.xyzw vf17xyzw,vf15xyzw
  36b870:	3c 83 ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf16xyzw
  36b878:	3c 63 f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf12xyzw
  36b880:	3c 6b ec 81 ff 02 00 00 	nop 	move.xyzw vf12xyzw,vf13xyzw
  36b888:	3c 9b ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf19xyzw
  36b890:	3c a3 f3 81 ff 02 00 00 	nop 	move.xyzw vf19xyzw,vf20xyzw
  36b898:	3c 6b f4 81 ff 02 00 00 	nop 	move.xyzw vf20xyzw,vf13xyzw
  36b8a0:	3c 83 ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf16xyzw
  36b8a8:	3c 8b f0 81 6c 74 ef 01 	sub.xyzw vf17xyzw,vf14xyzw,vf15xyzw 	move.xyzw vf16xyzw,vf17xyzw
  36b8b0:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036b8b8 <_$RNOSWP1>:
  36b8b8:	40 00 02 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x40
  36b8c0:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36b8c8:	00 10 01 34 ff 02 00 00 	nop 	fmand vi01,vi02
  36b8d0:	0b 08 02 52 6c 7c f0 01 	sub.xyzw vf17xyzw,vf15xyzw,vf16xyzw 	ibne vi02,vi01,36b930 <_$RNOSWP2>
  36b8d8:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036b8e0 <_$RSWP2>:
  36b8e0:	3c 7b f1 81 ff 02 00 00 	nop 	move.xyzw vf17xyzw,vf15xyzw
  36b8e8:	3c 73 ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf14xyzw
  36b8f0:	3c 63 ee 81 ff 02 00 00 	nop 	move.xyzw vf14xyzw,vf12xyzw
  36b8f8:	3c 5b ec 81 ff 02 00 00 	nop 	move.xyzw vf12xyzw,vf11xyzw
  36b900:	3c 9b eb 81 ff 02 00 00 	nop 	move.xyzw vf11xyzw,vf19xyzw
  36b908:	3c 93 f3 81 ff 02 00 00 	nop 	move.xyzw vf19xyzw,vf18xyzw
  36b910:	3c 5b f2 81 ff 02 00 00 	nop 	move.xyzw vf18xyzw,vf11xyzw
  36b918:	3c 73 eb 81 ff 02 00 00 	nop 	move.xyzw vf11xyzw,vf14xyzw
  36b920:	3c 8b ee 81 6c 7c f0 01 	sub.xyzw vf17xyzw,vf15xyzw,vf16xyzw 	move.xyzw vf14xyzw,vf17xyzw
  36b928:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036b930 <_$RNOSWP2>:
  36b930:	40 00 02 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x40
  36b938:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36b940:	00 10 01 34 ff 02 00 00 	nop 	fmand vi01,vi02
  36b948:	09 08 02 52 ff 02 00 00 	nop 	ibne vi02,vi01,36b998 <_$RNOSWP3>

0036b950 <_$RSWP3>:
  36b950:	3c 7b f1 81 ff 02 00 00 	nop 	move.xyzw vf17xyzw,vf15xyzw
  36b958:	3c 83 ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf16xyzw
  36b960:	3c 63 f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf12xyzw
  36b968:	3c 6b ec 81 ff 02 00 00 	nop 	move.xyzw vf12xyzw,vf13xyzw
  36b970:	3c 9b ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf19xyzw
  36b978:	3c a3 f3 81 ff 02 00 00 	nop 	move.xyzw vf19xyzw,vf20xyzw
  36b980:	3c 6b f4 81 ff 02 00 00 	nop 	move.xyzw vf20xyzw,vf13xyzw
  36b988:	3c 83 ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf16xyzw
  36b990:	3c 8b f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf17xyzw

0036b998 <_$RNOSWP3>:
  36b998:	00 70 e9 03 ff 02 00 00 	nop 	sq.xyzw vf14xyzw,0(vi09)
  36b9a0:	01 90 e9 03 ff 02 00 00 	nop 	sq.xyzw vf18xyzw,1(vi09)
  36b9a8:	02 58 e9 03 ff 02 00 00 	nop 	sq.xyzw vf11xyzw,2(vi09)
  36b9b0:	03 78 e9 03 ff 02 00 00 	nop 	sq.xyzw vf15xyzw,3(vi09)
  36b9b8:	04 98 e9 03 ff 02 00 00 	nop 	sq.xyzw vf19xyzw,4(vi09)
  36b9c0:	05 60 e9 03 ff 02 00 00 	nop 	sq.xyzw vf12xyzw,5(vi09)
  36b9c8:	06 80 e9 03 ff 02 00 00 	nop 	sq.xyzw vf16xyzw,6(vi09)
  36b9d0:	07 a0 e9 03 ff 02 00 00 	nop 	sq.xyzw vf20xyzw,7(vi09)
  36b9d8:	08 68 e9 03 ff 02 00 00 	nop 	sq.xyzw vf13xyzw,8(vi09)
  36b9e0:	09 70 e9 03 ff 02 00 00 	nop 	sq.xyzw vf14xyzw,9(vi09)
  36b9e8:	0a 90 e9 03 ff 02 00 00 	nop 	sq.xyzw vf18xyzw,10(vi09)
  36b9f0:	0b 58 e9 03 ff 02 00 00 	nop 	sq.xyzw vf11xyzw,11(vi09)
  36b9f8:	00 00 22 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x800
  36ba00:	20 00 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi00,0x20
  36ba08:	02 00 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi00,2
  36ba10:	2b 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x2b
  36ba18:	43 00 0a 10 ff 02 00 00 	nop 	iaddiu vi10,vi00,0x43
  36ba20:	03 00 05 10 ff 02 00 00 	nop 	iaddiu vi05,vi00,3
  36ba28:	00 00 06 10 87 07 00 01 	subw.x vf30x,vf00x,vf00w 	iaddiu vi06,vi00,0
  36ba30:	7c 4b f2 81 ff 02 00 00 	nop 	lqi.xyzw vf18xyzw,(vi09++)
  36ba38:	7c 4b f3 81 ff 02 00 00 	nop 	lqi.xyzw vf19xyzw,(vi09++)
  36ba40:	7c 4b f4 81 ff 02 00 00 	nop 	lqi.xyzw vf20xyzw,(vi09++)

0036ba48 <_$RLOOPZ1>:
  36ba48:	63 00 0e 42 ff 02 00 00 	nop 	bal vi14,36bd68 <_$RNODRAW+0x8>
  36ba50:	01 28 05 12 ff 02 00 00 	nop 	isubiu vi05,vi05,1
  36ba58:	fd 07 05 52 ff 02 00 00 	nop 	ibne vi05,vi00,36ba48 <_$RLOOPZ1>
  36ba60:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36ba68:	5d 00 06 50 ff 02 00 00 	nop 	ibeq vi06,vi00,36bd58 <.vu.70+0x60>
  36ba70:	43 00 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,67(vi00)
  36ba78:	44 00 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,68(vi00)
  36ba80:	45 00 f4 01 ff 02 00 00 	nop 	lq.xyzw vf20xyzw,69(vi00)
  36ba88:	00 01 02 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x100
  36ba90:	7d 93 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf18xyzw,(vi10++)
  36ba98:	7d 9b ea 81 ff 02 00 00 	nop 	sqi.xyzw vf19xyzw,(vi10++)
  36baa0:	7d a3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf20xyzw,(vi10++)
  36baa8:	04 00 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi00,4
  36bab0:	01 00 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi00,1
  36bab8:	43 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x43
  36bac0:	2b 00 0a 10 ff 02 00 00 	nop 	iaddiu vi10,vi00,0x2b
  36bac8:	70 01 06 80 ff 02 00 00 	nop 	iadd vi05,vi00,vi06
  36bad0:	00 00 06 10 83 07 00 01 	addw.x vf30x,vf00x,vf00w 	iaddiu vi06,vi00,0
  36bad8:	7c 4b f2 81 ff 02 00 00 	nop 	lqi.xyzw vf18xyzw,(vi09++)
  36bae0:	7c 4b f3 81 ff 02 00 00 	nop 	lqi.xyzw vf19xyzw,(vi09++)
  36bae8:	7c 4b f4 81 ff 02 00 00 	nop 	lqi.xyzw vf20xyzw,(vi09++)

0036baf0 <_$RLOOPY2>:
  36baf0:	4e 00 0e 42 ff 02 00 00 	nop 	bal vi14,36bd68 <_$RNODRAW+0x8>
  36baf8:	01 28 05 12 ff 02 00 00 	nop 	isubiu vi05,vi05,1
  36bb00:	fd 07 05 52 ff 02 00 00 	nop 	ibne vi05,vi00,36baf0 <_$RLOOPY2>
  36bb08:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36bb10:	48 00 06 50 ff 02 00 00 	nop 	ibeq vi06,vi00,36bd58 <.vu.70+0x60>
  36bb18:	2b 00 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,43(vi00)
  36bb20:	2c 00 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,44(vi00)
  36bb28:	2d 00 f4 01 ff 02 00 00 	nop 	lq.xyzw vf20xyzw,45(vi00)
  36bb30:	00 02 02 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x200
  36bb38:	7d 93 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf18xyzw,(vi10++)
  36bb40:	7d 9b ea 81 ff 02 00 00 	nop 	sqi.xyzw vf19xyzw,(vi10++)
  36bb48:	7d a3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf20xyzw,(vi10++)
  36bb50:	08 00 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi00,8
  36bb58:	01 00 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi00,1
  36bb60:	2b 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x2b
  36bb68:	43 00 0a 10 ff 02 00 00 	nop 	iaddiu vi10,vi00,0x43
  36bb70:	70 01 06 80 ff 02 00 00 	nop 	iadd vi05,vi00,vi06
  36bb78:	00 00 06 10 87 07 00 01 	subw.x vf30x,vf00x,vf00w 	iaddiu vi06,vi00,0
  36bb80:	7c 4b f2 81 ff 02 00 00 	nop 	lqi.xyzw vf18xyzw,(vi09++)
  36bb88:	7c 4b f3 81 ff 02 00 00 	nop 	lqi.xyzw vf19xyzw,(vi09++)
  36bb90:	7c 4b f4 81 ff 02 00 00 	nop 	lqi.xyzw vf20xyzw,(vi09++)

0036bb98 <_$RLOOPY1>:
  36bb98:	39 00 0e 42 ff 02 00 00 	nop 	bal vi14,36bd68 <_$RNODRAW+0x8>
  36bba0:	01 28 05 12 ff 02 00 00 	nop 	isubiu vi05,vi05,1
  36bba8:	fd 07 05 52 ff 02 00 00 	nop 	ibne vi05,vi00,36bb98 <_$RLOOPY1>
  36bbb0:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36bbb8:	33 00 06 50 ff 02 00 00 	nop 	ibeq vi06,vi00,36bd58 <.vu.70+0x60>
  36bbc0:	43 00 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,67(vi00)
  36bbc8:	44 00 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,68(vi00)
  36bbd0:	45 00 f4 01 ff 02 00 00 	nop 	lq.xyzw vf20xyzw,69(vi00)
  36bbd8:	80 00 02 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x80
  36bbe0:	7d 93 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf18xyzw,(vi10++)
  36bbe8:	7d 9b ea 81 ff 02 00 00 	nop 	sqi.xyzw vf19xyzw,(vi10++)
  36bbf0:	7d a3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf20xyzw,(vi10++)
  36bbf8:	02 00 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi00,2
  36bc00:	00 00 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi00,0
  36bc08:	43 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x43
  36bc10:	2b 00 0a 10 ff 02 00 00 	nop 	iaddiu vi10,vi00,0x2b
  36bc18:	70 01 06 80 ff 02 00 00 	nop 	iadd vi05,vi00,vi06
  36bc20:	00 00 06 10 87 07 00 01 	subw.x vf30x,vf00x,vf00w 	iaddiu vi06,vi00,0
  36bc28:	7c 4b f2 81 ff 02 00 00 	nop 	lqi.xyzw vf18xyzw,(vi09++)
  36bc30:	7c 4b f3 81 ff 02 00 00 	nop 	lqi.xyzw vf19xyzw,(vi09++)
  36bc38:	7c 4b f4 81 ff 02 00 00 	nop 	lqi.xyzw vf20xyzw,(vi09++)

0036bc40 <_$RLOOPX1>:
  36bc40:	24 00 0e 42 ff 02 00 00 	nop 	bal vi14,36bd68 <_$RNODRAW+0x8>
  36bc48:	01 28 05 12 ff 02 00 00 	nop 	isubiu vi05,vi05,1
  36bc50:	fd 07 05 52 ff 02 00 00 	nop 	ibne vi05,vi00,36bc40 <_$RLOOPX1>
  36bc58:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36bc60:	1e 00 06 50 ff 02 00 00 	nop 	ibeq vi06,vi00,36bd58 <.vu.70+0x60>
  36bc68:	2b 00 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,43(vi00)
  36bc70:	2c 00 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,44(vi00)
  36bc78:	2d 00 f4 01 ff 02 00 00 	nop 	lq.xyzw vf20xyzw,45(vi00)
  36bc80:	40 00 02 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x40
  36bc88:	7d 93 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf18xyzw,(vi10++)
  36bc90:	7d 9b ea 81 ff 02 00 00 	nop 	sqi.xyzw vf19xyzw,(vi10++)
  36bc98:	7d a3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf20xyzw,(vi10++)
  36bca0:	01 00 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi00,1
  36bca8:	00 00 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi00,0
  36bcb0:	2b 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x2b
  36bcb8:	43 00 0a 10 ff 02 00 00 	nop 	iaddiu vi10,vi00,0x43
  36bcc0:	70 01 06 80 ff 02 00 00 	nop 	iadd vi05,vi00,vi06
  36bcc8:	00 00 06 10 83 07 00 01 	addw.x vf30x,vf00x,vf00w 	iaddiu vi06,vi00,0
  36bcd0:	7c 4b f2 81 ff 02 00 00 	nop 	lqi.xyzw vf18xyzw,(vi09++)
  36bcd8:	7c 4b f3 81 ff 02 00 00 	nop 	lqi.xyzw vf19xyzw,(vi09++)
  36bce0:	7c 4b f4 81 ff 02 00 00 	nop 	lqi.xyzw vf20xyzw,(vi09++)

0036bce8 <_$RLOOPX2>:
  36bce8:	0f 00 0e 42 ff 02 00 00 	nop 	bal vi14,36bd68 <_$RNODRAW+0x8>

0036bcf0 <.vif.67>:
  36bcf0:	00 00 00 00 	vifnop
  36bcf4:	b8 02 60 4a 	mpg 0x2b8,0x60

0036bcf8 <.vu.70>:
  36bcf8:	01 28 05 12 ff 02 00 00 	nop 	isubiu vi05,vi05,1
  36bd00:	fd 07 05 52 ff 02 00 00 	nop 	ibne vi05,vi00,36bcf0 <.vif.67>
  36bd08:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36bd10:	09 00 06 50 ff 02 00 00 	nop 	ibeq vi06,vi00,36bd60 <_$RNODRAW>
  36bd18:	43 00 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,67(vi00)
  36bd20:	44 00 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,68(vi00)
  36bd28:	45 00 f4 01 ff 02 00 00 	nop 	lq.xyzw vf20xyzw,69(vi00)
  36bd30:	43 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x43
  36bd38:	7d 93 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf18xyzw,(vi10++)
  36bd40:	7d 9b ea 81 ff 02 00 00 	nop 	sqi.xyzw vf19xyzw,(vi10++)
  36bd48:	7d a3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf20xyzw,(vi10++)
  36bd50:	2f 00 00 40 ff 02 00 00 	nop 	b 36bed0 <_$RDRAWPOLY>
  36bd58:	70 01 06 80 ff 02 00 00 	nop 	iadd vi05,vi00,vi06

0036bd60 <_$RNODRAW>:
  36bd60:	00 78 00 48 ff 02 00 00 	nop 	jr vi15
  36bd68:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036bd70 <_$RDOCLIP>:
  36bd70:	7c 4b f2 81 68 95 ff 01 	add.xyzw vf21xyzw,vf18xyzw,vf31xyzw 	lqi.xyzw vf18xyzw,(vi09++)
  36bd78:	7c 4b f3 81 a8 9d ff 01 	add.xyzw vf22xyzw,vf19xyzw,vf31xyzw 	lqi.xyzw vf19xyzw,(vi09++)
  36bd80:	7c 4b f4 81 e8 a5 ff 01 	add.xyzw vf23xyzw,vf20xyzw,vf31xyzw 	lqi.xyzw vf20xyzw,(vi09++)
  36bd88:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36bd90:	3c 03 00 80 ff a9 d5 01 	clipw.xyz vf21xyz,vf21w 	nop
  36bd98:	3c 03 00 80 ff 91 d2 01 	clipw.xyz vf18xyz,vf18w 	nop
  36bda0:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36bda8:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36bdb0:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36bdb8:	00 00 01 38 ff 02 00 00 	nop 	fcget vi01
  36bdc0:	f4 0a 02 80 ff 02 00 00 	nop 	iand vi11,vi01,vi02
  36bdc8:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36bdd0:	0d 00 0b 50 ff 02 00 00 	nop 	ibeq vi11,vi00,36be40 <_$RFIRSTIN>
  36bdd8:	f4 0a 03 80 ff 02 00 00 	nop 	iand vi11,vi01,vi03

0036bde0 <_$RFIRSTOUT>:
  36bde0:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36bde8:	03 00 0b 50 ff 02 00 00 	nop 	ibeq vi11,vi00,36be08 <_$ROUT_TO_IN>
  36bdf0:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036bdf8 <_$ROUT_TO_OUT>:
  36bdf8:	00 70 00 48 ff 02 00 00 	nop 	jr vi14
  36be00:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036be08 <_$ROUT_TO_IN>:
  36be08:	62 06 0c 42 ff 02 00 00 	nop 	bal vi12,36b120 <_$OENDR+0x40>
  36be10:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36be18:	7d c3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf24xyzw,(vi10++)
  36be20:	7d cb ea 81 ff 02 00 00 	nop 	sqi.xyzw vf25xyzw,(vi10++)
  36be28:	7d d3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf26xyzw,(vi10++)
  36be30:	00 70 00 48 ff 02 00 00 	nop 	jr vi14
  36be38:	01 30 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi06,1

0036be40 <_$RFIRSTIN>:
  36be40:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36be48:	0b 00 0b 50 ff 02 00 00 	nop 	ibeq vi11,vi00,36bea8 <_$RIN_TO_IN>
  36be50:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036be58 <_$RIN_TO_OUT>:
  36be58:	6d 06 0c 42 ff 02 00 00 	nop 	bal vi12,36b1c8 <_$OENDR2+0x40>
  36be60:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36be68:	7d ab ea 81 ff 02 00 00 	nop 	sqi.xyzw vf21xyzw,(vi10++)
  36be70:	7d b3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf22xyzw,(vi10++)
  36be78:	7d bb ea 81 ff 02 00 00 	nop 	sqi.xyzw vf23xyzw,(vi10++)
  36be80:	7d c3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf24xyzw,(vi10++)
  36be88:	7d cb ea 81 ff 02 00 00 	nop 	sqi.xyzw vf25xyzw,(vi10++)
  36be90:	7d d3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf26xyzw,(vi10++)
  36be98:	00 70 00 48 ff 02 00 00 	nop 	jr vi14
  36bea0:	02 30 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi06,2

0036bea8 <_$RIN_TO_IN>:
  36bea8:	7d ab ea 81 ff 02 00 00 	nop 	sqi.xyzw vf21xyzw,(vi10++)
  36beb0:	7d b3 ea 81 ff 02 00 00 	nop 	sqi.xyzw vf22xyzw,(vi10++)
  36beb8:	7d bb ea 81 ff 02 00 00 	nop 	sqi.xyzw vf23xyzw,(vi10++)
  36bec0:	00 70 00 48 ff 02 00 00 	nop 	jr vi14
  36bec8:	01 30 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi06,1

0036bed0 <_$RDRAWPOLY>:
  36bed0:	fc 06 00 80 ff 02 00 00 	nop 	xgkick vi00
  36bed8:	0f 00 01 10 ff 02 00 00 	nop 	iaddiu vi01,vi00,15
  36bee0:	bc 06 02 80 ff 02 00 00 	nop 	xtop vi02
  36bee8:	01 10 f5 01 ff 02 00 00 	nop 	lq.xyzw vf21xyzw,1(vi02)
  36bef0:	02 10 f6 01 ff 02 00 00 	nop 	lq.xyzw vf22xyzw,2(vi02)
  36bef8:	03 10 f7 01 ff 02 00 00 	nop 	lq.xyzw vf23xyzw,3(vi02)
  36bf00:	04 10 f8 01 ff 02 00 00 	nop 	lq.xyzw vf24xyzw,4(vi02)
  36bf08:	05 10 f9 01 ff 02 00 00 	nop 	lq.xyzw vf25xyzw,5(vi02)
  36bf10:	06 10 fa 01 ff 02 00 00 	nop 	lq.xyzw vf26xyzw,6(vi02)
  36bf18:	7d ab e1 81 ff 02 00 00 	nop 	sqi.xyzw vf21xyzw,(vi01++)
  36bf20:	7d b3 e1 81 ff 02 00 00 	nop 	sqi.xyzw vf22xyzw,(vi01++)
  36bf28:	7d bb e1 81 ff 02 00 00 	nop 	sqi.xyzw vf23xyzw,(vi01++)
  36bf30:	7d c3 e1 81 ff 02 00 00 	nop 	sqi.xyzw vf24xyzw,(vi01++)
  36bf38:	7d cb e1 81 ff 02 00 00 	nop 	sqi.xyzw vf25xyzw,(vi01++)
  36bf40:	7d d3 e1 81 ff 02 00 00 	nop 	sqi.xyzw vf26xyzw,(vi01++)
  36bf48:	01 00 fd 01 ff 02 00 00 	nop 	lq.xyzw vf29xyzw,1(vi00)
  36bf50:	00 28 02 11 ff 02 00 00 	nop 	iaddiu vi02,vi05,0x4000
  36bf58:	00 10 02 11 ff 02 00 00 	nop 	iaddiu vi02,vi02,0x4000
  36bf60:	7d eb e1 81 ff 02 00 00 	nop 	sqi.xyzw vf29xyzw,(vi01++)
  36bf68:	ff 0f 02 0b ff 02 00 00 	nop 	isw.x vi02,-1(vi01)x

0036bf70 <_$RLOOPP1>:
  36bf70:	7c 4b fd 81 ff 02 00 00 	nop 	lqi.xyzw vf29xyzw,(vi09++)
  36bf78:	7c 4b fc 81 ff 02 00 00 	nop 	lqi.xyzw vf28xyzw,(vi09++)
  36bf80:	7c 4b fb 81 ff 02 00 00 	nop 	lqi.xyzw vf27xyzw,(vi09++)
  36bf88:	03 08 01 10 ff 02 00 00 	nop 	iaddiu vi01,vi01,3
  36bf90:	bc 03 fd 81 ff 02 00 00 	nop 	div q,vf00w,vf00x
  36bf98:	3c 03 00 80 7c e1 fc 01 	ftoi0.xyzw vf28xyzw,vf28xyzw 	nop
  36bfa0:	bf 03 00 80 5c ef e0 01 	mulq.xyzw vf29xyzw,vf29xyzw,q 	waitq
  36bfa8:	3c 03 00 80 3c 30 e0 01 	addax.xyzw accxyzw,vf06xyzw,vf00x 	nop
  36bfb0:	3c 03 00 80 69 ef e5 01 	madd.xyzw vf29xyzw,vf29xyzw,vf05xyzw 	nop
  36bfb8:	01 28 05 12 7d e9 fd 01 	ftoi4.xyzw vf29xyzw,vf29xyzw 	isubiu vi05,vi05,1
  36bfc0:	fe e7 e1 03 ff 02 00 00 	nop 	sq.xyzw vf28xyzw,-2(vi01)
  36bfc8:	fd df e1 03 ff 02 00 00 	nop 	sq.xyzw vf27xyzw,-3(vi01)
  36bfd0:	f3 07 05 52 ff 02 00 00 	nop 	ibne vi05,vi00,36bf70 <_$RLOOPP1>
  36bfd8:	ff ef e1 03 ff 02 00 00 	nop 	sq.xyzw vf29xyzw,-1(vi01)
  36bfe0:	0f 00 01 10 ff 02 00 00 	nop 	iaddiu vi01,vi00,15
  36bfe8:	00 78 00 48 ff 02 00 00 	nop 	jr vi15
  36bff0:	fc 0e 00 80 ff 02 00 00 	nop 	xgkick vi01

0036bff8 <.vif.81>:
  36bff8:	00 00 00 00 	vifnop
  36bffc:	20 03 ad 4a 	mpg 0x320,0xad

0036c000 <_$START_LIT>:
  36c000:	bc 06 02 80 d8 ff e0 01 	mulx.xyzw vf31xyzw,vf31xyzw,vf00x 	xtop vi02
  36c008:	e1 10 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi02,0xe1
  36c010:	01 10 e7 01 ff 02 00 00 	nop 	lq.xyzw vf07xyzw,1(vi02)
  36c018:	02 10 e8 01 ff 02 00 00 	nop 	lq.xyzw vf08xyzw,2(vi02)
  36c020:	03 10 e9 01 ff 02 00 00 	nop 	lq.xyzw vf09xyzw,3(vi02)
  36c028:	04 10 ea 01 ff 02 00 00 	nop 	lq.xyzw vf10xyzw,4(vi02)
  36c030:	05 10 eb 01 ff 02 00 00 	nop 	lq.xyzw vf11xyzw,5(vi02)
  36c038:	06 10 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,6(vi02)
  36c040:	7d 3b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf07xyzw,(vi04++)
  36c048:	7d 43 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf08xyzw,(vi04++)
  36c050:	7d 4b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf09xyzw,(vi04++)
  36c058:	7d 53 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf10xyzw,(vi04++)
  36c060:	7d 5b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf11xyzw,(vi04++)
  36c068:	7d 63 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf12xyzw,(vi04++)
  36c070:	08 10 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi02,8
  36c078:	67 00 f0 01 ff 02 00 00 	nop 	lq.xyzw vf16xyzw,103(vi00)
  36c080:	68 00 f1 01 ff 02 00 00 	nop 	lq.xyzw vf17xyzw,104(vi00)
  36c088:	69 00 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,105(vi00)
  36c090:	6a 00 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,106(vi00)
  36c098:	00 10 fd 01 ff 02 00 00 	nop 	lq.xyzw vf29xyzw,0(vi02)
  36c0a0:	00 10 0b 09 ff 02 00 00 	nop 	ilw.x vi11,0(vi02)x
  36c0a8:	ff 07 e1 11 ff 02 00 00 	nop 	iaddiu vi01,vi00,0x7fff
  36c0b0:	00 00 00 22 ff 02 00 00 	nop 	fcset 0
  36c0b8:	7d eb e4 81 ff 02 00 00 	nop 	sqi.xyzw vf29xyzw,(vi04++)
  36c0c0:	f4 5a 01 80 ff 02 00 00 	nop 	iand vi11,vi11,vi01
  36c0c8:	f0 5a 06 80 ff 02 00 00 	nop 	iadd vi11,vi11,vi06
  36c0d0:	90 30 ef 01 ff 02 00 00 	nop 	lq.xyzw vf15xyzw,144(vi06)
  36c0d8:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36c0e0:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36c0e8:	3c 03 00 80 bf 99 e0 01 	mulaw.xyzw accxyzw,vf19xyzw,vf00w 	nop
  36c0f0:	00 30 ec 01 bc 80 ef 01 	maddax.xyzw accxyzw,vf16xyzw,vf15x 	lq.xyzw vf12xyzw,0(vi06)
  36c0f8:	3c 03 00 80 bd 88 ef 01 	madday.xyzw accxyzw,vf17xyzw,vf15y 	nop
  36c100:	3c 03 00 80 0a 94 ef 01 	maddz.xyzw vf16xyzw,vf18xyzw,vf15z 	nop
  36c108:	3c 03 00 80 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	nop
  36c110:	00 00 fe 42 bc 08 ec 81 	maddax[i].xyzw accxyzw,vf01xyzw,vf12x 	loi 127

0036c118 <_$LLOOP1>:
  36c118:	3c 03 00 80 bd 10 ec 01 	madday.xyzw accxyzw,vf02xyzw,vf12y 	nop
  36c120:	5b 00 f4 01 10 84 e0 01 	maxx.xyzw vf16xyzw,vf16xyzw,vf00x 	lq.xyzw vf20xyzw,91(vi00)
  36c128:	5c 00 f5 01 8a 1a ec 01 	maddz.xyzw vf10xyzw,vf03xyzw,vf12z 	lq.xyzw vf21xyzw,92(vi00)
  36c130:	5d 00 f6 01 ff 02 00 00 	nop 	lq.xyzw vf22xyzw,93(vi00)
  36c138:	5e 00 f7 01 ff 02 00 00 	nop 	lq.xyzw vf23xyzw,94(vi00)
  36c140:	3c 03 00 80 bc a1 f0 01 	mulax.xyzw accxyzw,vf20xyzw,vf16x 	nop
  36c148:	3c 03 00 80 bd a8 f0 01 	madday.xyzw accxyzw,vf21xyzw,vf16y 	nop
  36c150:	fc 63 63 80 be b0 f0 01 	maddaz.xyzw accxyzw,vf22xyzw,vf16z 	mtir vi03,vf12w
  36c158:	3c 63 27 80 4b bb d0 01 	maddw.xyz vf13xyz,vf23xyz,vf16w 	move.w vf07w,vf12w
  36c160:	48 30 ee 01 5d 03 20 00 	maxi.w vf13w,vf00w,i 	lq.xyzw vf14xyzw,72(vi06)
  36c168:	bc 03 ea 81 3c 30 e0 01 	addax.xyzw accxyzw,vf06xyzw,vf00x 	div q,vf00w,vf00x
  36c170:	3c 03 00 80 ff 51 ca 01 	clipw.xyz vf10xyz,vf10w 	nop
  36c178:	91 30 ef 01 5e 6b c0 01 	muli.xyz vf13xyz,vf13xyz,i 	lq.xyzw vf15xyzw,145(vi06)
  36c180:	01 30 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,1(vi06)
  36c188:	67 00 f0 01 ea 51 c5 01 	mul.xyz vf07xyz,vf10xyz,vf05xyz 	lq.xyzw vf16xyzw,103(vi00)
  36c190:	ef fb 02 24 ff 02 00 00 	nop 	fcand vi01,0x2fbef
  36c198:	03 20 04 10 5f 6b e0 01 	minii.xyzw vf13xyzw,vf13xyzw,i 	iaddiu vi04,vi04,3
  36c1a0:	3c 03 00 80 5c 77 e0 01 	mulq.xyzw vf29xyzw,vf14xyzw,q 	nop
  36c1a8:	3c 03 00 80 e1 39 c0 01 	maddq.xyz vf07xyz,vf07xyz,q 	nop
  36c1b0:	01 30 06 10 bf 99 e0 01 	mulaw.xyzw accxyzw,vf19xyzw,vf00w 	iaddiu vi06,vi06,1
  36c1b8:	3c 03 00 80 7c 69 ed 01 	ftoi0.xyzw vf13xyzw,vf13xyzw 	nop
  36c1c0:	fd ef e4 03 bc 80 ef 01 	maddax.xyzw accxyzw,vf16xyzw,vf15x 	sq.xyzw vf29xyzw,-3(vi04)
  36c1c8:	3c 03 00 80 7d 39 c7 01 	ftoi4.xyz vf07xyz,vf07xyz 	nop
  36c1d0:	06 08 00 5a bd 88 ef 01 	madday.xyzw accxyzw,vf17xyzw,vf15y 	ibgtz vi01,36c208 <_$LXYZ3>
  36c1d8:	fe 6f e4 03 0a 94 ef 01 	maddz.xyzw vf16xyzw,vf18xyzw,vf15z 	sq.xyzw vf13xyzw,-2(vi04)

0036c1e0 <_$LNEXTV>:
  36c1e0:	e6 5f 06 52 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	ibne vi06,vi11,36c118 <_$LLOOP1>
  36c1e8:	ff 3f e4 03 bc 08 ec 01 	maddax.xyzw accxyzw,vf01xyzw,vf12x 	sq.xyzw vf07xyzw,-1(vi04)
  36c1f0:	e1 10 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi02,0xe1
  36c1f8:	fc 1e 00 80 ff 02 00 40 	nop[e] 	xgkick vi03
  36c200:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036c208 <_$LXYZ3>:
  36c208:	fa 1f 00 58 ff 02 00 00 	nop 	ibltz vi03,36c1e0 <_$LNEXTV>
  36c210:	7d df ff 26 ff 02 00 00 	nop 	fcor vi01,0xffdf7d
  36c218:	22 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36c330 <_$LCULL>
  36c220:	be ef ff 26 ff 02 00 00 	nop 	fcor vi01,0xffefbe
  36c228:	20 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36c330 <_$LCULL>
  36c230:	df f7 fd 26 ff 02 00 00 	nop 	fcor vi01,0xfdf7df
  36c238:	1e 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36c330 <_$LCULL>
  36c240:	ef fb fe 26 ff 02 00 00 	nop 	fcor vi01,0xfefbef
  36c248:	1c 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36c330 <_$LCULL>
  36c250:	f7 7d ff 26 ff 02 00 00 	nop 	fcor vi01,0xff7df7
  36c258:	1a 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36c330 <_$LCULL>
  36c260:	fb be ff 26 ff 02 00 00 	nop 	fcor vi01,0xffbefb
  36c268:	18 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36c330 <_$LCULL>
  36c270:	62 00 82 0a ff 02 00 00 	nop 	isw.y vi02,98(vi00)y
  36c278:	62 00 24 0a ff 02 00 00 	nop 	isw.w vi04,98(vi00)w
  36c280:	60 00 4b 0a ff 02 00 00 	nop 	isw.z vi11,96(vi00)z
  36c288:	18 00 0f 42 ff 02 00 00 	nop 	bal vi15,36c350 <_$LCLIPPEDPOLY>
  36c290:	61 00 86 0a ff 02 00 00 	nop 	isw.y vi06,97(vi00)y
  36c298:	61 00 86 08 ff 02 00 00 	nop 	ilw.y vi06,97(vi00)y
  36c2a0:	60 00 4b 08 ff 02 00 00 	nop 	ilw.z vi11,96(vi00)z
  36c2a8:	62 00 24 08 ff 02 00 00 	nop 	ilw.w vi04,98(vi00)w
  36c2b0:	62 00 82 08 ff 02 00 00 	nop 	ilw.y vi02,98(vi00)y
  36c2b8:	fe 37 e8 01 ff 02 00 00 	nop 	lq.xyzw vf08xyzw,-2(vi06)
  36c2c0:	ff 37 e9 01 ff 02 00 00 	nop 	lq.xyzw vf09xyzw,-1(vi06)
  36c2c8:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36c2d0:	3c 03 00 80 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	nop
  36c2d8:	3c 03 00 80 bc 08 e8 01 	maddax.xyzw accxyzw,vf01xyzw,vf08x 	nop
  36c2e0:	3c 03 00 80 bd 10 e8 01 	madday.xyzw accxyzw,vf02xyzw,vf08y 	nop
  36c2e8:	3c 03 00 80 0a 1a e8 01 	maddz.xyzw vf08xyzw,vf03xyzw,vf08z 	nop
  36c2f0:	3c 03 00 80 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	nop
  36c2f8:	00 30 ec 01 bc 08 e9 01 	maddax.xyzw accxyzw,vf01xyzw,vf09x 	lq.xyzw vf12xyzw,0(vi06)
  36c300:	48 30 ee 01 bd 10 e9 01 	madday.xyzw accxyzw,vf02xyzw,vf09y 	lq.xyzw vf14xyzw,72(vi06)
  36c308:	90 30 ef 01 4a 1a e9 01 	maddz.xyzw vf09xyzw,vf03xyzw,vf09z 	lq.xyzw vf15xyzw,144(vi06)
  36c310:	67 00 f0 01 ff 02 00 00 	nop 	lq.xyzw vf16xyzw,103(vi00)
  36c318:	68 00 f1 01 ff 02 00 00 	nop 	lq.xyzw vf17xyzw,104(vi00)
  36c320:	69 00 f2 01 ff 41 c8 01 	clipw.xyz vf08xyz,vf08w 	lq.xyzw vf18xyzw,105(vi00)
  36c328:	6a 00 f3 01 ff 49 c9 01 	clipw.xyz vf09xyz,vf09w 	lq.xyzw vf19xyzw,106(vi00)

0036c330 <_$LCULL>:
  36c330:	3c 03 00 80 bc 81 e0 01 	mulax.xyzw accxyzw,vf16xyzw,vf00x 	nop
  36c338:	01 00 01 12 bd 88 ef 01 	madday.xyzw accxyzw,vf17xyzw,vf15y 	isubiu vi01,vi00,1
  36c340:	d3 07 00 40 be 90 ef 01 	maddaz.xyzw accxyzw,vf18xyzw,vf15z 	b 36c1e0 <_$LNEXTV>
  36c348:	fd 0b 27 80 0b 9c ef 01 	maddw.xyzw vf16xyzw,vf19xyzw,vf15w 	mfir.w vf07w,vi01

0036c350 <_$LCLIPPEDPOLY>:
  36c350:	fe 37 ef 01 ff 02 00 00 	nop 	lq.xyzw vf15xyzw,-2(vi06)
  36c358:	fd 37 ee 01 ff 02 00 00 	nop 	lq.xyzw vf14xyzw,-3(vi06)
  36c360:	2b 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x2b
  36c368:	3c 53 f0 81 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	move.xyzw vf16xyzw,vf10xyzw
  36c370:	3c 03 00 80 bc 08 ef 01 	maddax.xyzw accxyzw,vf01xyzw,vf15x 	nop
  36c378:	3c 03 00 80 bd 10 ef 01 	madday.xyzw accxyzw,vf02xyzw,vf15y 	nop
  36c380:	3c 03 00 80 ca 1b ef 01 	maddz.xyzw vf15xyzw,vf03xyzw,vf15z 	nop
  36c388:	3c 03 00 80 bf 21 e0 01 	mulaw.xyzw accxyzw,vf04xyzw,vf00w 	nop
  36c390:	3c 03 00 80 bc 08 ee 01 	maddax.xyzw accxyzw,vf01xyzw,vf14x 	nop
  36c398:	f8 27 f2 01 bd 10 ee 01 	madday.xyzw accxyzw,vf02xyzw,vf14y 	lq.xyzw vf18xyzw,-8(vi04)
  36c3a0:	fb 27 f3 01 8a 1b ee 01 	maddz.xyzw vf14xyzw,vf03xyzw,vf14z 	lq.xyzw vf19xyzw,-5(vi04)
  36c3a8:	fe 27 f4 01 2c 78 f0 01 	sub.xyzw vf00xyzw,vf15xyzw,vf16xyzw 	lq.xyzw vf20xyzw,-2(vi04)
  36c3b0:	40 00 02 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x40
  36c3b8:	45 30 eb 01 3c 91 f2 01 	itof0.xyzw vf18xyzw,vf18xyzw 	lq.xyzw vf11xyzw,69(vi06)
  36c3c0:	46 30 ec 01 3c 99 f3 01 	itof0.xyzw vf19xyzw,vf19xyzw 	lq.xyzw vf12xyzw,70(vi06)
  36c3c8:	00 10 01 34 2c 70 ef 01 	sub.xyzw vf00xyzw,vf14xyzw,vf15xyzw 	fmand vi01,vi02
  36c3d0:	0b 08 02 52 3c a1 f4 01 	itof0.xyzw vf20xyzw,vf20xyzw 	ibne vi02,vi01,36c430 <_$LNOSWP1>
  36c3d8:	47 30 ed 01 ff 02 00 00 	nop 	lq.xyzw vf13xyzw,71(vi06)

0036c3e0 <_$LSWP1>:
  36c3e0:	3c 7b f1 81 ff 02 00 00 	nop 	move.xyzw vf17xyzw,vf15xyzw
  36c3e8:	3c 83 ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf16xyzw
  36c3f0:	3c 63 f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf12xyzw
  36c3f8:	3c 6b ec 81 ff 02 00 00 	nop 	move.xyzw vf12xyzw,vf13xyzw
  36c400:	3c 9b ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf19xyzw
  36c408:	3c a3 f3 81 ff 02 00 00 	nop 	move.xyzw vf19xyzw,vf20xyzw
  36c410:	3c 6b f4 81 ff 02 00 00 	nop 	move.xyzw vf20xyzw,vf13xyzw
  36c418:	3c 83 ed 81 2c 70 ef 01 	sub.xyzw vf00xyzw,vf14xyzw,vf15xyzw 	move.xyzw vf13xyzw,vf16xyzw
  36c420:	3c 8b f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf17xyzw
  36c428:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036c430 <_$LNOSWP1>:
  36c430:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36c438:	00 10 01 34 2c 78 f0 01 	sub.xyzw vf00xyzw,vf15xyzw,vf16xyzw 	fmand vi01,vi02
  36c440:	0a 08 02 52 ff 02 00 00 	nop 	ibne vi02,vi01,36c498 <_$LNOSWP2>

0036c448 <_$LSWP2>:
  36c448:	3c 7b f1 81 ff 02 00 00 	nop 	move.xyzw vf17xyzw,vf15xyzw
  36c450:	3c 73 ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf14xyzw
  36c458:	3c 63 ee 81 ff 02 00 00 	nop 	move.xyzw vf14xyzw,vf12xyzw
  36c460:	3c 5b ec 81 ff 02 00 00 	nop 	move.xyzw vf12xyzw,vf11xyzw
  36c468:	3c 9b eb 81 ff 02 00 00 	nop 	move.xyzw vf11xyzw,vf19xyzw
  36c470:	3c 93 f3 81 ff 02 00 00 	nop 	move.xyzw vf19xyzw,vf18xyzw
  36c478:	3c 5b f2 81 ff 02 00 00 	nop 	move.xyzw vf18xyzw,vf11xyzw
  36c480:	3c 73 eb 81 ff 02 00 00 	nop 	move.xyzw vf11xyzw,vf14xyzw
  36c488:	3c 8b ee 81 2c 78 f0 01 	sub.xyzw vf00xyzw,vf15xyzw,vf16xyzw 	move.xyzw vf14xyzw,vf17xyzw
  36c490:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036c498 <_$LNOSWP2>:
  36c498:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36c4a0:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36c4a8:	00 10 01 34 ff 02 00 00 	nop 	fmand vi01,vi02
  36c4b0:	09 08 02 52 ff 02 00 00 	nop 	ibne vi02,vi01,36c500 <_$LNOSWP3>

0036c4b8 <_$LSWP3>:
  36c4b8:	3c 7b f1 81 ff 02 00 00 	nop 	move.xyzw vf17xyzw,vf15xyzw
  36c4c0:	3c 83 ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf16xyzw
  36c4c8:	3c 63 f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf12xyzw
  36c4d0:	3c 6b ec 81 ff 02 00 00 	nop 	move.xyzw vf12xyzw,vf13xyzw
  36c4d8:	3c 9b ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf19xyzw
  36c4e0:	3c a3 f3 81 ff 02 00 00 	nop 	move.xyzw vf19xyzw,vf20xyzw
  36c4e8:	3c 6b f4 81 ff 02 00 00 	nop 	move.xyzw vf20xyzw,vf13xyzw
  36c4f0:	3c 83 ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf16xyzw
  36c4f8:	3c 8b f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf17xyzw

0036c500 <_$LNOSWP3>:
  36c500:	00 70 e9 03 ff 02 00 00 	nop 	sq.xyzw vf14xyzw,0(vi09)
  36c508:	01 90 e9 03 ff 02 00 00 	nop 	sq.xyzw vf18xyzw,1(vi09)
  36c510:	02 58 e9 03 ff 02 00 00 	nop 	sq.xyzw vf11xyzw,2(vi09)
  36c518:	03 78 e9 03 ff 02 00 00 	nop 	sq.xyzw vf15xyzw,3(vi09)
  36c520:	04 98 e9 03 ff 02 00 00 	nop 	sq.xyzw vf19xyzw,4(vi09)
  36c528:	05 60 e9 03 ff 02 00 00 	nop 	sq.xyzw vf12xyzw,5(vi09)
  36c530:	06 80 e9 03 ff 02 00 00 	nop 	sq.xyzw vf16xyzw,6(vi09)
  36c538:	07 a0 e9 03 ff 02 00 00 	nop 	sq.xyzw vf20xyzw,7(vi09)
  36c540:	08 68 e9 03 ff 02 00 00 	nop 	sq.xyzw vf13xyzw,8(vi09)
  36c548:	09 70 e9 03 ff 02 00 00 	nop 	sq.xyzw vf14xyzw,9(vi09)
  36c550:	0a 90 e9 03 ff 02 00 00 	nop 	sq.xyzw vf18xyzw,10(vi09)
  36c558:	df 04 00 40 ff 02 00 00 	nop 	b 36ac58 <_$OLOOPZ1+0x8>
  36c560:	0b 58 e9 03 ff 02 00 00 	nop 	sq.xyzw vf11xyzw,11(vi09)

0036c568 <.vif.96>:
  36c568:	00 00 00 00 	vifnop
  36c56c:	e8 03 ab 4a 	mpg 0x3e8,0xab

0036c570 <_$START_LITFILLET>:
  36c570:	bc 06 02 80 d8 ff e0 01 	mulx.xyzw vf31xyzw,vf31xyzw,vf00x 	xtop vi02
  36c578:	e1 10 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi02,0xe1
  36c580:	01 10 e7 01 ff 02 00 00 	nop 	lq.xyzw vf07xyzw,1(vi02)
  36c588:	02 10 e8 01 ff 02 00 00 	nop 	lq.xyzw vf08xyzw,2(vi02)
  36c590:	03 10 e9 01 ff 02 00 00 	nop 	lq.xyzw vf09xyzw,3(vi02)
  36c598:	04 10 ea 01 ff 02 00 00 	nop 	lq.xyzw vf10xyzw,4(vi02)
  36c5a0:	05 10 eb 01 ff 02 00 00 	nop 	lq.xyzw vf11xyzw,5(vi02)
  36c5a8:	06 10 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,6(vi02)
  36c5b0:	7d 3b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf07xyzw,(vi04++)
  36c5b8:	7d 43 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf08xyzw,(vi04++)
  36c5c0:	7d 4b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf09xyzw,(vi04++)
  36c5c8:	7d 53 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf10xyzw,(vi04++)
  36c5d0:	7d 5b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf11xyzw,(vi04++)
  36c5d8:	7d 63 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf12xyzw,(vi04++)
  36c5e0:	08 10 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi02,8
  36c5e8:	00 10 fd 01 ff 02 00 00 	nop 	lq.xyzw vf29xyzw,0(vi02)
  36c5f0:	00 10 0b 09 ff 02 00 00 	nop 	ilw.x vi11,0(vi02)x
  36c5f8:	00 00 fe 42 ff 02 00 80 	nop[i] 	loi 127
  36c600:	00 00 00 22 ff 02 00 00 	nop 	fcset 0
  36c608:	7d eb e4 81 ff 02 00 00 	nop 	sqi.xyzw vf29xyzw,(vi04++)
  36c610:	90 30 ef 01 ff 02 00 00 	nop 	lq.xyzw vf15xyzw,144(vi06)
  36c618:	00 30 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,0(vi06)
  36c620:	3c 03 e8 81 ff 02 00 00 	nop 	move.xyzw vf08xyzw,vf00xyzw
  36c628:	3c 03 e9 81 ff 02 00 00 	nop 	move.xyzw vf09xyzw,vf00xyzw
  36c630:	fc 7b 6d 80 ff 02 00 00 	nop 	mtir vi13,vf15w
  36c638:	ff 07 e1 11 ff 02 00 00 	nop 	iaddiu vi01,vi00,0x7fff
  36c640:	f4 5a 01 80 ff 02 00 00 	nop 	iand vi11,vi11,vi01
  36c648:	f0 5a 06 80 ff 02 00 00 	nop 	iadd vi11,vi11,vi06
  36c650:	67 68 f0 01 ff 02 00 00 	nop 	lq.xyzw vf16xyzw,103(vi13)
  36c658:	68 68 f1 01 ff 02 00 00 	nop 	lq.xyzw vf17xyzw,104(vi13)
  36c660:	69 68 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,105(vi13)
  36c668:	6a 68 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,106(vi13)

0036c670 <_$LFLOOP1>:
  36c670:	63 68 e1 01 bc 81 ef 01 	mulax.xyzw accxyzw,vf16xyzw,vf15x 	lq.xyzw vf01xyzw,99(vi13)
  36c678:	64 68 e2 01 bd 88 ef 01 	madday.xyzw accxyzw,vf17xyzw,vf15y 	lq.xyzw vf02xyzw,100(vi13)
  36c680:	65 68 e3 01 be 90 ef 01 	maddaz.xyzw accxyzw,vf18xyzw,vf15z 	lq.xyzw vf03xyzw,101(vi13)
  36c688:	66 68 e4 01 0b 9c e0 01 	maddw.xyzw vf16xyzw,vf19xyzw,vf00w 	lq.xyzw vf04xyzw,102(vi13)
  36c690:	3c 4b e8 81 bc 09 ec 01 	mulax.xyzw accxyzw,vf01xyzw,vf12x 	move.xyzw vf08xyzw,vf09xyzw
  36c698:	3c 53 e9 81 bd 10 ec 01 	madday.xyzw accxyzw,vf02xyzw,vf12y 	move.xyzw vf09xyzw,vf10xyzw
  36c6a0:	48 30 ee 01 be 18 ec 01 	maddaz.xyzw accxyzw,vf03xyzw,vf12z 	lq.xyzw vf14xyzw,72(vi06)
  36c6a8:	91 30 ef 01 8b 22 e0 01 	maddw.xyzw vf10xyzw,vf04xyzw,vf00w 	lq.xyzw vf15xyzw,145(vi06)
  36c6b0:	5b 00 f4 01 10 84 e0 01 	maxx.xyzw vf16xyzw,vf16xyzw,vf00x 	lq.xyzw vf20xyzw,91(vi00)
  36c6b8:	5c 00 f5 01 ff 41 c8 01 	clipw.xyz vf08xyz,vf08w 	lq.xyzw vf21xyzw,92(vi00)
  36c6c0:	5d 00 f6 01 ff 49 c9 01 	clipw.xyz vf09xyz,vf09w 	lq.xyzw vf22xyzw,93(vi00)
  36c6c8:	bc 03 ea 81 ea 51 c5 01 	mul.xyz vf07xyz,vf10xyz,vf05xyz 	div q,vf00w,vf00x
  36c6d0:	5e 00 f7 01 ff 51 ca 01 	clipw.xyz vf10xyz,vf10w 	lq.xyzw vf23xyzw,94(vi00)
  36c6d8:	fc 7b 6d 80 bc a1 f0 01 	mulax.xyzw accxyzw,vf20xyzw,vf16x 	mtir vi13,vf15w
  36c6e0:	fc 63 63 80 bd a8 f0 01 	madday.xyzw accxyzw,vf21xyzw,vf16y 	mtir vi03,vf12w
  36c6e8:	3c 63 27 80 be b0 f0 01 	maddaz.xyzw accxyzw,vf22xyzw,vf16z 	move.w vf07w,vf12w
  36c6f0:	ef fb 02 24 4b bb d0 01 	maddw.xyz vf13xyz,vf23xyz,vf16w 	fcand vi01,0x2fbef
  36c6f8:	3c 03 00 80 5d 03 20 00 	maxi.w vf13w,vf00w,i 	nop
  36c700:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36c708:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36c710:	3c 03 00 80 5e 6b c0 01 	muli.xyz vf13xyz,vf13xyz,i 	nop
  36c718:	01 30 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi06,1
  36c720:	03 20 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi04,3
  36c728:	00 30 ec 01 3c 30 e0 01 	addax.xyzw accxyzw,vf06xyzw,vf00x 	lq.xyzw vf12xyzw,0(vi06)
  36c730:	3c 03 00 80 1f 6d e0 01 	minii.xyzw vf20xyzw,vf13xyzw,i 	nop
  36c738:	3c 03 00 80 5c 77 e0 01 	mulq.xyzw vf29xyzw,vf14xyzw,q 	nop
  36c740:	67 68 f0 01 e1 39 c0 01 	maddq.xyz vf07xyz,vf07xyz,q 	lq.xyzw vf16xyzw,103(vi13)
  36c748:	68 68 f1 01 ff 02 00 00 	nop 	lq.xyzw vf17xyzw,104(vi13)
  36c750:	69 68 f2 01 7c a1 f4 01 	ftoi0.xyzw vf20xyzw,vf20xyzw 	lq.xyzw vf18xyzw,105(vi13)
  36c758:	6a 68 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,106(vi13)
  36c760:	fd ef e4 03 7d 39 c7 01 	ftoi4.xyz vf07xyz,vf07xyz 	sq.xyzw vf29xyzw,-3(vi04)
  36c768:	0a 08 00 5a ff 02 00 00 	nop 	ibgtz vi01,36c7c0 <_$LFXYZ3>
  36c770:	fe a7 e4 03 ff 02 00 00 	nop 	sq.xyzw vf20xyzw,-2(vi04)

0036c778 <_$LFNEXTV>:
  36c778:	de 5f 06 52 ff 02 00 00 	nop 	ibne vi06,vi11,36c670 <_$LFLOOP1>
  36c780:	ff 3f e4 03 ff 02 00 00 	nop 	sq.xyzw vf07xyzw,-1(vi04)
  36c788:	63 00 e1 01 ff 02 00 00 	nop 	lq.xyzw vf01xyzw,99(vi00)
  36c790:	64 00 e2 01 ff 02 00 00 	nop 	lq.xyzw vf02xyzw,100(vi00)
  36c798:	65 00 e3 01 ff 02 00 00 	nop 	lq.xyzw vf03xyzw,101(vi00)
  36c7a0:	66 00 e4 01 ff 02 00 00 	nop 	lq.xyzw vf04xyzw,102(vi00)
  36c7a8:	e1 10 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi02,0xe1
  36c7b0:	fc 1e 00 80 ff 02 00 40 	nop[e] 	xgkick vi03
  36c7b8:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036c7c0 <_$LFXYZ3>:
  36c7c0:	f6 1f 00 58 ff 02 00 00 	nop 	ibltz vi03,36c778 <_$LFNEXTV>
  36c7c8:	7d df ff 26 ff 02 00 00 	nop 	fcor vi01,0xffdf7d
  36c7d0:	1e 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36c8c8 <_$LFCULL>
  36c7d8:	be ef ff 26 ff 02 00 00 	nop 	fcor vi01,0xffefbe
  36c7e0:	1c 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36c8c8 <_$LFCULL>
  36c7e8:	df f7 fd 26 ff 02 00 00 	nop 	fcor vi01,0xfdf7df
  36c7f0:	1a 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36c8c8 <_$LFCULL>
  36c7f8:	ef fb fe 26 ff 02 00 00 	nop 	fcor vi01,0xfefbef
  36c800:	18 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36c8c8 <_$LFCULL>
  36c808:	f7 7d ff 26 ff 02 00 00 	nop 	fcor vi01,0xff7df7
  36c810:	16 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36c8c8 <_$LFCULL>
  36c818:	fb be ff 26 ff 02 00 00 	nop 	fcor vi01,0xffbefb
  36c820:	14 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36c8c8 <_$LFCULL>
  36c828:	62 00 82 0a ff 02 00 00 	nop 	isw.y vi02,98(vi00)y
  36c830:	62 00 24 0a ff 02 00 00 	nop 	isw.w vi04,98(vi00)w
  36c838:	61 00 86 0a ff 02 00 00 	nop 	isw.y vi06,97(vi00)y
  36c840:	13 00 0f 42 ff 02 00 00 	nop 	bal vi15,36c8e0 <_$LFCLIPPEDPOLY>
  36c848:	60 00 4b 0a ff 02 00 00 	nop 	isw.z vi11,96(vi00)z
  36c850:	61 00 86 08 ff 02 00 00 	nop 	ilw.y vi06,97(vi00)y
  36c858:	60 00 4b 08 ff 02 00 00 	nop 	ilw.z vi11,96(vi00)z
  36c860:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36c868:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36c870:	90 30 ef 01 ff 02 00 00 	nop 	lq.xyzw vf15xyzw,144(vi06)
  36c878:	62 00 24 08 ff 02 00 00 	nop 	ilw.w vi04,98(vi00)w
  36c880:	62 00 82 08 ff 02 00 00 	nop 	ilw.y vi02,98(vi00)y
  36c888:	00 30 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,0(vi06)
  36c890:	fc 7b 6d 80 ff 02 00 00 	nop 	mtir vi13,vf15w
  36c898:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36c8a0:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36c8a8:	67 68 f0 01 ff 02 00 00 	nop 	lq.xyzw vf16xyzw,103(vi13)
  36c8b0:	68 68 f1 01 ff 02 00 00 	nop 	lq.xyzw vf17xyzw,104(vi13)
  36c8b8:	69 68 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,105(vi13)
  36c8c0:	6a 68 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,106(vi13)

0036c8c8 <_$LFCULL>:
  36c8c8:	01 00 01 12 ff 02 00 00 	nop 	isubiu vi01,vi00,1
  36c8d0:	d4 07 00 40 ff 02 00 00 	nop 	b 36c778 <_$LFNEXTV>
  36c8d8:	fd 0b 27 80 ff 02 00 00 	nop 	mfir.w vf07w,vi01

0036c8e0 <_$LFCLIPPEDPOLY>:
  36c8e0:	2b 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x2b
  36c8e8:	3c 53 f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf10xyzw
  36c8f0:	3c 4b ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf09xyzw
  36c8f8:	3c 43 ee 81 ff 02 00 00 	nop 	move.xyzw vf14xyzw,vf08xyzw
  36c900:	f8 27 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,-8(vi04)
  36c908:	fb 27 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,-5(vi04)
  36c910:	fe 27 f4 01 2c 78 f0 01 	sub.xyzw vf00xyzw,vf15xyzw,vf16xyzw 	lq.xyzw vf20xyzw,-2(vi04)
  36c918:	40 00 02 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x40
  36c920:	45 30 eb 01 3c 91 f2 01 	itof0.xyzw vf18xyzw,vf18xyzw 	lq.xyzw vf11xyzw,69(vi06)
  36c928:	46 30 ec 01 3c 99 f3 01 	itof0.xyzw vf19xyzw,vf19xyzw 	lq.xyzw vf12xyzw,70(vi06)
  36c930:	00 10 01 34 2c 70 ef 01 	sub.xyzw vf00xyzw,vf14xyzw,vf15xyzw 	fmand vi01,vi02
  36c938:	0b 08 02 52 3c a1 f4 01 	itof0.xyzw vf20xyzw,vf20xyzw 	ibne vi02,vi01,36c998 <_$LFNOSWP1>
  36c940:	47 30 ed 01 ff 02 00 00 	nop 	lq.xyzw vf13xyzw,71(vi06)

0036c948 <_$LFSWP1>:
  36c948:	3c 7b f1 81 ff 02 00 00 	nop 	move.xyzw vf17xyzw,vf15xyzw
  36c950:	3c 83 ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf16xyzw
  36c958:	3c 63 f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf12xyzw
  36c960:	3c 6b ec 81 ff 02 00 00 	nop 	move.xyzw vf12xyzw,vf13xyzw
  36c968:	3c 9b ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf19xyzw
  36c970:	3c a3 f3 81 ff 02 00 00 	nop 	move.xyzw vf19xyzw,vf20xyzw
  36c978:	3c 6b f4 81 ff 02 00 00 	nop 	move.xyzw vf20xyzw,vf13xyzw
  36c980:	3c 83 ed 81 2c 70 ef 01 	sub.xyzw vf00xyzw,vf14xyzw,vf15xyzw 	move.xyzw vf13xyzw,vf16xyzw
  36c988:	3c 8b f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf17xyzw
  36c990:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036c998 <_$LFNOSWP1>:
  36c998:	3c 03 00 80 2c 78 f1 01 	sub.xyzw vf00xyzw,vf15xyzw,vf17xyzw 	nop
  36c9a0:	00 10 01 34 ff 02 00 00 	nop 	fmand vi01,vi02
  36c9a8:	0a 08 02 52 ff 02 00 00 	nop 	ibne vi02,vi01,36ca00 <_$LFNOSWP2>

0036c9b0 <_$LFSWP2>:
  36c9b0:	3c 7b f1 81 ff 02 00 00 	nop 	move.xyzw vf17xyzw,vf15xyzw
  36c9b8:	3c 73 ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf14xyzw
  36c9c0:	3c 63 ee 81 ff 02 00 00 	nop 	move.xyzw vf14xyzw,vf12xyzw
  36c9c8:	3c 5b ec 81 ff 02 00 00 	nop 	move.xyzw vf12xyzw,vf11xyzw
  36c9d0:	3c 9b eb 81 ff 02 00 00 	nop 	move.xyzw vf11xyzw,vf19xyzw
  36c9d8:	3c 93 f3 81 ff 02 00 00 	nop 	move.xyzw vf19xyzw,vf18xyzw
  36c9e0:	3c 5b f2 81 ff 02 00 00 	nop 	move.xyzw vf18xyzw,vf11xyzw
  36c9e8:	3c 73 eb 81 2c 78 f0 01 	sub.xyzw vf00xyzw,vf15xyzw,vf16xyzw 	move.xyzw vf11xyzw,vf14xyzw
  36c9f0:	3c 8b ee 81 ff 02 00 00 	nop 	move.xyzw vf14xyzw,vf17xyzw
  36c9f8:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036ca00 <_$LFNOSWP2>:
  36ca00:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36ca08:	00 10 01 34 ff 02 00 00 	nop 	fmand vi01,vi02
  36ca10:	09 08 02 52 ff 02 00 00 	nop 	ibne vi02,vi01,36ca60 <_$LFNOSWP3>

0036ca18 <_$LFSWP3>:
  36ca18:	3c 7b f1 81 ff 02 00 00 	nop 	move.xyzw vf17xyzw,vf15xyzw
  36ca20:	3c 83 ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf16xyzw
  36ca28:	3c 63 f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf12xyzw
  36ca30:	3c 6b ec 81 ff 02 00 00 	nop 	move.xyzw vf12xyzw,vf13xyzw
  36ca38:	3c 9b ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf19xyzw
  36ca40:	3c a3 f3 81 ff 02 00 00 	nop 	move.xyzw vf19xyzw,vf20xyzw
  36ca48:	3c 6b f4 81 ff 02 00 00 	nop 	move.xyzw vf20xyzw,vf13xyzw
  36ca50:	3c 83 ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf16xyzw
  36ca58:	3c 8b f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf17xyzw

0036ca60 <_$LFNOSWP3>:
  36ca60:	00 70 e9 03 ff 02 00 00 	nop 	sq.xyzw vf14xyzw,0(vi09)
  36ca68:	01 90 e9 03 ff 02 00 00 	nop 	sq.xyzw vf18xyzw,1(vi09)
  36ca70:	02 58 e9 03 ff 02 00 00 	nop 	sq.xyzw vf11xyzw,2(vi09)
  36ca78:	03 78 e9 03 ff 02 00 00 	nop 	sq.xyzw vf15xyzw,3(vi09)
  36ca80:	04 98 e9 03 ff 02 00 00 	nop 	sq.xyzw vf19xyzw,4(vi09)
  36ca88:	05 60 e9 03 ff 02 00 00 	nop 	sq.xyzw vf12xyzw,5(vi09)
  36ca90:	06 80 e9 03 ff 02 00 00 	nop 	sq.xyzw vf16xyzw,6(vi09)
  36ca98:	07 a0 e9 03 ff 02 00 00 	nop 	sq.xyzw vf20xyzw,7(vi09)
  36caa0:	08 68 e9 03 ff 02 00 00 	nop 	sq.xyzw vf13xyzw,8(vi09)
  36caa8:	09 70 e9 03 ff 02 00 00 	nop 	sq.xyzw vf14xyzw,9(vi09)
  36cab0:	0a 90 e9 03 ff 02 00 00 	nop 	sq.xyzw vf18xyzw,10(vi09)
  36cab8:	19 04 00 40 ff 02 00 00 	nop 	b 36ab88 <_$SWP3+0x30>
  36cac0:	0b 58 e9 03 ff 02 00 00 	nop 	sq.xyzw vf11xyzw,11(vi09)

0036cac8 <.vif.111>:
  36cac8:	00 00 00 00 	vifnop
  36cacc:	b0 04 ac 4a 	mpg 0x4b0,0xac

0036cad0 <_$START_CUTSCENE>:
  36cad0:	bc 06 02 80 d8 ff e0 01 	mulx.xyzw vf31xyzw,vf31xyzw,vf00x 	xtop vi02
  36cad8:	bd 10 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi02,0xbd
  36cae0:	01 10 e7 01 ff 02 00 00 	nop 	lq.xyzw vf07xyzw,1(vi02)
  36cae8:	02 10 e8 01 ff 02 00 00 	nop 	lq.xyzw vf08xyzw,2(vi02)
  36caf0:	03 10 e9 01 ff 02 00 00 	nop 	lq.xyzw vf09xyzw,3(vi02)
  36caf8:	04 10 ea 01 ff 02 00 00 	nop 	lq.xyzw vf10xyzw,4(vi02)
  36cb00:	05 10 eb 01 ff 02 00 00 	nop 	lq.xyzw vf11xyzw,5(vi02)
  36cb08:	06 10 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,6(vi02)
  36cb10:	7d 3b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf07xyzw,(vi04++)
  36cb18:	7d 43 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf08xyzw,(vi04++)
  36cb20:	7d 4b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf09xyzw,(vi04++)
  36cb28:	7d 53 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf10xyzw,(vi04++)
  36cb30:	7d 5b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf11xyzw,(vi04++)
  36cb38:	7d 63 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf12xyzw,(vi04++)
  36cb40:	08 10 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi02,8
  36cb48:	00 10 fd 01 ff 02 00 00 	nop 	lq.xyzw vf29xyzw,0(vi02)
  36cb50:	00 10 0b 09 ff 02 00 00 	nop 	ilw.x vi11,0(vi02)x
  36cb58:	ff 07 e1 11 ff 02 00 00 	nop 	iaddiu vi01,vi00,0x7fff
  36cb60:	7d eb e4 81 ff 02 00 00 	nop 	sqi.xyzw vf29xyzw,(vi04++)
  36cb68:	f4 5a 01 80 ff 02 00 00 	nop 	iand vi11,vi11,vi01
  36cb70:	f0 5a 06 80 ff 02 00 00 	nop 	iadd vi11,vi11,vi06
  36cb78:	78 30 ef 01 ff 02 00 00 	nop 	lq.xyzw vf15xyzw,120(vi06)
  36cb80:	00 30 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,0(vi06)
  36cb88:	3c 03 e8 81 ff 02 00 00 	nop 	move.xyzw vf08xyzw,vf00xyzw
  36cb90:	3c 03 e9 81 ff 02 00 00 	nop 	move.xyzw vf09xyzw,vf00xyzw
  36cb98:	fc 7b 6d 80 ff 02 00 00 	nop 	mtir vi13,vf15w
  36cba0:	00 00 fe 42 ff 02 00 80 	nop[i] 	loi 127
  36cba8:	00 00 00 22 ff 02 00 00 	nop 	fcset 0
  36cbb0:	67 68 f0 01 ff 02 00 00 	nop 	lq.xyzw vf16xyzw,103(vi13)
  36cbb8:	68 68 f1 01 ff 02 00 00 	nop 	lq.xyzw vf17xyzw,104(vi13)
  36cbc0:	69 68 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,105(vi13)
  36cbc8:	6a 68 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,106(vi13)

0036cbd0 <_$CSLOOP1>:
  36cbd0:	63 68 e1 01 bc 81 ef 01 	mulax.xyzw accxyzw,vf16xyzw,vf15x 	lq.xyzw vf01xyzw,99(vi13)
  36cbd8:	64 68 e2 01 bd 88 ef 01 	madday.xyzw accxyzw,vf17xyzw,vf15y 	lq.xyzw vf02xyzw,100(vi13)
  36cbe0:	65 68 e3 01 be 90 ef 01 	maddaz.xyzw accxyzw,vf18xyzw,vf15z 	lq.xyzw vf03xyzw,101(vi13)
  36cbe8:	66 68 e4 01 0b 9c e0 01 	maddw.xyzw vf16xyzw,vf19xyzw,vf00w 	lq.xyzw vf04xyzw,102(vi13)
  36cbf0:	3c 4b e8 81 bc 09 ec 01 	mulax.xyzw accxyzw,vf01xyzw,vf12x 	move.xyzw vf08xyzw,vf09xyzw
  36cbf8:	3c 53 e9 81 bd 10 ec 01 	madday.xyzw accxyzw,vf02xyzw,vf12y 	move.xyzw vf09xyzw,vf10xyzw
  36cc00:	3c 30 ee 01 be 18 ec 01 	maddaz.xyzw accxyzw,vf03xyzw,vf12z 	lq.xyzw vf14xyzw,60(vi06)
  36cc08:	79 30 ef 01 8b 22 e0 01 	maddw.xyzw vf10xyzw,vf04xyzw,vf00w 	lq.xyzw vf15xyzw,121(vi06)
  36cc10:	5b 00 f4 01 10 84 e0 01 	maxx.xyzw vf16xyzw,vf16xyzw,vf00x 	lq.xyzw vf20xyzw,91(vi00)
  36cc18:	5c 00 f5 01 ff 41 c8 01 	clipw.xyz vf08xyz,vf08w 	lq.xyzw vf21xyzw,92(vi00)
  36cc20:	5d 00 f6 01 ff 49 c9 01 	clipw.xyz vf09xyz,vf09w 	lq.xyzw vf22xyzw,93(vi00)
  36cc28:	bc 03 ea 81 ea 51 c5 01 	mul.xyz vf07xyz,vf10xyz,vf05xyz 	div q,vf00w,vf00x
  36cc30:	5e 00 f7 01 ff 51 ca 01 	clipw.xyz vf10xyz,vf10w 	lq.xyzw vf23xyzw,94(vi00)
  36cc38:	fc 7b 6d 80 bc a1 f0 01 	mulax.xyzw accxyzw,vf20xyzw,vf16x 	mtir vi13,vf15w
  36cc40:	fc 63 63 80 bd a8 f0 01 	madday.xyzw accxyzw,vf21xyzw,vf16y 	mtir vi03,vf12w
  36cc48:	3c 63 27 80 be b0 f0 01 	maddaz.xyzw accxyzw,vf22xyzw,vf16z 	move.w vf07w,vf12w
  36cc50:	ef fb 02 24 4b bb d0 01 	maddw.xyz vf13xyz,vf23xyz,vf16w 	fcand vi01,0x2fbef
  36cc58:	3c 03 00 80 5d 03 20 00 	maxi.w vf13w,vf00w,i 	nop
  36cc60:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36cc68:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36cc70:	3c 03 00 80 5e 6b c0 01 	muli.xyz vf13xyz,vf13xyz,i 	nop
  36cc78:	01 30 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi06,1
  36cc80:	03 20 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi04,3
  36cc88:	00 30 ec 01 3c 30 e0 01 	addax.xyzw accxyzw,vf06xyzw,vf00x 	lq.xyzw vf12xyzw,0(vi06)
  36cc90:	3c 03 00 80 1f 6d e0 01 	minii.xyzw vf20xyzw,vf13xyzw,i 	nop
  36cc98:	3c 03 00 80 5c 77 e0 01 	mulq.xyzw vf29xyzw,vf14xyzw,q 	nop
  36cca0:	67 68 f0 01 e1 39 c0 01 	maddq.xyz vf07xyz,vf07xyz,q 	lq.xyzw vf16xyzw,103(vi13)
  36cca8:	68 68 f1 01 ff 02 00 00 	nop 	lq.xyzw vf17xyzw,104(vi13)
  36ccb0:	69 68 f2 01 7c a1 f4 01 	ftoi0.xyzw vf20xyzw,vf20xyzw 	lq.xyzw vf18xyzw,105(vi13)
  36ccb8:	6a 68 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,106(vi13)
  36ccc0:	fd ef e4 03 7d 39 c7 01 	ftoi4.xyz vf07xyz,vf07xyz 	sq.xyzw vf29xyzw,-3(vi04)
  36ccc8:	0a 08 00 5a ff 02 00 00 	nop 	ibgtz vi01,36cd20 <_$CSXYZ3>
  36ccd0:	fe a7 e4 03 ff 02 00 00 	nop 	sq.xyzw vf20xyzw,-2(vi04)

0036ccd8 <_$CSNEXTV>:
  36ccd8:	de 5f 06 52 ff 02 00 00 	nop 	ibne vi06,vi11,36cbd0 <_$CSLOOP1>
  36cce0:	ff 3f e4 03 ff 02 00 00 	nop 	sq.xyzw vf07xyzw,-1(vi04)
  36cce8:	63 00 e1 01 ff 02 00 00 	nop 	lq.xyzw vf01xyzw,99(vi00)
  36ccf0:	64 00 e2 01 ff 02 00 00 	nop 	lq.xyzw vf02xyzw,100(vi00)
  36ccf8:	65 00 e3 01 ff 02 00 00 	nop 	lq.xyzw vf03xyzw,101(vi00)
  36cd00:	66 00 e4 01 ff 02 00 00 	nop 	lq.xyzw vf04xyzw,102(vi00)
  36cd08:	bd 10 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi02,0xbd
  36cd10:	fc 1e 00 80 ff 02 00 40 	nop[e] 	xgkick vi03
  36cd18:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036cd20 <_$CSXYZ3>:
  36cd20:	f6 1f 00 58 ff 02 00 00 	nop 	ibltz vi03,36ccd8 <_$CSNEXTV>
  36cd28:	7d df ff 26 ff 02 00 00 	nop 	fcor vi01,0xffdf7d
  36cd30:	1f 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36ce30 <_$CSCULL>
  36cd38:	be ef ff 26 ff 02 00 00 	nop 	fcor vi01,0xffefbe
  36cd40:	1d 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36ce30 <_$CSCULL>
  36cd48:	df f7 fd 26 ff 02 00 00 	nop 	fcor vi01,0xfdf7df
  36cd50:	1b 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36ce30 <_$CSCULL>
  36cd58:	ef fb fe 26 ff 02 00 00 	nop 	fcor vi01,0xfefbef
  36cd60:	19 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36ce30 <_$CSCULL>
  36cd68:	f7 7d ff 26 ff 02 00 00 	nop 	fcor vi01,0xff7df7
  36cd70:	17 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36ce30 <_$CSCULL>
  36cd78:	fb be ff 26 ff 02 00 00 	nop 	fcor vi01,0xffbefb
  36cd80:	15 00 01 52 ff 02 00 00 	nop 	ibne vi01,vi00,36ce30 <_$CSCULL>
  36cd88:	62 00 82 0a ff 02 00 00 	nop 	isw.y vi02,98(vi00)y
  36cd90:	62 00 24 0a ff 02 00 00 	nop 	isw.w vi04,98(vi00)w
  36cd98:	61 00 86 0a ff 02 00 00 	nop 	isw.y vi06,97(vi00)y
  36cda0:	14 00 0f 42 ff 02 00 00 	nop 	bal vi15,36ce48 <_$CSCLIPPEDPOLY>
  36cda8:	60 00 4b 0a ff 02 00 00 	nop 	isw.z vi11,96(vi00)z
  36cdb0:	61 00 86 08 ff 02 00 00 	nop 	ilw.y vi06,97(vi00)y
  36cdb8:	60 00 4b 08 ff 02 00 00 	nop 	ilw.z vi11,96(vi00)z
  36cdc0:	62 00 24 08 ff 02 00 00 	nop 	ilw.w vi04,98(vi00)w
  36cdc8:	62 00 82 08 ff 02 00 00 	nop 	ilw.y vi02,98(vi00)y
  36cdd0:	78 30 ef 01 ff 02 00 00 	nop 	lq.xyzw vf15xyzw,120(vi06)
  36cdd8:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36cde0:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36cde8:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36cdf0:	fc 7b 6d 80 ff 02 00 00 	nop 	mtir vi13,vf15w
  36cdf8:	00 30 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,0(vi06)
  36ce00:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36ce08:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36ce10:	67 68 f0 01 ff 02 00 00 	nop 	lq.xyzw vf16xyzw,103(vi13)
  36ce18:	68 68 f1 01 ff 02 00 00 	nop 	lq.xyzw vf17xyzw,104(vi13)
  36ce20:	69 68 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,105(vi13)
  36ce28:	6a 68 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,106(vi13)

0036ce30 <_$CSCULL>:
  36ce30:	01 00 01 12 ff 02 00 00 	nop 	isubiu vi01,vi00,1
  36ce38:	d3 07 00 40 ff 02 00 00 	nop 	b 36ccd8 <_$CSNEXTV>
  36ce40:	fd 0b 27 80 ff 02 00 00 	nop 	mfir.w vf07w,vi01

0036ce48 <_$CSCLIPPEDPOLY>:
  36ce48:	2b 00 09 10 ff 02 00 00 	nop 	iaddiu vi09,vi00,0x2b
  36ce50:	3c 53 f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf10xyzw
  36ce58:	3c 4b ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf09xyzw
  36ce60:	3c 43 ee 81 ff 02 00 00 	nop 	move.xyzw vf14xyzw,vf08xyzw
  36ce68:	f8 27 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,-8(vi04)
  36ce70:	fb 27 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,-5(vi04)
  36ce78:	fe 27 f4 01 2c 78 f0 01 	sub.xyzw vf00xyzw,vf15xyzw,vf16xyzw 	lq.xyzw vf20xyzw,-2(vi04)
  36ce80:	40 00 02 10 ff 02 00 00 	nop 	iaddiu vi02,vi00,0x40
  36ce88:	39 30 eb 01 3c 91 f2 01 	itof0.xyzw vf18xyzw,vf18xyzw 	lq.xyzw vf11xyzw,57(vi06)
  36ce90:	3a 30 ec 01 3c 99 f3 01 	itof0.xyzw vf19xyzw,vf19xyzw 	lq.xyzw vf12xyzw,58(vi06)
  36ce98:	00 10 01 34 2c 70 ef 01 	sub.xyzw vf00xyzw,vf14xyzw,vf15xyzw 	fmand vi01,vi02
  36cea0:	0b 08 02 52 3c a1 f4 01 	itof0.xyzw vf20xyzw,vf20xyzw 	ibne vi02,vi01,36cf00 <_$CSNOSWP1>
  36cea8:	3b 30 ed 01 ff 02 00 00 	nop 	lq.xyzw vf13xyzw,59(vi06)

0036ceb0 <_$CSSWP1>:
  36ceb0:	3c 7b f1 81 ff 02 00 00 	nop 	move.xyzw vf17xyzw,vf15xyzw
  36ceb8:	3c 83 ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf16xyzw
  36cec0:	3c 63 f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf12xyzw
  36cec8:	3c 6b ec 81 ff 02 00 00 	nop 	move.xyzw vf12xyzw,vf13xyzw
  36ced0:	3c 9b ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf19xyzw
  36ced8:	3c a3 f3 81 ff 02 00 00 	nop 	move.xyzw vf19xyzw,vf20xyzw
  36cee0:	3c 6b f4 81 ff 02 00 00 	nop 	move.xyzw vf20xyzw,vf13xyzw
  36cee8:	3c 83 ed 81 2c 70 ef 01 	sub.xyzw vf00xyzw,vf14xyzw,vf15xyzw 	move.xyzw vf13xyzw,vf16xyzw
  36cef0:	3c 8b f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf17xyzw
  36cef8:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036cf00 <_$CSNOSWP1>:
  36cf00:	3c 03 00 80 2c 78 f1 01 	sub.xyzw vf00xyzw,vf15xyzw,vf17xyzw 	nop
  36cf08:	00 10 01 34 ff 02 00 00 	nop 	fmand vi01,vi02
  36cf10:	0a 08 02 52 ff 02 00 00 	nop 	ibne vi02,vi01,36cf68 <_$CSNOSWP2>

0036cf18 <_$CSSWP2>:
  36cf18:	3c 7b f1 81 ff 02 00 00 	nop 	move.xyzw vf17xyzw,vf15xyzw
  36cf20:	3c 73 ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf14xyzw
  36cf28:	3c 63 ee 81 ff 02 00 00 	nop 	move.xyzw vf14xyzw,vf12xyzw
  36cf30:	3c 5b ec 81 ff 02 00 00 	nop 	move.xyzw vf12xyzw,vf11xyzw
  36cf38:	3c 9b eb 81 ff 02 00 00 	nop 	move.xyzw vf11xyzw,vf19xyzw
  36cf40:	3c 93 f3 81 ff 02 00 00 	nop 	move.xyzw vf19xyzw,vf18xyzw
  36cf48:	3c 5b f2 81 ff 02 00 00 	nop 	move.xyzw vf18xyzw,vf11xyzw
  36cf50:	3c 73 eb 81 2c 78 f0 01 	sub.xyzw vf00xyzw,vf15xyzw,vf16xyzw 	move.xyzw vf11xyzw,vf14xyzw
  36cf58:	3c 8b ee 81 ff 02 00 00 	nop 	move.xyzw vf14xyzw,vf17xyzw
  36cf60:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036cf68 <_$CSNOSWP2>:
  36cf68:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36cf70:	00 10 01 34 ff 02 00 00 	nop 	fmand vi01,vi02
  36cf78:	09 08 02 52 ff 02 00 00 	nop 	ibne vi02,vi01,36cfc8 <_$CSNOSWP3>

0036cf80 <_$CSSWP3>:
  36cf80:	3c 7b f1 81 ff 02 00 00 	nop 	move.xyzw vf17xyzw,vf15xyzw
  36cf88:	3c 83 ef 81 ff 02 00 00 	nop 	move.xyzw vf15xyzw,vf16xyzw
  36cf90:	3c 63 f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf12xyzw
  36cf98:	3c 6b ec 81 ff 02 00 00 	nop 	move.xyzw vf12xyzw,vf13xyzw
  36cfa0:	3c 9b ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf19xyzw
  36cfa8:	3c a3 f3 81 ff 02 00 00 	nop 	move.xyzw vf19xyzw,vf20xyzw
  36cfb0:	3c 6b f4 81 ff 02 00 00 	nop 	move.xyzw vf20xyzw,vf13xyzw
  36cfb8:	3c 83 ed 81 ff 02 00 00 	nop 	move.xyzw vf13xyzw,vf16xyzw
  36cfc0:	3c 8b f0 81 ff 02 00 00 	nop 	move.xyzw vf16xyzw,vf17xyzw

0036cfc8 <_$CSNOSWP3>:
  36cfc8:	00 70 e9 03 ff 02 00 00 	nop 	sq.xyzw vf14xyzw,0(vi09)
  36cfd0:	01 90 e9 03 ff 02 00 00 	nop 	sq.xyzw vf18xyzw,1(vi09)
  36cfd8:	02 58 e9 03 ff 02 00 00 	nop 	sq.xyzw vf11xyzw,2(vi09)
  36cfe0:	03 78 e9 03 ff 02 00 00 	nop 	sq.xyzw vf15xyzw,3(vi09)
  36cfe8:	04 98 e9 03 ff 02 00 00 	nop 	sq.xyzw vf19xyzw,4(vi09)
  36cff0:	05 60 e9 03 ff 02 00 00 	nop 	sq.xyzw vf12xyzw,5(vi09)
  36cff8:	06 80 e9 03 ff 02 00 00 	nop 	sq.xyzw vf16xyzw,6(vi09)
  36d000:	07 a0 e9 03 ff 02 00 00 	nop 	sq.xyzw vf20xyzw,7(vi09)
  36d008:	08 68 e9 03 ff 02 00 00 	nop 	sq.xyzw vf13xyzw,8(vi09)
  36d010:	09 70 e9 03 ff 02 00 00 	nop 	sq.xyzw vf14xyzw,9(vi09)
  36d018:	0a 90 e9 03 ff 02 00 00 	nop 	sq.xyzw vf18xyzw,10(vi09)
  36d020:	50 03 00 40 ff 02 00 00 	nop 	b 36eaa8 <scratchbuffer+0x1128>
  36d028:	0b 58 e9 03 ff 02 00 00 	nop 	sq.xyzw vf11xyzw,11(vi09)

0036d030 <.vif.126>:
  36d030:	00 00 00 00 	vifnop
  36d034:	e0 06 60 4a 	mpg 0x6e0,0x60

0036d038 <_$START_PARTICLE1>:
  36d038:	bc 06 02 80 d8 ff e0 01 	mulx.xyzw vf31xyzw,vf31xyzw,vf00x 	xtop vi02
  36d040:	e1 10 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi02,0xe1
  36d048:	01 10 e7 01 ff 02 00 00 	nop 	lq.xyzw vf07xyzw,1(vi02)
  36d050:	02 10 e8 01 ff 02 00 00 	nop 	lq.xyzw vf08xyzw,2(vi02)
  36d058:	03 10 e9 01 ff 02 00 00 	nop 	lq.xyzw vf09xyzw,3(vi02)
  36d060:	04 10 ea 01 ff 02 00 00 	nop 	lq.xyzw vf10xyzw,4(vi02)
  36d068:	05 10 eb 01 ff 02 00 00 	nop 	lq.xyzw vf11xyzw,5(vi02)
  36d070:	06 10 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,6(vi02)
  36d078:	7d 3b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf07xyzw,(vi04++)
  36d080:	7d 43 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf08xyzw,(vi04++)
  36d088:	7d 4b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf09xyzw,(vi04++)
  36d090:	7d 53 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf10xyzw,(vi04++)
  36d098:	7d 5b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf11xyzw,(vi04++)
  36d0a0:	7d 63 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf12xyzw,(vi04++)
  36d0a8:	08 10 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi02,8
  36d0b0:	00 10 fd 01 ff 02 00 00 	nop 	lq.xyzw vf29xyzw,0(vi02)
  36d0b8:	00 10 0b 09 ff 02 00 00 	nop 	ilw.x vi11,0(vi02)x
  36d0c0:	ff 07 e1 11 ff 02 00 00 	nop 	iaddiu vi01,vi00,0x7fff
  36d0c8:	7d eb e4 81 ff 02 00 00 	nop 	sqi.xyzw vf29xyzw,(vi04++)
  36d0d0:	f4 5a 01 80 ff 02 00 00 	nop 	iand vi11,vi11,vi01
  36d0d8:	30 5b 0b 80 ff 02 00 00 	nop 	iadd vi12,vi11,vi11
  36d0e0:	f0 5a 06 80 ff 02 00 00 	nop 	iadd vi11,vi11,vi06
  36d0e8:	f0 5a 0c 80 ff 02 00 00 	nop 	iadd vi11,vi11,vi12

0036d0f0 <_$PLOOP1>:
  36d0f0:	7c 33 ec 81 ff 02 00 00 	nop 	lqi.xyzw vf12xyzw,(vi06++)
  36d0f8:	7c 33 ed 81 ff 02 00 00 	nop 	lqi.xyzw vf13xyzw,(vi06++)
  36d100:	7c 33 ee 81 ff 02 00 00 	nop 	lqi.xyzw vf14xyzw,(vi06++)
  36d108:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36d110:	3c 03 00 80 bc 09 ec 01 	mulax.xyzw accxyzw,vf01xyzw,vf12x 	nop
  36d118:	3c 03 00 80 bd 10 ec 01 	madday.xyzw accxyzw,vf02xyzw,vf12y 	nop
  36d120:	3c 03 00 80 be 18 ec 01 	maddaz.xyzw accxyzw,vf03xyzw,vf12z 	nop
  36d128:	fc 77 40 80 8b 22 e0 01 	maddw.xyzw vf10xyzw,vf04xyzw,vf00w 	esin p,vf14z
  36d130:	da 0f c9 3f ff 02 00 80 	nop[i] 	loi 1.5708
  36d138:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36d140:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36d148:	bc 03 ea 81 ff 02 00 00 	nop 	div q,vf00w,vf00x
  36d150:	3c 03 00 80 a2 73 40 00 	addi.z vf14z,vf14z,i 	nop
  36d158:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36d160:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36d168:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36d170:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36d178:	3c 03 00 80 ff 51 ca 01 	clipw.xyz vf10xyz,vf10w 	nop
  36d180:	3c 03 00 80 9c 52 e0 01 	mulq.xyzw vf10xyzw,vf10xyzw,q 	nop
  36d188:	2f 00 00 24 9c 73 00 01 	mulq.x vf14x,vf14x,q 	fcand vi01,0x2f
  36d190:	3c 03 00 80 9c 07 20 00 	mulq.w vf30w,vf00w,q 	nop
  36d198:	ff 0f e5 11 ff 02 00 00 	nop 	iaddiu vi05,vi01,0x7fff
  36d1a0:	f2 07 01 80 aa 52 c5 01 	mul.xyz vf10xyz,vf10xyz,vf05xyz 	iaddi vi01,vi00,-1
  36d1a8:	3c 03 00 80 97 73 0e 01 	miniw.x vf14x,vf14x,vf14w 	nop
  36d1b0:	3c 03 00 80 83 07 de 01 	addw.xyz vf30xyz,vf00xyz,vf30w 	nop
  36d1b8:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36d1c0:	fd 0b 35 80 a8 52 c6 01 	add.xyz vf10xyz,vf10xyz,vf06xyz 	mfir.w vf21w,vi01
  36d1c8:	fd 0b 36 80 98 73 8e 00 	mulx.y vf14y,vf14y,vf14x 	mfir.w vf22w,vi01
  36d1d0:	fd 2b 37 80 ff 02 00 00 	nop 	mfir.w vf23w,vi05
  36d1d8:	fd 2b 38 80 ff 02 00 00 	nop 	mfir.w vf24w,vi05
  36d1e0:	3c 53 d5 81 ff 02 00 00 	nop 	move.xyz vf21xyz,vf10xyz
  36d1e8:	3c 53 d6 81 ff 02 00 00 	nop 	move.xyz vf22xyz,vf10xyz
  36d1f0:	3c 53 d7 81 ff 02 00 00 	nop 	move.xyz vf23xyz,vf10xyz
  36d1f8:	3c 53 d8 81 ff 02 00 00 	nop 	move.xyz vf24xyz,vf10xyz
  36d200:	bf 07 00 80 ff 02 00 00 	nop 	waitp
  36d208:	7c 06 8f 80 ff 02 00 00 	nop 	mfp.y vf15y,p
  36d210:	fc 77 40 80 ff 02 00 00 	nop 	esin p,vf14z
  36d218:	bf 07 00 80 ff 02 00 00 	nop 	waitp
  36d220:	7c 06 0f 81 ff 02 00 00 	nop 	mfp.x vf15x,p
  36d228:	3c 03 00 80 01 04 0f 01 	addy.x vf16x,vf00x,vf15y 	nop
  36d230:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36d238:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36d240:	3c 03 00 80 04 04 8f 00 	subx.y vf16y,vf00y,vf15x 	nop
  36d248:	3c 03 00 80 ac 04 8f 01 	sub.xy vf18xy,vf00xy,vf15xy 	nop
  36d250:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36d258:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36d260:	3c 03 00 80 6c 04 90 01 	sub.xy vf17xy,vf00xy,vf16xy 	nop
  36d268:	3c 03 00 80 ea 7b 8e 01 	mul.xy vf15xy,vf15xy,vf14xy 	nop
  36d270:	3c 03 00 80 2a 84 8e 01 	mul.xy vf16xy,vf16xy,vf14xy 	nop
  36d278:	3c 03 00 80 6a 8c 8e 01 	mul.xy vf17xy,vf17xy,vf14xy 	nop
  36d280:	3c 03 00 80 aa 94 8e 01 	mul.xy vf18xy,vf18xy,vf14xy 	nop
  36d288:	3c 03 00 80 68 ad 8f 01 	add.xy vf21xy,vf21xy,vf15xy 	nop
  36d290:	3c 03 00 80 a8 b5 90 01 	add.xy vf22xy,vf22xy,vf16xy 	nop
  36d298:	3c 03 00 80 e8 bd 91 01 	add.xy vf23xy,vf23xy,vf17xy 	nop
  36d2a0:	3c 03 00 80 28 c6 92 01 	add.xy vf24xy,vf24xy,vf18xy 	nop
  36d2a8:	00 00 e4 03 7d a9 d5 01 	ftoi4.xyz vf21xyz,vf21xyz 	sq.xyzw vf00xyzw,0(vi04)
  36d2b0:	03 00 e4 03 7d b1 d6 01 	ftoi4.xyz vf22xyz,vf22xyz 	sq.xyzw vf00xyzw,3(vi04)
  36d2b8:	06 00 e4 03 7d b9 d7 01 	ftoi4.xyz vf23xyz,vf23xyz 	sq.xyzw vf00xyzw,6(vi04)
  36d2c0:	09 00 e4 03 7d c1 d8 01 	ftoi4.xyz vf24xyz,vf24xyz 	sq.xyzw vf00xyzw,9(vi04)
  36d2c8:	7d f3 64 80 ff 02 00 00 	nop 	sqi.zw vf30zw,(vi04++)
  36d2d0:	7d 6b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf13xyzw,(vi04++)
  36d2d8:	7d ab e4 81 ff 02 00 00 	nop 	sqi.xyzw vf21xyzw,(vi04++)
  36d2e0:	7d f3 64 81 ff 02 00 00 	nop 	sqi.xzw vf30xzw,(vi04++)
  36d2e8:	7d b3 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf22xyzw,(vi04++)
  36d2f0:	7d f3 e4 80 ff 02 00 00 	nop 	sqi.yzw vf30yzw,(vi04++)
  36d2f8:	7d bb e4 81 ff 02 00 00 	nop 	sqi.xyzw vf23xyzw,(vi04++)
  36d300:	7d f3 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf30xyzw,(vi04++)
  36d308:	7d c3 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf24xyzw,(vi04++)

0036d310 <_$PNEXTV>:
  36d310:	bb 5f 06 52 ff 02 00 00 	nop 	ibne vi06,vi11,36d0f0 <_$PLOOP1>
  36d318:	3c 03 00 80 ff 02 00 00 	nop 	nop
  36d320:	e1 10 03 10 ff 02 00 00 	nop 	iaddiu vi03,vi02,0xe1
  36d328:	fc 1e 00 80 ff 02 00 40 	nop[e] 	xgkick vi03
  36d330:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036d338 <.vif.132>:
  36d338:	00 00 00 00 	vifnop
  36d33c:	78 05 3e 4a 	mpg 0x578,0x3e

0036d340 <_$START_LITNOCLIP>:
  36d340:	bc 06 02 80 d8 ff e0 01 	mulx.xyzw vf31xyzw,vf31xyzw,vf00x 	xtop vi02
  36d348:	e1 10 04 10 ff 02 00 00 	nop 	iaddiu vi04,vi02,0xe1
  36d350:	01 10 f0 01 ff 02 00 00 	nop 	lq.xyzw vf16xyzw,1(vi02)
  36d358:	02 10 f1 01 ff 02 00 00 	nop 	lq.xyzw vf17xyzw,2(vi02)
  36d360:	03 10 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,3(vi02)
  36d368:	04 10 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,4(vi02)
  36d370:	05 10 f4 01 ff 02 00 00 	nop 	lq.xyzw vf20xyzw,5(vi02)
  36d378:	06 10 f5 01 ff 02 00 00 	nop 	lq.xyzw vf21xyzw,6(vi02)
  36d380:	7d 83 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf16xyzw,(vi04++)
  36d388:	7d 8b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf17xyzw,(vi04++)
  36d390:	7d 93 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf18xyzw,(vi04++)
  36d398:	7d 9b e4 81 ff 02 00 00 	nop 	sqi.xyzw vf19xyzw,(vi04++)
  36d3a0:	7d a3 e4 81 ff 02 00 00 	nop 	sqi.xyzw vf20xyzw,(vi04++)
  36d3a8:	7d ab e4 81 ff 02 00 00 	nop 	sqi.xyzw vf21xyzw,(vi04++)
  36d3b0:	08 10 06 10 ff 02 00 00 	nop 	iaddiu vi06,vi02,8
  36d3b8:	67 00 f0 01 ff 02 00 00 	nop 	lq.xyzw vf16xyzw,103(vi00)
  36d3c0:	90 30 ef 01 ff 02 00 00 	nop 	lq.xyzw vf15xyzw,144(vi06)
  36d3c8:	68 00 f1 01 ff 02 00 00 	nop 	lq.xyzw vf17xyzw,104(vi00)
  36d3d0:	69 00 f2 01 ff 02 00 00 	nop 	lq.xyzw vf18xyzw,105(vi00)
  36d3d8:	6a 00 f3 01 ff 02 00 00 	nop 	lq.xyzw vf19xyzw,106(vi00)
  36d3e0:	00 30 ec 01 bc 81 ef 01 	mulax.xyzw accxyzw,vf16xyzw,vf15x 	lq.xyzw vf12xyzw,0(vi06)
  36d3e8:	00 10 fd 01 bd 88 ef 01 	madday.xyzw accxyzw,vf17xyzw,vf15y 	lq.xyzw vf29xyzw,0(vi02)
  36d3f0:	3c 03 00 80 be 90 ef 01 	maddaz.xyzw accxyzw,vf18xyzw,vf15z 	nop
  36d3f8:	3c 03 00 80 0b 9f e0 01 	maddw.xyzw vf28xyzw,vf19xyzw,vf00w 	nop
  36d400:	5b 00 f4 01 bc 09 ec 01 	mulax.xyzw accxyzw,vf01xyzw,vf12x 	lq.xyzw vf20xyzw,91(vi00)
  36d408:	7d eb e4 81 bd 10 ec 01 	madday.xyzw accxyzw,vf02xyzw,vf12y 	sqi.xyzw vf29xyzw,(vi04++)
  36d410:	00 00 00 22 be 18 ec 01 	maddaz.xyzw accxyzw,vf03xyzw,vf12z 	fcset 0
  36d418:	00 00 fe 42 10 e7 e0 81 	maxx[i].xyzw vf28xyzw,vf28xyzw,vf00x 	loi 127
  36d420:	5c 00 f5 01 8b 22 e0 01 	maddw.xyzw vf10xyzw,vf04xyzw,vf00w 	lq.xyzw vf21xyzw,92(vi00)
  36d428:	5d 00 f6 01 ff 02 00 00 	nop 	lq.xyzw vf22xyzw,93(vi00)
  36d430:	5e 00 f7 01 ff 02 00 00 	nop 	lq.xyzw vf23xyzw,94(vi00)
  36d438:	00 10 0b 09 bc a1 fc 01 	mulax.xyzw accxyzw,vf20xyzw,vf28x 	ilw.x vi11,0(vi02)x
  36d440:	bc 03 ea 81 bd a8 fc 01 	madday.xyzw accxyzw,vf21xyzw,vf28y 	div q,vf00w,vf00x
  36d448:	ff 07 e1 11 be b0 fc 01 	maddaz.xyzw accxyzw,vf22xyzw,vf28z 	iaddiu vi01,vi00,0x7fff
  36d450:	3c 03 00 80 4b bb dc 01 	maddw.xyz vf13xyz,vf23xyz,vf28w 	nop
  36d458:	f4 5a 01 80 ff 51 ca 01 	clipw.xyz vf10xyz,vf10w 	iand vi11,vi11,vi01
  36d460:	f0 5a 06 80 ea 51 c5 01 	mul.xyz vf07xyz,vf10xyz,vf05xyz 	iadd vi11,vi11,vi06

0036d468 <_$LNCLOOP1>:
  36d468:	48 30 ee 01 5d 03 20 00 	maxi.w vf13w,vf00w,i 	lq.xyzw vf14xyzw,72(vi06)
  36d470:	91 30 ef 01 5e 6b c0 01 	muli.xyz vf13xyz,vf13xyz,i 	lq.xyzw vf15xyzw,145(vi06)
  36d478:	fc 63 65 80 3c 30 e0 01 	addax.xyzw accxyzw,vf06xyzw,vf00x 	mtir vi05,vf12w
  36d480:	20 08 02 24 e1 39 c0 01 	maddq.xyz vf07xyz,vf07xyz,q 	fcand vi01,0x20820
  36d488:	3c 03 00 80 5c 77 e0 01 	mulq.xyzw vf29xyzw,vf14xyzw,q 	nop
  36d490:	ff 0f e1 11 9f 6f e0 01 	minii.xyzw vf30xyzw,vf13xyzw,i 	iaddiu vi01,vi01,0x7fff
  36d498:	01 30 ec 01 bc 81 ef 01 	mulax.xyzw accxyzw,vf16xyzw,vf15x 	lq.xyzw vf12xyzw,1(vi06)
  36d4a0:	75 08 05 80 bd 88 ef 01 	madday.xyzw accxyzw,vf17xyzw,vf15y 	ior vi01,vi01,vi05
  36d4a8:	3c 03 00 80 be 90 ef 01 	maddaz.xyzw accxyzw,vf18xyzw,vf15z 	nop
  36d4b0:	fd 0b 27 80 0b 9f e0 01 	maddw.xyzw vf28xyzw,vf19xyzw,vf00w 	mfir.w vf07w,vi01
  36d4b8:	3c 03 00 80 bc 09 ec 01 	mulax.xyzw accxyzw,vf01xyzw,vf12x 	nop
  36d4c0:	3c 03 00 80 bd 10 ec 01 	madday.xyzw accxyzw,vf02xyzw,vf12y 	nop
  36d4c8:	3c 03 00 80 be 18 ec 01 	maddaz.xyzw accxyzw,vf03xyzw,vf12z 	nop
  36d4d0:	3c 03 00 80 10 e7 e0 01 	maxx.xyzw vf28xyzw,vf28xyzw,vf00x 	nop
  36d4d8:	3c 03 00 80 8b 22 e0 01 	maddw.xyzw vf10xyzw,vf04xyzw,vf00w 	nop
  36d4e0:	e1 10 03 10 7c f1 fe 01 	ftoi0.xyzw vf30xyzw,vf30xyzw 	iaddiu vi03,vi02,0xe1
  36d4e8:	01 30 06 10 7d 39 c7 01 	ftoi4.xyz vf07xyz,vf07xyz 	iaddiu vi06,vi06,1
  36d4f0:	00 e8 e4 03 bc a1 fc 01 	mulax.xyzw accxyzw,vf20xyzw,vf28x 	sq.xyzw vf29xyzw,0(vi04)
  36d4f8:	bc 03 ea 81 bd a8 fc 01 	madday.xyzw accxyzw,vf21xyzw,vf28y 	div q,vf00w,vf00x
  36d500:	01 f0 e4 03 be b0 fc 01 	maddaz.xyzw accxyzw,vf22xyzw,vf28z 	sq.xyzw vf30xyzw,1(vi04)
  36d508:	02 38 e4 03 4b bb dc 01 	maddw.xyz vf13xyz,vf23xyz,vf28w 	sq.xyzw vf07xyzw,2(vi04)
  36d510:	ea 5f 06 52 ff 51 ca 01 	clipw.xyz vf10xyz,vf10w 	ibne vi06,vi11,36d468 <_$LNCLOOP1>
  36d518:	03 20 04 10 ea 51 c5 01 	mul.xyz vf07xyz,vf10xyz,vf05xyz 	iaddiu vi04,vi04,3
  36d520:	fc 1e 00 80 ff 02 00 40 	nop[e] 	xgkick vi03
  36d528:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036d530 <.vif.137>:
  36d530:	00 00 00 00 	vifnop
  36d534:	fa 07 06 4a 	mpg 0x7fa,6

0036d538 <_$START_PASS>:
  36d538:	bc 06 01 80 ff 02 00 00 	nop 	xtop vi01
  36d540:	08 08 01 10 ff 02 00 00 	nop 	iaddiu vi01,vi01,8
  36d548:	fc 0e 00 80 ff 02 00 00 	nop 	xgkick vi01
  36d550:	fc 06 00 80 ff 02 00 00 	nop 	xgkick vi00
  36d558:	3c 03 00 80 ff 02 00 40 	nop[e] 	nop
  36d560:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036d568 <.vif.141>:
  36d568:	00 00 00 00 	vifnop
  36d56c:	b4 07 0c 4a 	mpg 0x7b4,12

0036d570 <_$START_LOADP>:
  36d570:	bc 06 01 80 ff 02 00 00 	nop 	xtop vi01
  36d578:	08 08 e9 01 ff 02 00 00 	nop 	lq.xyzw vf09xyzw,8(vi01)
  36d580:	09 08 ea 01 ff 02 00 00 	nop 	lq.xyzw vf10xyzw,9(vi01)
  36d588:	0a 08 eb 01 ff 02 00 00 	nop 	lq.xyzw vf11xyzw,10(vi01)
  36d590:	0b 08 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,11(vi01)
  36d598:	02 48 e0 03 ff 02 00 00 	nop 	sq.xyzw vf09xyzw,2(vi00)
  36d5a0:	03 50 e0 03 ff 02 00 00 	nop 	sq.xyzw vf10xyzw,3(vi00)
  36d5a8:	04 58 e0 03 ff 02 00 00 	nop 	sq.xyzw vf11xyzw,4(vi00)
  36d5b0:	05 60 e0 03 ff 02 00 00 	nop 	sq.xyzw vf12xyzw,5(vi00)
  36d5b8:	fc 06 00 80 ff 02 00 00 	nop 	xgkick vi00
  36d5c0:	3c 03 00 80 ff 02 00 40 	nop[e] 	nop
  36d5c8:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036d5d0 <.vif.145>:
  36d5d0:	00 00 00 00 	vifnop
  36d5d4:	c0 07 1d 4a 	mpg 0x7c0,0x1d

0036d5d8 <_$START_LOADM>:
  36d5d8:	bc 06 01 80 ff 02 00 00 	nop 	xtop vi01
  36d5e0:	08 08 ed 01 ff 02 00 00 	nop 	lq.xyzw vf13xyzw,8(vi01)
  36d5e8:	02 00 e9 01 ff 02 00 00 	nop 	lq.xyzw vf09xyzw,2(vi00)
  36d5f0:	03 00 ea 01 ff 02 00 00 	nop 	lq.xyzw vf10xyzw,3(vi00)
  36d5f8:	04 00 eb 01 ff 02 00 00 	nop 	lq.xyzw vf11xyzw,4(vi00)
  36d600:	05 00 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,5(vi00)
  36d608:	09 08 ee 01 bc 49 ed 01 	mulax.xyzw accxyzw,vf09xyzw,vf13x 	lq.xyzw vf14xyzw,9(vi01)
  36d610:	0a 08 ef 01 bd 50 ed 01 	madday.xyzw accxyzw,vf10xyzw,vf13y 	lq.xyzw vf15xyzw,10(vi01)
  36d618:	0b 08 f0 01 be 58 ed 01 	maddaz.xyzw accxyzw,vf11xyzw,vf13z 	lq.xyzw vf16xyzw,11(vi01)
  36d620:	3c 03 00 80 4b 60 ed 01 	maddw.xyzw vf01xyzw,vf12xyzw,vf13w 	nop
  36d628:	06 68 e0 03 bc 49 ee 01 	mulax.xyzw accxyzw,vf09xyzw,vf14x 	sq.xyzw vf13xyzw,6(vi00)
  36d630:	07 70 e0 03 bd 50 ee 01 	madday.xyzw accxyzw,vf10xyzw,vf14y 	sq.xyzw vf14xyzw,7(vi00)
  36d638:	08 78 e0 03 be 58 ee 01 	maddaz.xyzw accxyzw,vf11xyzw,vf14z 	sq.xyzw vf15xyzw,8(vi00)
  36d640:	09 80 e0 03 8b 60 ee 01 	maddw.xyzw vf02xyzw,vf12xyzw,vf14w 	sq.xyzw vf16xyzw,9(vi00)
  36d648:	3c 03 00 80 bc 49 ef 01 	mulax.xyzw accxyzw,vf09xyzw,vf15x 	nop
  36d650:	3c 03 00 80 bd 50 ef 01 	madday.xyzw accxyzw,vf10xyzw,vf15y 	nop
  36d658:	3c 03 00 80 be 58 ef 01 	maddaz.xyzw accxyzw,vf11xyzw,vf15z 	nop
  36d660:	3c 03 00 80 cb 60 ef 01 	maddw.xyzw vf03xyzw,vf12xyzw,vf15w 	nop
  36d668:	3c 03 00 80 bc 49 f0 01 	mulax.xyzw accxyzw,vf09xyzw,vf16x 	nop
  36d670:	3c 03 00 80 bd 50 f0 01 	madday.xyzw accxyzw,vf10xyzw,vf16y 	nop
  36d678:	3c 03 00 80 be 58 f0 01 	maddaz.xyzw accxyzw,vf11xyzw,vf16z 	nop
  36d680:	3c 03 00 80 0b 61 f0 01 	maddw.xyzw vf04xyzw,vf12xyzw,vf16w 	nop
  36d688:	63 08 e0 03 ff 02 00 00 	nop 	sq.xyzw vf01xyzw,99(vi00)
  36d690:	64 10 e0 03 ff 02 00 00 	nop 	sq.xyzw vf02xyzw,100(vi00)
  36d698:	65 18 e0 03 ff 02 00 00 	nop 	sq.xyzw vf03xyzw,101(vi00)
  36d6a0:	66 20 e0 03 ff 02 00 00 	nop 	sq.xyzw vf04xyzw,102(vi00)
  36d6a8:	fc 06 00 80 ff 02 00 00 	nop 	xgkick vi00
  36d6b0:	3c 03 00 80 ff 02 00 40 	nop[e] 	nop
  36d6b8:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036d6c0 <.vif.149>:
  36d6c0:	00 00 00 00 	vifnop
  36d6c4:	dd 07 1d 4a 	mpg 0x7dd,0x1d

0036d6c8 <_$START_LOADM_FIL>:
  36d6c8:	bc 06 01 80 ff 02 00 00 	nop 	xtop vi01
  36d6d0:	08 08 ed 01 ff 02 00 00 	nop 	lq.xyzw vf13xyzw,8(vi01)
  36d6d8:	02 00 e9 01 ff 02 00 00 	nop 	lq.xyzw vf09xyzw,2(vi00)
  36d6e0:	03 00 ea 01 ff 02 00 00 	nop 	lq.xyzw vf10xyzw,3(vi00)
  36d6e8:	04 00 eb 01 ff 02 00 00 	nop 	lq.xyzw vf11xyzw,4(vi00)
  36d6f0:	05 00 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,5(vi00)
  36d6f8:	09 08 ee 01 bc 49 ed 01 	mulax.xyzw accxyzw,vf09xyzw,vf13x 	lq.xyzw vf14xyzw,9(vi01)
  36d700:	0a 08 ef 01 bd 50 ed 01 	madday.xyzw accxyzw,vf10xyzw,vf13y 	lq.xyzw vf15xyzw,10(vi01)
  36d708:	0b 08 f0 01 be 58 ed 01 	maddaz.xyzw accxyzw,vf11xyzw,vf13z 	lq.xyzw vf16xyzw,11(vi01)
  36d710:	3c 03 00 80 4b 66 ed 01 	maddw.xyzw vf25xyzw,vf12xyzw,vf13w 	nop
  36d718:	3c 03 00 80 bc 49 ee 01 	mulax.xyzw accxyzw,vf09xyzw,vf14x 	nop
  36d720:	3c 03 00 80 bd 50 ee 01 	madday.xyzw accxyzw,vf10xyzw,vf14y 	nop
  36d728:	3c 03 00 80 be 58 ee 01 	maddaz.xyzw accxyzw,vf11xyzw,vf14z 	nop
  36d730:	3c 03 00 80 8b 66 ee 01 	maddw.xyzw vf26xyzw,vf12xyzw,vf14w 	nop
  36d738:	3c 03 00 80 bc 49 ef 01 	mulax.xyzw accxyzw,vf09xyzw,vf15x 	nop
  36d740:	3c 03 00 80 bd 50 ef 01 	madday.xyzw accxyzw,vf10xyzw,vf15y 	nop
  36d748:	3c 03 00 80 be 58 ef 01 	maddaz.xyzw accxyzw,vf11xyzw,vf15z 	nop
  36d750:	3c 03 00 80 cb 66 ef 01 	maddw.xyzw vf27xyzw,vf12xyzw,vf15w 	nop
  36d758:	0c 08 02 09 bc 49 f0 01 	mulax.xyzw accxyzw,vf09xyzw,vf16x 	ilw.x vi02,12(vi01)x
  36d760:	3c 03 00 80 bd 50 f0 01 	madday.xyzw accxyzw,vf10xyzw,vf16y 	nop
  36d768:	3c 03 00 80 be 58 f0 01 	maddaz.xyzw accxyzw,vf11xyzw,vf16z 	nop
  36d770:	3c 03 00 80 0b 67 f0 01 	maddw.xyzw vf28xyzw,vf12xyzw,vf16w 	nop
  36d778:	00 c8 e2 03 ff 02 00 00 	nop 	sq.xyzw vf25xyzw,0(vi02)
  36d780:	01 d0 e2 03 ff 02 00 00 	nop 	sq.xyzw vf26xyzw,1(vi02)
  36d788:	02 d8 e2 03 ff 02 00 00 	nop 	sq.xyzw vf27xyzw,2(vi02)
  36d790:	03 e0 e2 03 ff 02 00 00 	nop 	sq.xyzw vf28xyzw,3(vi02)
  36d798:	fc 06 00 80 ff 02 00 00 	nop 	xgkick vi00
  36d7a0:	3c 03 00 80 ff 02 00 40 	nop[e] 	nop
  36d7a8:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036d7b0 <.vif.153>:
  36d7b0:	00 00 00 00 	vifnop
  36d7b4:	a4 07 08 4a 	mpg 0x7a4,8

0036d7b8 <_$START_LOADVP>:
  36d7b8:	bc 06 01 80 ff 02 00 00 	nop 	xtop vi01
  36d7c0:	08 08 e5 01 ff 02 00 00 	nop 	lq.xyzw vf05xyzw,8(vi01)
  36d7c8:	09 08 e6 01 ff 02 00 00 	nop 	lq.xyzw vf06xyzw,9(vi01)
  36d7d0:	0a 28 e0 03 ff 02 00 00 	nop 	sq.xyzw vf05xyzw,10(vi00)
  36d7d8:	0b 30 e0 03 ff 02 00 00 	nop 	sq.xyzw vf06xyzw,11(vi00)
  36d7e0:	fc 06 00 80 ff 02 00 00 	nop 	xgkick vi00
  36d7e8:	3c 03 00 80 ff 02 00 40 	nop[e] 	nop
  36d7f0:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036d7f8 <.vif.157>:
  36d7f8:	00 00 00 00 	vifnop
  36d7fc:	ac 07 08 4a 	mpg 0x7ac,8

0036d800 <_$START_LOADTAGS>:
  36d800:	bc 06 01 80 ff 02 00 00 	nop 	xtop vi01
  36d808:	08 08 e9 01 ff 02 00 00 	nop 	lq.xyzw vf09xyzw,8(vi01)
  36d810:	09 08 ea 01 ff 02 00 00 	nop 	lq.xyzw vf10xyzw,9(vi01)
  36d818:	01 48 e0 03 ff 02 00 00 	nop 	sq.xyzw vf09xyzw,1(vi00)
  36d820:	00 50 e0 03 ff 02 00 00 	nop 	sq.xyzw vf10xyzw,0(vi00)
  36d828:	fc 06 00 80 ff 02 00 00 	nop 	xgkick vi00
  36d830:	3c 03 00 80 ff 02 00 40 	nop[e] 	nop
  36d838:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036d840 <.vif.161>:
  36d840:	00 00 00 00 	vifnop
  36d844:	97 07 0d 4a 	mpg 0x797,13

0036d848 <_$START_COPY4>:
  36d848:	bc 06 01 80 ff 02 00 00 	nop 	xtop vi01
  36d850:	0c 08 02 09 ff 02 00 00 	nop 	ilw.x vi02,12(vi01)x
  36d858:	08 08 e9 01 ff 02 00 00 	nop 	lq.xyzw vf09xyzw,8(vi01)
  36d860:	09 08 ea 01 ff 02 00 00 	nop 	lq.xyzw vf10xyzw,9(vi01)
  36d868:	0a 08 eb 01 ff 02 00 00 	nop 	lq.xyzw vf11xyzw,10(vi01)
  36d870:	0b 08 ec 01 ff 02 00 00 	nop 	lq.xyzw vf12xyzw,11(vi01)
  36d878:	00 48 e2 03 ff 02 00 00 	nop 	sq.xyzw vf09xyzw,0(vi02)
  36d880:	01 50 e2 03 ff 02 00 00 	nop 	sq.xyzw vf10xyzw,1(vi02)
  36d888:	02 58 e2 03 ff 02 00 00 	nop 	sq.xyzw vf11xyzw,2(vi02)
  36d890:	03 60 e2 03 ff 02 00 00 	nop 	sq.xyzw vf12xyzw,3(vi02)
  36d898:	fc 06 00 80 ff 02 00 00 	nop 	xgkick vi00
  36d8a0:	3c 03 00 80 ff 02 00 40 	nop[e] 	nop
  36d8a8:	3c 03 00 80 ff 02 00 00 	nop 	nop

0036d8b0 <.vif.165>:
  36d8b0:	7c 00 00 03 	base 0x7c
  36d8b4:	c2 01 00 02 	offset 0x1c2
	...
