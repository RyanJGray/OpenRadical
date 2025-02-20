typedef struct {
	int real;
	int imag;
} complex int;

typedef long unsigned int clock_t;
typedef long int time_t;

struct tm {
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
};

typedef struct {
	_Bigint *_next;
	int _k;
	int _maxwds;
	int _sign;
	int _wds;
	ULong _x[1];
} _Bigint;

struct _atexit {
	_atexit *_next;
	int _ind;
	void (*_fns[32])(/* parameters unknown */);
};

struct __sbuf {
	unsigned char *_base;
	int _size;
};

struct __sFILE {
	unsigned char *_p;
	int _r;
	int _w;
	short int _flags;
	short int _file;
	__sbuf _bf;
	int _lbfsize;
	void *_cookie;
	int (*_read)(/* parameters unknown */);
	int (*_write)(/* parameters unknown */);
	_fpos_t (*_seek)(/* parameters unknown */);
	int (*_close)(/* parameters unknown */);
	__sbuf _ub;
	unsigned char *_up;
	int _ur;
	unsigned char _ubuf[3];
	unsigned char _nbuf[1];
	__sbuf _lb;
	int _blksize;
	int _offset;
	_reent *_data;
};

struct _reent {
	int _errno;
	__sFILE *_stdin;
	__sFILE *_stdout;
	__sFILE *_stderr;
	int _inc;
	char _emergency[25];
	int _current_category;
	char *_current_locale;
	int __sdidinit;
	void (*__cleanup)(/* parameters unknown */);
	_Bigint *_result;
	int _result_k;
	_Bigint *_p5s;
	_Bigint **_freelist;
	int _cvtlen;
	char *_cvtbuf;
	union {
		struct {
			unsigned int _rand_next;
			char *_strtok_last;
			char _asctime_buf[26];
			tm _localtime_buf;
			int _gamma_signgam;
		} _reent;
		struct {
			unsigned char *_nextf[30];
			unsigned int _nmalloc[30];
		} _unused;
	} _new;
	_atexit *_atexit;
	_atexit _atexit0;
	void (**_sig_func)(/* parameters unknown */);
	_glue __sglue;
	__sFILE __sf[3];
};

typedef struct {
	int quot;
	int rem;
} div_t;

typedef struct {
	long int quot;
	long int rem;
} ldiv_t;

typedef short unsigned int u_short;

struct ThreadParam {
	int status;
	void *entry;
	void *stack;
	int stackSize;
	void *gpReg;
	int initPriority;
	int currentPriority;
	u_int attr;
	u_int option;
	int waitType;
	int waitId;
	int wakeupCount;
};

struct SemaParam {
	int currentCount;
	int maxCount;
	int initCount;
	int numWaitThreads;
	u_int attr;
	u_int option;
};

typedef struct {
	unsigned int COUNT : 16;
	unsigned int p0 : 16;
} tT_COUNT;

typedef struct {
	unsigned int CLKS : 2;
	unsigned int GATE : 1;
	unsigned int GATS : 1;
	unsigned int GATM : 2;
	unsigned int ZRET : 1;
	unsigned int CUE : 1;
	unsigned int CMPE : 1;
	unsigned int OVFE : 1;
	unsigned int EQUF : 1;
	unsigned int OVFF : 1;
	unsigned int p0 : 20;
} tT_MODE;

typedef struct {
	unsigned int COMP : 16;
	unsigned int p0 : 16;
} tT_COMP;

typedef struct {
	unsigned int HOLD : 16;
	unsigned int p0 : 16;
} tT_HOLD;

typedef struct {
	unsigned int OPTION : 28;
	unsigned int CODE : 4;
} tIPU_CMD_write;

typedef struct {
	unsigned int DATA;
	unsigned int p0 : 31;
	unsigned int BUSY : 1;
} tIPU_CMD_read;

typedef struct {
	unsigned int BSTOP;
	unsigned int p0 : 31;
	unsigned int BUSY : 1;
} tIPU_TOP;

typedef struct {
	unsigned int IFC : 4;
	unsigned int OFC : 4;
	unsigned int CBP : 6;
	unsigned int ECD : 1;
	unsigned int SCD : 1;
	unsigned int IDP : 2;
	unsigned int p0 : 2;
	unsigned int AS : 1;
	unsigned int IVF : 1;
	unsigned int QST : 1;
	unsigned int MP1 : 1;
	unsigned int PCT : 3;
	unsigned int p1 : 3;
	unsigned int RST : 1;
	unsigned int BUSY : 1;
} tIPU_CTRL;

typedef struct {
	unsigned int BP : 7;
	unsigned int p0 : 1;
	unsigned int IFC : 4;
	unsigned int p1 : 4;
	unsigned int FP : 2;
	unsigned int p2 : 14;
} tIPU_BP;

typedef struct {
	unsigned int RST : 1;
	unsigned int p0 : 2;
	unsigned int PSE : 1;
	unsigned int p1 : 28;
} tGIF_CTRL;

typedef struct {
	unsigned int M3R : 1;
	unsigned int p0 : 1;
	unsigned int IMT : 1;
	unsigned int p1 : 29;
} tGIF_MODE;

typedef struct {
	unsigned int M3R : 1;
	unsigned int M3P : 1;
	unsigned int IMT : 1;
	unsigned int PSE : 1;
	unsigned int p0 : 1;
	unsigned int IP3 : 1;
	unsigned int P3Q : 1;
	unsigned int P2Q : 1;
	unsigned int P1Q : 1;
	unsigned int OPH : 1;
	unsigned int APATH : 2;
	unsigned int DIR : 1;
	unsigned int p1 : 11;
	unsigned int FQC : 5;
	unsigned int p2 : 3;
} tGIF_STAT;

typedef struct {
	unsigned int NLOOP : 15;
	unsigned int EOP : 1;
	unsigned int tag : 16;
} tGIF_TAG0;

typedef struct {
	unsigned int tag : 14;
	unsigned int PRE : 1;
	unsigned int PRIM : 11;
	unsigned int FLG : 2;
	unsigned int NREG : 4;
} tGIF_TAG1;

typedef struct {
	unsigned int tag;
} tGIF_TAG2;

typedef struct {
	unsigned int tag;
} tGIF_TAG3;

typedef struct {
	unsigned int LOOPCNT : 15;
	unsigned int p0 : 1;
	unsigned int REGCNT : 4;
	unsigned int VUADDR : 10;
	unsigned int p1 : 2;
} tGIF_CNT;

typedef struct {
	unsigned int P3CNT : 15;
	unsigned int p0 : 17;
} tGIF_P3CNT;

typedef struct {
	unsigned int LOOPCNT : 15;
	unsigned int EOP : 1;
	unsigned int p0 : 16;
} tGIF_P3TAG;

typedef struct {
	unsigned int VPS : 2;
	unsigned int VEW : 1;
	unsigned int p0 : 3;
	unsigned int MRK : 1;
	unsigned int p1 : 1;
	unsigned int VSS : 1;
	unsigned int VFS : 1;
	unsigned int VIS : 1;
	unsigned int INT : 1;
	unsigned int ERO : 1;
	unsigned int ER1 : 1;
	unsigned int p2 : 10;
	unsigned int FQC : 4;
	unsigned int p3 : 4;
} tVIF0_STAT;

typedef struct {
	unsigned int RST : 1;
	unsigned int FBK : 1;
	unsigned int STP : 1;
	unsigned int STC : 1;
	unsigned int p0 : 28;
} tVIF0_FBRST;

typedef struct {
	unsigned int MII : 1;
	unsigned int ME0 : 1;
	unsigned int ME1 : 1;
	unsigned int p0 : 29;
} tVIF0_ERR;

typedef struct {
	unsigned int MARK : 16;
	unsigned int p0 : 16;
} tVIF_MARK;

typedef struct {
	unsigned int CL : 8;
	unsigned int WL : 8;
	unsigned int p0 : 16;
} tVIF_CYCLE;

typedef struct {
	unsigned int MOD : 2;
	unsigned int p0 : 30;
} tVIF_MODE;

typedef struct {
	unsigned int num : 8;
	unsigned int p0 : 24;
} tVIF0_NUM;

typedef struct {
	unsigned int m0 : 2;
	unsigned int m1 : 2;
	unsigned int m2 : 2;
	unsigned int m3 : 2;
	unsigned int m4 : 2;
	unsigned int m5 : 2;
	unsigned int m6 : 2;
	unsigned int m7 : 2;
	unsigned int m8 : 2;
	unsigned int m9 : 2;
	unsigned int m10 : 2;
	unsigned int m11 : 2;
	unsigned int m12 : 2;
	unsigned int m13 : 2;
	unsigned int m14 : 2;
	unsigned int m15 : 2;
} tVIF_MASK;

typedef struct {
	unsigned int immediate : 16;
	unsigned int num : 8;
	unsigned int CMD : 8;
} tVIF_CODE;

typedef struct {
	unsigned int ITOPS : 10;
	unsigned int p0 : 22;
} tVIF_ITOPS;

typedef struct {
	unsigned int ITOP : 10;
	unsigned int p0 : 22;
} tVIF_ITOP;

typedef struct {
	unsigned int R0;
} tVIF_R0;

typedef struct {
	unsigned int R1;
} tVIF_R1;

typedef struct {
	unsigned int R2;
} tVIF_R2;

typedef struct {
	unsigned int R3;
} tVIF_R3;

typedef struct {
	unsigned int C0;
} tVIF_C0;

typedef struct {
	unsigned int C1;
} tVIF_C1;

typedef struct {
	unsigned int C2;
} tVIF_C2;

typedef struct {
	unsigned int C3;
} tVIF_C3;

typedef struct {
	unsigned int VPS : 2;
	unsigned int VEW : 1;
	unsigned int VGW : 1;
	unsigned int p0 : 2;
	unsigned int MRK : 1;
	unsigned int DBF : 1;
	unsigned int VSS : 1;
	unsigned int VFS : 1;
	unsigned int VIS : 1;
	unsigned int INT : 1;
	unsigned int ERO : 1;
	unsigned int ER1 : 1;
	unsigned int p1 : 9;
	unsigned int FDR : 1;
	unsigned int FQC : 5;
	unsigned int p2 : 3;
} tVIF1_STAT;

typedef struct {
	unsigned int RST : 1;
	unsigned int FBK : 1;
	unsigned int STP : 1;
	unsigned int STC : 1;
	unsigned int p0 : 28;
} tVIF1_FBRST;

typedef struct {
	unsigned int MII : 1;
	unsigned int ME0 : 1;
	unsigned int ME1 : 1;
	unsigned int p0 : 29;
} tVIF1_ERR;

typedef struct {
	unsigned int num : 8;
	unsigned int p0 : 24;
} tVIF1_NUM;

typedef struct {
	unsigned int BASE : 10;
	unsigned int p0 : 22;
} tVIF1_BASE;

typedef struct {
	unsigned int OFFSET : 10;
	unsigned int p0 : 22;
} tVIF1_OFST;

typedef struct {
	unsigned int TOPS : 10;
	unsigned int p0 : 22;
} tVIF1_TOPS;

typedef struct {
	unsigned int TOP : 10;
	unsigned int p0 : 22;
} tVIF1_TOP;

typedef struct {
	unsigned int ADDR : 31;
	unsigned int SPR : 1;
} tD_MADR;

typedef struct {
	unsigned int QWC : 16;
	unsigned int p0 : 16;
} tD_QWC;

typedef struct {
	unsigned int ADDR : 31;
	unsigned int SPR : 1;
} tD_TADR;

typedef struct {
	unsigned int ADDR : 31;
	unsigned int SPR : 1;
} tD_ASR0;

typedef struct {
	unsigned int ADDR : 31;
	unsigned int SPR : 1;
} tD_ASR1;

typedef struct {
	unsigned int ADDR : 14;
	unsigned int p0 : 18;
} tD_SADR;

typedef struct {
	unsigned int DMAE : 1;
	unsigned int RELE : 1;
	unsigned int MFD : 2;
	unsigned int STS : 2;
	unsigned int STD : 2;
	unsigned int RCYC : 3;
	unsigned int p0 : 21;
} tD_CTRL;

typedef struct {
	unsigned int CIS0 : 1;
	unsigned int CIS1 : 1;
	unsigned int CIS2 : 1;
	unsigned int CIS3 : 1;
	unsigned int CIS4 : 1;
	unsigned int CIS5 : 1;
	unsigned int CIS6 : 1;
	unsigned int CIS7 : 1;
	unsigned int CIS8 : 1;
	unsigned int CIS9 : 1;
	unsigned int p0 : 3;
	unsigned int SIS : 1;
	unsigned int MEIS : 1;
	unsigned int BEIS : 1;
	unsigned int CIM0 : 1;
	unsigned int CIM1 : 1;
	unsigned int CIM2 : 1;
	unsigned int CIM3 : 1;
	unsigned int CIM4 : 1;
	unsigned int CIM5 : 1;
	unsigned int CIM6 : 1;
	unsigned int CIM7 : 1;
	unsigned int CIM8 : 1;
	unsigned int CIM9 : 1;
	unsigned int p1 : 3;
	unsigned int SIM : 1;
	unsigned int MEIM : 1;
	unsigned int p2 : 1;
} tD_STAT;

typedef struct {
	unsigned int CPC0 : 1;
	unsigned int CPC1 : 1;
	unsigned int CPC2 : 1;
	unsigned int CPC3 : 1;
	unsigned int CPC4 : 1;
	unsigned int CPC5 : 1;
	unsigned int CPC6 : 1;
	unsigned int CPC7 : 1;
	unsigned int CPC8 : 1;
	unsigned int CPC9 : 1;
	unsigned int p0 : 6;
	unsigned int CDE0 : 1;
	unsigned int CDE1 : 1;
	unsigned int CDE2 : 1;
	unsigned int CDE3 : 1;
	unsigned int CDE4 : 1;
	unsigned int CDE5 : 1;
	unsigned int CDE6 : 1;
	unsigned int CDE7 : 1;
	unsigned int CDE8 : 1;
	unsigned int CDE9 : 1;
	unsigned int p1 : 5;
	unsigned int PCE : 1;
} tD_PCR;

typedef struct {
	unsigned int SQWC : 8;
	unsigned int p0 : 8;
	unsigned int TQWC : 8;
	unsigned int p1 : 8;
} tD_SQWC;

typedef struct {
	unsigned int RMSK : 31;
	unsigned int p0 : 1;
} tD_RBSR;

typedef struct {
	unsigned int ADDR : 31;
	unsigned int p0 : 1;
} tD_RBOR;

typedef struct {
	unsigned int ADDR : 31;
	unsigned int p0 : 1;
} tD_STADR;

typedef struct {
	unsigned int p0 : 16;
	unsigned int CPND : 1;
	unsigned int p1 : 15;
} tD_ENABLER;

typedef struct {
	unsigned int p0 : 16;
	unsigned int CPND : 1;
	unsigned int p1 : 15;
} tD_ENABLEW;

typedef struct {
	unsigned int EN1 : 1;
	unsigned int EN2 : 1;
	unsigned int CRTMD : 3;
	unsigned int MMOD : 1;
	unsigned int AMOD : 1;
	unsigned int SLBG : 1;
	unsigned int ALP : 8;
	unsigned int p0 : 16;
	unsigned int p1;
} tGS_PMODE;

typedef struct {
	unsigned int INT : 1;
	unsigned int FFMD : 1;
	unsigned int DPMS : 2;
	unsigned int p0 : 28;
	unsigned int p1;
} tGS_SMODE2;

typedef struct {
	unsigned int FBP : 9;
	unsigned int FBW : 6;
	unsigned int PSM : 5;
	unsigned int p0 : 12;
	unsigned int DBX : 11;
	unsigned int DBY : 11;
	unsigned int p1 : 10;
} tGS_DISPFB1;

typedef struct {
	unsigned int DX : 12;
	unsigned int DY : 11;
	unsigned int MAGH : 4;
	unsigned int MAGV : 2;
	unsigned int p0 : 3;
	unsigned int DW : 12;
	unsigned int DH : 11;
	unsigned int p1 : 9;
} tGS_DISPLAY1;

typedef struct {
	unsigned int FBP : 9;
	unsigned int FBW : 6;
	unsigned int PSM : 5;
	unsigned int p0 : 12;
	unsigned int DBX : 11;
	unsigned int DBY : 11;
	unsigned int p1 : 10;
} tGS_DISPFB2;

typedef struct {
	unsigned int DX : 12;
	unsigned int DY : 11;
	unsigned int MAGH : 4;
	unsigned int MAGV : 2;
	unsigned int p0 : 3;
	unsigned int DW : 12;
	unsigned int DH : 11;
	unsigned int p1 : 9;
} tGS_DISPLAY2;

typedef struct {
	unsigned int EXBP : 14;
	unsigned int EXBW : 6;
	unsigned int FBIN : 2;
	unsigned int WFFMD : 1;
	unsigned int EMODA : 2;
	unsigned int EMODC : 2;
	unsigned int p0 : 5;
	unsigned int WDX : 11;
	unsigned int WDY : 11;
	unsigned int p1 : 10;
} tGS_EXTBUF;

typedef struct {
	unsigned int SX : 12;
	unsigned int SY : 11;
	unsigned int SMPH : 4;
	unsigned int SMPV : 2;
	unsigned int p0 : 3;
	unsigned int WW : 12;
	unsigned int WH : 11;
	unsigned int p1 : 9;
} tGS_EXTDATA;

typedef struct {
	unsigned int WRITE : 1;
	unsigned int p0 : 31;
	unsigned int p1;
} tGS_EXTWRITE;

typedef struct {
	unsigned int R : 8;
	unsigned int G : 8;
	unsigned int B : 8;
	unsigned int p0 : 8;
	unsigned int p1;
} tGS_BGCOLOR;

typedef struct {
	unsigned int SIGNAL : 1;
	unsigned int FINISH : 1;
	unsigned int HSINT : 1;
	unsigned int VSINT : 1;
	unsigned int EDWINT : 1;
	unsigned int p0 : 3;
	unsigned int FLUSH : 1;
	unsigned int RESET : 1;
	unsigned int p1 : 2;
	unsigned int NFIELD : 1;
	unsigned int FIELD : 1;
	unsigned int FIFO : 2;
	unsigned int REV : 8;
	unsigned int ID : 8;
	unsigned int p2;
} tGS_CSR;

typedef struct {
	unsigned int p0 : 8;
	unsigned int SIGMSK : 1;
	unsigned int FINISHMSK : 1;
	unsigned int HSMSK : 1;
	unsigned int VSMSK : 1;
	unsigned int EDWMSK : 1;
	unsigned int p1 : 19;
	unsigned int p2;
} tGS_IMR;

typedef struct {
	unsigned int DIR : 1;
	unsigned int p0 : 31;
	unsigned int p1;
} tGS_BUSDIR;

typedef struct {
	unsigned int SIGID;
	unsigned int LBLID;
} tGS_SIGLBLID;

struct _sceDmaTag {
	u_short qwc;
	u_char mark;
	u_char id;
	_sceDmaTag *next;
	u_int p[2];
};

typedef struct {
	u_char sts;
	u_char std;
	u_char mfd;
	u_char rcycle;
	u_short express;
	u_short notify;
	u_short sqwc;
	u_short tqwc;
	void *rbadr;
	u_int rbmsk;
} sceDmaEnv;

typedef struct {
	u_long128 vf[32];
	u_int status;
	u_int mac;
	u_int clipping;
	u_int r;
	u_int i;
	u_int q;
	u_short vi[16];
} sceDevVu0Cnd;

typedef struct {
	u_long128 vf[32];
	u_int status;
	u_int mac;
	u_int clipping;
	u_int r;
	u_int i;
	u_int q;
	u_int p;
	u_short vi[16];
} sceDevVu1Cnd;

typedef struct {
	u_long128 tag;
	u_int stat;
	u_int count;
	u_int p3count;
	u_int p3tag;
	u_int pad;
} sceDevGifCnd;

typedef struct {
	u_int row[4];
	u_int col[4];
	u_int mask;
	u_int code;
	u_int stat;
	u_short itop;
	u_short itops;
	u_short mark;
	u_short num;
	u_char error;
	u_char cl;
	u_char wl;
	u_char cmod;
	u_char pad;
} sceDevVif0Cnd;

typedef struct {
	u_int row[4];
	u_int col[4];
	u_int mask;
	u_int code;
	u_int stat;
	u_short itop;
	u_short itops;
	u_short base;
	u_short offset;
	u_short top;
	u_short tops;
	u_short mark;
	u_short num;
	u_char error;
	u_char cl;
	u_char wl;
	u_char cmod;
	u_char pad;
} sceDevVif1Cnd;

typedef struct {
	long unsigned int A : 2;
	long unsigned int B : 2;
	long unsigned int C : 2;
	long unsigned int D : 2;
	long unsigned int pad8 : 24;
	long unsigned int FIX : 8;
	long unsigned int pad40 : 24;
} sceGsAlpha;

typedef struct {
	long unsigned int WMS : 2;
	long unsigned int WMT : 2;
	long unsigned int MINU : 10;
	long unsigned int MAXU : 10;
	long unsigned int MINV : 10;
	long unsigned int MAXV : 10;
	long unsigned int pad44 : 20;
} sceGsClamp;

typedef struct {
	long unsigned int CLAMP : 1;
	long unsigned int pad01 : 63;
} sceGsColclamp;

typedef struct {
	long unsigned int DIMX00 : 3;
	long unsigned int pad00 : 1;
	long unsigned int DIMX01 : 3;
	long unsigned int pad01 : 1;
	long unsigned int DIMX02 : 3;
	long unsigned int pad02 : 1;
	long unsigned int DIMX03 : 3;
	long unsigned int pad03 : 1;
	long unsigned int DIMX10 : 3;
	long unsigned int pad10 : 1;
	long unsigned int DIMX11 : 3;
	long unsigned int pad11 : 1;
	long unsigned int DIMX12 : 3;
	long unsigned int pad12 : 1;
	long unsigned int DIMX13 : 3;
	long unsigned int pad13 : 1;
	long unsigned int DIMX20 : 3;
	long unsigned int pad20 : 1;
	long unsigned int DIMX21 : 3;
	long unsigned int pad21 : 1;
	long unsigned int DIMX22 : 3;
	long unsigned int pad22 : 1;
	long unsigned int DIMX23 : 3;
	long unsigned int pad23 : 1;
	long unsigned int DIMX30 : 3;
	long unsigned int pad30 : 1;
	long unsigned int DIMX31 : 3;
	long unsigned int pad31 : 1;
	long unsigned int DIMX32 : 3;
	long unsigned int pad32 : 1;
	long unsigned int DIMX33 : 3;
	long unsigned int pad33 : 1;
} sceGsDimx;

typedef struct {
	long unsigned int DTHE : 1;
	long unsigned int pad01 : 63;
} sceGsDthe;

typedef struct {
	long unsigned int FBA : 1;
	long unsigned int pad01 : 63;
} sceGsFba;

typedef struct {
	long unsigned int pad00 : 56;
	long unsigned int F : 8;
} sceGsFog;

typedef struct {
	long unsigned int FCR : 8;
	long unsigned int FCG : 8;
	long unsigned int FCB : 8;
	long unsigned int pad24 : 40;
} sceGsFogcol;

typedef struct {
	long unsigned int FBP : 9;
	long unsigned int pad09 : 7;
	long unsigned int FBW : 6;
	long unsigned int pad22 : 2;
	long unsigned int PSM : 6;
	long unsigned int pad30 : 2;
	long unsigned int FBMSK : 32;
} sceGsFrame;

typedef struct {
	long unsigned int WDATA;
} sceGsHwreg;

typedef struct {
	u_int ID;
	u_int IDMSK;
} sceGsLabel;

typedef struct {
	long unsigned int TBP1 : 14;
	long unsigned int TBW1 : 6;
	long unsigned int TBP2 : 14;
	long unsigned int TBW2 : 6;
	long unsigned int TBP3 : 14;
	long unsigned int TBW3 : 6;
	long unsigned int pad60 : 4;
} sceGsMiptbp1;

typedef struct {
	long unsigned int TBP4 : 14;
	long unsigned int TBW4 : 6;
	long unsigned int TBP5 : 14;
	long unsigned int TBW5 : 6;
	long unsigned int TBP6 : 14;
	long unsigned int TBW6 : 6;
	long unsigned int pad60 : 4;
} sceGsMiptbp2;

typedef struct {
	long unsigned int PABE : 1;
	long unsigned int pad01 : 63;
} sceGsPabe;

typedef struct {
	long unsigned int PRIM : 3;
	long unsigned int IIP : 1;
	long unsigned int TME : 1;
	long unsigned int FGE : 1;
	long unsigned int ABE : 1;
	long unsigned int AA1 : 1;
	long unsigned int FST : 1;
	long unsigned int CTXT : 1;
	long unsigned int FIX : 1;
	long unsigned int pad11 : 53;
} sceGsPrim;

typedef struct {
	long unsigned int pad00 : 3;
	long unsigned int IIP : 1;
	long unsigned int TME : 1;
	long unsigned int FGE : 1;
	long unsigned int ABE : 1;
	long unsigned int AA1 : 1;
	long unsigned int FST : 1;
	long unsigned int CTXT : 1;
	long unsigned int FIX : 1;
	long unsigned int pad11 : 53;
} sceGsPrmode;

typedef struct {
	long unsigned int AC : 1;
	long unsigned int pad01 : 63;
} sceGsPrmodecont;

typedef struct {
	u_int R : 8;
	u_int G : 8;
	u_int B : 8;
	u_int A : 8;
	float Q;
} sceGsRgbaq;

typedef struct {
	long unsigned int MSK : 2;
	long unsigned int pad02 : 62;
} sceGsScanmsk;

typedef struct {
	long unsigned int SCAX0 : 11;
	long unsigned int pad11 : 5;
	long unsigned int SCAX1 : 11;
	long unsigned int pad27 : 5;
	long unsigned int SCAY0 : 11;
	long unsigned int pad43 : 5;
	long unsigned int SCAY1 : 11;
	long unsigned int pad59 : 5;
} sceGsScissor;

typedef struct {
	float S;
	float T;
} sceGsSt;

typedef struct {
	long unsigned int ATE : 1;
	long unsigned int ATST : 3;
	long unsigned int AREF : 8;
	long unsigned int AFAIL : 2;
	long unsigned int DATE : 1;
	long unsigned int DATM : 1;
	long unsigned int ZTE : 1;
	long unsigned int ZTST : 2;
	long unsigned int pad19 : 45;
} sceGsTest;

typedef struct {
	long unsigned int TBP0 : 14;
	long unsigned int TBW : 6;
	long unsigned int PSM : 6;
	long unsigned int TW : 4;
	long unsigned int TH : 4;
	long unsigned int TCC : 1;
	long unsigned int TFX : 2;
	long unsigned int CBP : 14;
	long unsigned int CPSM : 4;
	long unsigned int CSM : 1;
	long unsigned int CSA : 5;
	long unsigned int CLD : 3;
} sceGsTex0;

typedef struct {
	long unsigned int LCM : 1;
	long unsigned int pad01 : 1;
	long unsigned int MXL : 3;
	long unsigned int MMAG : 1;
	long unsigned int MMIN : 3;
	long unsigned int MTBA : 1;
	long unsigned int pad10 : 9;
	long unsigned int L : 2;
	long unsigned int pad21 : 11;
	long unsigned int K : 12;
	long unsigned int pad44 : 20;
} sceGsTex1;

typedef struct {
	long unsigned int pad00 : 20;
	long unsigned int PSM : 6;
	long unsigned int pad26 : 11;
	long unsigned int CBP : 14;
	long unsigned int CPSM : 4;
	long unsigned int CSM : 1;
	long unsigned int CSA : 5;
	long unsigned int CLD : 3;
} sceGsTex2;

typedef struct {
	long unsigned int TA0 : 8;
	long unsigned int pad08 : 7;
	long unsigned int AEM : 1;
	long unsigned int pad16 : 16;
	long unsigned int TA1 : 8;
	long unsigned int pad40 : 24;
} sceGsTexa;

typedef struct {
	long unsigned int CBW : 6;
	long unsigned int COU : 6;
	long unsigned int COV : 10;
	long unsigned int pad22 : 42;
} sceGsTexclut;

typedef struct {
	long unsigned int pad00;
} sceGsTexflush;

typedef struct {
	long unsigned int U : 14;
	long unsigned int pad14 : 2;
	long unsigned int V : 14;
	long unsigned int pad30 : 34;
} sceGsUv;

typedef struct {
	long unsigned int OFX : 16;
	long unsigned int pad16 : 16;
	long unsigned int OFY : 16;
	long unsigned int pad48 : 16;
} sceGsXyoffset;

typedef struct {
	long unsigned int X : 16;
	long unsigned int Y : 16;
	long unsigned int Z : 32;
} sceGsXyz;

typedef struct {
	long unsigned int X : 16;
	long unsigned int Y : 16;
	long unsigned int Z : 24;
	long unsigned int F : 8;
} sceGsXyzf;

typedef struct {
	long unsigned int ZBP : 9;
	long unsigned int pad09 : 15;
	long unsigned int PSM : 4;
	long unsigned int pad28 : 4;
	long unsigned int ZMSK : 1;
	long unsigned int pad33 : 31;
} sceGsZbuf;

typedef struct {
	sceGsFrame frame2;
	u_long frame2addr;
	sceGsZbuf zbuf2;
	long int zbuf2addr;
	sceGsXyoffset xyoffset2;
	long int xyoffset2addr;
	sceGsScissor scissor2;
	long int scissor2addr;
	sceGsPrmodecont prmodecont;
	long int prmodecontaddr;
	sceGsColclamp colclamp;
	long int colclampaddr;
	sceGsDthe dthe;
	long int dtheaddr;
	sceGsTest test2;
	long int test2addr;
} sceGsDrawEnv2;

typedef struct {
	sceGsDispEnv disp[2];
	sceGifTag giftag0;
	sceGsDrawEnv1 draw01;
	sceGsDrawEnv2 draw02;
	sceGsClear clear0;
	sceGifTag giftag1;
	sceGsDrawEnv1 draw11;
	sceGsDrawEnv2 draw12;
	sceGsClear clear1;
} sceGsDBuffDc;

typedef struct {
	sceGsTexflush texflush;
	long int texflushaddr;
	sceGsTex1 tex11;
	long int tex11addr;
	sceGsTex0 tex01;
	long int tex01addr;
	sceGsClamp clamp1;
	long int clamp1addr;
} sceGsTexEnv;

typedef struct {
	sceGsTexflush texflush;
	long int texflushaddr;
	sceGsTex1 tex12;
	long int tex12addr;
	sceGsTex0 tex02;
	long int tex02addr;
	sceGsClamp clamp2;
	long int clamp2addr;
} sceGsTexEnv2;

typedef struct {
	sceGsAlpha alpha1;
	long int alpha1addr;
	sceGsPabe pabe;
	long int pabeaddr;
	sceGsTexa texa;
	long int texaaddr;
	sceGsFba fba1;
	long int fba1addr;
} sceGsAlphaEnv;

typedef struct {
	sceGsAlpha alpha2;
	long int alpha2addr;
	sceGsPabe pabe;
	long int pabeaddr;
	sceGsTexa texa;
	long int texaaddr;
	sceGsFba fba2;
	long int fba2addr;
} sceGsAlphaEnv2;

typedef struct {
	sceGifTag giftag0;
	sceGsBitbltbuf bitbltbuf;
	long int bitbltbufaddr;
	sceGsTrxpos trxpos;
	long int trxposaddr;
	sceGsTrxreg trxreg;
	long int trxregaddr;
	sceGsTrxdir trxdir;
	long int trxdiraddr;
	sceGifTag giftag1;
} sceGsLoadImage;

typedef struct {
	short int sceGsInterMode;
	short int sceGsOutMode;
	short int sceGsFFMode;
	short int sceGsVersion;
	int (*sceGsVSCfunc)(/* parameters unknown */);
	int sceGsVSCid;
} sceGsGParam;

typedef struct {
	u_int *pCurrent;
	u_long128 *pBase;
	u_long128 *pDmaTag;
	u_long *pGifTag;
} sceGifPacket;

typedef struct {
	u_char y[256];
	u_char cb[64];
	u_char cr[64];
} sceIpuRAW8;

typedef struct {
	short int y[256];
	short int cb[64];
	short int cr[64];
} sceIpuRAW16;

typedef struct {
	u_int pix[256];
} sceIpuRGB32;

typedef struct {
	u_short pix[256];
} sceIpuRGB16;

typedef struct {
	u_int pix[32];
} sceIpuINDX4;

typedef struct {
	u_int d4madr;
	u_int d4tadr;
	u_int d4qwc;
	u_int d4chcr;
	u_int d3madr;
	u_int d3qwc;
	u_int d3chcr;
	u_int ipubp;
	u_int ipuctrl;
} sceIpuDmaEnv;

struct sce_stat {
	unsigned int st_mode;
	unsigned int st_attr;
	unsigned int st_size;
	unsigned char st_ctime[8];
	unsigned char st_atime[8];
	unsigned char st_mtime[8];
	unsigned int st_hisize;
	unsigned int st_private[6];
};

struct sce_dirent {
	sce_stat d_stat;
	char d_name[256];
	void *d_private;
};

typedef struct {
	unsigned int epc;
	unsigned int gp;
	unsigned int sp;
	unsigned int dummy;
} sceExecData;

typedef int _iconVu0IVECTOR[4];
typedef float _iconVu0FVECTOR[4];

typedef struct {
	unsigned char Head[4];
	short unsigned int Reserv1;
	short unsigned int OffsLF;
	unsigned int Reserv2;
	unsigned int TransRate;
	_iconVu0IVECTOR BgColor[4];
	_iconVu0FVECTOR LightDir[3];
	_iconVu0FVECTOR LightColor[3];
	_iconVu0FVECTOR Ambient;
	unsigned char TitleName[68];
	unsigned char FnameView[64];
	unsigned char FnameCopy[64];
	unsigned char FnameDel[64];
	unsigned char Reserve3[512];
} sceMcIconSys;

typedef struct {
	struct {
		unsigned char Resv2;
		unsigned char Sec;
		unsigned char Min;
		unsigned char Hour;
		unsigned char Day;
		unsigned char Month;
		short unsigned int Year;
	} _Create;
	struct {
		unsigned char Resv2;
		unsigned char Sec;
		unsigned char Min;
		unsigned char Hour;
		unsigned char Day;
		unsigned char Month;
		short unsigned int Year;
	} _Modify;
	unsigned int FileSizeByte;
	short unsigned int AttrFile;
	short unsigned int Reserve1;
	unsigned int Reserve2;
	unsigned int PdaAplNo;
	unsigned char EntryName[32];
} sceMcTblGetDir;

typedef int qword[4];
typedef int sceVu0IVECTOR[4];
typedef float sceVu0FVECTOR[4];
typedef float sceVu0FMATRIX[4][4];

struct _sif_rpc_data {
	void *paddr;
	unsigned int pid;
	int tid;
	unsigned int mode;
};

typedef _sif_rpc_data sceSifRpcData;
typedef void (*sceSifEndFunc)(/* parameters unknown */);

struct _sif_client_data {
	_sif_rpc_data rpcd;
	unsigned int command;
	void *buff;
	void *cbuff;
	sceSifEndFunc func;
	void *para;
	_sif_serve_data *serve;
};

struct _sif_receive_data {
	_sif_rpc_data rpcd;
	void *src;
	void *dest;
	int size;
};

typedef _sif_receive_data sceSifReceiveData;
typedef void* (*sceSifRpcFunc)(/* parameters unknown */);

struct _sif_serve_data {
	unsigned int command;
	sceSifRpcFunc func;
	void *buff;
	int size;
	sceSifRpcFunc cfunc;
	void *cbuff;
	int csize;
	sceSifClientData *client;
	void *paddr;
	unsigned int fno;
	void *receive;
	int rsize;
	int rmode;
	unsigned int rid;
	_sif_serve_data *link;
	_sif_serve_data *next;
	_sif_queue_data *base;
};

typedef _sif_serve_data sceSifServeData;

struct _sif_queue_data {
	int key;
	int active;
	_sif_serve_data *link;
	_sif_serve_data *start;
	_sif_serve_data *end;
	_sif_queue_data *next;
};

typedef _sif_queue_data sceSifQueueData;

typedef struct {
	unsigned int psize : 8;
	unsigned int dsize : 24;
	unsigned int daddr;
	unsigned int fcode;
	unsigned int opt;
} sceSifCmdHdr;

typedef void (*sceSifCmdHandler)(/* parameters unknown */);

typedef struct {
	sceSifCmdHandler func;
	void *data;
} sceSifCmdData;

typedef struct {
	sceSifCmdHdr chdr;
	void *newaddr;
} sceSifCmdCSData;

typedef struct {
	sceSifCmdHdr chdr;
	int rno;
	unsigned int value;
} sceSifCmdSRData;

typedef struct {
	sceSifCmdHdr chdr;
	int size;
	int flag;
	char arg[80];
} sceSifCmdResetData;

typedef enum {
	STR_NULL = 0,
	STR_TILES_START_ALL = 1,
	STR_TILES_START_TEAM_RED = 2,
	STR_TILES_START_TEAM_BLUE = 3,
	STR_TILES_START_TEAM_YELLOW = 4,
	STR_TILES_START_TEAM_GREEN = 5,
	STR_TILES_BAG_BASE_RED = 6,
	STR_TILES_BAG_BASE_BLUE = 7,
	STR_TILES_BAG_BASE_YELLOW = 8,
	STR_TILES_BAG_BASE_GREEN = 9,
	STR_TILES_TELEPORT_A = 10,
	STR_TILES_TELEPORT_B = 11,
	STR_TILES_TELEPORT_C = 12,
	STR_TILES_TELEPORT_D = 13,
	STR_TILES_TELEPORT_E = 14,
	STR_TILES_TELEPORT_F = 15,
	STR_TILES_TELEPORT_G = 16,
	STR_TILES_TELEPORT_H = 17,
	STR_TILES_TELEPORT_I = 18,
	STR_TILES_TELEPORT_J = 19,
	STR_TILES_PICKUP_GUN_1 = 20,
	STR_TILES_PICKUP_GUN_2 = 21,
	STR_TILES_PICKUP_GUN_3 = 22,
	STR_TILES_PICKUP_GUN_4 = 23,
	STR_TILES_PICKUP_GUN_5 = 24,
	STR_TILES_PICKUP_AMMO_1 = 25,
	STR_TILES_PICKUP_AMMO_2 = 26,
	STR_TILES_PICKUP_AMMO_3 = 27,
	STR_TILES_PICKUP_AMMO_4 = 28,
	STR_TILES_PICKUP_AMMO_5 = 29,
	STR_TILES_KEYCARD_1 = 30,
	STR_TILES_KEYCARD_2 = 31,
	STR_TILES_KEYCARD_3 = 32,
	STR_TILES_KEYCARD_4 = 33,
	STR_TILES_BAG_BAGTAG = 34,
	STR_TILES_BAG_KNOCKOUT = 35,
	STR_TILES_HEALTH_LO = 36,
	STR_TILES_HEALTH_HI = 37,
	STR_TILES_ARMOUR_LO = 38,
	STR_TILES_ARMOUR_HI = 39,
	STR_TILES_POWERUP_1 = 40,
	STR_TILES_POWERUP_2 = 41,
	STR_TILES_POWERUP_3 = 42,
	STR_TILES_POWERUP_4 = 43,
	STR_TILES_POWERUP_5 = 44,
	STR_TILES_ITEM_PROP = 45,
	STR_TILES_ITEM_FIXEDGUN = 46,
	STR_TILES_ITEM_AUTOGUN = 47,
	STR_TILES_NPC_1 = 48,
	STR_TILES_NPC_2 = 49,
	STR_TILES_NPC_3 = 50,
	STR_TILES_NPC_4 = 51,
	STR_TILES_NPC_5 = 52,
	STR_TILES_NPC_6 = 53,
	STR_CHR_EVIL_COWBOY = 54,
	STR_CHR_JUNGLE_QUEEN = 55,
	STR_CHR_MONKEY = 56,
	STR_CHR_STONE_GOLEM = 57,
	STR_CHR_WOOD_GOLEM = 58,
	STR_CHR_COWGIRL = 59,
	STR_CHR_MAIN_COWBOY = 60,
	STR_CHR_MEXICAN = 61,
	STR_CHR_CURTAINS_COWBOY = 62,
	STR_CHR_MINER = 63,
	STR_CHR_SALOON_HOOER = 64,
	STR_CHR_SKINNY_HOOER = 65,
	STR_CHR_BRACES_THUG = 66,
	STR_CHR_GODFATHER = 67,
	STR_CHR_JESTER = 68,
	STR_CHR_WITCH = 69,
	STR_CHR_BARREL_ROBOT = 70,
	STR_CHR_RAILSPIDER_ROBOT = 71,
	STR_CHR_BERET_SOLDIER_ARTIC = 72,
	STR_CHR_BERET_SOLDIER_DESERT = 73,
	STR_CHR_BERET_SOLDIER_WOOD = 74,
	STR_CHR_BERET_SOLDIER_SPFORCE = 75,
	STR_CHR_BERET_SOLDIER_ZOMBIE = 76,
	STR_CHR_HELMET_SOLDIER_DESERT = 77,
	STR_CHR_HELMET_SOLDIER_ARTIC = 78,
	STR_CHR_HELMET_SOLDIER_WOOD = 79,
	STR_CHR_HELMET_SOLDIER_SPFORCE = 80,
	STR_CHR_HELMET_SOLDIER_ZOMBIE = 81,
	STR_CHR_FEMALE_SOLDIER_ARTIC = 82,
	STR_CHR_FEMALE_SOLDIER_DESERT = 83,
	STR_CHR_FEMALE_SOLDIER_HAT = 84,
	STR_CHR_FEMALE_SOLDIER_SPFORCE = 85,
	STR_CHR_FEMALE_SOLDIER_WOOD = 86,
	STR_CHR_FEMALE_SOLDIER_ZOMBIE = 87,
	STR_CHR_FEMALE_SOLDIER_ZOMBIEHAT = 88,
	STR_CHR_GASMASK_SOLDIER_ARTIC = 89,
	STR_CHR_GASMASK_SOLDIER_DESERT = 90,
	STR_CHR_GASMASK_SOLDIER_SPFORCE = 91,
	STR_CHR_GASMASK_SOLDIER_WOOD = 92,
	STR_CHR_GASMASK_SOLDIER_ZOMBIE = 93,
	STR_CHR_VEIL_SOLDIER_ARTIC = 94,
	STR_CHR_VEIL_SOLDIER_DESERT = 95,
	STR_CHR_VEIL_SOLDIER_SPFORCE = 96,
	STR_CHR_VEIL_SOLDIER_WOOD = 97,
	STR_CHR_VEIL_SOLDIER_ZOMBIE = 98,
	STR_CHR_SOLDIER_MUTANT = 99,
	STR_CHR_ILSA_NADIR = 100,
	STR_CHR_BIG_ROBOT = 101,
	STR_CHR_KID_ROBOT = 102,
	STR_CHR_JACQUES_MISERE = 103,
	STR_CHR_OLGA_STROM = 104,
	STR_CHR_MALEHOOD = 105,
	STR_CHR_CULTIST = 106,
	STR_CHR_DUCKMAN_DRAKE = 107,
	STR_CHR_DUCKMAN = 108,
	STR_CHR_THE_IMPERSONATOR = 109,
	STR_CHR_IMPERSONATOR = 110,
	STR_CHR_GINGERBREAD_MAN = 111,
	STR_CHR_GINGER = 112,
	STR_CHR_FARRAH_FUN_BUNNY = 113,
	STR_CHR_FUN_BUNNY = 114,
	STR_CHR_ROBOFISH = 115,
	STR_CHR_NONAME = 116,
	STR_CHR_PRIESTESS = 117,
	STR_CHR_LUMBERJACK = 118,
	STR_CHR_CHINESE_WAITER = 119,
	STR_CHR_WAITER = 120,
	STR_CHR_MR_BIG = 121,
	STR_CHR_FEMALE_ALIEN = 122,
	STR_CHR_PILLAR_ALIEN = 123,
	STR_CHR_FLOAT_ALIEN = 124,
	STR_CHR_RED_ALIEN = 125,
	STR_CHR_GREEN_ALIEN = 126,
	STR_CHR_FEMALE_CYBORG = 127,
	STR_CHR_SIAMESE_CYBORG = 128,
	STR_CHR_TUXEDO_CYBORG = 129,
	STR_CHR_BADASS_CYBORG = 130,
	STR_CHR_POLICE_ZOMBIE = 131,
	STR_CHR_GIRL_ZOMBIE = 132,
	STR_CHR_JACKET_ZOMBIE = 133,
	STR_CHR_BROWN_ZOMBIE = 134,
	STR_CHR_GREEN_ZOMBIE = 135,
	STR_CHR_HICK_MUTANT = 136,
	STR_CHR_FISHWIFE_MUTANT = 137,
	STR_CHR_INSECT_MUTANT = 138,
	STR_CHR_OVERALL_MUTANT = 139,
	STR_CHR_PRIEST_MUTANT = 140,
	STR_CHR_MALE_SWAT = 141,
	STR_CHR_GASMASK_SWAT = 142,
	STR_CHR_VEILED_SWAT = 143,
	STR_CHR_FEMALE_SWAT = 144,
	STR_CHR_SPACEWAYS_STEWARDESS = 145,
	STR_CHR_STEWARDESS = 146,
	STR_CHR_MALE_SOLDIER = 147,
	STR_CHR_GASMASK_SOLDIER = 148,
	STR_CHR_SHOCK_TROOPER = 149,
	STR_CHR_FEMALE_SOLDIER = 150,
	STR_CHR_TEETH_MUMMY = 151,
	STR_CHR_EYES_MUMMY = 152,
	STR_CHR_SUIT_HOODLUM = 153,
	STR_CHR_CHINESE_CHEF = 154,
	STR_CHR_CHEF = 155,
	STR_CHR_SKULL_ZOMBIE = 156,
	STR_CHR_TIMESPLITTER = 157,
	STR_CHR_BLUEROBOT = 158,
	STR_ENEMY_PHASE = 159,
	STR_ENEMY_COMPLETE = 160,
	STR_ENEMY_PHASE_BONUS = 161,
	STR_ENEMY_POINTS = 162,
	STR_FRONT_NONE1 = 163,
	STR_FRONT_ON1 = 164,
	STR_FRONT_OFF = 165,
	STR_FRONT_YES = 166,
	STR_FRONT_NO = 167,
	STR_FRONT_STATISTICS1 = 168,
	STR_FRONT_SAVING_GAME_STATUS = 169,
	STR_FRONT_SIGN_ON1 = 170,
	STR_FRONT_SELECT_GAME_TYPE = 171,
	STR_FRONT_AUDIO_VIDEO_OPTIONS1 = 172,
	STR_FRONT_SELECT_LEVEL = 173,
	STR_FRONT_SELECT_CHALLENGE = 174,
	STR_FRONT_MAPMAKER1 = 175,
	STR_FRONT_OPTIONS = 176,
	STR_FRONT_SETUP_WEAPONS = 177,
	STR_FRONT_SETUP_BOTS = 178,
	STR_FRONT_2_START = 179,
	STR_FRONT_2_SELECT = 180,
	STR_FRONT_2_ENTER = 181,
	STR_FRONT_CHEATS = 182,
	STR_FRONT_ON2 = 183,
	STR_FRONT_KILLS_LOSSES = 184,
	STR_FRONT_KILLS = 185,
	STR_FRONT_1_CHEATS_MENU = 186,
	STR_FRONT_PLAYER1 = 187,
	STR_FRONT_TIMESPLITTERS_SIGN_ONS_ON = 188,
	STR_FRONT_MEMORY_CARD_PS2_IN1 = 189,
	STR_FRONT_MAY_BE_CORRUPTED = 190,
	STR_FRONT_NO_TIMESPLITTERS_SIGN_ONS_ON = 191,
	STR_FRONT_MEMORY_CARD_PS2_IN2 = 192,
	STR_FRONT_TIMESPLITTERS_SIGN_ONS_IN = 193,
	STR_FRONT_HAVE = 194,
	STR_FRONT_ALREADY_BEEN_LOADED = 195,
	STR_FRONT_SAVE_PLAYER = 196,
	STR_FRONT_CAN_NOT_SAVE_SIGN_ON = 197,
	STR_FRONT_ALL_16_SIGN_ON_SLOTS_ARE_USED = 198,
	STR_FRONT_ON3 = 199,
	STR_FRONT_DELETE_A_SIGN_ON_AND_TRY_AGAIN = 200,
	STR_FRONT_A_SIGN_ON_NAMED = 201,
	STR_FRONT_ALREADY_EXISTS_ON_MEMORY_CARD_PS2 = 202,
	STR_FRONT_IN1 = 203,
	STR_FRONT_MEMORY_CARD_PS2_IN3 = 204,
	STR_FRONT_HAS_BEEN_CHANGED1 = 205,
	STR_FRONT_PLEASE_INSERT_MEMORY_CARD_PS2_CONTAINING1 = 206,
	STR_FRONT_INTO1 = 207,
	STR_FRONT_MEMORY_CARD_PS2_IN4 = 208,
	STR_FRONT_HAS_BEEN_REMOVED1 = 209,
	STR_FRONT_PLEASE_INSERT_MEMORY_CARD_PS2_CONTAINING2 = 210,
	STR_FRONT_INTO2 = 211,
	STR_FRONT_PLAYER2 = 212,
	STR_FRONT_MEMORY_CARD_PS2 = 213,
	STR_FRONT_IN2 = 214,
	STR_FRONT_HAS_BEEN_CHANGED2 = 215,
	STR_FRONT_DELETE_FAILED1 = 216,
	STR_FRONT_MEMORY_CARD_PS2_IN5 = 217,
	STR_FRONT_HAS_BEEN_REMOVED2 = 218,
	STR_FRONT_DELETE_FAILED2 = 219,
	STR_FRONT_EXIT1 = 220,
	STR_FRONT_2_SELECT_BOT = 221,
	STR_FRONT_2_OK_3_CANCEL = 222,
	STR_FRONT_2_MOVE_1_COPY_TO_ALL_4_CLEAR = 223,
	STR_FRONT_2_CHANGE_1_COPY_TO_ALL = 224,
	STR_FRONT_2_CHANGE_1_COPY_TO_ALL_4_CLEAR = 225,
	STR_FRONT_MUSIC = 226,
	STR_FRONT_MUSIC_VOLUME = 227,
	STR_FRONT_SOUND = 228,
	STR_FRONT_SOUND_VOLUME = 229,
	STR_FRONT_4_CHANNEL_SOUND = 230,
	STR_FRONT_SCREEN_ADJUST = 231,
	STR_FRONT_EXIT2 = 232,
	STR_FRONT_3_BACK1 = 233,
	STR_FRONT_2_START_GAME = 234,
	STR_FRONT_3_BACK2 = 235,
	STR_FRONT_2_OK_3_BACK1 = 236,
	STR_FRONT_2_OK1 = 237,
	STR_FRONT_2_OK_3_BACK2 = 238,
	STR_FRONT_2_OK_3_BACK3 = 239,
	STR_FRONT_WEAPON_SET = 240,
	STR_FRONT_BOT_SET = 241,
	STR_FRONT_GO = 242,
	STR_FRONT_BACK1 = 243,
	STR_FRONT_TIME_LIMIT1 = 244,
	STR_FRONT_BAG_CARRIER_CAN_SHOOT = 245,
	STR_FRONT_TEAMPLAY1 = 246,
	STR_FRONT_USE_TEAM_STARTS1 = 247,
	STR_FRONT_FRIENDLY_FIRE_DAMAGE = 248,
	STR_FRONT_ALWAYS_START_WITH_GUN1 = 249,
	STR_FRONT_DISPLAY_RADAR1 = 250,
	STR_FRONT_HANDICAPS1 = 251,
	STR_FRONT_SCORE_LIMIT1 = 252,
	STR_FRONT_TIME_LIMIT2 = 253,
	STR_FRONT_FRIENDLY_FIRE_DAMAGE1 = 254,
	STR_FRONT_ALWAYS_START_WITH_GUN2 = 255,
	STR_FRONT_DISPLAY_RADAR2 = 256,
	STR_FRONT_HANDICAPS2 = 257,
	STR_FRONT_SCORE_LIMIT2 = 258,
	STR_FRONT_SCORE_METHOD = 259,
	STR_FRONT_TIME_LIMIT3 = 260,
	STR_FRONT_TEAMPLAY2 = 261,
	STR_FRONT_USE_TEAM_STARTS2 = 262,
	STR_FRONT_FRIENDLY_FIRE_DAMAGE2 = 263,
	STR_FRONT_ALWAYS_START_WITH_GUN3 = 264,
	STR_FRONT_DISPLAY_RADAR3 = 265,
	STR_FRONT_ONE_SHOT_KILL = 266,
	STR_FRONT_HANDICAPS3 = 267,
	STR_FRONT_FRIENDLY_FIRE_DAMAGE3 = 268,
	STR_FRONT_ALWAYS_START_WITH_GUN4 = 269,
	STR_FRONT_DISPLAY_RADAR4 = 270,
	STR_FRONT_HANDICAPS4 = 271,
	STR_FRONT_SCORE_LIMIT3 = 272,
	STR_FRONT_TIME_LIMIT4 = 273,
	STR_FRONT_FRIENDLY_FIRE_DAMAGE4 = 274,
	STR_FRONT_ALWAYS_START_WITH_GUN5 = 275,
	STR_FRONT_DISPLAY_RADAR5 = 276,
	STR_FRONT_HANDICAPS5 = 277,
	STR_FRONT_FRIENDLY_FIRE_DAMAGE5 = 278,
	STR_FRONT_DISPLAY_RADAR6 = 279,
	STR_FRONT_HANDICAPS6 = 280,
	STR_FRONT_MINS1 = 281,
	STR_FRONT_POINTS = 282,
	STR_FRONT_2_EDIT = 283,
	STR_FRONT_BACK2 = 284,
	STR_FRONT_ARCADE_CHEATS = 285,
	STR_FRONT_STORY_CHEATS = 286,
	STR_FRONT_NO_TIMESPLITTERS_MAPS = 287,
	STR_FRONT_3_EXIT_4_CHANGE_MEMORY_CARD_PS2 = 288,
	STR_FRONT_MORE_UP = 289,
	STR_FRONT_MORE_DOWN = 290,
	STR_FRONT_DIRECTORY_IS_CORRUPT_2_OK = 291,
	STR_FRONT_THERE_IS_NO_MEMORY_CARD_PS2_2_OK = 292,
	STR_FRONT_MAPS_ON = 293,
	STR_FRONT_DATA_IS_CORRUPT_LOAD_FAILED_2_OK = 294,
	STR_FRONT_LOAD_FAILED_2_OK = 295,
	STR_FRONT_MAPMAKER2 = 296,
	STR_FRONT_LOAD_MAP = 297,
	STR_FRONT_EDIT_MAP = 298,
	STR_FRONT_EXIT3 = 299,
	STR_FRONT_TILE_SET = 300,
	STR_FRONT_BACK3 = 301,
	STR_FRONT_MAPMAKER3 = 302,
	STR_FRONT_2_SELECT_A_MAP = 303,
	STR_FRONT_ARCADE1 = 304,
	STR_FRONT_EASY = 305,
	STR_FRONT_NORMAL = 306,
	STR_FRONT_HARD = 307,
	STR_FRONT_BACK4 = 308,
	STR_FRONT_DASH1 = 309,
	STR_FRONT_STORY1 = 310,
	STR_FRONT_BACK5 = 311,
	STR_FRONT_BEST = 312,
	STR_FRONT_DASH2 = 313,
	STR_FRONT_PLAYER3 = 314,
	STR_FRONT_GAME_TYPE = 315,
	STR_FRONT_PAGE = 316,
	STR_FRONT_BACK6 = 317,
	STR_FRONT_FAVOURITE_CHARACTER = 318,
	STR_FRONT_NONE2 = 319,
	STR_FRONT_PLAYED_FOR = 320,
	STR_FRONT_NO_TIME = 321,
	STR_FRONT_DAYS = 322,
	STR_FRONT_HOURS = 323,
	STR_FRONT_MINS2 = 324,
	STR_FRONT_SECS = 325,
	STR_FRONT_TOTAL_GAMES = 326,
	STR_FRONT_TOTAL_KILLS = 327,
	STR_FRONT_TOTAL_LOSSES = 328,
	STR_FRONT_MOST_KILLS_WITHOUT_DYING = 329,
	STR_FRONT_MOST_KILLS_WITHIN_3_SECONDS = 330,
	STR_FRONT_LONGEST_KILLING_SPREE = 331,
	STR_FRONT_SUCCESS_RATE = 332,
	STR_FRONT_NOT_AVAILABLE1 = 333,
	STR_FRONT_NOT_APPLICABLE1 = 334,
	STR_FRONT_TIMESPLITTERS_DISPATCHED = 335,
	STR_FRONT_NOT_APPLICABLE2 = 336,
	STR_FRONT_FAVOURITE_WEAPON = 337,
	STR_FRONT_UNARMED = 338,
	STR_FRONT_AWARDS_EARNED = 339,
	STR_FRONT_NOT_APPLICABLE3 = 340,
	STR_FRONT_TOTAL_BULLETS_FIRED = 341,
	STR_FRONT_ACCURACY = 342,
	STR_FRONT_NOT_AVAILABLE2 = 343,
	STR_FRONT_HEAD_SHOTS = 344,
	STR_FRONT_NOT_AVAILABLE3 = 345,
	STR_FRONT_BODY_SHOTS = 346,
	STR_FRONT_NOT_AVAILABLE4 = 347,
	STR_FRONT_ARM_SHOTS = 348,
	STR_FRONT_NOT_AVAILABLE5 = 349,
	STR_FRONT_LEG_SHOTS = 350,
	STR_FRONT_NOT_AVAILABLE6 = 351,
	STR_FRONT_HEADS_SHOT_OFF = 352,
	STR_FRONT_HEADS_PUNCHED_OFF = 353,
	STR_FRONT_GLASS_PANES_BROKEN = 354,
	STR_FRONT_DISTANCE_TRAVELLED = 355,
	STR_FRONT_MILES = 356,
	STR_FRONT_AVERAGE_SPEED = 357,
	STR_FRONT_MPH = 358,
	STR_FRONT_STATISTICS2 = 359,
	STR_FRONT_OVERALL = 360,
	STR_FRONT_STORY2 = 361,
	STR_FRONT_ARCADE2 = 362,
	STR_FRONT_CHALLENGE1 = 363,
	STR_FRONT_STORY3 = 364,
	STR_FRONT_ARCADE3 = 365,
	STR_FRONT_CHALLENGE2 = 366,
	STR_FRONT_VIEW_STATISTICS = 367,
	STR_FRONT_AUDIO_VIDEO_OPTIONS2 = 368,
	STR_FRONT_DEBUG_IMITATE_END_OF_LEVEL_FOR_FASTER_SAVE_TESTING = 369,
	STR_FRONT_BACK7 = 370,
	STR_FRONT_STORY4 = 371,
	STR_FRONT_ARCADE4 = 372,
	STR_FRONT_CHALLENGE3 = 373,
	STR_FRONT_VIEW_CREDITS = 374,
	STR_FRONT_3_BACK3 = 375,
	STR_FRONT_NEW_PLAYER = 376,
	STR_FRONT_LOAD_SIGN_ONS = 377,
	STR_FRONT_PLAYER4 = 378,
	STR_FRONT_4_DELETE_SIGN_ON = 379,
	STR_FRONT_MAXIMUM_OF_16_UNSAVED_SIGN_ONS_REACHED = 380,
	STR_FRONT_SIGN_ON2 = 381,
	STR_FRONT_CAN_NOT_BE_CREATED = 382,
	STR_FRONT_2_3_OK1 = 383,
	STR_FRONT_SIGN_ON_NAME = 384,
	STR_FRONT_IS_ALREADY_USED = 385,
	STR_FRONT_2_3_OK2 = 386,
	STR_FRONT_PLAYER5 = 387,
	STR_FRONT_ARE_YOU_SURE_YOU_WANT_TO_DELETE1 = 388,
	STR_FRONT_FROM_MEMORY_CARD_PS2_IN = 389,
	STR_FRONT_QUESTION = 390,
	STR_FRONT_2_YES_3_NO1 = 391,
	STR_FRONT_PLAYER6 = 392,
	STR_FRONT_ARE_YOU_SURE_YOU_WANT_TO_DELETE2 = 393,
	STR_FRONT_FROM_MEMORY = 394,
	STR_FRONT_2_YES_3_NO2 = 395,
	STR_FRONT_1UP = 396,
	STR_FRONT_2UP = 397,
	STR_FRONT_3UP = 398,
	STR_FRONT_4UP = 399,
	STR_FRONT_PLAYER7 = 400,
	STR_FRONT_UPDATE_SAVED_GAME_DATA = 401,
	STR_FRONT_2_YES_3_NO3 = 402,
	STR_FRONT_2_OK2 = 403,
	STR_FRONT_CUSTOM1 = 404,
	STR_FRONT_CUSTOM2 = 405,
	STR_FRONT_PLAYER8 = 406,
	STR_FRONT_PLAYER9 = 407,
	STR_FRONT_FAVOURITE_LEVEL = 408,
	STR_FRONT_NONE3 = 409,
	STR_FRONT_NONE4 = 410,
	STR_FRONT_NOT_APPLICABLE4 = 411,
	STR_FRONT_NOT_AVAILABLE7 = 412,
	STR_FRONT_NOT_APPLICABLE5 = 413,
	STR_FRONT_BOTS = 414,
	STR_FRONT_NO_BOTS = 415,
	STR_GUI_LOADING = 416,
	STR_MCSEQ_MEMORY_CARD_SLOT = 417,
	STR_MCSEQ_MEMORY_CARD_PS2_IN1 = 418,
	STR_MCSEQ_IS_UNFORMATTED1 = 419,
	STR_MCSEQ_DO_YOU_WANT_TO_FORMAT = 420,
	STR_MCSEQ_1_YES_3_NO1 = 421,
	STR_MCSEQ_2_ACCEPT_3_CANCEL = 422,
	STR_MCSEQ_3_CANCEL = 423,
	STR_MCSEQ_OPERATION_CANCELLED = 424,
	STR_MCSEQ_PLEASE_WAIT = 425,
	STR_MCSEQ_NO_MEMORY_CARD_PS2_INSERTED1 = 426,
	STR_MCSEQ_NO_MEMORY_CARD_PS2_INSERTED2 = 427,
	STR_MCSEQ_INTO = 428,
	STR_MCSEQ_MEMORY_CARD_PS2_IN2 = 429,
	STR_MCSEQ_IS_UNFORMATTED2 = 430,
	STR_MCSEQ_LOAD_FAILED = 431,
	STR_MCSEQ_LOAD_COMPLETED = 432,
	STR_MCSEQ_SAVE_FAILED1 = 433,
	STR_MCSEQ_SAVE_FAILED2 = 434,
	STR_MCSEQ_2_OK_3_BACK = 435,
	STR_MCSEQ_SAVE_COMPLETED = 436,
	STR_MCSEQ_DELETE_FAILED = 437,
	STR_MCSEQ_DELETE_COMPLETED = 438,
	STR_MCSEQ_TIMESPLITTERS_SIGN_ONS_ON = 439,
	STR_MCSEQ_MEMORY_CARD_PS2_IN3 = 440,
	STR_MCSEQ_MAY_BE_CORRUPTED = 441,
	STR_MCSEQ_WOULD_YOU_LIKE_TO_OVERWRITE = 442,
	STR_MCSEQ_INSUFFICIENT_FREE_SPACE_ON1 = 443,
	STR_MCSEQ_MEMORY_CARD_PS2_IN4 = 444,
	STR_MCSEQ_TIMESPLITTERS_SIGN_ONS_REQUIRE = 445,
	STR_MCSEQ_KB_OF1 = 446,
	STR_MCSEQ_FREE_SPACE_ON_THE_MEMORY_CARD_PS21 = 447,
	STR_MCSEQ_INSUFFICIENT_FREE_SPACE_ON2 = 448,
	STR_MCSEQ_MEMORY_CARD_PS2_IN5 = 449,
	STR_MCSEQ_TIMESPLITTERS_MAPS_REQUIRE = 450,
	STR_MCSEQ_KB_OF2 = 451,
	STR_MCSEQ_FREE_SPACE_ON_THE_MEMORY_CARD_PS22 = 452,
	STR_MCSEQ_2_OK1 = 453,
	STR_MCSEQ_OPERATION_FAILED = 454,
	STR_MCSEQ_2_OK2 = 455,
	STR_MCSEQ_2_RETRY_3_CANCEL = 456,
	STR_MCSEQ_2_YES_3_NO2 = 457,
	STR_MCSEQ_1_YES_3_NO2 = 458,
	STR_MESSAGES_CHEATS_ON = 459,
	STR_MESSAGES_LOAD_MAP = 460,
	STR_MESSAGES_EDIT_CREATE_NEW_MAP = 461,
	STR_MESSAGES_CURRENT_WEAPON_SET = 462,
	STR_MESSAGES_AVAILABLE_WEAPONS = 463,
	STR_MESSAGES_PRESET_WEAPONS = 464,
	STR_MESSAGES_SELECTED_WEAPONS = 465,
	STR_MESSAGES_2_EDIT_WEAPONS = 466,
	STR_MESSAGES_2_ADD_WEAPON_4_REMOVE_WEAPON = 467,
	STR_MESSAGES_CURRENT_BOT_SET = 468,
	STR_MESSAGES_AVAILABLE_BOTS = 469,
	STR_MESSAGES_PRESET_BOTS = 470,
	STR_MESSAGES_SELECTED_BOTS = 471,
	STR_MESSAGES_2_EDIT_BOTS = 472,
	STR_MESSAGES_SELECT_HANDICAP = 473,
	STR_MESSAGES_AWAITING_OTHER_PLAYERS = 474,
	STR_MESSAGES_DEFENDERS = 475,
	STR_MESSAGES_ATTACKERS = 476,
	STR_MESSAGES_DEFENDERS_TEAM = 477,
	STR_MESSAGES_ATTACKERS_TEAM = 478,
	STR_MESSAGES_NOT_AN_ESCORT_TEAM = 479,
	STR_MESSAGES_TEAM_NOT_SET_IN_MAP = 480,
	STR_MESSAGES_THERE_ARE_NO_BOTS_IN_THE_ATTACKER_TEAM = 481,
	STR_MESSAGES_THERE_ARE_NO_BOTS_IN_THE_DEFENDERS_TEAM = 482,
	STR_MESSAGES_THERE_ARE_NO_BOTS_ACTIVATED = 483,
	STR_MESSAGES_THERE_ARE_TEAM_STARTS_FOR_ONLY_ONE_TEAM = 484,
	STR_MESSAGES_NEW_CHEAT_AVAILABLE = 485,
	STR_MESSAGES_NEW_ARCADE_LEVEL_AVAILABLE = 486,
	STR_MESSAGES_NEW_ARCADE_BOT_AVAILABLE = 487,
	STR_MESSAGES_NEW_PLAYABLE_CHARACTER_AVAILABLE = 488,
	STR_MESSAGES_THE_BRICK_IS_NOW_AVAILABLE = 489,
	STR_MESSAGES_CHALLENGE_MODE_AVAILABLE = 490,
	STR_MESSAGES_NEW_ARCADE_BOT_SET_AVAILABLE = 491,
	STR_MESSAGES_DASH = 492,
	STR_MESSAGES_1_MINUTE_LEFT = 493,
	STR_MESSAGES_10_SECONDS_LEFT = 494,
	STR_MESSAGES_FIRST_KILL = 495,
	STR_MESSAGES_2_RESTART = 496,
	STR_MESSAGES_3_QUIT = 497,
	STR_MESSAGES_PRESS_2_TO_END_GAME = 498,
	STR_MESSAGES_PRESS_2_TO_RETURN_TO_MAPMAKER = 499,
	STR_MESSAGES_MISSION_BRIEFING = 500,
	STR_MESSAGES_YOUR_TIME_SO_FAR = 501,
	STR_MESSAGES_LEVEL_COMPLETED = 502,
	STR_MESSAGES_GAME_OVER1 = 503,
	STR_MESSAGES_YOUR_TIME = 504,
	STR_MESSAGES_BEST_TIME = 505,
	STR_MESSAGES_NEW_BEST_TIME = 506,
	STR_MESSAGES_DEFENDERS_WIN = 507,
	STR_MESSAGES_DEFENDERS_LOSE = 508,
	STR_MESSAGES_ESCORTEE_HEALTH_LEFT = 509,
	STR_MESSAGES_ESCORTEE_DIED = 510,
	STR_MESSAGES_LASTSTAND_OBJECTIVE = 511,
	STR_MESSAGES_GAME_OVER2 = 512,
	STR_MESSAGES_COMPLETED = 513,
	STR_MESSAGES_FAILED = 514,
	STR_MESSAGES_YOUR_SCORE = 515,
	STR_MESSAGES_BEST_SCORE = 516,
	STR_MESSAGES_NEW_BEST_SCORE = 517,
	STR_MESSAGES_HURRY_UP = 518,
	STR_MESSAGES_ENTER_MAP_DESCRIPTION = 519,
	STR_MESSAGES_MEMORY_CARD_PS2 = 520,
	STR_MESSAGES_MEMORY_CARD_SLOT = 521,
	STR_MESSAGES_NO_MEMORY_CARD_PS2_INSERTED = 522,
	STR_MESSAGES_SELECT_MEMORY_CARD_PS2 = 523,
	STR_MESSAGES_LOADING = 524,
	STR_MESSAGES_SAVING = 525,
	STR_MESSAGES_DELETING = 526,
	STR_MESSAGES_CHECKING = 527,
	STR_MESSAGES_FORMATTING = 528,
	STR_MESSAGES_PLEASE_INSERT_MEMORY_CARD_PS2 = 529,
	STR_MESSAGES_DO_NOT_REMOVE_MEMORY_CARD = 530,
	STR_MESSAGES_LOAD_SIGN_ONS = 531,
	STR_MESSAGES_SAVE_SIGN_ON = 532,
	STR_MESSAGES_UPDATE_SAVED_GAME_DATA_2_YES_3_NO = 533,
	STR_MESSAGES_DONT_SAVE = 534,
	STR_MESSAGES_TIMESPLITTERS = 535,
	STR_MESSAGES_TIMESPLITTERS_SIGN_ONS = 536,
	STR_MESSAGES_TIMESPLITTERS_MAPS = 537,
	STR_MESSAGES_LOAD_MAPMAKER_MAP = 538,
	STR_MESSAGES_SAVE_MAPMAKER_MAP = 539,
	STR_MESSAGES_SAMPLE_MAPS = 540,
	STR_MESSAGES_3_EXIT_4_CHANGE_MEMORY_CARD_PS2 = 541,
	STR_MESSAGES_INSERT_MEMORY_CARD_PS2_AND_PRESS_4 = 542,
	STR_MESSAGES_4_CHECK_MEMORY_CARD_PS2S = 543,
	STR_TEXTBOX_DELETE = 544,
	STR_TEXTBOX_SPACE = 545,
	STR_TEXTBOX_CAPS_ON = 546,
	STR_TEXTBOX_CAPS_OFF = 547,
	STR_TEXTBOX_END = 548,
	STR_TEXTBOX_2_ADD_3_CANCEL = 549,
	STR_CREDITS_FREE_RADICAL_DESIGN_STAFF = 550,
	STR_CREDITS_STEPHEN_ELLIS = 551,
	STR_CREDITS_LEAD_PROGRAMMER = 552,
	STR_CREDITS_DAVID_DOAK = 553,
	STR_CREDITS_DESIGNER_PROGRAMMER = 554,
	STR_CREDITS_KARL_HILTON = 555,
	STR_CREDITS_LEAD_ARTIST = 556,
	STR_CREDITS_GRAEME_NORGATE = 557,
	STR_CREDITS_SOUND_MUSIC = 558,
	STR_CREDITS_LEE_RAY = 559,
	STR_CREDITS_SENIOR_ARTIST = 560,
	STR_CREDITS_HASIT_ZALA = 561,
	STR_CREDITS_SENIOR_PROGRAMMER = 562,
	STR_CREDITS_JAMES_CUNLIFFE = 563,
	STR_CREDITS_LEAD_ANIMATOR = 564,
	STR_CREDITS_BEN_NEWMAN = 565,
	STR_CREDITS_LEAD_CHARACTER_ARTIST = 566,
	STR_CREDITS_EZRA_ALLEN = 567,
	STR_CREDITS_ANIMATOR = 568,
	STR_CREDITS_LES_SPINK = 569,
	STR_CREDITS_CHARACTER_ARTIST = 570,
	STR_CREDITS_DENIS_FABRICE = 571,
	STR_CREDITS_PROGRAMMER1 = 572,
	STR_CREDITS_PAUL_HANSHAW = 573,
	STR_CREDITS_PROGRAMMER2 = 574,
	STR_CREDITS_JOE_MOULDING = 575,
	STR_CREDITS_PROGRAMMER3 = 576,
	STR_CREDITS_BRAD_WARREN = 577,
	STR_CREDITS_BACKGROUND_ARTIST1 = 578,
	STR_CREDITS_ROB_STEPTOE = 579,
	STR_CREDITS_BACKGROUND_ARTIST2 = 580,
	STR_CREDITS_THOMAS_HOUGHTON = 581,
	STR_CREDITS_LEVEL_SETUP = 582,
	STR_CREDITS_VOICE_TALENT = 583,
	STR_CREDITS_BARBARA_WHITEHILL = 584,
	STR_CREDITS_ELAINE_MARSH = 585,
	STR_CREDITS_ANDY_WHITEHILL = 586,
	STR_CREDITS_KEVIN_CLARKE = 587,
	STR_CREDITS_JO_WHITEHILL = 588,
	STR_CREDITS_LUCY_YOUNG = 589,
	STR_CREDITS_MALIKA_DJELLALI = 590,
	STR_CREDITS_ANA_LOUISE_MARSH = 591,
	STR_CREDITS_JENNY_SACKIN = 592,
	STR_CREDITS_ILKE_DECKER = 593,
	STR_CREDITS_TONI_MORGAN = 594,
	STR_CREDITS_BRIGITTE_JUERGENSEN = 595,
	STR_CREDITS_IMME_DAHLBERG = 596,
	STR_CREDITS_KEVIN_ELLIS = 597,
	STR_CREDITS_STEWART_GRAHAM = 598,
	STR_CREDITS_PAUL_ELLIS = 599,
	STR_CREDITS_ROB_MOYE = 600,
	STR_CREDITS_NEIL_HILL = 601,
	STR_CREDITS_HELEN_JACKSON = 602,
	STR_CREDITS_LYNDSAY_COOPER = 603,
	STR_CREDITS_EIDOS_STAFF = 604,
	STR_CREDITS_RICHARD_CARTER = 605,
	STR_CREDITS_PRODUCER = 606,
	STR_CREDITS_FRANK_HOM = 607,
	STR_CREDITS_SHADOW_PRODUCER = 608,
	STR_CREDITS_ED_BAINBRIDGE = 609,
	STR_CREDITS_EXECUTIVE_PRODUCER = 610,
	STR_CREDITS_MICHAEL_NEWEY = 611,
	STR_CREDITS_BRAND_MANAGER = 612,
	STR_CREDITS_GREG_RIZZER = 613,
	STR_CREDITS_US_PUBLICITY = 614,
	STR_CREDITS_STEVE_STARVIS = 615,
	STR_CREDITS_UK_PUBLICITY = 616,
	STR_CREDITS_DAVE_DEPAULIS = 617,
	STR_CREDITS_US_PRODUCT_MANAGER = 618,
	STR_CREDITS_EIDOS_QA_UK = 619,
	STR_CREDITS_DAVID_PETTIT = 620,
	STR_CREDITS_PHIL_MASKELL = 621,
	STR_CREDITS_ALEX_HOOD = 622,
	STR_CREDITS_DAVID_BABAJEE = 623,
	STR_CREDITS_JOHN_WAGLAND = 624,
	STR_CREDITS_MIKE_OWUSU = 625,
	STR_CREDITS_DERREN_TOUSSAINT = 626,
	STR_CREDITS_ABRUS_ALI = 627,
	STR_CREDITS_GORDON_GRAM = 628,
	STR_CREDITS_KEIR_EDMONDS = 629,
	STR_CREDITS_MATTHEW_IBBS = 630,
	STR_CREDITS_JURIE_GELDENHUYS = 631,
	STR_CREDITS_EIDOS_QA_US = 632,
	STR_CREDITS_CARLO_DELALLANA = 633,
	STR_CREDITS_CLIFTON_WHERRY = 634,
	STR_CREDITS_FRANKLIN_VASQUEZ = 635,
	STR_CREDITS_NEVIN_CHOU = 636,
	STR_CREDITS_TAMARA_WILLIAMSON = 637,
	STR_CREDITS_JONNY_COSTA = 638,
	STR_CREDITS_ERUCH_ADAMS = 639,
	STR_CREDITS_ALEXANDER_STRAYER = 640,
	STR_CREDITS_GENNADY_SHEYNER = 641,
	STR_CREDITS_CHRISTINE_FRAZIER = 642,
	STR_CREDITS_JESSE_ANDREWS = 643,
	STR_CREDITS_SPECIAL_THANKS1 = 644,
	STR_CREDITS_ALISTAIR_BODIN = 645,
	STR_CREDITS_ZENO_COLECO = 646,
	STR_CREDITS_PAUL_HOLMAN = 647,
	STR_CREDITS_COLIN_HUGHES = 648,
	STR_CREDITS_MIKE_KAVALLIEROU = 649,
	STR_CREDITS_MARK_BREUGELMANS = 650,
	STR_CREDITS_GEORGE_BAIN = 651,
	STR_CREDITS_SPECIAL_THANKS2 = 652,
	STR_CREDITS_GILLIAN_CORDALL = 653,
	STR_CREDITS_JONAS_ENEROTH = 654,
	STR_CREDITS_EMMI = 655,
	STR_CREDITS_TIMESPLITTERS_WILL_RETURN = 656,
	STR_INTRO_DAM_1 = 657,
	STR_BRIEFING_DAM = 658,
	STR_CHALLENGE_1A = 659,
	STR_CHALLENGE_1A_DESC = 660,
	STR_CHALLENGE_1B = 661,
	STR_CHALLENGE_1B_DESC = 662,
	STR_CHALLENGE_1C = 663,
	STR_CHALLENGE_1C_DESC = 664,
	STR_CHALLENGE_2A = 665,
	STR_CHALLENGE_2A_DESC = 666,
	STR_CHALLENGE_2B = 667,
	STR_CHALLENGE_2B_DESC = 668,
	STR_CHALLENGE_2C = 669,
	STR_CHALLENGE_2C_DESC = 670,
	STR_CHALLENGE_3A = 671,
	STR_CHALLENGE_3A_DESC = 672,
	STR_CHALLENGE_3B = 673,
	STR_CHALLENGE_3B_DESC = 674,
	STR_CHALLENGE_3C = 675,
	STR_CHALLENGE_3C_DESC = 676,
	STR_CHALLENGE_4A = 677,
	STR_CHALLENGE_4A_DESC = 678,
	STR_CHALLENGE_4B = 679,
	STR_CHALLENGE_4B_DESC = 680,
	STR_CHALLENGE_4C = 681,
	STR_CHALLENGE_4C_DESC = 682,
	STR_CHALLENGE_5A = 683,
	STR_CHALLENGE_5A_DESC = 684,
	STR_CHALLENGE_5B = 685,
	STR_CHALLENGE_5B_DESC = 686,
	STR_CHALLENGE_5C = 687,
	STR_CHALLENGE_5C_DESC = 688,
	STR_CHALLENGE_6A = 689,
	STR_CHALLENGE_6A_DESC = 690,
	STR_CHALLENGE_6B = 691,
	STR_CHALLENGE_6B_DESC = 692,
	STR_CHALLENGE_6C = 693,
	STR_CHALLENGE_6C_DESC = 694,
	STR_CHALLENGE_7A = 695,
	STR_CHALLENGE_7A_DESC = 696,
	STR_CHALLENGE_7B = 697,
	STR_CHALLENGE_7B_DESC = 698,
	STR_CHALLENGE_7C = 699,
	STR_CHALLENGE_7C_DESC = 700,
	STR_CHALLENGE_8A = 701,
	STR_CHALLENGE_8A_DESC = 702,
	STR_CHALLENGE_8B = 703,
	STR_CHALLENGE_8B_DESC = 704,
	STR_CHALLENGE_8C = 705,
	STR_CHALLENGE_8C_DESC = 706,
	STR_CHALLENGE_9A = 707,
	STR_CHALLENGE_9A_DESC = 708,
	STR_CHALLENGE_9B = 709,
	STR_CHALLENGE_9B_DESC = 710,
	STR_CHALLENGE_9C = 711,
	STR_CHALLENGE_9C_DESC = 712,
	STR_CHALLENGE_KILLS = 713,
	STR_CHALLENGE_HEALTH = 714,
	STR_CHALLENGE_HEADS = 715,
	STR_CHALLENGE_GLASS_LEFT = 716,
	STR_CHALLENGE_BARRELS_LEFT = 717,
	STR_CHALLENGE_BAGS_LOST = 718,
	STR_CHALLENGE_DIED = 719,
	STR_CHALLENGE_THE_KING_DIED = 720,
	STR_CHALLENGE_DO_NOT_COMPETE_WITH_THE_KING = 721,
	STR_CHALLENGE_KILLS2 = 722,
	STR_CHEATS_INVINCIBLE = 723,
	STR_CHEATS_BIG_HEADS = 724,
	STR_CHEATS_SMALL_HEADS = 725,
	STR_CHEATS_BIG_HANDS = 726,
	STR_CHEATS_INFINITE_AMMO = 727,
	STR_CHEATS_PAINTBALL = 728,
	STR_CHEATS_GUN_SOUNDS = 729,
	STR_CHEATS_ENEMY_ROCKETS = 730,
	STR_CHEATS_ENEMY_BRICKS = 731,
	STR_CHEATS_ALL_ENEMIES_ARE_IMPERSONATORS = 732,
	STR_CHEATS_ALL_ENEMIES_ARE_BUNNIES = 733,
	STR_CHEATS_ALL_ENEMIES_ARE_GINGERBREADS = 734,
	STR_CHEATS_ALL_ENEMIES_ARE_DUCKS = 735,
	STR_CHEATS_ALL_ENEMIES_ARE_ROBOFISH = 736,
	STR_CHEATS_ALL_CHARACTERS_HEADLESS = 737,
	STR_CHEATS_ALL_HEADS_DETACHABLE = 738,
	STR_GAME_1935_TOMB = 739,
	STR_GAME_1970_CHINESE = 740,
	STR_GAME_2005_CYBERDEN = 741,
	STR_GAME_1950_VILLAGE = 742,
	STR_GAME_1985_CHEMICAL_PLANT = 743,
	STR_GAME_2020_PLANET_X = 744,
	STR_GAME_1965_MANSION = 745,
	STR_GAME_2000_DOCKS = 746,
	STR_GAME_2035_SPACEWAYS = 747,
	STR_GAME_RED = 748,
	STR_GAME_BLUE = 749,
	STR_GAME_YELLOW = 750,
	STR_GAME_GREEN = 751,
	STR_GAME_GREY = 752,
	STR_GAME_BAGTAG = 753,
	STR_GAME_CAPTURE_THE_BAG = 754,
	STR_GAME_DEATHMATCH = 755,
	STR_GAME_ESCORT = 756,
	STR_GAME_KNOCKOUT = 757,
	STR_GAME_LASTSTAND = 758,
	STR_GAME_ZONES = 759,
	STR_GAME_STORY = 760,
	STR_GAME_TEAM = 761,
	STR_GAME_SECS = 762,
	STR_GAME_3_MORE_KILLS_TO_GO = 763,
	STR_GAME_2_MORE_KILLS_TO_GO = 764,
	STR_GAME_GOING_FOR_THE_LAST_KILL = 765,
	STR_GAME_GOT_THE_BAG1 = 766,
	STR_GAME_GOT_THE_BAG2 = 767,
	STR_GAME_TOO_LATE = 768,
	STR_GAME_YOU_HAVE = 769,
	STR_GAME_SECONDS_TO_RETURN = 770,
	STR_STATS_NO_AWARD = 771,
	STR_STATS_MOST_LETHAL = 772,
	STR_STATS_MOST_LOSSES = 773,
	STR_STATS_LEMMING_AWARD = 774,
	STR_STATS_MOST_PROFESSIONAL = 775,
	STR_STATS_MULTI_KILL = 776,
	STR_STATS_LONGEST_SPREE = 777,
	STR_STATS_MOST_EFFECTIVE = 778,
	STR_STATS_PATHETIC_SHOT = 779,
	STR_STATS_MANIAC = 780,
	STR_STATS_BRAIN_SURGEON = 781,
	STR_STATS_FISTS_OF_FURY = 782,
	STR_STATS_GLASS_JAW = 783,
	STR_STATS_DECAPITATOR = 784,
	STR_STATS_FISTS_OF_STEEL = 785,
	STR_STATS_BETRAYER = 786,
	STR_STATS_VANDALISM_AWARD = 787,
	STR_STATS_HYPOCHONDRIAC = 788,
	STR_STATS_AC_10_AWARD = 789,
	STR_STATS_WHERES_THE_HEALTH = 790,
	STR_STATS_WHERES_THE_ARMOUR = 791,
	STR_STATS_HOARDER = 792,
	STR_STATS_SLOTH = 793,
	STR_STATS_MOST_FRANTIC = 794,
	STR_STATS_BACKPEDDLER = 795,
	STR_STATS_SIDESTEPPER = 796,
	STR_STATS_LEDGEHOPPER = 797,
	STR_STATS_MOST_SNEAKY = 798,
	STR_STATS_MOST_COWARDLY = 799,
	STR_STATS_DODGER = 800,
	STR_STATS_MOST_OUTGUNNED = 801,
	STR_STATS_BEST_EQUIPPED = 802,
	STR_STATS_UNLUCKY_TO_LOSE = 803,
	STR_STATS_WEAPONS_EXPERT = 804,
	STR_STATS_PORTER = 805,
	STR_STATS_BAG_MAN = 806,
	STR_STATS_MOST_USELESS = 807,
	STR_STATS_RICOCHET_KING = 808,
	STR_STATS_UNDEREQUIPPED = 809,
	STR_STATS_VICTIM = 810,
	STR_STATS_BULLY = 811,
	STR_STATS_MOST_PEACEFUL = 812,
	STR_STATS_MOST_DISHONOURABLE = 813,
	STR_STATS_MOST_MANIC = 814,
	STR_STATS_CARTOGRAPHER = 815,
	STR_STATS_SHORTEST_INNINGS = 816,
	STR_STATS_LONGEST_INNINGS = 817,
	STR_STATS_SURVIVOR = 818,
	STR_STATS_MARKSMANSHIP_AWARD = 819,
	STR_STATS_NO_MEDAL_AWARDED1 = 820,
	STR_STATS_NO_COMMENT = 821,
	STR_STATS_UNDESERVING_OF_A_MEDAL = 822,
	STR_STATS_UNLIKELY_TO_GET_A_MEDAL = 823,
	STR_STATS_NO_MEDAL_AWARDED2 = 824,
	STR_STATS_NONE = 825,
	STR_GUN_GUN_TURRET = 826,
	STR_GUN_PUNCH = 827,
	STR_GUN_PISTOL = 828,
	STR_GUN_PISTOL_X2 = 829,
	STR_GUN_FLAREPISTOL = 830,
	STR_GUN_FLAREPISTOL_X2 = 831,
	STR_GUN_MAGNUM = 832,
	STR_GUN_MAGNUM_X2 = 833,
	STR_GUN_ASSAULT_RIFLE = 834,
	STR_GUN_SNIPER_RIFLE = 835,
	STR_GUN_FLAMETHROWER = 836,
	STR_GUN_FIRE_EXTINGUISHER = 837,
	STR_GUN_AK47 = 838,
	STR_GUN_AK47_X2 = 839,
	STR_GUN_ELECTROGUN = 840,
	STR_GUN_SCIFI_HANDGUN = 841,
	STR_GUN_ROCKET_LAUNCHER = 842,
	STR_GUN_HOMING_ROCKET_LAUNCHER = 843,
	STR_GUN_LASER = 844,
	STR_GUN_PLASMA_MACHINEGUN = 845,
	STR_GUN_PLASMA_MACHINEGUN_X2 = 846,
	STR_GUN_DISCTHROWER = 847,
	STR_GUN_DISCTHROWER_X2 = 848,
	STR_GUN_GRENADE_LAUNCHER = 849,
	STR_GUN_GRENADE_THROW = 850,
	STR_GUN_PROXIMITY_MINE = 851,
	STR_GUN_REMOTE_MINE = 852,
	STR_GUN_TIMED_MINE = 853,
	STR_GUN_TNT = 854,
	STR_GUN_TOMMY_GUN = 855,
	STR_GUN_TOMMY_GUN_X2 = 856,
	STR_GUN_ASSAULT_SHOTGUN = 857,
	STR_GUN_UZI = 858,
	STR_GUN_UZI_X2 = 859,
	STR_GUN_BLUNDERBUSS = 860,
	STR_GUN_BLUNDERBUSS_X2 = 861,
	STR_GUN_GATLING = 862,
	STR_GUN_GATLING_X2 = 863,
	STR_GUN_SHOTGUN = 864,
	STR_GUN_SHOTGUN_X2 = 865,
	STR_GUN_BRICK = 866,
	STR_AMMO_SMALLBULLET = 867,
	STR_AMMO_BIGBULLET = 868,
	STR_AMMO_SHELL = 869,
	STR_AMMO_PLASMA = 870,
	STR_AMMO_ROCKET = 871,
	STR_AMMO_GRENADE = 872,
	STR_AMMO_BRICK = 873,
	STR_AMMO_REMOTEMINE = 874,
	STR_AMMO_TIMEDMINE = 875,
	STR_AMMO_PROXIMITYMINE = 876,
	STR_AMMO_TNT = 877,
	STR_AMMO_FLARE = 878,
	STR_AMMO_DISC = 879,
	STR_AMMO_ELECTRIC = 880,
	STR_AMMO_PETROL = 881,
	STR_AMMO_FIREEXTINGUISHER = 882,
	STR_COMPUTERDISK = 883,
	STR_HUD_ESCORTEE = 884,
	STR_HUD_BASE = 885,
	STR_HUD_BAG_TIME = 886,
	STR_HUD_SCORE1 = 887,
	STR_HUD_TIME_LEFT = 888,
	STR_HUD_SCORE2 = 889,
	STR_HUD_RANK = 890,
	STR_HUD_DEMO = 891,
	STR_LV_PRISON = 892,
	STR_LV_VILLAGE = 893,
	STR_LV_NSA1 = 894,
	STR_LV_OUTSKIRTS = 895,
	STR_LV_CHEMICAL_PLANT = 896,
	STR_LV_TEST = 897,
	STR_LV_ASYLUM = 898,
	STR_LV_MANSION = 899,
	STR_LV_PLANET_X = 900,
	STR_LV_COMPOUND = 901,
	STR_LV_STREETS = 902,
	STR_LV_WARZONE = 903,
	STR_LV_SITE = 904,
	STR_LV_CYBERDEN = 905,
	STR_LV_BANK = 906,
	STR_LV_GRAVEYARD = 907,
	STR_LV_SPACESHIP = 908,
	STR_LV_MALL = 909,
	STR_LV_TILE_TEST = 910,
	STR_LV_WAREHOUSE = 911,
	STR_LV_CHINESE = 912,
	STR_LV_CASTLE = 913,
	STR_LV_TOMB1 = 914,
	STR_LV_DOCKS = 915,
	STR_LV_RON = 916,
	STR_LV_TOMB2 = 917,
	STR_LV_SPACEWAYS = 918,
	STR_LV_TECH = 919,
	STR_LV_AZTEC = 920,
	STR_LV_OUTPOST = 921,
	STR_LV_ATOMSMASHER = 922,
	STR_LV_WILDWEST = 923,
	STR_LV_HANGAR = 924,
	STR_LV_NOTREDAME = 925,
	STR_LV_DAM = 926,
	STR_LV_PIVOTAL = 927,
	STR_LV_TUBE = 928,
	STR_LV_NEOTOKYO = 929,
	STR_LV_SPACESTATION = 930,
	STR_LV_PLANET2 = 931,
	STR_LV_RFACTORY = 932,
	STR_LV_MEXICAN = 933,
	STR_LV_NIGHTCLUB = 934,
	STR_LV_MARTIAN = 935,
	STR_LV_HOSPITAL = 936,
	STR_LV_SCRAPYARD = 937,
	STR_LV_CIRCUS = 938,
	STR_LV_TILESET = 939,
	STR_LV_FRONTRED = 940,
	STR_LV_FRONTMPG = 941,
	STR_LV_MAPMAKER = 942,
	STR_LV_DUMMY = 943,
	STR_LV_CREDITS = 944,
	STR_LV_TIMESPLITTERS = 945,
	STR_LV_LOADING = 946,
	STR_LV_LEGAL = 947,
	STR_LVSETUP_DEFAULT = 948,
	STR_LVSETUP_PERIOD_HORROR = 949,
	STR_LVSETUP_USUAL_SUSPECTS = 950,
	STR_LVSETUP_SPACE_OPERA = 951,
	STR_LVSETUP_HORROR_SHOCKER = 952,
	STR_LVSETUP_LAW_AND_ORDER = 953,
	STR_LVSETUP_THE_LIVING_DEAD = 954,
	STR_LVSETUP_TIMESPLITTERS = 955,
	STR_LVSETUP_RETRO = 956,
	STR_LVSETUP_HEAT = 957,
	STR_LVSETUP_PLASMA = 958,
	STR_LVSETUP_HANDGUNS = 959,
	STR_LVSETUP_REMOTE_MINES = 960,
	STR_LVSETUP_PROXIMITY_MINES = 961,
	STR_LVSETUP_TIMED_MINES = 962,
	STR_LVSETUP_BRICKS = 963,
	STR_MM_NO_MORE_FREE_MEMORY_2_OK = 964,
	STR_MM_CAN_NOT_PLACE_MORE_THAN = 965,
	STR_MM_3_BACK1 = 966,
	STR_MM_2_EDIT_COLOUR = 967,
	STR_MM_2_SELECT = 968,
	STR_MM_1_NEXT_PAGE = 969,
	STR_MM_RESET_PALETTE = 970,
	STR_MM_YOU_HAVENT_PLACED_ANY_TILE_YET = 971,
	STR_MM_STARTS = 972,
	STR_MM_BASES = 973,
	STR_MM_WEAPONS = 974,
	STR_MM_HEALTH1 = 975,
	STR_MM_ARMOUR1 = 976,
	STR_MM_BAGTAG_BAG = 977,
	STR_MM_KNOCKOUT_BAGS = 978,
	STR_MM_CLEAR1 = 979,
	STR_MM_PLACE1 = 980,
	STR_MM_EXIT1 = 981,
	STR_MM_COPY1 = 982,
	STR_MM_2_PLACE_ITEM_3_EXIT = 983,
	STR_MM_3_EXIT = 984,
	STR_MM_TILE = 985,
	STR_MM_ITEM = 986,
	STR_MM_LIGHT1 = 987,
	STR_MM_FREE = 988,
	STR_MM_LIGHT2 = 989,
	STR_MM_PHASE1 = 990,
	STR_MM_CLEAR2 = 991,
	STR_MM_SELECT_ITEM = 992,
	STR_MM_RESET_LIGHT = 993,
	STR_MM_PHASE2 = 994,
	STR_MM_COPY2 = 995,
	STR_MM_SET_LIGHT = 996,
	STR_MM_SELECT_LIGHT = 997,
	STR_MM_DELETE1 = 998,
	STR_MM_ROTATE = 999,
	STR_MM_PLACE2 = 1000,
	STR_MM_DELETE_MARKED = 1001,
	STR_MM_DELETE2 = 1002,
	STR_MM_MARK = 1003,
	STR_MM_GRAB = 1004,
	STR_MM_COPY3 = 1005,
	STR_MM_SELECT_TILE = 1006,
	STR_MM_PLACE_TILES_WITHOUT_THE_ITEMS_2_OK_3_CANCEL = 1007,
	STR_MM_PLACE_A_BAG_BAGTAG_TO_ENABLE_BAGTAG_2_OK = 1008,
	STR_MM_PLACE_AT_LEAST_2_BAG_BASES_PLUS = 1009,
	STR_MM_PLACE_AT_LEAST_2_BAG_BASES = 1010,
	STR_MM_ESCORT_IS_NOT_AVAILABLE_2_OK = 1011,
	STR_MM_LASTSTAND_IS_NOT_AVAILABLE_2_OK = 1012,
	STR_MM_VIRTUAL1 = 1013,
	STR_MM_INDUSTRIAL1 = 1014,
	STR_MM_GOTHIC1 = 1015,
	STR_MM_ALIEN1 = 1016,
	STR_MM_SPACEPORT1 = 1017,
	STR_MM_DEFAULT = 1018,
	STR_MM_GOTHIC2 = 1019,
	STR_MM_INDUSTRIAL2 = 1020,
	STR_MM_VIRTUAL2 = 1021,
	STR_MM_SPACEPORT2 = 1022,
	STR_MM_ALIEN2 = 1023,
	STR_MM_STREETS = 1024,
	STR_MM_THE_BANK = 1025,
	STR_MM_CHINESE = 1026,
	STR_MM_GRAVEYARD = 1027,
	STR_MM_CYBERDEN = 1028,
	STR_MM_MANSION = 1029,
	STR_MM_PLANET_X = 1030,
	STR_MM_CASTLE = 1031,
	STR_MM_VILLAGE = 1032,
	STR_MM_TOMB = 1033,
	STR_MM_WARZONE = 1034,
	STR_MM_BUILDING_SITE = 1035,
	STR_MM_DOCKS = 1036,
	STR_MM_SPACEWAYS = 1037,
	STR_MM_SPACESHIP = 1038,
	STR_MM_COMPOUND = 1039,
	STR_MM_CHEMICAL_PLANT = 1040,
	STR_MM_MALL = 1041,
	STR_MM_GRID_INTENSITY = 1042,
	STR_MM_BACK1 = 1043,
	STR_MM_TILE_SET = 1044,
	STR_MM_MUSIC = 1045,
	STR_MM_EDIT_MAP_DESCRIPTION = 1046,
	STR_MM_BACK2 = 1047,
	STR_MM_GAME_MODES = 1048,
	STR_MM_BACK3 = 1049,
	STR_MM_2_HELP = 1050,
	STR_MM_2_FOR_INFO = 1051,
	STR_MM_OK = 1052,
	STR_MM_NEW_FILE = 1053,
	STR_MM_NO_TIMESPLITTERS_MAPS = 1054,
	STR_MM_3_BACK2 = 1055,
	STR_MM_3_BACK_4_DELETE_MAP = 1056,
	STR_MM_MORE_UP = 1057,
	STR_MM_MORE_DOWN = 1058,
	STR_MM_DIRECTORY_IS_CORRUPT_2_OK = 1059,
	STR_MM_THERE_IS_NO_MEMORY_CARD_2_OK = 1060,
	STR_MM_MEMORY_CARD_PS2_IN = 1061,
	STR_MM_IS_UNFORMATTED = 1062,
	STR_MM_2_OK1 = 1063,
	STR_MM_MAPS_ON = 1064,
	STR_MM_ARE_YOU_SURE_YOU_WANT_TO_DELETE = 1065,
	STR_MM_FROM_MEMORY_CARD_PS2_IN = 1066,
	STR_MM_2_YES_3_NO1 = 1067,
	STR_MM_DO_YOU_WANT_TO_OVERWRITE_THE_MAP = 1068,
	STR_MM_ON_MEMORY_CARD_PS2_IN = 1069,
	STR_MM_1_YES_3_NO2 = 1070,
	STR_MM_SAVE_COMPLETED_2_OK = 1071,
	STR_MM_TIMESPLITTERS_MAP = 1072,
	STR_MM_MAY_BE_CORRUPTED = 1073,
	STR_MM_LOAD_FAILED = 1074,
	STR_MM_2_OK2 = 1075,
	STR_MM_LOAD_COMPLETED_2_OK = 1076,
	STR_MM_MAP_FILE_VERSION_OUTDATED_2_OK = 1077,
	STR_MM_MAP_SETTINGS = 1078,
	STR_MM_PREVIEW_MAP = 1079,
	STR_MM_UNDO_LAST_CHANGE = 1080,
	STR_MM_CENTER_MAP = 1081,
	STR_MM_CLEAR_MAP = 1082,
	STR_MM_OPTIONS = 1083,
	STR_MM_LOAD_MAP = 1084,
	STR_MM_SAVE_MAP = 1085,
	STR_MM_HELP = 1086,
	STR_MM_QUIT_MAPMAKER = 1087,
	STR_MM_BACK4 = 1088,
	STR_MM_ARE_YOU_SURE_YOU_WANT_TO_CLEAR_THE_MAP_2_YES_3_NO = 1089,
	STR_MM_HELP_SCREEN = 1090,
	STR_MM_YOU_HAVE_MADE_CHANGES_THAT_HAVE_NOT_BEEN_SAVED = 1091,
	STR_MM_ALL = 1092,
	STR_MM_RED1 = 1093,
	STR_MM_BLUE1 = 1094,
	STR_MM_YELLOW1 = 1095,
	STR_MM_GREEN1 = 1096,
	STR_MM_RED2 = 1097,
	STR_MM_BLUE2 = 1098,
	STR_MM_YELLOW2 = 1099,
	STR_MM_GREEN2 = 1100,
	STR_MM_LOW = 1101,
	STR_MM_HI = 1102,
	STR_MM_CLEAR3 = 1103,
	STR_MM_START = 1104,
	STR_MM_BAG_BASE = 1105,
	STR_MM_HEALTH2 = 1106,
	STR_MM_BAG_BAGTAG = 1107,
	STR_MM_BAG_KNOCKOUT = 1108,
	STR_MM_ARMOUR2 = 1109,
	STR_MM_GUN = 1110,
	STR_MM_EXIT2 = 1111,
	STR_MM_START_ITEMS = 1112,
	STR_MM_PICKUP_GUN_ITEMS = 1113,
	STR_MM_HEALTH_ITEMS = 1114,
	STR_MM_ARMOUR_ITEMS = 1115,
	STR_MM_SAMPLE_MAP_1 = 1116,
	STR_MM_SAMPLE_MAP_2 = 1117,
	STR_MM_SAMPLE_MAP_3 = 1118,
	STR_MM_SAMPLE_MAP_4 = 1119,
	STR_MM_SAMPLE_MAP_5 = 1120,
	STR_MM_SAMPLE_MAP_6 = 1121,
	STR_MM_SAMPLE_MAP_7 = 1122,
	STR_MM_SAMPLE_MAP_8 = 1123,
	STR_MM_SAMPLE_MAP_9 = 1124,
	STR_MM_SAMPLE_MAP_10 = 1125,
	STR_BACK = 1126,
	STR_MENU_YES = 1127,
	STR_MENU_NO = 1128,
	STR_MENU_CANCEL_CHANGES = 1129,
	STR_MENU_SELECT = 1130,
	STR_MENU_CHANGEPAGE = 1131,
	STR_MENU_CHANGEITEM = 1132,
	STR_MENU_TITLE_OPTIONS = 1133,
	STR_MENU_CONTINUE = 1134,
	STR_MENU_CONTINUE_QUESTION = 1135,
	STR_MENU_REMATCH = 1136,
	STR_MENU_RETRY = 1137,
	STR_MENU_CONTROLS = 1138,
	STR_MENU_PREFS = 1139,
	STR_MENU_RESTART = 1140,
	STR_MENU_TITLE_ENDGAME = 1141,
	STR_MENU_TITLE_PREFS = 1142,
	STR_MENU_TITLE_RESTART = 1143,
	STR_MENU_QUIT = 1144,
	STR_MENU_ENDPREVIEW = 1145,
	STR_MENU_TITLE_QUIT = 1146,
	STR_MENU_TITLE_STATISTICS = 1147,
	STR_MENU_P_LOSSES = 1148,
	STR_MENU_P_KILLS = 1149,
	STR_MENU_TITLE_STATUS = 1150,
	STR_MENU_TITLE_SCORES = 1151,
	STR_MENU_TITLE_INVENTORY = 1152,
	STR_MENU_STORY = 1153,
	STR_MENU_CHALLENGE = 1154,
	STR_MENU_PAUSE = 1155,
	STR_MENU_END_GAME = 1156,
	STR_MENU_TITLE_BRIEFING = 1157,
	STR_MENU_TITLE_AWARDS = 1158,
	STR_MENU_PRESS_START = 1159,
	STR_MENU_3_CANCEL = 1160,
	STR_MENU_3_BACK_2_EDIT = 1161,
	STR_MENU_3_BACK = 1162,
	STR_MENU_KILLS = 1163,
	STR_MENU_SETUP_MAIN_OPTIONS = 1164,
	STR_MENU_SETUP_AIM_CONTROL_OPTIONS = 1165,
	STR_MENU_SETUP_SWITCH_CONTROLS = 1166,
	STR_MENU_LEFT_ANALOG_STICK = 1167,
	STR_MENU_RIGHT_ANALOG_STICK = 1168,
	STR_MENU_DIRECTIONAL_BUTTONS = 1169,
	STR_MENU_UP_DIRECTIONAL_BUTTON = 1170,
	STR_MENU_DOWN_DIRECTIONAL_BUTTON = 1171,
	STR_MENU_LEFT_DIRECTIONAL_BUTTON = 1172,
	STR_MENU_RIGHT_DIRECTIONAL_BUTTON = 1173,
	STR_MENU_RUN = 1174,
	STR_MENU_TURN = 1175,
	STR_MENU_SIDE_STEP = 1176,
	STR_MENU_LOOK = 1177,
	STR_MENU_RUN_AIMING = 1178,
	STR_MENU_TURN_AIMING = 1179,
	STR_MENU_SIDE_STEP_AIMING = 1180,
	STR_MENU_LOOK_AIMING = 1181,
	STR_MENU_AIM = 1182,
	STR_MENU_ZOOM_IN = 1183,
	STR_MENU_ZOOM_OUT = 1184,
	STR_MENU_ZOOM_INOUT = 1185,
	STR_MENU_FIRE1 = 1186,
	STR_MENU_ALTERNATE_FIRE = 1187,
	STR_MENU_MANUAL_RELOAD = 1188,
	STR_MENU_CROUCH = 1189,
	STR_MENU_ACTIVATE = 1190,
	STR_MENU_PREV_WEAPON = 1191,
	STR_MENU_NEXT_WEAPON = 1192,
	STR_MENU_SWAP_WEAPON = 1193,
	STR_MENU_RUN_FORWARD = 1194,
	STR_MENU_RUN_BACKWARD = 1195,
	STR_MENU_TURN_LEFT = 1196,
	STR_MENU_TURN_RIGHT = 1197,
	STR_MENU_STEP_LEFT = 1198,
	STR_MENU_STEP_RIGHT = 1199,
	STR_MENU_LOOK_UP = 1200,
	STR_MENU_LOOK_DOWN = 1201,
	STR_MENU_ACCEPT_CHANGES = 1202,
	STR_MENU_TOGGLE = 1203,
	STR_MENU_HOLD = 1204,
	STR_MENU_CUSTOM = 1205,
	STR_MENU_DEFAULT = 1206,
	STR_MENU_DEFAULT_LH = 1207,
	STR_MENU_EXPERT = 1208,
	STR_MENU_EXPERT_B = 1209,
	STR_MENU_DIGITAL = 1210,
	STR_MENU_DIGITAL_LH = 1211,
	STR_MENU_CONFIGURATION = 1212,
	STR_MENU_INVERSE_LOOK = 1213,
	STR_MENU_AIM_MODE = 1214,
	STR_MENU_CROUCH_MODE = 1215,
	STR_MENU_AUTO_LOOKAHEAD = 1216,
	STR_MENU_ALWAYS = 1217,
	STR_MENU_NEVER = 1218,
	STR_MENU_BEST = 1219,
	STR_MENU_OFF = 1220,
	STR_MENU_FIRE2 = 1221,
	STR_MENU_HIT = 1222,
	STR_MENU_FIRE_HIT = 1223,
	STR_MENU_AUTO_AIM = 1224,
	STR_MENU_WEAPON_CHANGE = 1225,
	STR_MENU_VIBRATION = 1226,
	STR_MENU_VIBRATION_MODE = 1227,
	STR_MENU_CANCEL = 1228,
	STR_MENU_CONFIRM = 1229,
	STR_MENU_FOLLOWING_CONTROLS_NOT_ASSIGNED1 = 1230,
	STR_MENU_FOLLOWING_CONTROLS_NOT_ASSIGNED2 = 1231,
	STR_MENU_SEVERAL_CONTROLS_NOT_ASSIGNED1 = 1232,
	STR_MENU_SEVERAL_CONTROLS_NOT_ASSIGNED2 = 1233,
	STR_MENU_SEVERAL_CONTROLS_NOT_ASSIGNED3 = 1234,
	STR_MENU_PRESS_2_TO_END_GAME = 1235,
	STR_MENU_BAG_SCORED = 1236,
	STR_MENU_TIME1 = 1237,
	STR_MENU_TIMES1 = 1238,
	STR_MENU_BAG_GRABBED = 1239,
	STR_MENU_TIME2 = 1240,
	STR_MENU_TIMES2 = 1241,
	STR_MENU_BAG_SECURED = 1242,
	STR_MENU_TIME3 = 1243,
	STR_MENU_TIMES3 = 1244,
	STR_MENU_MOST_KILLS_WITHOUT_DYING = 1245,
	STR_MENU_MOST_KILLS_WITHIN_3_SECS = 1246,
	STR_MENU_MOST_KILLS_WITHIN_3_SECONDS = 1247,
	STR_MENU_LONGEST_KILLING_SPREE = 1248,
	STR_MENU_ACCURACY = 1249,
	STR_MENU_NOT_AVAILABLE = 1250,
	STR_MENU_HEAD_SHOTS = 1251,
	STR_MENU_NONE = 1252,
	STR_MENU_FAVOURITE_WEAPON = 1253,
	STR_MENU_NOITEMS = 1254,
	STR_MENU_UNARMED = 1255,
	STR_MENU_DEBUG_MENU = 1256,
	STR_MENU_SETUP_CONTROLS = 1257,
	STR_MENU_PREFERENCES = 1258,
	STR_MENU_GAME_PAUSED = 1259,
	STR_MENU_FAILED = 1260,
	STR_MENU_SUCCESS = 1261,
	STR_MENU_FIND_THE_CULTISTS_ANKH = 1262,
	STR_MENU_SEIZE_THE_GANGS_FILES_AS_EVIDENCE = 1263,
	STR_MENU_GET_THE_CYBORGS_PLANS_AND = 1264,
	STR_MENU_FIND_THE_CURSED_ARTEFACT_AND = 1265,
	STR_MENU_RECLAIM_THE_CASE_OF_STOLEN_JEWELS = 1266,
	STR_MENU_RECOVER_THE_HOSTAGE_CYBERBRAIN_AND = 1267,
	STR_MENU_RETURN_THE_MURDERERS_REMAINS_TO_THE = 1268,
	STR_MENU_MAKE_THE_RANSOM_PICKUP_AND_PROCEED = 1269,
	STR_MENU_GRAB_YOUR_DUTY_FREE_GOODS = 1270,
	STR_MENU_YOUR_ARE_DOOMED_FIGHT_THE_ZOMBIE_ONSLAUGHT = 1271,
	STR_MENU_DEFEND_BASES_FOR_AS_LONG_AS_POSSIBLE = 1272,
	STR_MENU_AWARDS_EARNED = 1273,
	STR_PLAYER_ROOKIE_HEALTH_PLUS_10 = 1274,
	STR_PLAYER_NOVICE_HEALTH_PLUS_5 = 1275,
	STR_PLAYER_NOVICE_HEALTH_PLUS_1 = 1276,
	STR_PLAYER_NORMAL = 1277,
	STR_PLAYER_VETERAN_HEALTH_MINUS_1 = 1278,
	STR_PLAYER_VETERAN_HEALTH_MINUS_5 = 1279,
	STR_PLAYER_HERO_HEALTH_MINUS_10 = 1280,
	STR_PLAYER_KILLED_BY = 1281,
	STR_PROP_YOUR_BAG_HAS_BEEN_STOLEN = 1282,
	STR_PROP_GOT_THE_BAG = 1283,
	STR_PROP_GOT_THE = 1284,
	STR_PROP_RED = 1285,
	STR_PROP_BLUE = 1286,
	STR_PROP_YELLOW = 1287,
	STR_PROP_GREEN = 1288,
	STR_PROP_SCORED_WITH_YOUR_BAG = 1289,
	STR_PROP_SCORE = 1290,
	STR_PROP_BAG_SECURED_BY_TEAMMATE = 1291,
	STR_PROP_BAG_SECURED = 1292,
	STR_PROP_TEAM = 1293,
	STR_PROP_IS_GOING_FOR_THE_LAST_KILL1 = 1294,
	STR_PROP_IS_GOING_FOR_THE_LAST_KILL2 = 1295,
	STR_PROP_INDIRECT_SCORE = 1296,
	STR_MISC_MAX = 1297,
	STR_MISC_MISC = 1298,
	STR_MISC_TRAVERSALS_BASE = 1299,
	STR_MISC_TRAVERSALS_M1 = 1300,
	STR_MISC_TRAVERSALS_M1A = 1301,
	STR_MISC_TRAVERSALS_M2A = 1302,
	STR_MISC_TRAVERSALS_M2 = 1303,
	STR_MISC_TRAVERSALS_M1B = 1304,
	STR_MISC_TRAVERSALS_M2B = 1305,
	STR_MISC_TRAVERSALS_M0F = 1306,
	STR_MISC_TRAVERSALS_M1F = 1307,
	STR_MISC_TRAVERSALS_M2F = 1308,
	STR_MISC_CROUCHES_BASE = 1309,
	STR_MISC_CROUCHES_M1 = 1310,
	STR_MISC_CROUCHES_M1A = 1311,
	STR_MISC_CROUCHES_M2A = 1312,
	STR_MISC_CROUCHES_M2 = 1313,
	STR_MISC_CROUCHES_M1B = 1314,
	STR_MISC_CROUCHES_M2B = 1315,
	STR_MISC_CROUCHES_M0F = 1316,
	STR_MISC_CROUCHES_M1F = 1317,
	STR_MISC_CROUCHES_M2F = 1318,
	STR_MISC_DEATHS = 1319,
	STR_MISC_ANIM_BIND_POSE = 1320,
	STR_MISC_ANIM_STAND = 1321,
	STR_MISC_ANIM_STANDB = 1322,
	STR_MISC_ANIM_RUN = 1323,
	STR_MISC_ANIM_RUNBACK = 1324,
	STR_MISC_ANIM_RUNSTRAFERIGHT = 1325,
	STR_MISC_ANIM_RUNSTRAFELEFT = 1326,
	STR_MISC_ANIM_SNEAK = 1327,
	STR_MISC_ANIM_SNEAKBACK = 1328,
	STR_MISC_ANIM_SNEAKSTRAFERIGHT = 1329,
	STR_MISC_ANIM_SNEAKSTRAFELEFT = 1330,
	STR_MISC_ANIM_TURNLEFT = 1331,
	STR_MISC_ANIM_TURNRIGHT = 1332,
	STR_MISC_ANIM_CROUCHPOSE = 1333,
	STR_MISC_ANIM_CROUCHPOSEB = 1334,
	STR_MISC_ANIM_CROUCHRUN = 1335,
	STR_MISC_ANIM_CROUCHRUNBACK = 1336,
	STR_MISC_ANIM_CROUCHSTRAFELEFT = 1337,
	STR_MISC_ANIM_CROUCHSTRAFERIGHT = 1338,
	STR_MISC_ANIM_CROUCHRUNSTRAFELEFT = 1339,
	STR_MISC_ANIM_CROUCHRUNSTRAFERIGHT = 1340,
	STR_MISC_ANIM_CROUCHSNEAK = 1341,
	STR_MISC_ANIM_CROUCHSNEAKBACK = 1342,
	STR_MISC_ANIM_CROUCHTURNLEFT = 1343,
	STR_MISC_ANIM_CROUCHTURNRIGHT = 1344,
	STR_MISC_ANIM_SHOTHEAD = 1345,
	STR_MISC_ANIM_SHOTHEAD2 = 1346,
	STR_MISC_ANIM_SHOTGUT = 1347,
	STR_MISC_ANIM_SHOTCHEST = 1348,
	STR_MISC_ANIM_SHOT1 = 1349,
	STR_MISC_ANIM_SHOT2 = 1350,
	STR_MISC_ANIM_SHOT3 = 1351,
	STR_MISC_ANIM_SHOT4 = 1352,
	STR_MISC_ANIM_SHOT5 = 1353,
	STR_MISC_ANIM_SHOT6 = 1354,
	STR_MISC_ANIM_SHOT7 = 1355,
	STR_MISC_ANIM_SHOT8 = 1356,
	STR_MISC_ANIM_SHOT9 = 1357,
	STR_MISC_ANIM_SHOT10 = 1358,
	STR_MISC_ANIM_SHOT11 = 1359,
	STR_MISC_ANIM_SHOT12 = 1360,
	STR_MISC_ANIM_SHOT13 = 1361,
	STR_MISC_ANIM_SHOT14 = 1362,
	STR_MISC_ANIM_SHOT15 = 1363,
	STR_MISC_ANIM_SHOT16 = 1364,
	STR_MISC_ANIM_SHOT17 = 1365,
	STR_MISC_ANIM_SHOT18 = 1366,
	STR_MISC_ANIM_SHOT19 = 1367,
	STR_MISC_ANIM_SHOT20 = 1368,
	STR_MISC_ANIM_SHOT21 = 1369,
	STR_MISC_FIRST_PERSON = 1370,
	STR_MISC_PROP_VIEW = 1371,
	STR_MISC_FLOOR = 1372,
	STR_MISC_FLOATING = 1373,
	STR_MISC_CONTROL_PAD = 1374,
	STR_MISC_GAME = 1375,
	STR_MISC_3 = 1376,
	STR_MISC_2 = 1377,
	STR_MISC_4 = 1378,
	STR_MISC_1 = 1379,
	STR_MISC_L1 = 1380,
	STR_MISC_L2 = 1381,
	STR_MISC_R1 = 1382,
	STR_MISC_R2 = 1383,
	STR_MISC_L3 = 1384,
	STR_MISC_R3 = 1385,
	STR_NUM = 1386
};

typedef long long int s64;
typedef void (*CdlCB)(/* parameters unknown */);

typedef struct {
	u_char minute;
	u_char second;
	u_char sector;
	u_char track;
} sceCdlLOCCD;

typedef struct {
	u_int lsn;
	u_int size;
	char name[16];
	u_char date[8];
	u_int flag;
} sceCdlFILE;

typedef struct {
	u_char stat;
	u_char second;
	u_char minute;
	u_char hour;
	u_char pad;
	u_char day;
	u_char month;
	u_char year;
} sceCdCLOCK;

typedef enum {
	POS_ABSOLUTE = 0,
	POS_STARTOFFSTART = 1,
	POS_STARTOFFMID = 2,
	POS_STARTOFFEND = 3,
	POS_MIDOFFSTART = 4,
	POS_MIDOFFMID = 5,
	POS_MIDOFFEND = 6,
	POS_ENDOFFSTART = 7,
	POS_ENDOFFMID = 8,
	POS_ENDOFFEND = 9,
	POS_NUM = 10
};

typedef enum {
	JOYMODE_GAME = 0,
	JOYMODE_DEBUGMENU = 1,
	JOYMODE_MOVEVIEW = 2,
	JOYMODE_MAX = 3
};

typedef enum {
	MEM_PER_LOCAL = 0,
	MEM_PER_LEV = 1,
	MEM_PER_ETER = 2,
	MEM_PER_MAX = 3
};

typedef enum {
	MEMDB_LOADING = 0,
	MEMDB_FRONTEND = 1,
	MEMDB_LEVEL = 2
} memdbstate;

typedef enum {
	JOYAXIS_NONE = 0,
	JOYAXIS_X1 = 1,
	JOYAXIS_Y1 = 2,
	JOYAXIS_X2 = 3,
	JOYAXIS_Y2 = 4,
	JOYAXIS_NUM = 5
} joyaxisnum;

typedef enum {
	RM_NONE = 0,
	RM_REPLAY = 1,
	RM_RECORD = 2,
	RM_NUM = 3
};

typedef enum {
	UCODE_NORMAL = 0,
	UCODE_REFLECT = 1,
	UCODE_LIT = 2,
	UCODE_LITFILLET = 3,
	UCODE_LITNEARCLIP = 4,
	UCODE_CUTSCENE = 5,
	UCODE_NUM = 6
};

typedef enum {
	DMTX_NULL = -1,
	DMTX_NONE = 0,
	DMTX_NORMAL = 1,
	DMTX_OVERLAY = 2
};

typedef enum {
	BLENDMODE_NULL = -1,
	BLENDMODE_RGB = 0,
	BLENDMODE_RGBA = 1,
	BLENDMODE_ADDRGBA = 2,
	BLENDMODE_INVERSE_ADDRGBA = 3,
	BLENDMODE_FRAMEBUFFER_USES_ALPHA = 4,
	BLENDMODE_LIGHTEN_WITH_ALPHA = 5,
	BLENDMODE_DARKEN_WITH_ALPHA = 6,
	BLENDMODE_RGB_EXTRA = 7,
	BLENDMODE_SUBTRACTION = 8,
	BLENDMODE_RGBFIXA = 9,
	BLENDMODE_ADDRGBFIXA = 10,
	BLENDMODE_INVERSE_ADDRGBFIXA = 11,
	BLENDMODE_FRAMEBUFFER_USES_FIXED_ALPHA = 12,
	BLENDMODE_LIGHTEN_WITH_FIXED_ALPHA = 13,
	BLENDMODE_DARKEN_WITH_FIXED_ALPHA = 14,
	BLENDMODE_RGB_EXTRA_FIXED = 15,
	BLENDMODE_SUBTRACTION_FIXED = 16
};

typedef struct {
	u32 *pTags;
	u8 *pData;
	int DataSize;
	int NumFrames;
	int Frame;
	float Rate;
	float Count;
	sceIpuDmaEnv Env;
} MovieData;

typedef enum {
	ZB_NULL = -1,
	ZB_NOTEST_NOWRITE = 0,
	ZB_NOTEST_WRITE = 1,
	ZB_TEST_NOWRITE = 2,
	ZB_TEST_WRITE = 3,
	ZB_TEST_WRITE_ALPHATEST = 4,
	ZB_NOTEST_NOWRITE_DEST_ALPHATEST = 5,
	ZB_TEST_WRITE_GREATER = 6,
	ZB_NUMMODES = 7
};

typedef enum {
	GS_INDETERMINED = 0,
	GS_NOTINLEVEL = 1,
	GS_LOADING = 2,
	GS_LEVEL = 3,
	GS_COMPLETED = 4,
	GS_LEVELOUT = 5,
	GS_LOADINGSCREENIN = 6,
	GS_ENDLEVEL = 7,
	GS_ENDLEVELCOUNT = 8
} gamestate_t;

typedef enum {
	GAMESKILL_EASY = 0,
	GAMESKILL_NORMAL = 1,
	GAMESKILL_HARD = 2,
	GAMESKILL_NUM = 3
};

typedef enum {
	BOTSKILL_PATHETIC = 0,
	BOTSKILL_EASY = 1,
	BOTSKILL_AVERAGE = 2,
	BOTSKILL_GOOD = 3,
	BOTSKILL_TOUGH = 4,
	BOTSKILL_NUM = 5
};

typedef enum {
	GM_INDETERMINED = 0,
	GM_BAGTAG = 1,
	GM_CTF = 2,
	GM_DEATHMATCH = 3,
	GM_ESCORT = 4,
	GM_KNOCKOUT = 5,
	GM_LASTSTAND = 6,
	GM_ZONES = 7,
	GM_STORY = 8,
	NUM_GAMEMODES = 9
} gamemode_t;

typedef enum {
	SKELTYPE_NONE = -1,
	SKELTYPE_HUMAN19 = 0,
	SKELTYPE_BARRELROBOT = 1,
	SKELTYPE_RAILSPIDER = 2,
	SKELTYPE_SPIDER = 3,
	SKELTYPE_LIMBRELOCATED = 4,
	SKELTYPE_NUM = 5
};

typedef enum {
	CHANNEL_TYPE_NULL = 0,
	CHANNEL_TYPE_QUATERNION_LINEAR = 1,
	CHANNEL_TYPE_QUATERNION_SPHERICAL = 2,
	CHANNEL_TYPE_MATRIX = 3,
	CHANNEL_TYPE_TRANSFORM_XYZ = 4,
	CHANNEL_TYPE_TRANSFORM_X = 5,
	CHANNEL_TYPE_TRANSFORM_Y = 6,
	CHANNEL_TYPE_TRANSFORM_Z = 7,
	CHANNEL_TYPE_QUATERNION_SPHERICAL_TRANSFORM_XYZ = 8,
	CHANNEL_TYPE_NUM = 9
};

struct channel_s {
	int id;
	int type;
	float duration;
	int numKeyframes;
	int *keyframeList;
	float *data;
	channel *prev;
	channel *next;
};

typedef struct {
	float m[4][4];
	float m2[4][4];
} animRawCSCam_t;

typedef struct {
	float dx;
	float dy;
	float dz;
	float r;
	float g;
	float b;
} animRawCSLight_t;

struct animHeader_s {
	int totalFrames;
	int numKeyframes;
	int numJoints;
	int fAnimProp;
	float length;
	int *pKeyframes;
	int unused;
	int numChannels;
	channel *pChannel;
};

typedef animHeader_s animHeader;

struct animChannel_s {
	int id;
	int type;
	float duration;
	int numKeyframes;
	int *keyframeList;
	float *data;
	channel *prev;
	channel *next;
};

typedef animChannel_s animChannel;

typedef enum {
	GFX_OPA = 0,
	GFX_XLU = 1,
	GFX_SEMIOPA = 2,
	GFX_NUM = 3
};

typedef enum {
	OVERRIDEFX_FRAMEMASK = 1
};

typedef enum {
	AIMING_NOTPOINTING = 1,
	AIMING_SET = 2,
	AIMING_TWEENUP = 4,
	AIMING_TWEENDOWN = 8,
	AIMING_OVERWRITEANGLECALCED = 16
};

typedef enum {
	UCODETYPE_CLIP = 0,
	UCODETYPE_NOCLIP = 1
};

typedef enum {
	PARTTYPE_BEAD = 0,
	PARTTYPE_FILLET = 1,
	PARTTYPE_DOUBLEFILLET = 2,
	PARTTYPE_SPECIALFILLET = 3,
	PARTTYPE_NULL = 4
};

struct vector3_u {
	float v[3];
};

typedef vector3_u vector3;

typedef enum {
	DAXIS_X = 0,
	DAXIS_Y = 1,
	DAXIS_Z = 2
};

typedef enum {
	ANIMFLAG_TURNLEFT = 1,
	ANIMFLAG_TURNRIGHT = 2,
	ANIMFLAG_HASROTATED = 4
};

typedef enum {
	ANIM_TYPE_TRAVERSAL = 0,
	ANIM_TYPE_DEATH = 1
};

typedef enum {
	ANIMPARTHIT_BODY = 1,
	ANIMPARTHIT_LARM = 2,
	ANIMPARTHIT_RARM = 3,
	ANIMPARTHIT_HEAD = 4,
	ANIMPARTHIT_LLEG = 5,
	ANIMPARTHIT_RLEG = 6
};

typedef enum {
	GUNOPTION_ALWAYS_CHANGE_ON_PICKUP = 0,
	GUNOPTION_KEEP_CURRENT_WEAPON_ON_PICKUP = 1,
	GUNOPTION_USE_BEST_ON_PICKUP = 2,
	GUNOPTION_NUM = 3
};

typedef enum {
	AMMOTYPE_NONE = 0,
	AMMOTYPE_SMALLBULLET = 1,
	AMMOTYPE_BIGBULLET = 2,
	AMMOTYPE_SHELL = 3,
	AMMOTYPE_PLASMA = 4,
	AMMOTYPE_ROCKET = 5,
	AMMOTYPE_GRENADE = 6,
	AMMOTYPE_BRICK = 7,
	AMMOTYPE_REMOTEMINE = 8,
	AMMOTYPE_TIMEDMINE = 9,
	AMMOTYPE_PROXIMITYMINE = 10,
	AMMOTYPE_TNT = 11,
	AMMOTYPE_FLARE = 12,
	AMMOTYPE_DISC = 13,
	AMMOTYPE_ELECTRIC = 14,
	AMMOTYPE_PETROL = 15,
	AMMOTYPE_FOAM = 16,
	AMMOTYPE_NUM = 17
};

typedef enum {
	GUNFLAG_ONEHANDED = 1,
	GUNFLAG_TWOHANDED = 2,
	GUNFLAG_TWOHANDONLY = 4,
	GUNFLAG_CANSPRAYFIRE = 8,
	GUNFLAG_NODROP = 16,
	GUNFLAG_TOGGLEZOOM = 32,
	GUNFLAG_SILENCED = 64
};

typedef enum {
	GUNANIMFLAG_NONE = 0,
	GUNANIMFLAG_HAMMER = 1
};

typedef enum {
	GUNFIREFLAG_NONE = 0,
	GUNFIREFLAG_AIAIMATFLOOR = 1,
	GUNFIREFLAG_NOAIMACCURACY = 2
};

typedef enum {
	FIREMODE_NORMAL = 0,
	FIREMODE_ALT = 1,
	FIREMODE_NUM = 2
};

typedef enum {
	RELOAD_AUTOMATIC = 0,
	RELOAD_MANUAL = 1
};

typedef enum {
	REPEATMODE_SINGLE = 0,
	REPEATMODE_REPEAT = 1
};

typedef enum {
	GUNTYPE_NONE = -1,
	GUNTYPE_SILENCED_PISTOL = 0,
	GUNTYPE_FLARE_PISTOL = 1,
	GUNTYPE_MAGNUM = 2,
	GUNTYPE_ASSAULT_RIFLE = 3,
	GUNTYPE_ASSAULT_SHOTGUN = 4,
	GUNTYPE_SNIPER_RIFLE = 5,
	GUNTYPE_FLAMETHROWER = 6,
	GUNTYPE_FIRE_EXTINGUISHER = 7,
	GUNTYPE_AK47 = 8,
	GUNTYPE_ELECTROGUN = 9,
	GUNTYPE_SCIFI_HANDGUN = 10,
	GUNTYPE_ROCKET_LAUNCHER = 11,
	GUNTYPE_HOMING_ROCKET_LAUNCHER = 12,
	GUNTYPE_LASERGUN = 13,
	GUNTYPE_PLASMA_MACHINEGUN = 14,
	GUNTYPE_DISCTHROWER = 15,
	GUNTYPE_GRENADE_LAUNCHER = 16,
	GUNTYPE_GRENADE_THROW = 17,
	GUNTYPE_PROXIMITY_MINE = 18,
	GUNTYPE_REMOTE_MINE = 19,
	GUNTYPE_TIMED_MINE = 20,
	GUNTYPE_TNT = 21,
	GUNTYPE_TOMMY_GUN = 22,
	GUNTYPE_UZI = 23,
	GUNTYPE_BLUNDERBUSS = 24,
	GUNTYPE_GATLINGGUN = 25,
	GUNTYPE_DOUBLE_BARREL_SHOTGUN = 26,
	GUNTYPE_BRICK = 27,
	GUNTYPE_TIMESPLITTER = 28,
	GUNTYPE_FIXED = 29,
	GUNTYPE_BARRELROBOT = 30,
	GUNTYPE_APACHE = 31,
	GUNTYPE_TEST = 32,
	GUNTYPE_MAX = 33
};

typedef enum {
	GUNCOMBO_NONE = 0,
	GUNCOMBO_SILENCED_PISTOL = 1,
	GUNCOMBO_SILENCED_PISTOL_X2 = 2,
	GUNCOMBO_FLARE_PISTOL = 3,
	GUNCOMBO_FLARE_PISTOL_X2 = 4,
	GUNCOMBO_MAGNUM = 5,
	GUNCOMBO_MAGNUM_X2 = 6,
	GUNCOMBO_ASSAULT_RIFLE = 7,
	GUNCOMBO_ASSAULT_SHOTGUN = 8,
	GUNCOMBO_SNIPER_RIFLE = 9,
	GUNCOMBO_FLAMETHROWER = 10,
	GUNCOMBO_FIRE_EXTINGUISHER = 11,
	GUNCOMBO_AK47 = 12,
	GUNCOMBO_AK47_X2 = 13,
	GUNCOMBO_ELECTROGUN = 14,
	GUNCOMBO_SCIFI_HANDGUN = 15,
	GUNCOMBO_ROCKET_LAUNCHER = 16,
	GUNCOMBO_HOMING_ROCKET_LAUNCHER = 17,
	GUNCOMBO_LASERGUN = 18,
	GUNCOMBO_PLASMA_MACHINEGUN = 19,
	GUNCOMBO_PLASMA_MACHINEGUN_X2 = 20,
	GUNCOMBO_DISCTHROWER = 21,
	GUNCOMBO_DISCTHROWER_X2 = 22,
	GUNCOMBO_GRENADE_LAUNCHER = 23,
	GUNCOMBO_PROXIMITY_MINE = 24,
	GUNCOMBO_REMOTE_MINE = 25,
	GUNCOMBO_TIMED_MINE = 26,
	GUNCOMBO_TNT = 27,
	GUNCOMBO_TOMMY_GUN = 28,
	GUNCOMBO_TOMMY_GUN_X2 = 29,
	GUNCOMBO_UZI = 30,
	GUNCOMBO_UZI_X2 = 31,
	GUNCOMBO_BLUNDERBUSS = 32,
	GUNCOMBO_GATLINGGUN = 33,
	GUNCOMBO_GATLINGGUN_X2 = 34,
	GUNCOMBO_DOUBLE_BARREL_SHOTGUN = 35,
	GUNCOMBO_DOUBLE_BARREL_SHOTGUN_X2 = 36,
	GUNCOMBO_BRICK = 37,
	GUNCOMBO_TEST = 38,
	GUNCOMBO_TEST_X2 = 39,
	GUNCOMBO_MAX = 40
};

typedef enum {
	GUNSTATE_NOGUN = 0,
	GUNSTATE_NORMAL = 1,
	GUNSTATE_CHANGELOWER = 2,
	GUNSTATE_CHANGEDELETE = 3,
	GUNSTATE_CHANGECREATE = 4,
	GUNSTATE_CHANGEWAIT = 5,
	GUNSTATE_CHANGERAISE = 6,
	GUNSTATE_RELOADLOWER = 7,
	GUNSTATE_RELOADRAISE = 8,
	GUNSTATE_SHOTGUNRELOADOPEN = 9,
	GUNSTATE_SHOTGUNRELOADRELEASE = 10,
	GUNSTATE_SHOTGUNRELOADDOWN = 11,
	GUNSTATE_SHOTGUNRELOADUP = 12,
	GUNSTATE_SHOTGUNRELOADCLOSE = 13,
	GUNSTATE_SHOTGUNRELOADWAIT = 14,
	GUNSTATE_TNTTURNDOWN = 15,
	GUNSTATE_TNTTURNUP = 16,
	GUNSTATE_TNTBURN = 17,
	GUNSTATE_TNTWAIT = 18,
	GUNSTATE_TNTRAISE = 19,
	GUNSTATE_REMOTEMINE_WAIT = 20,
	GUNSTATE_MAX = 21
};

typedef enum {
	PICKUP_TYPE_BAG = 1,
	PICKUP_TYPE_GUN = 2,
	PICKUP_TYPE_KEY = 4,
	PICKUP_TYPE_HEALTH = 8,
	PICKUP_TYPE_ARMOUR = 16,
	PICKUP_TYPE_DROP = 32,
	PICKUP_TYPE_AMMO = 64,
	PICKUP_TYPE_POWERUP = 128,
	PICKUP_TYPE_TELEPORT = 256,
	PICKUP_TYPE_ITEM = 512
};

typedef enum {
	ITEM_COMPUTERDISK = 0,
	ITEM_NUM = 1
};

typedef enum {
	POSMODE_ORIGIN = 0,
	POSMODE_WORLD = 1,
	POSMODE_CAMERA = 2
};

typedef enum {
	ROTMODE_NONE = 0,
	ROTMODE_Y = 1,
	ROTMODE_ZXY = 2,
	ROTMODE_ATTACH = 3,
	ROTMODE_MTXROLL = 4
};

typedef enum {
	EVENT_PICKUP = 0,
	EVENT_DROP = 1,
	EVENT_ACTIVATE = 2,
	EVENT_DESTROY = 3,
	EVENT_ATTACH = 4,
	EVENT_TIMER = 5,
	EVENT_RESPAWN = 6,
	EVENT_TICKBEFORE = 7,
	EVENT_TICKAFTER = 8,
	EVENT_BURN = 9,
	EVENT_ROCK = 10,
	EVENT_NUM = 11
};

typedef enum {
	DOORTYPE_SINGLE_SLIDE_L = 0,
	DOORTYPE_SINGLE_SLIDE_R = 1,
	DOORTYPE_SINGLE_SLIDE_U = 2,
	DOORTYPE_DOUBLE_SLIDE_RL = 3,
	DOORTYPE_DOUBLE_SLIDE_LR = 4,
	DOORTYPE_DOUBLE_SLIDE_DOUBLE_LR = 5,
	DOORTYPE_DOUBLE_SLIDE_RR = 6,
	DOORTYPE_DOUBLE_DOUBLE_SLIDE = 7,
	DOORTYPE_NUMBER = 8
};

typedef enum {
	DOORKEY_NONE = 0,
	DOORKEY_RED = 1,
	DOORKEY_BLUE = 2,
	DOORKEY_YELLOW = 3,
	DOORKEY_GREEN = 4,
	DOORKEY_NUM = 5,
	DOORTYPE_WINDOW = 5
};

struct gundata_s {
	int a;
};

typedef gundata_s gundata;

typedef enum {
	PICKUP_READY = 1,
	PICKUP_DROPPING = 2,
	PICKUP_CARRIED = 4
};

typedef enum {
	LIMBSTATE_CHANGEOVER = 0,
	LIMBSTATE_ATTACHED = 1,
	LIMBSTATE_HIT = 2,
	LIMBSTATE_INFLIGHT = 3,
	LIMBSTATE_DELETE = 4
};

struct limbdata_s {
	mtx_u mtx;
	int state;
	int limb;
	float time;
	float xrotinc;
	float yrotinc;
	float zrotinc;
	float xrot;
	float yrot;
	float zrot;
	prop *chrbelongsto;
	float bulletdir[3];
};

typedef limbdata_s limbdata;

struct basedata_s {
	int id;
	int padnum;
};

typedef basedata_s basedata;

typedef enum {
	COLTYPE_CHR_AS_CYLINDER = 1,
	COLTYPE_CHR_AS_POLYS = 2,
	COLTYPE_IGNORE_DEAD_CHR = 4
};

typedef enum {
	OVERRIDE_XYZ = 1,
	OVERRIDE_ST = 2,
	OVERRIDE_RGBA = 4,
	OVERRIDE_GIFTAGS = 8,
	OVERRIDE_NORM = 16
};

typedef enum {
	PARTHIT_UNDEFINED = 0,
	PARTHIT_BODY = 1,
	PARTHIT_HEAD = 2,
	PARTHIT_LEFTARM = 3,
	PARTHIT_RIGHTARM = 4,
	PARTHIT_LEFTLEG = 5,
	PARTHIT_RIGHTLEG = 6,
	PARTHIT_NUM = 7
};

typedef enum {
	GC_FIRE = 0,
	GC_ALTFIRE = 1,
	GC_ACTIVATE = 2,
	GC_RELOAD = 3,
	GC_AIM = 4,
	GC_CROUCH = 5,
	GC_FORWARD = 6,
	GC_BACKWARD = 7,
	GC_TURNLEFT = 8,
	GC_TURNRIGHT = 9,
	GC_STEPLEFT = 10,
	GC_STEPRIGHT = 11,
	GC_LOOKUP = 12,
	GC_LOOKDOWN = 13,
	GC_ZOOMIN = 14,
	GC_ZOOMOUT = 15,
	GC_PREVWEAPON = 16,
	GC_NEXTWEAPON = 17,
	GC_AIMFORWARD = 18,
	GC_AIMBACKWARD = 19,
	GC_AIMTURNLEFT = 20,
	GC_AIMTURNRIGHT = 21,
	GC_AIMSTEPLEFT = 22,
	GC_AIMSTEPRIGHT = 23,
	GC_AIMLOOKUP = 24,
	GC_AIMLOOKDOWN = 25,
	GC_AIMZOOMIN = 26,
	GC_AIMZOOMOUT = 27,
	GC_AIMPREVWEAPON = 28,
	GC_AIMNEXTWEAPON = 29,
	GC_FORWARDAXIS = 30,
	GC_STRAFEAXIS = 31,
	GC_LOOKAXIS = 32,
	GC_TURNAXIS = 33,
	GC_CHANGEWEAPONAXIS = 34,
	GC_ZOOMAXIS = 35,
	GC_AIMFORWARDAXIS = 36,
	GC_AIMSTRAFEAXIS = 37,
	GC_AIMLOOKAXIS = 38,
	GC_AIMTURNAXIS = 39,
	GC_AIMCHANGEWEAPONAXIS = 40,
	GC_AIMZOOMAXIS = 41,
	NUM_GAMECONTROLS = 42
} gamecontrols;

typedef enum {
	PLAYER_CONFIG0 = 0,
	PLAYER_CONFIG_DEFAULT = 1,
	PLAYER_CONFIG_DEFAULT_LH = 2,
	PLAYER_CONFIG_EXPERT = 3,
	PLAYER_CONFIG_EXPERT_B = 4,
	PLAYER_CONFIG_DIGITAL = 5,
	PLAYER_CONFIG_DIGITAL_LH = 6,
	PLAYER_CONFIG_NUM = 7
};

typedef enum {
	HANDICAP_ROOKIE = 0,
	HANDICAP_NOVICE1 = 1,
	HANDICAP_NOVICE2 = 2,
	HANDICAP_NORMAL = 3,
	HANDICAP_VETERAN1 = 4,
	HANDICAP_VETERAN2 = 5,
	HANDICAP_HERO = 6,
	HANDICAP_NUM = 7
};

typedef enum {
	CHRFX_NONE = 0,
	CHRFX_SPAWN = 1,
	CHRFX_FADEOUT = 2,
	CHRFX_BURN = 4,
	CHRFX_ACTION = 8,
	CHRFX_CLOAKED = 16,
	CHRFX_BREATHING = 32,
	CHRFX_FOOTDECAL = 128
};

typedef enum {
	CHRFX_SPAWN_NONE = -1,
	CHRFX_SPAWN_RING = 0,
	CHRFX_SPAWN_ENERGY = 1,
	CHRFX_SPAWN_SPHERE = 2,
	CHRFX_SPAWN_BLAST = 3,
	NUM_CHRFX_SPAWN = 4
};

typedef enum {
	CHRFX_SPAWNSUBTYPE_RED = 0,
	CHRFX_SPAWNSUBTYPE_YELLOW = 1,
	CHRFX_SPAWNSUBTYPE_BLUE = 2,
	CHRFX_SPAWNSUBTYPE_GREEN = 3
};

typedef enum {
	CHRFX_ACTION_NONE = -1,
	CHRFX_ACTION_TIMESPLITTER_HANDS = 0,
	CHRFX_ACTION_TIMESPLITTER_RADIUS = 1,
	NUM_CHRFX_ACTION = 2
};

typedef enum {
	CHRTYPE_1 = 0,
	CHRTYPE_2 = 1,
	CHRTYPE_3 = 2,
	CHRTYPE_4 = 3,
	CHRTYPE_5 = 4,
	CHRTYPE_6 = 5,
	CHRTYPE_7 = 6,
	CHRTYPE_8 = 7,
	CHRTYPE_9 = 8,
	CHRTYPE_10 = 9,
	CHRTYPE_11 = 10,
	CHRTYPE_12 = 11,
	CHRTYPE_13 = 12,
	CHRTYPE_14 = 13,
	CHRTYPE_15 = 14,
	CHRTYPE_16 = 15,
	CHRTYPE_17 = 16,
	CHRTYPE_18 = 17,
	CHRTYPE_19 = 18,
	CHRTYPE_20 = 19,
	CHRTYPE_21 = 20,
	CHRTYPE_22 = 21,
	CHRTYPE_23 = 22,
	CHRTYPE_24 = 23,
	CHRTYPE_25 = 24,
	CHRTYPE_26 = 25,
	CHRTYPE_27 = 26,
	CHRTYPE_28 = 27,
	CHRTYPE_29 = 28,
	CHRTYPE_30 = 29,
	CHRTYPE_31 = 30,
	CHRTYPE_32 = 31,
	CHRTYPE_33 = 32,
	CHRTYPE_34 = 33,
	CHRTYPE_35 = 34,
	CHRTYPE_36 = 35,
	CHRTYPE_37 = 36,
	CHRTYPE_38 = 37,
	CHRTYPE_39 = 38,
	CHRTYPE_40 = 39,
	CHRTYPE_41 = 40,
	CHRTYPE_42 = 41,
	CHRTYPE_43 = 42,
	CHRTYPE_44 = 43,
	CHRTYPE_45 = 44,
	CHRTYPE_46 = 45,
	CHRTYPE_47 = 46,
	CHRTYPE_48 = 47,
	CHRTYPE_49 = 48,
	CHRTYPE_50 = 49,
	CHRTYPE_NUM = 50
};

typedef enum {
	CHRSUBTYPE_HUMAN = 0,
	CHRSUBTYPE_ZOMBIE = 1,
	CHRSUBTYPE_TIMESPLITTER = 2,
	CHRSUBTYPE_ROBOT = 3
};

typedef enum {
	APPEARANCE_HUMAN = 0,
	APPEARANCE_ZOMBIE = 1,
	APPEARANCE_TIMESPLITTER = 2,
	APPEARANCE_ROBOT = 3,
	APPEARANCE_ALIEN = 4
};

typedef enum {
	SEX_MALE = 0,
	SEX_FEMALE = 1
};

typedef enum {
	CHRMOVEMODE_NORMAL = 1,
	CHRMOVEMODE_STRAFE = 2,
	CHRMOVEMODE_CROUCH = 4,
	CHRMOVEMODE_STATIONARY = 8,
	CHRMOVEMODE_GUNREADY = 16,
	CHRMOVEMODE_DEATH = 32,
	CHRMOVEMODE_DECELERATE = 64,
	CHRMOVEMODE_BACKWARDS = 128,
	CHRMOVEMODE_JUMP = 256,
	CHRMOVEMODE_OVERRIDE = 512,
	CHRMOVEMODE_PATROL = 1024,
	CHRMOVEMODE_BOUND = 2048,
	CHRMOVEMODE_FALLING = 4096,
	CHRMOVEMODE_MAX = 4097
};

typedef enum {
	POWER_INVISIBLE = 1,
	POWER_KEYCARD_1 = 2,
	POWER_KEYCARD_2 = 4,
	POWER_KEYCARD_3 = 8,
	POWER_KEYCARD_4 = 16
};

typedef enum {
	ARMOUR_TYPE_NONE = 0,
	ARMOUR_TYPE_LOW = 1,
	ARMOUR_TYPE_HIGH = 2
};

typedef enum {
	LIMB_HEAD = 0,
	LIMB_LEFTARM = 1,
	LIMB_RIGHTARM = 2,
	LIMB_LEFTLEG = 3,
	LIMB_RIGHTLEG = 4,
	LIMB_HAT = 5,
	NUM_LIMBS = 6
};

typedef enum {
	SHOOTFLAG_NORMAL = 1,
	SHOOTFLAG_SPRAY = 2,
	SHOOTFLAG_SPRAYXPOS = 4,
	SHOOTFLAG_SPRAYXNEG = 8
};

typedef enum {
	UTF_DROPPINGBAG = 0,
	UTF_PICKINGUPBAG = 1
};

typedef enum {
	BLURMODE_NORMAL = 0,
	BLURMODE_ADDITIVE = 1
};

typedef enum {
	SFX_SIBERIA_GUARD_ALERT01 = 0,
	SFX_SIBERIA_GUARD_ALERT02 = 1,
	SFX_SIBERIA_GUARD_ALERT03 = 2,
	SFX_SIBERIA_GUARD_ALERT04 = 3,
	SFX_SIBERIA_GUARD_ALERT05 = 4,
	SFX_SIBERIA_GUARD_ALERT06 = 5,
	SFX_SIBERIA_GUARD_ALERT07 = 6,
	SFX_SIBERIA_GUARD_ALERT08 = 7,
	SFX_SIBERIA_GUARD_ALERT09 = 8,
	SFX_SIBERIA_GUARD_ALERT10 = 9,
	SFX_SIBERIA_GUARD_ALERT11 = 10,
	SFX_SIBERIA_GUARD_ALERT12 = 11,
	SFX_SIBERIA_GUARD_ALERT13 = 12,
	SFX_SIBERIA_GUARD_ALERT14 = 13,
	SFX_SIBERIA_GUARD_ALERT15 = 14,
	SFX_SIBERIA_GUARD_ALERT16 = 15,
	SFX_SIBERIA_GUARD_ALERT17 = 16,
	SFX_SIBERIA_GUARD_ALERT18 = 17,
	SFX_SIBERIA_GUARD_ALERT19 = 18,
	SFX_TANNOY_MAN01 = 19,
	SFX_COPTER = 20,
	SFX_LIFT_DING = 21,
	SFX_DOOR_METAL_SLIDE = 22,
	SFX_DOOR_LIFT_SLIDE = 23,
	SFX_TURNY_PIPE = 24,
	SFX_TARGET_AQUIRED = 25,
	SFX_CAMERA_EXPLODE = 26,
	SFX_STEAM_LOOPED = 27,
	SFX_DOOR_BIG_METAL_SHUT = 28,
	SFX_RESTORE_POWER = 29,
	SFX_BUTTON_PRESS = 30,
	SFX_SHOWER_LOOPED = 31,
	SFX_BIOHAZARD = 32,
	SFX_DOOR_FILING_CABINET = 33,
	SFX_SATDISH_HITFLOOR = 34,
	SFX_APACHE_GUN = 35,
	SFX_APACHE_ROCKET = 36,
	SFX_LASERLOCK_LOOPED = 37,
	SFX_CHURCHBELL = 38,
	SFX_RF_TARGET_AQUIRED = 39,
	SFX_RF_DOOR_SLIDE1 = 40,
	SFX_AIRPLANE = 41,
	SFX_SCIFI_FAN = 42,
	SFX_CONSOLE_ON = 43,
	SFX_CYBERDEN_ENGINESTEAM = 44,
	SFX_WEAPON_CHECK = 45,
	SFX_LAUNCH_ENGINESTEAM = 46,
	SFX_GONG = 47,
	SFX_ELEC_LOOP = 48,
	SFX_SPARK1 = 49,
	SFX_SPARK2 = 50,
	SFX_SPARK3 = 51,
	SFX_WATERFALL = 52,
	SFX_PLANET_CRYSTALBLAST = 53,
	SFX_PLANET_CRYSTALBLAST2 = 54,
	SFX_HELICOPTER = 55,
	SFX_BANK_HOURCHIME = 56,
	SFX_MALL_CLOCK2 = 57,
	SFX_PUB_SIGN = 58,
	SFX_GRAVEYARD_LAUGH01 = 59,
	SFX_GRAVEYARD_LAUGH02 = 60,
	SFX_GRAVEYARD_WOLF01 = 61,
	SFX_MANSION_DOOR_OPEN = 62,
	SFX_SPACEWAYS_DOOR_OPEN = 63,
	SFX_LEVELCOMPLETE_LEVEL2_L = 64,
	SFX_LEVELFAIL_LEVEL2_L = 65,
	SFX_LEVELCOMPLETE_LEVEL5_L = 66,
	SFX_LEVELFAIL_LEVEL5_L = 67,
	SFX_LEVELCOMPLETE_LEVEL8_L = 68,
	SFX_LEVELFAIL_LEVEL8_L = 69,
	SFX_LEVELCOMPLETE_LEVEL9_L = 70,
	SFX_LEVELFAIL_LEVEL9_L = 71,
	SFX_LEVELCOMPLETE_LEVEL10_L = 72,
	SFX_LEVELFAIL_LEVEL10_L = 73,
	SFX_LEVELCOMPLETE_LEVEL11_L = 74,
	SFX_LEVELFAIL_LEVEL11_L = 75,
	SFX_LEVELCOMPLETE_LEVEL12_L = 76,
	SFX_LEVELFAIL_LEVEL12_L = 77,
	SFX_LEVELCOMPLETE_LEVEL13_L = 78,
	SFX_LEVELFAIL_LEVEL13_L = 79,
	SFX_LEVELCOMPLETE_LEVEL14_L = 80,
	SFX_LEVELFAIL_LEVEL14_L = 81,
	SFX_LEVELCOMPLETE_LEVEL15_L = 82,
	SFX_LEVELFAIL_LEVEL15_L = 83,
	SFX_LEVELCOMPLETE_LEVEL16_L = 84,
	SFX_LEVELFAIL_LEVEL16_L = 85,
	SFX_LEVELCOMPLETE_LEVEL17_L = 86,
	SFX_LEVELFAIL_LEVEL17_L = 87,
	SFX_LEVELCOMPLETE_LEVEL18_L = 88,
	SFX_LEVELFAIL_LEVEL18_L = 89,
	SFX_LEVELCOMPLETE_LEVEL21_L = 90,
	SFX_LEVELFAIL_LEVEL21_L = 91,
	SFX_LEVELCOMPLETE_LEVEL22_L = 92,
	SFX_LEVELFAIL_LEVEL22_L = 93,
	SFX_LEVELCOMPLETE_LEVEL23_L = 94,
	SFX_LEVELFAIL_LEVEL23_L = 95,
	SFX_LEVELCOMPLETE_LEVEL24_L = 96,
	SFX_LEVELFAIL_LEVEL24_L = 97,
	SFX_LEVELCOMPLETE_LEVEL26_L = 98,
	SFX_LEVELFAIL_LEVEL26_L = 99,
	SFX_LEVELCOMPLETE_LEVEL27_L = 100,
	SFX_LEVELFAIL_LEVEL27_L = 101,
	SFX_GUARD_MALE_HUH01 = 102,
	SFX_GUARD_FEM_HUH01 = 103,
	SFX_GUARD_ZOMBIE_HUH01 = 104,
	SFX_GUARD_GASMASK_HUH01 = 105,
	SFX_MALE_ONFIRE = 106,
	SFX_FEM_ONFIRE = 107,
	SFX_ZOMBIE_ONFIRE = 108,
	SFX_GASMASK_ONFIRE = 109,
	SFX_BODYFALL1 = 110,
	SFX_BODYFALL2 = 111,
	SFX_BODYFALL3 = 112,
	SFX_BODYFALL4 = 113,
	SFX_BODYFALL5 = 114,
	SFX_BODYFALL6 = 115,
	SFX_BODYFALL7 = 116,
	SFX_BODYFALL8 = 117,
	SFX_BODYFALL9 = 118,
	SFX_BODYFALL10 = 119,
	SFX_BODYFALL11 = 120,
	SFX_EXPLOSION1 = 121,
	SFX_EXPLOSION2 = 122,
	SFX_EXPLOSION3 = 123,
	SFX_EXPLOSION4 = 124,
	SFX_EXPLOSION5 = 125,
	SFX_EXPLOSION6 = 126,
	SFX_DRGUN3 = 127,
	SFX_GUN1 = 128,
	SFX_GUN2 = 129,
	SFX_GUN5 = 130,
	SFX_GUN5B = 131,
	SFX_GUN13 = 132,
	SFX_GUN18 = 133,
	SFX_GUNGRENADELAUNCHER = 134,
	SFX_GUNSNIPERRIFLE = 135,
	SFX_GUNWALTHER = 136,
	SFX_GUNCOLT = 137,
	SFX_GUNCOLT_SHORT = 138,
	SFX_GUNMAUSER = 139,
	SFX_GUNTOMMYGUN = 140,
	SFX_GUNLASER1 = 141,
	SFX_GUNLASER2 = 142,
	SFX_GUNSCIFIHANDGUN = 143,
	SFX_GUNSCIFISNIPER = 144,
	SFX_GUN_SILENCED_PISTOL = 145,
	SFX_GUN_ELECTROGUN_SECONDARY = 146,
	SFX_GUN_ELECTROGUN_LOOP = 147,
	SFX_GUN_ELECTROGUN_FIRST = 148,
	SFX_GUN_UZI = 149,
	SFX_GUNRAIL_END = 150,
	SFX_GUNROCKET02 = 151,
	SFX_GUN_FLAMETHROWER = 152,
	SFX_GUN_FLAMETHROWER_LOOP = 153,
	SFX_GUN_FIRE_EXTINGUISHER = 154,
	SFX_GUN_FIRE_EXTINGUISHER_LOOP = 155,
	SFX_GUNASSAULT = 156,
	SFX_GUNROCKET03 = 157,
	SFX_GUN_REDLASER = 158,
	SFX_RICOCHET1 = 159,
	SFX_RICOCHET2 = 160,
	SFX_RICOCHET3 = 161,
	SFX_RICOCHET4 = 162,
	SFX_RICOCHET5 = 163,
	SFX_RICOCHET6 = 164,
	SFX_RICOCHET7 = 165,
	SFX_RICOCHET8 = 166,
	SFX_RICOCHET9 = 167,
	SFX_RICOCHET10 = 168,
	SFX_RICOCHET11 = 169,
	SFX_RICOCHET12 = 170,
	SFX_GETGUN = 171,
	SFX_GETGUN_SCIFI = 172,
	SFX_GETBRICK = 173,
	SFX_BRICKHIT = 174,
	SFX_CHANGEGUN = 175,
	SFX_RELOAD = 176,
	SFX_THROW = 177,
	SFX_FRONTEND1 = 178,
	SFX_FRONTEND2 = 179,
	SFX_FRONTEND3 = 180,
	SFX_CHOOSE1 = 181,
	SFX_CHOOSE2 = 182,
	SFX_OPENUP = 183,
	SFX_CAMERA = 184,
	SFX_BEEP01 = 185,
	SFX_BEEP02 = 186,
	SFX_SPLITTER_ROAR = 187,
	SFX_ZOMBIE_SWIPE1 = 188,
	SFX_ZOMBIE_SWIPE2 = 189,
	SFX_SPLITTER_FIREBALL = 190,
	SFX_SCIFI_RICO1 = 191,
	SFX_SCIFI_RICO2 = 192,
	SFX_SCIFI_RICO3 = 193,
	SFX_SCIFI_RICO4 = 194,
	SFX_TNT_FUSE = 195,
	SFX_TNT_BOUNCE01 = 196,
	SFX_TNT_BOUNCE02 = 197,
	SFX_TNT_BOUNCE03 = 198,
	SFX_TNT_BOUNCE04 = 199,
	SFX_GET_AMMO = 200,
	SFX_GET_HEALTH = 201,
	SFX_GET_ARMOUR = 202,
	SFX_TNT_LIGHT = 203,
	SFX_GUN_DRYFIRE01 = 204,
	SFX_GUN_BADDIECOCK01 = 205,
	SFX_TIME_MINE_COUNT = 206,
	SFX_TIME_MINE_COUNTLAST = 207,
	SFX_PROXIMITY_MINE_LOOP = 208,
	SFX_ATTACH_MINE = 209,
	SFX_REMOTE_MINE_TRIGGER = 210,
	SFX_DROPGUN = 211,
	SFX_SHOTGUN_COCK = 212,
	SFX_TIMEUP = 213,
	SFX_ONEMINLEFT = 214,
	SFX_TENSECLEFT = 215,
	SFX_GLASSBREAK1 = 216,
	SFX_GLASSBREAK2 = 217,
	SFX_GLASSBREAK3 = 218,
	SFX_GLASSBREAK4 = 219,
	SFX_DYING_FALL_MALE = 220,
	SFX_BONECRACK = 221,
	SFX_PUNCH01 = 222,
	SFX_PUNCH02 = 223,
	SFX_PUNCH03 = 224,
	SFX_PUNCH04 = 225,
	SFX_HEADSUP = 226,
	SFX_CAMERA_ALARM = 227,
	SFX_PLAYER_RESPAWN = 228,
	SFX_GUN_RESPAWN = 229,
	SFX_ROCKET_RELOAD = 230,
	SFX_FIXED_GUN01 = 231,
	SFX_INVUNERABLE = 232,
	SFX_FIXEDGUN_ON = 233,
	SFX_FIXEDGUN_OFF = 234,
	SFX_TEXT_SWEEP = 235,
	SFX_SNIPER_RESPAWN = 236,
	SFX_PAUSEGAME = 237,
	SFX_NO_CAN_DO = 238,
	SFX_GENERIC_BEEP = 239,
	SFX_PICKUP_ANKH = 240,
	SFX_PICKUP_PAPERWALLET = 241,
	SFX_PICKUP_MINIDISC = 242,
	SFX_PICKUP_EGGTIMER = 243,
	SFX_PICKUP_METALCASE = 244,
	SFX_PICKUP_BRAIN = 245,
	SFX_PICKUP_SKULL = 246,
	SFX_PICKUP_BRIEFCASE = 247,
	SFX_PICKUP_BOTTLE = 248,
	SFX_PICKUP_BAG = 249,
	SFX_DROP_BAG = 250,
	SFX_GUNCHEAT_BLOWER = 251,
	SFX_GUNCHEAT_BLUNDER = 252,
	SFX_GUNCHEAT_BOING01 = 253,
	SFX_GUNCHEAT_BOING02 = 254,
	SFX_GUNCHEAT_HORN1 = 255,
	SFX_GUNCHEAT_HORN2 = 256,
	SFX_GUNCHEAT_CUKOO = 257,
	SFX_GUNCHEAT_DUCK = 258,
	SFX_GUNCHEAT_FART = 259,
	SFX_GUNCHEAT_FROG = 260,
	SFX_GUNCHEAT_JHARP = 261,
	SFX_GUNCHEAT_POP01 = 262,
	SFX_GUNCHEAT_POP02 = 263,
	SFX_GUNCHEAT_POP03 = 264,
	SFX_GUNCHEAT_RULER = 265,
	SFX_GUNCHEAT_SQUEEZETOY = 266,
	SFX_GUNCHEAT_SWANEEDOWN = 267,
	SFX_GUNCHEAT_SWANEEUP = 268,
	SFX_GUNCHEAT_TWANG = 269,
	SFX_GUNCHEAT_TWEAK = 270,
	SFX_GUNCHEAT_WHISTLEUP = 271,
	SFX_FE_ACTING_REDALIEN = 272,
	SFX_FE_ACTING_M_COP = 273,
	SFX_FE_ACTING_F_STEWARDESS_KISS = 274,
	SFX_FE_ACTING_M_CLEANER = 275,
	SFX_FE_ACTING_M_COOK = 276,
	SFX_FE_ACTING_F_FUTCOP = 277,
	SFX_FE_ACTING_M_RESDOG = 278,
	SFX_FE_ACTING_M_SWAT = 279,
	SFX_FE_ACTING_M_ROBOT = 280,
	SFX_FE_ACTING_U_OVERALL = 281,
	SFX_FE_ACTING_M_SMARINE = 282,
	SFX_FE_ACTING_M_HOOD = 283,
	SFX_FE_ACTING_X_ROBOFISH = 284,
	SFX_FE_ACTING_Z_ZOMBIE = 285,
	SFX_FE_ACTING_F_ROBOT = 286,
	SFX_FE_ACTING_F_HOOD = 287,
	SFX_FE_ACTING_M_PERHOR = 288,
	SFX_FE_ACTING_DUCK = 289,
	SFX_FE_ACTING_PRIESTESS = 290,
	SFX_FE_ACTING_HICK = 291,
	SFX_FE_ACTING_M_SCIENTIST = 292,
	SFX_FE_ACTING_M_MRBIG = 293,
	SFX_FE_ACTING_M_FUTCOP = 294,
	SFX_FE_ACTING_F_PERHORROR = 295,
	SFX_FE_ACTING_BONUSBOY = 296,
	SFX_FE_ACTING_F_SCIENTIST = 297,
	SFX_FE_ACTING_M_TEENHORROR = 298,
	SFX_FE_ACTING_F_SMARINE = 299,
	SFX_FE_ACTING_CHEERLEADER = 300,
	SFX_FE_ACTING_INSECTMUTANT = 301,
	SFX_FE_ACTING_FEMCOP = 302,
	SFX_FE_ACTING_PILLAR = 303,
	SFX_FE_ACTING_TEETH = 304,
	SFX_FE_ACTING_FEMCYBORG = 305,
	SFX_FE_ACTING_FEMZOMBIE = 306,
	SFX_FE_ACTING_SPLITTER2 = 307,
	SFX_FE_ACTING_TUXEDO = 308,
	SFX_FE_ACTING_FEMSWAT = 309,
	SFX_FE_ACTING_VEILMASK = 310,
	SFX_FE_ACTING_PRIESTMUTANT = 311,
	SFX_FE_ACTING_FEMALIEN = 312,
	SFX_FE_ACTING_SPLITTER1 = 313,
	SFX_FE_ACTING_GINGER = 314,
	SFX_FE_ACTING_BADASS = 315,
	SFX_FE_ACTING_WAITER = 316,
	SFX_FE_ACTING_FLOAT = 317,
	SFX_FE_ACTING_BUNNY = 318,
	SFX_SWAYS_ANNOUNCE01 = 319,
	SFX_SWAYS_ANNOUNCE02 = 320,
	SFX_SWAYS_ANNOUNCE03 = 321,
	SFX_SWAYS_ANNOUNCE04 = 322,
	SFX_MALL_ANNOUNCE01 = 323,
	SFX_MALL_ANNOUNCE02 = 324,
	SFX_MALL_ANNOUNCE03 = 325,
	SFX_MALL_ANNOUNCE04 = 326,
	SFX_GRAVEYARD_ANNOUNCE01 = 327,
	SFX_GRAVEYARD_ANNOUNCE02 = 328,
	SFX_GRAVEYARD_ANNOUNCE03 = 329,
	SFX_GRAVEYARD_ANNOUNCE04 = 330,
	SFX_WARZONE01 = 331,
	SFX_WARZONE02 = 332,
	SFX_WARZONE03 = 333,
	SFX_WARZONE04 = 334,
	SFX_COMPOUND01 = 335,
	SFX_COMPOUND02 = 336,
	SFX_STREETS_SIREN01 = 337,
	SFX_STREETS_SIREN02 = 338,
	SFX_BULLETHIT_WOOD01 = 339,
	SFX_BULLETHIT_WOOD02 = 340,
	SFX_BULLETHIT_STONE01 = 341,
	SFX_BULLETHIT_TILE01 = 342,
	SFX_BULLETHIT_PAPER01 = 343,
	SFX_BULLETHIT_PAPER02 = 344,
	SFX_BULLETHIT_GLASS01 = 345,
	SFX_BULLETHIT_GLASS02 = 346,
	SFX_BULLETHIT_WATER01 = 347,
	SFX_BULLETHIT_WATER02 = 348,
	SFX_BULLETHIT_DIRT01 = 349,
	SFX_BULLETHIT_METAL01 = 350,
	SFX_BULLETHIT_METAL02 = 351,
	SFX_BULLETHIT_METAL03 = 352,
	SFX_BULLETHIT_METAL04 = 353,
	SFX_BULLETHIT_METAL05 = 354,
	SFX_BULLETHIT_METAL06 = 355,
	SFX_BULLETHIT_METAL07 = 356,
	SFX_BULLETHIT_CHAINFENCE = 357,
	SFX_BULLETHITBODY = 358,
	SFX_BULLETHIT_DUCK = 359,
	SFX_BULLETHIT_ROBOT01 = 360,
	SFX_BULLETHIT_ROBOT02 = 361,
	SFX_BULLETHIT_ROBOT03 = 362,
	SFX_BULLETHIT_MISC01 = 363,
	SFX_BULLETHIT_MISC02 = 364,
	SFX_BULLETHIT_MISC03 = 365,
	SFX_BULLETHIT_MISC04 = 366,
	SFX_BULLETHIT_MISC05 = 367,
	SFX_BULLETHIT_MISC06 = 368,
	SFX_BULLETHIT_MISC07 = 369,
	SFX_BULLETHIT_MISC08 = 370,
	SFX_BULLETHIT_MISC09 = 371,
	SFX_BULLETHIT_MISC10 = 372,
	SFX_ANGEL_HIT01 = 373,
	SFX_ANGEL_HIT02 = 374,
	SFX_ANGEL_HIT03 = 375,
	SFX_ANGEL_HIT04 = 376,
	SFX_ANGEL_HIT05 = 377,
	SFX_ANGEL_HIT06 = 378,
	SFX_ANGEL_HIT07 = 379,
	SFX_ANGEL_HIT08 = 380,
	SFX_ANGEL_HIT09 = 381,
	SFX_ANGEL_HIT10 = 382,
	SFX_ANGEL_HIT11 = 383,
	SFX_ANGEL_HIT12 = 384,
	SFX_ANGEL_HIT13 = 385,
	SFX_ANGEL_HIT14 = 386,
	SFX_ANGEL_HIT15 = 387,
	SFX_ANGEL_HIT16 = 388,
	SFX_ANGEL_HIT17 = 389,
	SFX_MRBIG_HIT01 = 390,
	SFX_MRBIG_HIT02 = 391,
	SFX_MRBIG_HIT03 = 392,
	SFX_MRBIG_HIT04 = 393,
	SFX_MRBIG_HIT05 = 394,
	SFX_MRBIG_HIT06 = 395,
	SFX_MRBIG_HIT07 = 396,
	SFX_MRBIG_HIT08 = 397,
	SFX_MRBIG_HIT09 = 398,
	SFX_MRBIG_HIT10 = 399,
	SFX_MRBIG_HIT11 = 400,
	SFX_MRBIG_HIT12 = 401,
	SFX_MRBIG_HIT13 = 402,
	SFX_MRBIG_HIT14 = 403,
	SFX_MRBIG_HIT15 = 404,
	SFX_FUTCOP_M_HIT01 = 405,
	SFX_FUTCOP_M_HIT02 = 406,
	SFX_FUTCOP_M_HIT03 = 407,
	SFX_FUTCOP_M_HIT04 = 408,
	SFX_FUTCOP_M_HIT05 = 409,
	SFX_FUTCOP_M_HIT06 = 410,
	SFX_FUTCOP_M_HIT07 = 411,
	SFX_FUTCOP_M_HIT08 = 412,
	SFX_FUTCOP_M_HIT09 = 413,
	SFX_FUTCOP_M_HIT10 = 414,
	SFX_FUTCOP_M_HIT11 = 415,
	SFX_FUTCOP_M_HIT12 = 416,
	SFX_FUTCOP_M_HIT13 = 417,
	SFX_FUTCOP_M_HIT14 = 418,
	SFX_FUTCOP_M_HIT15 = 419,
	SFX_GRAVEN_HIT01 = 420,
	SFX_GRAVEN_HIT02 = 421,
	SFX_GRAVEN_HIT03 = 422,
	SFX_GRAVEN_HIT04 = 423,
	SFX_GRAVEN_HIT05 = 424,
	SFX_GRAVEN_HIT06 = 425,
	SFX_GRAVEN_HIT07 = 426,
	SFX_GRAVEN_HIT08 = 427,
	SFX_GRAVEN_HIT09 = 428,
	SFX_GRAVEN_HIT10 = 429,
	SFX_GRAVEN_HIT11 = 430,
	SFX_GRAVEN_HIT12 = 431,
	SFX_GRAVEN_HIT13 = 432,
	SFX_GRAVEN_HIT14 = 433,
	SFX_GRAVEN_HIT15 = 434,
	SFX_LUMBERJACK_HIT01 = 435,
	SFX_LUMBERJACK_HIT02 = 436,
	SFX_LUMBERJACK_HIT03 = 437,
	SFX_LUMBERJACK_HIT04 = 438,
	SFX_LUMBERJACK_HIT05 = 439,
	SFX_LUMBERJACK_HIT06 = 440,
	SFX_LUMBERJACK_HIT07 = 441,
	SFX_LUMBERJACK_HIT08 = 442,
	SFX_LUMBERJACK_HIT09 = 443,
	SFX_LUMBERJACK_HIT10 = 444,
	SFX_LUMBERJACK_HIT11 = 445,
	SFX_LUMBERJACK_HIT12 = 446,
	SFX_LUMBERJACK_HIT13 = 447,
	SFX_LUMBERJACK_HIT14 = 448,
	SFX_LUMBERJACK_HIT15 = 449,
	SFX_CAPT_ASH_HIT01 = 450,
	SFX_CAPT_ASH_HIT02 = 451,
	SFX_CAPT_ASH_HIT03 = 452,
	SFX_CAPT_ASH_HIT04 = 453,
	SFX_CAPT_ASH_HIT05 = 454,
	SFX_CAPT_ASH_HIT06 = 455,
	SFX_CAPT_ASH_HIT07 = 456,
	SFX_CAPT_ASH_HIT08 = 457,
	SFX_CAPT_ASH_HIT09 = 458,
	SFX_CAPT_ASH_HIT10 = 459,
	SFX_CAPT_ASH_HIT11 = 460,
	SFX_CAPT_ASH_HIT12 = 461,
	SFX_CAPT_ASH_HIT13 = 462,
	SFX_CYBORG_BADASS_HIT01 = 463,
	SFX_CYBORG_BADASS_HIT02 = 464,
	SFX_CYBORG_BADASS_HIT03 = 465,
	SFX_CYBORG_BADASS_HIT04 = 466,
	SFX_CYBORG_BADASS_HIT05 = 467,
	SFX_CYBORG_BADASS_HIT06 = 468,
	SFX_CYBORG_BADASS_HIT07 = 469,
	SFX_CYBORG_BADASS_HIT08 = 470,
	SFX_CYBORG_BADASS_HIT09 = 471,
	SFX_CYBORG_BADASS_HIT10 = 472,
	SFX_CYBORG_BADASS_HIT11 = 473,
	SFX_CYBORG_BADASS_HIT12 = 474,
	SFX_CYBORG_BADASS_HIT13 = 475,
	SFX_LADY_JAYNE_HIT01 = 476,
	SFX_LADY_JAYNE_HIT02 = 477,
	SFX_LADY_JAYNE_HIT03 = 478,
	SFX_LADY_JAYNE_HIT04 = 479,
	SFX_LADY_JAYNE_HIT05 = 480,
	SFX_LADY_JAYNE_HIT06 = 481,
	SFX_LADY_JAYNE_HIT07 = 482,
	SFX_LADY_JAYNE_HIT08 = 483,
	SFX_LADY_JAYNE_HIT09 = 484,
	SFX_LADY_JAYNE_HIT10 = 485,
	SFX_LADY_JAYNE_HIT11 = 486,
	SFX_LADY_JAYNE_HIT12 = 487,
	SFX_LADY_JAYNE_HIT13 = 488,
	SFX_FINGERS_HIT01 = 489,
	SFX_FINGERS_HIT02 = 490,
	SFX_FINGERS_HIT03 = 491,
	SFX_FINGERS_HIT04 = 492,
	SFX_FINGERS_HIT05 = 493,
	SFX_FINGERS_HIT06 = 494,
	SFX_FINGERS_HIT07 = 495,
	SFX_FINGERS_HIT08 = 496,
	SFX_FINGERS_HIT09 = 497,
	SFX_FINGERS_HIT10 = 498,
	SFX_FINGERS_HIT11 = 499,
	SFX_FINGERS_HIT12 = 500,
	SFX_FINGERS_HIT13 = 501,
	SFX_FINGERS_HIT14 = 502,
	SFX_FINGERS_HIT15 = 503,
	SFX_SCIENTIST_F_HIT01 = 504,
	SFX_SCIENTIST_F_HIT02 = 505,
	SFX_SCIENTIST_F_HIT03 = 506,
	SFX_SCIENTIST_F_HIT04 = 507,
	SFX_SCIENTIST_F_HIT05 = 508,
	SFX_SCIENTIST_F_HIT06 = 509,
	SFX_SCIENTIST_F_HIT07 = 510,
	SFX_SCIENTIST_F_HIT08 = 511,
	SFX_SCIENTIST_F_HIT09 = 512,
	SFX_SCIENTIST_F_HIT10 = 513,
	SFX_SCIENTIST_F_HIT11 = 514,
	SFX_SCIENTIST_F_FLINCH = 515,
	SFX_SCIENTIST_F_DIE01 = 516,
	SFX_SCIENTIST_F_DIE02 = 517,
	SFX_SCIENTIST_F_DIE03 = 518,
	SFX_SCIENTIST_F_DIE04 = 519,
	SFX_FUTCOP_F_HIT01 = 520,
	SFX_FUTCOP_F_HIT02 = 521,
	SFX_FUTCOP_F_HIT03 = 522,
	SFX_FUTCOP_F_HIT04 = 523,
	SFX_FUTCOP_F_HIT05 = 524,
	SFX_FUTCOP_F_HIT06 = 525,
	SFX_FUTCOP_F_HIT07 = 526,
	SFX_FUTCOP_F_HIT08 = 527,
	SFX_FUTCOP_F_HIT09 = 528,
	SFX_FUTCOP_F_HIT10 = 529,
	SFX_FUTCOP_F_HIT11 = 530,
	SFX_FUTCOP_F_HIT12 = 531,
	SFX_STEWARDESS_HIT01 = 532,
	SFX_STEWARDESS_HIT02 = 533,
	SFX_STEWARDESS_HIT03 = 534,
	SFX_STEWARDESS_HIT04 = 535,
	SFX_STEWARDESS_HIT05 = 536,
	SFX_STEWARDESS_HIT06 = 537,
	SFX_STEWARDESS_HIT07 = 538,
	SFX_STEWARDESS_HIT08 = 539,
	SFX_STEWARDESS_HIT09 = 540,
	SFX_STEWARDESS_HIT10 = 541,
	SFX_STEWARDESS_HIT11 = 542,
	SFX_STEWARDESS_HIT12 = 543,
	SFX_STEWARDESS_HIT13 = 544,
	SFX_FEM_SWAT_HIT01 = 545,
	SFX_FEM_SWAT_HIT02 = 546,
	SFX_FEM_SWAT_HIT03 = 547,
	SFX_FEM_SWAT_HIT04 = 548,
	SFX_FEM_SWAT_HIT06 = 549,
	SFX_FEM_SWAT_HIT07 = 550,
	SFX_FEM_SWAT_HIT08 = 551,
	SFX_FEM_SWAT_HIT09 = 552,
	SFX_FEM_SWAT_HIT10 = 553,
	SFX_FEM_SWAT_HIT11 = 554,
	SFX_FEM_SWAT_HIT12 = 555,
	SFX_FEM_SWAT_HIT13 = 556,
	SFX_FEM_SWAT_HIT14 = 557,
	SFX_MUT_PRIEST_HIT01 = 558,
	SFX_MUT_PRIEST_HIT02 = 559,
	SFX_MUT_PRIEST_HIT03 = 560,
	SFX_MUT_PRIEST_HIT04 = 561,
	SFX_MUT_PRIEST_HIT05 = 562,
	SFX_MUT_PRIEST_HIT06 = 563,
	SFX_MUT_PRIEST_HIT07 = 564,
	SFX_MUT_PRIEST_HIT08 = 565,
	SFX_MUT_PRIEST_HIT09 = 566,
	SFX_MUT_PRIEST_HIT10 = 567,
	SFX_MUT_PRIEST_HIT11 = 568,
	SFX_MUT_PRIEST_HIT12 = 569,
	SFX_MUT_PRIEST_HIT13 = 570,
	SFX_MUT_PRIEST_HIT14 = 571,
	SFX_MUT_PRIEST_HIT15 = 572,
	SFX_MUT_PRIEST_HIT16 = 573,
	SFX_CHINE_WAITER_HIT01 = 574,
	SFX_CHINE_WAITER_HIT02 = 575,
	SFX_CHINE_WAITER_HIT03 = 576,
	SFX_CHINE_WAITER_HIT04 = 577,
	SFX_CHINE_WAITER_HIT05 = 578,
	SFX_CHINE_WAITER_HIT06 = 579,
	SFX_CHINE_WAITER_HIT07 = 580,
	SFX_CHINE_WAITER_HIT08 = 581,
	SFX_CHINE_WAITER_HIT09 = 582,
	SFX_CHINE_WAITER_HIT10 = 583,
	SFX_CHINE_WAITER_HIT11 = 584,
	SFX_CHINE_WAITER_HIT12 = 585,
	SFX_CHINE_WAITER_HIT13 = 586,
	SFX_CHINE_WAITER_HIT14 = 587,
	SFX_CHINE_WAITER_HIT15 = 588,
	SFX_CHINE_WAITER_HIT16 = 589,
	SFX_ZOMB_JACKET_HIT01 = 590,
	SFX_ZOMB_JACKET_HIT02 = 591,
	SFX_ZOMB_JACKET_HIT03 = 592,
	SFX_ZOMB_JACKET_HIT04 = 593,
	SFX_ZOMB_JACKET_HIT05 = 594,
	SFX_ZOMB_JACKET_HIT06 = 595,
	SFX_ZOMB_JACKET_HIT07 = 596,
	SFX_ZOMB_JACKET_HIT08 = 597,
	SFX_ZOMB_JACKET_HIT09 = 598,
	SFX_ZOMB_JACKET_HIT10 = 599,
	SFX_ZOMB_JACKET_HIT11 = 600,
	SFX_ZOMB_JACKET_HIT12 = 601,
	SFX_ZOMB_JACKET_HIT14 = 602,
	SFX_ZOMB_ROTTEN_HIT01 = 603,
	SFX_ZOMB_ROTTEN_HIT02 = 604,
	SFX_ZOMB_ROTTEN_HIT03 = 605,
	SFX_ZOMB_ROTTEN_HIT04 = 606,
	SFX_ZOMB_ROTTEN_HIT05 = 607,
	SFX_ZOMB_ROTTEN_HIT06 = 608,
	SFX_ZOMB_ROTTEN_HIT07 = 609,
	SFX_ZOMB_ROTTEN_HIT08 = 610,
	SFX_ZOMB_ROTTEN_HIT09 = 611,
	SFX_ZOMB_GENERIC_HIT01 = 612,
	SFX_ZOMB_GENERIC_HIT02 = 613,
	SFX_ZOMB_GENERIC_HIT03 = 614,
	SFX_ZOMB_GENERIC_HIT04 = 615,
	SFX_ZOMB_GENERIC_HIT05 = 616,
	SFX_ZOMB_GENERIC_HIT06 = 617,
	SFX_ZOMB_GENERIC_HIT07 = 618,
	SFX_ZOMB_GENERIC_HIT08 = 619,
	SFX_ZOMB_GENERIC_HIT09 = 620,
	SFX_ZOMB_GENERIC_HIT10 = 621,
	SFX_ZOMB_GENERIC_HIT11 = 622,
	SFX_ZOMB_GENERIC_HIT12 = 623,
	SFX_ZOMB_GENERIC_HIT13 = 624,
	SFX_ZOMB_GENERIC_HIT14 = 625,
	SFX_ZOMB_OLDMAN_HIT01 = 626,
	SFX_ZOMB_OLDMAN_HIT02 = 627,
	SFX_ZOMB_OLDMAN_HIT03 = 628,
	SFX_ZOMB_OLDMAN_HIT04 = 629,
	SFX_ZOMB_OLDMAN_HIT05 = 630,
	SFX_ZOMB_OLDMAN_HIT06 = 631,
	SFX_ZOMB_OLDMAN_HIT07 = 632,
	SFX_ZOMB_OLDMAN_HIT08 = 633,
	SFX_ZOMB_OLDMAN_HIT09 = 634,
	SFX_ZOMB_OLDMAN_HIT10 = 635,
	SFX_ZOMB_OLDMAN_HIT11 = 636,
	SFX_ZOMB_OLDMAN_HIT12 = 637,
	SFX_ZOMB_OLDMAN_HIT13 = 638,
	SFX_ZOMB_OLDMAN_HIT14 = 639,
	SFX_ZOMB_COP_HIT01 = 640,
	SFX_ZOMB_COP_HIT02 = 641,
	SFX_ZOMB_COP_HIT03 = 642,
	SFX_ZOMB_COP_HIT04 = 643,
	SFX_ZOMB_COP_HIT05 = 644,
	SFX_ZOMB_COP_HIT06 = 645,
	SFX_ZOMB_COP_HIT07 = 646,
	SFX_ZOMB_COP_HIT08 = 647,
	SFX_ZOMB_COP_HIT09 = 648,
	SFX_ZOMB_COP_HIT10 = 649,
	SFX_ZOMB_COP_HIT11 = 650,
	SFX_ZOMB_COP_HIT12 = 651,
	SFX_ZOMB_COP_HIT13 = 652,
	SFX_ZOMB_COP_HIT14 = 653,
	SFX_DUCKMAN_HIT01 = 654,
	SFX_DUCKMAN_HIT02 = 655,
	SFX_DUCKMAN_HIT03 = 656,
	SFX_DUCKMAN_HIT04 = 657,
	SFX_DUCKMAN_HIT05 = 658,
	SFX_DUCKMAN_HIT06 = 659,
	SFX_DUCKMAN_HIT07 = 660,
	SFX_DUCKMAN_HIT08 = 661,
	SFX_DUCKMAN_HIT09 = 662,
	SFX_DUCKMAN_HIT10 = 663,
	SFX_DUCKMAN_HIT11 = 664,
	SFX_DUCKMAN_HIT12 = 665,
	SFX_DUCKMAN_HIT13 = 666,
	SFX_DUCKMAN_HIT14 = 667,
	SFX_DUCKMAN_HIT15 = 668,
	SFX_DUCKMAN_HIT16 = 669,
	SFX_DUCKMAN_HIT17 = 670,
	SFX_COP_M_HIT01 = 671,
	SFX_COP_M_HIT02 = 672,
	SFX_COP_M_HIT03 = 673,
	SFX_COP_M_HIT04 = 674,
	SFX_COP_M_HIT05 = 675,
	SFX_COP_M_HIT06 = 676,
	SFX_COP_M_HIT07 = 677,
	SFX_COP_M_HIT08 = 678,
	SFX_COP_M_HIT09 = 679,
	SFX_COP_M_HIT10 = 680,
	SFX_COP_M_HIT11 = 681,
	SFX_COP_M_HIT12 = 682,
	SFX_COP_M_HIT13 = 683,
	SFX_COP_M_HIT14 = 684,
	SFX_COP_M_HIT15 = 685,
	SFX_COP_M_HIT16 = 686,
	SFX_COP_M_HIT17 = 687,
	SFX_BONUSBOY_HIT01 = 688,
	SFX_BONUSBOY_HIT02 = 689,
	SFX_BONUSBOY_HIT03 = 690,
	SFX_BONUSBOY_HIT04 = 691,
	SFX_BONUSBOY_HIT05 = 692,
	SFX_BONUSBOY_HIT06 = 693,
	SFX_BONUSBOY_HIT07 = 694,
	SFX_BONUSBOY_HIT08 = 695,
	SFX_BONUSBOY_HIT09 = 696,
	SFX_BONUSBOY_HIT10 = 697,
	SFX_BONUSBOY_HIT11 = 698,
	SFX_BONUSBOY_HIT12 = 699,
	SFX_BONUSBOY_HIT13 = 700,
	SFX_BONUSBOY_HIT14 = 701,
	SFX_CYB_TUX_HIT01 = 702,
	SFX_CYB_TUX_HIT02 = 703,
	SFX_CYB_TUX_HIT03 = 704,
	SFX_CYB_TUX_HIT04 = 705,
	SFX_CYB_TUX_HIT05 = 706,
	SFX_CYB_TUX_HIT06 = 707,
	SFX_CYB_TUX_HIT07 = 708,
	SFX_CYB_TUX_HIT08 = 709,
	SFX_CYB_TUX_HIT09 = 710,
	SFX_CYB_TUX_HIT10 = 711,
	SFX_CYB_TUX_HIT11 = 712,
	SFX_CYB_TUX_HIT12 = 713,
	SFX_CYB_TUX_HIT13 = 714,
	SFX_CYB_TUX_HIT14 = 715,
	SFX_MUT_INSECT_HIT01 = 716,
	SFX_MUT_INSECT_HIT02 = 717,
	SFX_MUT_INSECT_HIT03 = 718,
	SFX_MUT_INSECT_HIT04 = 719,
	SFX_MUT_INSECT_HIT05 = 720,
	SFX_MUT_INSECT_HIT06 = 721,
	SFX_MUT_INSECT_HIT07 = 722,
	SFX_MUT_INSECT_HIT08 = 723,
	SFX_MUT_INSECT_HIT09 = 724,
	SFX_MUT_INSECT_HIT10 = 725,
	SFX_MUT_INSECT_HIT11 = 726,
	SFX_MUT_INSECT_HIT12 = 727,
	SFX_GRETEL_HIT01 = 728,
	SFX_GRETEL_HIT02 = 729,
	SFX_GRETEL_HIT03 = 730,
	SFX_GRETEL_HIT04 = 731,
	SFX_GRETEL_HIT05 = 732,
	SFX_GRETEL_HIT06 = 733,
	SFX_GRETEL_HIT07 = 734,
	SFX_GRETEL_HIT08 = 735,
	SFX_GRETEL_HIT09 = 736,
	SFX_GRETEL_HIT10 = 737,
	SFX_GRETEL_HIT11 = 738,
	SFX_MUMMY_HIT01 = 739,
	SFX_MUMMY_HIT02 = 740,
	SFX_MUMMY_HIT03 = 741,
	SFX_MUMMY_HIT04 = 742,
	SFX_MUMMY_HIT05 = 743,
	SFX_MUMMY_HIT06 = 744,
	SFX_MUMMY_HIT07 = 745,
	SFX_MUMMY_HIT08 = 746,
	SFX_MUMMY_HIT09 = 747,
	SFX_MUMMY_HIT10 = 748,
	SFX_MUMMY_HIT11 = 749,
	SFX_MUMMY_HIT12 = 750,
	SFX_MUMMY_HIT13 = 751,
	SFX_MUMMY_ROAM01 = 752,
	SFX_MUMMY_ROAM02 = 753,
	SFX_RAVELLE_F_HIT01 = 754,
	SFX_RAVELLE_F_HIT02 = 755,
	SFX_RAVELLE_F_HIT03 = 756,
	SFX_RAVELLE_F_HIT04 = 757,
	SFX_RAVELLE_F_HIT05 = 758,
	SFX_RAVELLE_F_HIT06 = 759,
	SFX_RAVELLE_F_HIT07 = 760,
	SFX_RAVELLE_F_HIT08 = 761,
	SFX_RAVELLE_F_HIT09 = 762,
	SFX_RAVELLE_F_HIT10 = 763,
	SFX_RAVELLE_F_HIT11 = 764,
	SFX_RAVELLE_F_HIT12 = 765,
	SFX_RAVELLE_F_HIT13 = 766,
	SFX_RAVELLE_F_HIT14 = 767,
	SFX_ZOMBIEGIRL_HIT01 = 768,
	SFX_ZOMBIEGIRL_HIT02 = 769,
	SFX_ZOMBIEGIRL_HIT03 = 770,
	SFX_ZOMBIEGIRL_HIT04 = 771,
	SFX_ZOMBIEGIRL_HIT05 = 772,
	SFX_ZOMBIEGIRL_HIT06 = 773,
	SFX_ZOMBIEGIRL_HIT07 = 774,
	SFX_ZOMBIEGIRL_HIT08 = 775,
	SFX_ZOMBIEGIRL_HIT09 = 776,
	SFX_ZOMBIEGIRL_HIT10 = 777,
	SFX_ZOMBIEGIRL_ROAM01 = 778,
	SFX_CHEERLEADER_HIT01 = 779,
	SFX_CHEERLEADER_HIT02 = 780,
	SFX_CHEERLEADER_HIT03 = 781,
	SFX_CHEERLEADER_HIT04 = 782,
	SFX_CHEERLEADER_HIT05 = 783,
	SFX_CHEERLEADER_HIT06 = 784,
	SFX_CHEERLEADER_HIT07 = 785,
	SFX_CHEERLEADER_HIT08 = 786,
	SFX_CHEERLEADER_HIT09 = 787,
	SFX_CHEERLEADER_HIT10 = 788,
	SFX_CYB_SIAMESE_HIT01 = 789,
	SFX_CYB_SIAMESE_HIT02 = 790,
	SFX_CYB_SIAMESE_HIT03 = 791,
	SFX_CYB_SIAMESE_HIT04 = 792,
	SFX_CYB_SIAMESE_HIT05 = 793,
	SFX_CYB_SIAMESE_HIT06 = 794,
	SFX_CYB_SIAMESE_HIT07 = 795,
	SFX_CYB_SIAMESE_HIT08 = 796,
	SFX_CYB_SIAMESE_HIT09 = 797,
	SFX_CYB_SIAMESE_HIT10 = 798,
	SFX_CYB_SIAMESE_HIT11 = 799,
	SFX_CYB_SIAMESE_HIT12 = 800,
	SFX_CYB_SIAMESE_HIT13 = 801,
	SFX_CYB_SIAMESE_HIT14 = 802,
	SFX_RED_ALIEN_HIT01 = 803,
	SFX_RED_ALIEN_HIT02 = 804,
	SFX_RED_ALIEN_HIT03 = 805,
	SFX_RED_ALIEN_HIT04 = 806,
	SFX_RED_ALIEN_HIT05 = 807,
	SFX_RED_ALIEN_HIT06 = 808,
	SFX_RED_ALIEN_HIT07 = 809,
	SFX_RED_ALIEN_HIT08 = 810,
	SFX_RED_ALIEN_HIT09 = 811,
	SFX_RED_ALIEN_HIT10 = 812,
	SFX_RED_ALIEN_HIT11 = 813,
	SFX_RED_ALIEN_HIT12 = 814,
	SFX_GINGERBREAD_HIT01 = 815,
	SFX_GINGERBREAD_HIT02 = 816,
	SFX_GINGERBREAD_HIT03 = 817,
	SFX_GINGERBREAD_HIT04 = 818,
	SFX_GINGERBREAD_HIT05 = 819,
	SFX_GINGERBREAD_HIT06 = 820,
	SFX_GINGERBREAD_HIT07 = 821,
	SFX_GINGERBREAD_HIT08 = 822,
	SFX_GINGERBREAD_HIT09 = 823,
	SFX_GINGERBREAD_HIT10 = 824,
	SFX_GINGERBREAD_HIT11 = 825,
	SFX_GINGERBREAD_HIT12 = 826,
	SFX_GINGERBREAD_HIT13 = 827,
	SFX_GINGERBREAD_DIE01 = 828,
	SFX_GINGERBREAD_DIE02 = 829,
	SFX_GINGERBREAD_DIE03 = 830,
	SFX_GINGERBREAD_DIE04 = 831,
	SFX_GINGERBREAD_FLINCH = 832,
	SFX_PEEKABOO_HIT01 = 833,
	SFX_PEEKABOO_HIT02 = 834,
	SFX_PEEKABOO_HIT03 = 835,
	SFX_PEEKABOO_HIT04 = 836,
	SFX_PEEKABOO_HIT05 = 837,
	SFX_PEEKABOO_HIT06 = 838,
	SFX_PEEKABOO_HIT07 = 839,
	SFX_PEEKABOO_HIT08 = 840,
	SFX_PEEKABOO_HIT09 = 841,
	SFX_PEEKABOO_HIT10 = 842,
	SFX_PEEKABOO_HIT11 = 843,
	SFX_PEEKABOO_DIE02 = 844,
	SFX_PEEKABOO_DIE04 = 845,
	SFX_OLGA_HIT01 = 846,
	SFX_OLGA_HIT02 = 847,
	SFX_OLGA_HIT03 = 848,
	SFX_OLGA_HIT04 = 849,
	SFX_OLGA_HIT05 = 850,
	SFX_OLGA_HIT06 = 851,
	SFX_OLGA_HIT07 = 852,
	SFX_OLGA_HIT08 = 853,
	SFX_OLGA_HIT09 = 854,
	SFX_OLGA_HIT10 = 855,
	SFX_OLGA_HIT11 = 856,
	SFX_OLGA_HIT12 = 857,
	SFX_OLGA_HIT13 = 858,
	SFX_OLGA_HIT14 = 859,
	SFX_OLGA_FLINCH = 860,
	SFX_OLGA_DIE01 = 861,
	SFX_OLGA_DIE02 = 862,
	SFX_OLGA_DIE03 = 863,
	SFX_OLGA_DIE04 = 864,
	SFX_M_SWAT_HIT01 = 865,
	SFX_M_SWAT_HIT02 = 866,
	SFX_M_SWAT_HIT03 = 867,
	SFX_M_SWAT_HIT04 = 868,
	SFX_M_SWAT_HIT05 = 869,
	SFX_M_SWAT_HIT06 = 870,
	SFX_M_SWAT_HIT07 = 871,
	SFX_M_SWAT_HIT08 = 872,
	SFX_M_SWAT_HIT09 = 873,
	SFX_M_SWAT_HIT10 = 874,
	SFX_M_SWAT_HIT11 = 875,
	SFX_M_SWAT_HIT12 = 876,
	SFX_M_SWAT_HIT13 = 877,
	SFX_M_SWAT_FLINCH = 878,
	SFX_M_SWAT_DIE01 = 879,
	SFX_M_SWAT_DIE02 = 880,
	SFX_M_SWAT_DIE03 = 881,
	SFX_M_SWAT_DIE04 = 882,
	SFX_M_SWATMASK_HIT01 = 883,
	SFX_M_SWATMASK_HIT02 = 884,
	SFX_M_SWATMASK_HIT03 = 885,
	SFX_M_SWATMASK_HIT04 = 886,
	SFX_M_SWATMASK_HIT05 = 887,
	SFX_M_SWATMASK_HIT06 = 888,
	SFX_M_SWATMASK_HIT07 = 889,
	SFX_M_SWATMASK_HIT08 = 890,
	SFX_M_SWATMASK_FLINCH = 891,
	SFX_M_SWATMASK_DIE01 = 892,
	SFX_M_SWATMASK_DIE02 = 893,
	SFX_M_SWATMASK_DIE03 = 894,
	SFX_M_SWATMASK_DIE04 = 895,
	SFX_M_SUITHOOD_HIT01 = 896,
	SFX_M_SUITHOOD_HIT02 = 897,
	SFX_M_SUITHOOD_HIT03 = 898,
	SFX_M_SUITHOOD_HIT04 = 899,
	SFX_M_SUITHOOD_HIT05 = 900,
	SFX_M_SUITHOOD_HIT06 = 901,
	SFX_M_SUITHOOD_HIT07 = 902,
	SFX_M_SUITHOOD_HIT08 = 903,
	SFX_M_SUITHOOD_HIT09 = 904,
	SFX_M_SUITHOOD_HIT10 = 905,
	SFX_M_SUITHOOD_HIT11 = 906,
	SFX_M_SUITHOOD_HIT12 = 907,
	SFX_M_SUITHOOD_FLINCH = 908,
	SFX_M_SUITHOOD_DIE01 = 909,
	SFX_M_SUITHOOD_DIE02 = 910,
	SFX_M_SUITHOOD_DIE03 = 911,
	SFX_M_SUITHOOD_DIE04 = 912,
	SFX_F_CYBORG_HIT01 = 913,
	SFX_F_CYBORG_HIT02 = 914,
	SFX_F_CYBORG_HIT03 = 915,
	SFX_F_CYBORG_HIT04 = 916,
	SFX_F_CYBORG_HIT05 = 917,
	SFX_F_CYBORG_HIT06 = 918,
	SFX_F_CYBORG_HIT07 = 919,
	SFX_F_CYBORG_HIT08 = 920,
	SFX_F_CYBORG_HIT09 = 921,
	SFX_F_CYBORG_HIT10 = 922,
	SFX_F_CYBORG_HIT11 = 923,
	SFX_F_CYBORG_HIT12 = 924,
	SFX_F_CYBORG_HIT13 = 925,
	SFX_F_CYBORG_FLINCH = 926,
	SFX_F_CYBORG_DIE01 = 927,
	SFX_F_CYBORG_DIE02 = 928,
	SFX_F_CYBORG_DIE03 = 929,
	SFX_F_CYBORG_DIE04 = 930,
	SFX_M_CULTIST_HIT01 = 931,
	SFX_M_CULTIST_HIT02 = 932,
	SFX_M_CULTIST_HIT03 = 933,
	SFX_M_CULTIST_HIT04 = 934,
	SFX_M_CULTIST_HIT05 = 935,
	SFX_M_CULTIST_HIT06 = 936,
	SFX_M_CULTIST_HIT07 = 937,
	SFX_M_CULTIST_HIT08 = 938,
	SFX_M_CULTIST_HIT09 = 939,
	SFX_M_CULTIST_FLINCH = 940,
	SFX_M_CULTIST_DIE01 = 941,
	SFX_M_CULTIST_DIE02 = 942,
	SFX_M_CULTIST_DIE03 = 943,
	SFX_M_CULTIST_DIE04 = 944,
	SFX_F_PRIESTESS_HIT01 = 945,
	SFX_F_PRIESTESS_HIT02 = 946,
	SFX_F_PRIESTESS_HIT03 = 947,
	SFX_F_PRIESTESS_HIT04 = 948,
	SFX_F_PRIESTESS_HIT05 = 949,
	SFX_F_PRIESTESS_HIT06 = 950,
	SFX_F_PRIESTESS_HIT07 = 951,
	SFX_F_PRIESTESS_HIT08 = 952,
	SFX_F_PRIESTESS_HIT09 = 953,
	SFX_F_PRIESTESS_FLINCH = 954,
	SFX_F_PRIESTESS_DIE01 = 955,
	SFX_F_PRIESTESS_DIE02 = 956,
	SFX_F_PRIESTESS_DIE03 = 957,
	SFX_F_PRIESTESS_DIE04 = 958,
	SFX_F_ALIEN_HIT01 = 959,
	SFX_F_ALIEN_HIT02 = 960,
	SFX_F_ALIEN_HIT03 = 961,
	SFX_F_ALIEN_HIT04 = 962,
	SFX_F_ALIEN_HIT05 = 963,
	SFX_F_ALIEN_HIT06 = 964,
	SFX_F_ALIEN_HIT07 = 965,
	SFX_F_ALIEN_HIT08 = 966,
	SFX_F_ALIEN_HIT09 = 967,
	SFX_F_ALIEN_HIT10 = 968,
	SFX_F_ALIEN_FLINCH = 969,
	SFX_F_ALIEN_DIE01 = 970,
	SFX_F_ALIEN_DIE02 = 971,
	SFX_F_ALIEN_DIE03 = 972,
	SFX_F_ALIEN_DIE04 = 973,
	SFX_M_ROBOT_HIT01 = 974,
	SFX_M_ROBOT_HIT02 = 975,
	SFX_M_ROBOT_HIT03 = 976,
	SFX_M_ROBOT_HIT04 = 977,
	SFX_M_ROBOT_HIT05 = 978,
	SFX_M_ROBOT_HIT06 = 979,
	SFX_M_ROBOT_HIT07 = 980,
	SFX_M_ROBOT_HIT08 = 981,
	SFX_M_ROBOT_HIT09 = 982,
	SFX_M_ROBOT_HIT10 = 983,
	SFX_M_ROBOT_HIT12 = 984,
	SFX_M_ROBOT_FLINCH = 985,
	SFX_M_ROBOT_DIE01 = 986,
	SFX_M_ROBOT_DIE02 = 987,
	SFX_M_ROBOT_DIE03 = 988,
	SFX_M_ROBOT_DIE04 = 989,
	SFX_M_CLEANER_HIT01 = 990,
	SFX_M_CLEANER_HIT02 = 991,
	SFX_M_CLEANER_HIT03 = 992,
	SFX_M_CLEANER_HIT04 = 993,
	SFX_M_CLEANER_HIT05 = 994,
	SFX_M_CLEANER_HIT06 = 995,
	SFX_M_CLEANER_HIT07 = 996,
	SFX_M_CLEANER_HIT08 = 997,
	SFX_M_CLEANER_HIT09 = 998,
	SFX_M_CLEANER_HIT10 = 999,
	SFX_M_CLEANER_HIT11 = 1000,
	SFX_M_CLEANER_FLINCH = 1001,
	SFX_M_CLEANER_DIE01 = 1002,
	SFX_M_CLEANER_DIE02 = 1003,
	SFX_M_CLEANER_DIE03 = 1004,
	SFX_M_CLEANER_DIE04 = 1005,
	SFX_M_COOK_HIT01 = 1006,
	SFX_M_COOK_HIT02 = 1007,
	SFX_M_COOK_HIT03 = 1008,
	SFX_M_COOK_HIT04 = 1009,
	SFX_M_COOK_HIT05 = 1010,
	SFX_M_COOK_HIT06 = 1011,
	SFX_M_COOK_HIT07 = 1012,
	SFX_M_COOK_HIT08 = 1013,
	SFX_M_COOK_HIT09 = 1014,
	SFX_M_COOK_HIT10 = 1015,
	SFX_M_COOK_FLINCH = 1016,
	SFX_M_COOK_DIE02 = 1017,
	SFX_M_COOK_DIE03 = 1018,
	SFX_M_COOK_DIE04 = 1019,
	SFX_ROBOFISH_HIT01 = 1020,
	SFX_ROBOFISH_HIT02 = 1021,
	SFX_ROBOFISH_HIT03 = 1022,
	SFX_ROBOFISH_HIT05 = 1023,
	SFX_ROBOFISH_HIT06 = 1024,
	SFX_ROBOFISH_HIT07 = 1025,
	SFX_ROBOFISH_HIT08 = 1026,
	SFX_ROBOFISH_HIT09 = 1027,
	SFX_ROBOFISH_HIT11 = 1028,
	SFX_ROBOFISH_HIT12 = 1029,
	SFX_ROBOFISH_HIT13 = 1030,
	SFX_ROBOFISH_HIT14 = 1031,
	SFX_ROBOFISH_HIT15 = 1032,
	SFX_ROBOFISH_FLINCH = 1033,
	SFX_ROBOFISH_DIE01 = 1034,
	SFX_ROBOFISH_DIE02 = 1035,
	SFX_ROBOFISH_DIE03 = 1036,
	SFX_ROBOFISH_DIE04 = 1037,
	SFX_FLOATY_HIT01 = 1038,
	SFX_FLOATY_HIT02 = 1039,
	SFX_FLOATY_HIT03 = 1040,
	SFX_FLOATY_HIT04 = 1041,
	SFX_FLOATY_HIT05 = 1042,
	SFX_FLOATY_HIT06 = 1043,
	SFX_FLOATY_HIT07 = 1044,
	SFX_FLOATY_HIT08 = 1045,
	SFX_FLOATY_HIT09 = 1046,
	SFX_FLOATY_FLINCH = 1047,
	SFX_FLOATY_DIE01 = 1048,
	SFX_FLOATY_DIE02 = 1049,
	SFX_FLOATY_DIE03 = 1050,
	SFX_FLOATY_DIE04 = 1051,
	SFX_GREENIE_HIT01 = 1052,
	SFX_GREENIE_HIT02 = 1053,
	SFX_GREENIE_HIT03 = 1054,
	SFX_GREENIE_HIT04 = 1055,
	SFX_GREENIE_HIT05 = 1056,
	SFX_GREENIE_HIT06 = 1057,
	SFX_GREENIE_HIT07 = 1058,
	SFX_GREENIE_HIT08 = 1059,
	SFX_GREENIE_HIT09 = 1060,
	SFX_GREENIE_FLINCH = 1061,
	SFX_GREENIE_DIE01 = 1062,
	SFX_GREENIE_DIE02 = 1063,
	SFX_GREENIE_DIE03 = 1064,
	SFX_GREENIE_DIE04 = 1065,
	SFX_BUNNY_HIT01 = 1066,
	SFX_BUNNY_HIT02 = 1067,
	SFX_BUNNY_HIT03 = 1068,
	SFX_BUNNY_HIT04 = 1069,
	SFX_BUNNY_HIT05 = 1070,
	SFX_BUNNY_HIT06 = 1071,
	SFX_BUNNY_HIT07 = 1072,
	SFX_BUNNY_HIT08 = 1073,
	SFX_BUNNY_HIT09 = 1074,
	SFX_BUNNY_FLINCH = 1075,
	SFX_BUNNY_DIE01 = 1076,
	SFX_BUNNY_DIE02 = 1077,
	SFX_BUNNY_DIE03 = 1078,
	SFX_BUNNY_DIE04 = 1079,
	SFX_TIMESPLITTER_HIT01 = 1080,
	SFX_TIMESPLITTER_HIT02 = 1081,
	SFX_TIMESPLITTER_HIT03 = 1082,
	SFX_TIMESPLITTER_HIT04 = 1083,
	SFX_TIMESPLITTER_HIT05 = 1084,
	SFX_TIMESPLITTER_HIT06 = 1085,
	SFX_TIMESPLITTER_HIT07 = 1086,
	SFX_TIMESPLITTER_HIT08 = 1087,
	SFX_TIMESPLITTER_HIT09 = 1088,
	SFX_TIMESPLITTER_FLINCH = 1089,
	SFX_TIMESPLITTER_DIE01 = 1090,
	SFX_TIMESPLITTER_DIE02 = 1091,
	SFX_TIMESPLITTER_DIE03 = 1092,
	SFX_TIMESPLITTER_DIE04 = 1093,
	SFX_MALE_SMARINE_HIT01 = 1094,
	SFX_MALE_SMARINE_HIT02 = 1095,
	SFX_MALE_SMARINE_HIT03 = 1096,
	SFX_MALE_SMARINE_HIT04 = 1097,
	SFX_MALE_SMARINE_HIT05 = 1098,
	SFX_MALE_SMARINE_HIT06 = 1099,
	SFX_MALE_SMARINE_HIT07 = 1100,
	SFX_MALE_SMARINE_HIT08 = 1101,
	SFX_MALE_SMARINE_HIT09 = 1102,
	SFX_MALE_SMARINE_HIT10 = 1103,
	SFX_MALE_SMARINE_FLINCH = 1104,
	SFX_MALE_SMARINE_DIE01 = 1105,
	SFX_MALE_SMARINE_DIE02 = 1106,
	SFX_MALE_SMARINE_DIE03 = 1107,
	SFX_MALE_SMARINE_DIE04 = 1108,
	SFX_FEMALE_COP_HIT01 = 1109,
	SFX_FEMALE_COP_HIT02 = 1110,
	SFX_FEMALE_COP_HIT03 = 1111,
	SFX_FEMALE_COP_HIT04 = 1112,
	SFX_FEMALE_COP_HIT05 = 1113,
	SFX_FEMALE_COP_HIT06 = 1114,
	SFX_FEMALE_COP_HIT07 = 1115,
	SFX_FEMALE_COP_HIT08 = 1116,
	SFX_FEMALE_COP_HIT09 = 1117,
	SFX_FEMALE_COP_HIT10 = 1118,
	SFX_FEMALE_COP_FLINCH = 1119,
	SFX_FEMALE_COP_DIE01 = 1120,
	SFX_FEMALE_COP_DIE02 = 1121,
	SFX_FEMALE_COP_DIE03 = 1122,
	SFX_FEMALE_COP_DIE04 = 1123,
	SFX_FEMALE_COP_DIE05 = 1124,
	SFX_FEMALE_COP_DIE06 = 1125,
	SFX_PILLAR_ALIEN_HIT01 = 1126,
	SFX_PILLAR_ALIEN_HIT02 = 1127,
	SFX_PILLAR_ALIEN_HIT03 = 1128,
	SFX_PILLAR_ALIEN_HIT04 = 1129,
	SFX_PILLAR_ALIEN_HIT05 = 1130,
	SFX_PILLAR_ALIEN_HIT06 = 1131,
	SFX_PILLAR_ALIEN_FLINCH = 1132,
	SFX_PILLAR_ALIEN_DIE01 = 1133,
	SFX_PILLAR_ALIEN_DIE02 = 1134,
	SFX_PILLAR_ALIEN_DIE03 = 1135,
	SFX_PILLAR_ALIEN_DIE04 = 1136,
	SFX_PILLAR_ALIEN_DIE05 = 1137,
	SFX_PILLAR_ALIEN_DIE06 = 1138,
	SFX_M_GASMASK1_HIT01 = 1139,
	SFX_M_GASMASK1_HIT02 = 1140,
	SFX_M_GASMASK1_HIT03 = 1141,
	SFX_M_GASMASK1_HIT04 = 1142,
	SFX_M_GASMASK1_HIT05 = 1143,
	SFX_M_GASMASK1_HIT06 = 1144,
	SFX_M_GASMASK1_HIT07 = 1145,
	SFX_M_GASMASK1_HIT08 = 1146,
	SFX_M_GASMASK1_FLINCH = 1147,
	SFX_M_GASMASK1_DIE01 = 1148,
	SFX_M_GASMASK1_DIE02 = 1149,
	SFX_M_GASMASK1_DIE03 = 1150,
	SFX_M_GASMASK1_DIE04 = 1151,
	SFX_M_GASMASK1_DIE05 = 1152,
	SFX_M_GASMASK1_DIE06 = 1153,
	SFX_F_SOLDIER_HIT01 = 1154,
	SFX_F_SOLDIER_HIT02 = 1155,
	SFX_F_SOLDIER_HIT03 = 1156,
	SFX_F_SOLDIER_HIT04 = 1157,
	SFX_F_SOLDIER_HIT05 = 1158,
	SFX_F_SOLDIER_HIT06 = 1159,
	SFX_F_SOLDIER_HIT07 = 1160,
	SFX_F_SOLDIER_DIE01 = 1161,
	SFX_F_SOLDIER_DIE02 = 1162,
	SFX_F_SOLDIER_DIE03 = 1163,
	SFX_F_SOLDIER_DIE04 = 1164,
	SFX_F_SOLDIER_DIE05 = 1165,
	SFX_F_SOLDIER_DIE06 = 1166,
	SFX_M_GASMASK2_HIT01 = 1167,
	SFX_M_GASMASK2_HIT02 = 1168,
	SFX_M_GASMASK2_HIT03 = 1169,
	SFX_M_GASMASK2_HIT04 = 1170,
	SFX_M_GASMASK2_HIT05 = 1171,
	SFX_M_GASMASK2_HIT06 = 1172,
	SFX_M_GASMASK2_HIT07 = 1173,
	SFX_M_GASMASK2_HIT08 = 1174,
	SFX_M_GASMASK2_DIE01 = 1175,
	SFX_M_GASMASK2_DIE02 = 1176,
	SFX_M_GASMASK2_DIE03 = 1177,
	SFX_M_GASMASK2_DIE04 = 1178,
	SFX_M_GASMASK2_DIE05 = 1179,
	SFX_M_GASMASK2_DIE06 = 1180,
	SFX_B_MONKEY_HIT01 = 1181,
	SFX_B_MONKEY_HIT02 = 1182,
	SFX_B_MONKEY_HIT03 = 1183,
	SFX_B_MONKEY_HIT04 = 1184,
	SFX_B_MONKEY_HIT05 = 1185,
	SFX_B_MONKEY_HIT06 = 1186,
	SFX_B_MONKEY_HIT07 = 1187,
	SFX_B_MONKEY_HIT08 = 1188,
	SFX_B_MONKEY_HIT09 = 1189,
	SFX_B_MONKEY_DIE01 = 1190,
	SFX_B_MONKEY_DIE02 = 1191,
	SFX_B_MONKEY_DIE03 = 1192,
	SFX_B_MONKEY_DIE04 = 1193,
	SFX_B_MONKEY_DIE05 = 1194,
	SFX_B_MONKEY_DIE06 = 1195,
	SFX_F_SKINNY_HOOER_HIT01 = 1196,
	SFX_F_SKINNY_HOOER_HIT02 = 1197,
	SFX_F_SKINNY_HOOER_HIT03 = 1198,
	SFX_F_SKINNY_HOOER_HIT04 = 1199,
	SFX_F_SKINNY_HOOER_HIT05 = 1200,
	SFX_F_SKINNY_HOOER_HIT06 = 1201,
	SFX_F_SKINNY_HOOER_DIE01 = 1202,
	SFX_F_SKINNY_HOOER_DIE02 = 1203,
	SFX_F_SKINNY_HOOER_DIE03 = 1204,
	SFX_F_SKINNY_HOOER_DIE04 = 1205,
	SFX_F_SKINNY_HOOER_DIE05 = 1206,
	SFX_F_SKINNY_HOOER_DIE06 = 1207,
	SFX_M_GASMASK_ZOMBIE_HIT01 = 1208,
	SFX_M_GASMASK_ZOMBIE_HIT02 = 1209,
	SFX_M_GASMASK_ZOMBIE_HIT03 = 1210,
	SFX_M_GASMASK_ZOMBIE_HIT05 = 1211,
	SFX_M_GASMASK_ZOMBIE_HIT06 = 1212,
	SFX_M_GASMASK_ZOMBIE_HIT07 = 1213,
	SFX_M_GASMASK_ZOMBIE_HIT08 = 1214,
	SFX_M_GASMASK_ZOMBIE_DIE01 = 1215,
	SFX_M_GASMASK_ZOMBIE_DIE02 = 1216,
	SFX_M_GASMASK_ZOMBIE_DIE03 = 1217,
	SFX_M_GASMASK_ZOMBIE_DIE04 = 1218,
	SFX_M_GASMASK_ZOMBIE_DIE05 = 1219,
	SFX_M_GASMASK_ZOMBIE_DIE06 = 1220,
	SFX_M_SOLDIER_ZOMBIE_HIT01 = 1221,
	SFX_M_SOLDIER_ZOMBIE_HIT02 = 1222,
	SFX_M_SOLDIER_ZOMBIE_HIT03 = 1223,
	SFX_M_SOLDIER_ZOMBIE_HIT04 = 1224,
	SFX_M_SOLDIER_ZOMBIE_HIT05 = 1225,
	SFX_M_SOLDIER_ZOMBIE_HIT06 = 1226,
	SFX_M_SOLDIER_ZOMBIE_HIT07 = 1227,
	SFX_M_SOLDIER_ZOMBIE_DIE01 = 1228,
	SFX_M_SOLDIER_ZOMBIE_DIE02 = 1229,
	SFX_M_SOLDIER_ZOMBIE_DIE03 = 1230,
	SFX_M_SOLDIER_ZOMBIE_DIE04 = 1231,
	SFX_M_SOLDIER_ZOMBIE_DIE05 = 1232,
	SFX_M_SOLDIER_ZOMBIE_DIE06 = 1233,
	SFX_WOOD_GOLEM_HIT01 = 1234,
	SFX_WOOD_GOLEM_HIT02 = 1235,
	SFX_WOOD_GOLEM_HIT03 = 1236,
	SFX_WOOD_GOLEM_HIT04 = 1237,
	SFX_WOOD_GOLEM_HIT05 = 1238,
	SFX_WOOD_GOLEM_HIT06 = 1239,
	SFX_WOOD_GOLEM_DIE01 = 1240,
	SFX_WOOD_GOLEM_DIE02 = 1241,
	SFX_WOOD_GOLEM_DIE03 = 1242,
	SFX_WOOD_GOLEM_DIE04 = 1243,
	SFX_WOOD_GOLEM_DIE05 = 1244,
	SFX_WOOD_GOLEM_DIE06 = 1245,
	SFX_F_JUNGLE_QUEEN_HIT01 = 1246,
	SFX_F_JUNGLE_QUEEN_HIT02 = 1247,
	SFX_F_JUNGLE_QUEEN_HIT03 = 1248,
	SFX_F_JUNGLE_QUEEN_HIT04 = 1249,
	SFX_F_JUNGLE_QUEEN_HIT05 = 1250,
	SFX_F_JUNGLE_QUEEN_HIT06 = 1251,
	SFX_F_JUNGLE_QUEEN_DIE01 = 1252,
	SFX_F_JUNGLE_QUEEN_DIE02 = 1253,
	SFX_F_JUNGLE_QUEEN_DIE03 = 1254,
	SFX_F_JUNGLE_QUEEN_DIE04 = 1255,
	SFX_F_JUNGLE_QUEEN_DIE05 = 1256,
	SFX_F_JUNGLE_QUEEN_DIE06 = 1257,
	SFX_F_WITCH_HIT01 = 1258,
	SFX_F_WITCH_HIT02 = 1259,
	SFX_F_WITCH_HIT03 = 1260,
	SFX_F_WITCH_HIT04 = 1261,
	SFX_F_WITCH_HIT05 = 1262,
	SFX_F_WITCH_HIT06 = 1263,
	SFX_F_WITCH_DIE01 = 1264,
	SFX_F_WITCH_DIE02 = 1265,
	SFX_F_WITCH_DIE03 = 1266,
	SFX_F_WITCH_DIE04 = 1267,
	SFX_F_WITCH_DIE05 = 1268,
	SFX_F_WITCH_DIE06 = 1269,
	SFX_M_CURTAINS_COWBOY_HIT01 = 1270,
	SFX_M_CURTAINS_COWBOY_HIT02 = 1271,
	SFX_M_CURTAINS_COWBOY_HIT03 = 1272,
	SFX_M_CURTAINS_COWBOY_HIT04 = 1273,
	SFX_M_CURTAINS_COWBOY_HIT05 = 1274,
	SFX_M_CURTAINS_COWBOY_HIT06 = 1275,
	SFX_M_CURTAINS_COWBOY_DIE01 = 1276,
	SFX_M_CURTAINS_COWBOY_DIE02 = 1277,
	SFX_M_CURTAINS_COWBOY_DIE03 = 1278,
	SFX_M_CURTAINS_COWBOY_DIE04 = 1279,
	SFX_M_CURTAINS_COWBOY_DIE05 = 1280,
	SFX_M_CURTAINS_COWBOY_DIE06 = 1281,
	SFX_M_EVIL_COWBOY_HIT01 = 1282,
	SFX_M_EVIL_COWBOY_HIT02 = 1283,
	SFX_M_EVIL_COWBOY_HIT03 = 1284,
	SFX_M_EVIL_COWBOY_HIT04 = 1285,
	SFX_M_EVIL_COWBOY_HIT05 = 1286,
	SFX_M_EVIL_COWBOY_HIT06 = 1287,
	SFX_M_EVIL_COWBOY_FLINCH = 1288,
	SFX_M_EVIL_COWBOY_DIE01 = 1289,
	SFX_M_EVIL_COWBOY_DIE02 = 1290,
	SFX_M_EVIL_COWBOY_DIE03 = 1291,
	SFX_M_EVIL_COWBOY_DIE04 = 1292,
	SFX_M_EVIL_COWBOY_DIE05 = 1293,
	SFX_M_EVIL_COWBOY_DIE06 = 1294,
	SFX_F_ISLA_NADIR_HIT01 = 1295,
	SFX_F_ISLA_NADIR_HIT02 = 1296,
	SFX_F_ISLA_NADIR_HIT03 = 1297,
	SFX_F_ISLA_NADIR_HIT04 = 1298,
	SFX_F_ISLA_NADIR_HIT05 = 1299,
	SFX_F_ISLA_NADIR_HIT06 = 1300,
	SFX_F_ISLA_NADIR_HIT07 = 1301,
	SFX_F_ISLA_NADIR_HIT08 = 1302,
	SFX_F_ISLA_NADIR_HIT09 = 1303,
	SFX_F_ISLA_NADIR_HIT10 = 1304,
	SFX_F_ISLA_NADIR_FLINCH = 1305,
	SFX_F_ISLA_NADIR_DIE01 = 1306,
	SFX_F_ISLA_NADIR_DIE02 = 1307,
	SFX_F_ISLA_NADIR_DIE03 = 1308,
	SFX_F_ISLA_NADIR_DIE04 = 1309,
	SFX_F_ISLA_NADIR_DIE05 = 1310,
	SFX_F_ISLA_NADIR_DIE06 = 1311,
	SFX_F_SALOON_HOOER_HIT01 = 1312,
	SFX_F_SALOON_HOOER_HIT02 = 1313,
	SFX_F_SALOON_HOOER_HIT03 = 1314,
	SFX_F_SALOON_HOOER_HIT04 = 1315,
	SFX_F_SALOON_HOOER_HIT05 = 1316,
	SFX_F_SALOON_HOOER_HIT06 = 1317,
	SFX_F_SALOON_HOOER_DIE01 = 1318,
	SFX_F_SALOON_HOOER_DIE02 = 1319,
	SFX_F_SALOON_HOOER_DIE03 = 1320,
	SFX_F_SALOON_HOOER_DIE04 = 1321,
	SFX_F_SALOON_HOOER_DIE05 = 1322,
	SFX_F_SALOON_HOOER_DIE06 = 1323,
	SFX_F_JESTER_HIT01 = 1324,
	SFX_F_JESTER_HIT02 = 1325,
	SFX_F_JESTER_HIT03 = 1326,
	SFX_F_JESTER_HIT04 = 1327,
	SFX_F_JESTER_HIT05 = 1328,
	SFX_F_JESTER_HIT06 = 1329,
	SFX_F_JESTER_DIE01 = 1330,
	SFX_F_JESTER_DIE02 = 1331,
	SFX_F_JESTER_DIE03 = 1332,
	SFX_F_JESTER_DIE04 = 1333,
	SFX_F_JESTER_DIE05 = 1334,
	SFX_M_MINER_HIT01 = 1335,
	SFX_M_MINER_HIT02 = 1336,
	SFX_M_MINER_HIT03 = 1337,
	SFX_M_MINER_HIT04 = 1338,
	SFX_M_MINER_HIT05 = 1339,
	SFX_M_MINER_HIT06 = 1340,
	SFX_M_MINER_HIT07 = 1341,
	SFX_M_MINER_DIE01 = 1342,
	SFX_M_MINER_DIE02 = 1343,
	SFX_M_MINER_DIE03 = 1344,
	SFX_M_MINER_DIE04 = 1345,
	SFX_M_MINER_DIE05 = 1346,
	SFX_M_MINER_DIE06 = 1347,
	SFX_F_SOLDIER_ZOMBIE_HIT01 = 1348,
	SFX_F_SOLDIER_ZOMBIE_HIT02 = 1349,
	SFX_F_SOLDIER_ZOMBIE_HIT03 = 1350,
	SFX_F_SOLDIER_ZOMBIE_DIE01 = 1351,
	SFX_F_SOLDIER_ZOMBIE_DIE02 = 1352,
	SFX_F_SOLDIER_ZOMBIE_DIE03 = 1353,
	SFX_M_SIBERIA_LEAD_HIT01 = 1354,
	SFX_M_SIBERIA_LEAD_HIT02 = 1355,
	SFX_M_SIBERIA_LEAD_HIT03 = 1356,
	SFX_M_SIBERIA_LEAD_HIT04 = 1357,
	SFX_M_SIBERIA_LEAD_HIT05 = 1358,
	SFX_M_SIBERIA_LEAD_HIT06 = 1359,
	SFX_M_SIBERIA_LEAD_DIE01 = 1360,
	SFX_M_SIBERIA_LEAD_DIE02 = 1361,
	SFX_M_SIBERIA_LEAD_DIE03 = 1362,
	SFX_M_SIBERIA_LEAD_DIE04 = 1363,
	SFX_M_SIBERIA_LEAD_DIE05 = 1364,
	SFX_M_SIBERIA_LEAD_DIE06 = 1365,
	SFX_M_TOKYO_LEAD_HIT01 = 1366,
	SFX_M_TOKYO_LEAD_HIT02 = 1367,
	SFX_M_TOKYO_LEAD_HIT03 = 1368,
	SFX_M_TOKYO_LEAD_HIT04 = 1369,
	SFX_M_TOKYO_LEAD_HIT05 = 1370,
	SFX_M_TOKYO_LEAD_HIT06 = 1371,
	SFX_M_TOKYO_LEAD_HIT07 = 1372,
	SFX_M_TOKYO_LEAD_DIE01 = 1373,
	SFX_M_TOKYO_LEAD_DIE02 = 1374,
	SFX_M_TOKYO_LEAD_DIE03 = 1375,
	SFX_M_TOKYO_LEAD_DIE04 = 1376,
	SFX_M_TOKYO_LEAD_DIE05 = 1377,
	SFX_M_TOKYO_LEAD_DIE06 = 1378,
	SFX_REACTION00 = 1379,
	SFX_LASTSOUND = 1380,
	NUM_SOUNDS = 1381
};

typedef enum {
	TUNE_NONE = 0,
	TUNE_GOTHIC_TILE = 1,
	TUNE_INDUSTRIAL_TILE = 2,
	TUNE_VIRTUAL_TILE = 3,
	TUNE_SPACEPORT_TILE = 4,
	TUNE_ALIEN_TILE = 5,
	TUNE_TOKYO_TILE = 6,
	TUNE_TSET_GTR = 7,
	TUNE_FRONTEND = 8,
	TUNE_MAPMAKER = 9,
	TUNE_AZTEC = 10,
	TUNE_FECKED = 11,
	TUNE_TOKYO = 12,
	TUNE_WESTERN = 13,
	TUNE_MISC1 = 14,
	TUNE_NOTREDAME = 15,
	TUNE_TS2TRANCE = 16,
	TUNE_MOBSTERS = 17,
	TUNE_MILITARY = 18,
	TUNE_ATOMSMASH = 19,
	TUNE_MEXICAN = 20,
	TUNE_ROBOT_MAIN = 21,
	TUNE_ROBOT_BOSS = 22,
	TUNE_HOSPITAL = 23,
	TUNE_MARTIAN = 24,
	TUNE_GAMEOVER_LOSE = 25,
	TUNE_SCRAPYARD = 26,
	TUNE_PLANET_X2 = 27,
	TUNE_SIBERIA = 28,
	TUNE_SIBERIA_BOSS = 29,
	TUNE_SIBERIA2 = 30,
	TUNE_CREDITS = 31,
	TUNE_CS_DAM1 = 32,
	TUNE_LOOPTEST = 33,
	TUNE_NUM = 34
};

typedef enum {
	MCARD_RESULT_BUSY = 0,
	MCARD_RESULT_SUCCESS = 1,
	MCARD_RESULT_WRONG_SIZE = 2,
	MCARD_RESULT_FAILED = 3,
	MCARD_RESULT_CARD_REMOVED = 4,
	MCARD_RESULT_NO_FILE = 5,
	MCARD_RESULT_UNFORMATTED = 6,
	MCARD_RESULT_NO_SPACE = 7,
	MCARD_RESULT_CANCELED = 8,
	MCARD_RESULT_EXTRAOPTION = 9,
	MCARD_RESULT_NUM = 10
};

typedef enum {
	MCARD_STATE_UNCHANGED = 0,
	MCARD_STATE_CHANGED_FORMATTED = 1,
	MCARD_STATE_CHANGED_UNFORMATTED = 2,
	MCARD_STATE_NO_CARD = 3
};

typedef enum {
	CHECKCARD_VOID = 0,
	CHECKCARD_CHECK = 1,
	CHECKCARD_NOCARD = 2,
	CHECKCARD_NOTPS2 = 3,
	CHECKCARD_FORMATTED = 4,
	CHECKCARD_UNFORMATTED = 5
};

typedef enum {
	GAMEDIR_1 = 0,
	GAMEDIR_2 = 1
};

typedef enum {
	MCSEQ_STATE_BUSY = -1,
	MCSEQ_STATE_MESSAGE = 0,
	MCSEQ_STATE_MESSAGE_BUT1 = 1,
	MCSEQ_STATE_MESSAGE_BUT2 = 2,
	MCSEQ_STATE_MESSAGE_BUT3 = 3,
	MCSEQ_STATE_MESSAGE_BUT4 = 4,
	MCSEQ_STATE_UNCHANGED = 5,
	MCSEQ_STATE_CHANGED_FORMATTED = 6,
	MCSEQ_STATE_CHANGED_UNFORMATTED = 7,
	MCSEQ_STATE_NO_CARD = 8,
	MCSEQ_STATE_USER = 9
};

typedef enum {
	MCMSG_NOCARD = 0,
	MCMSG_NOCARDINSLOT = 1,
	MCMSG_UNFORMATTED = 2,
	MCMSG_LOADFAILED = 3,
	MCMSG_LOADCOMPLETED = 4,
	MCMSG_SAVEFAILED = 5,
	MCMSG_SAVEFAILEDOKBACK = 6,
	MCMSG_SAVECOMPLETED = 7,
	MCMSG_DELETEFAILED = 8,
	MCMSG_DELETECOMPLETED = 9,
	MCMSG_GAMEFILE1CORRUPT = 10,
	MCMSG_NOSPACEGAMEFILE1 = 11,
	MCMSG_NOSPACEGAMEFILE2 = 12,
	MCMSG_NUM = 13
};

typedef enum {
	LETTER_FLAT = 0,
	LETTER_TTOP = 1,
	LETTER_TBOT = 2,
	LETTER_TMID = 3,
	LETTER_T = 4,
	LETTER_SMAL = 5,
	LETTER_STOP = 6,
	LETTER_SBOT = 7,
	LETTER_SMID = 8,
	LETTER_LITJ = 9,
	LETTER_SLOW = 10,
	NUM_LETTER_SHAPES = 11
};

typedef enum {
	FONTSEL_FUTURE = 0,
	FONTSEL_CAPS = 1,
	FONTSEL_BOOK = 2,
	FONTSEL_BOOKLIGHT = 3,
	FONTSEL_NUM = 4
};

typedef enum {
	FONT_FUTURE_SMALL = 0,
	FONT_FUTURE_NARROW = 1,
	FONT_FUTURE_SUBNORMAL = 2,
	FONT_FUTURE_NORMAL = 3,
	FONT_FUTURE_SEMI = 4,
	FONT_FUTURE_MEDIUM = 5,
	FONT_FUTURE_MEDBIG = 6,
	FONT_FUTURE_BIG = 7,
	FONT_BOOK_TINY = 8,
	FONT_BOOK_SMALL = 9,
	FONT_BOOK_NORMAL = 10,
	FONT_BOOK_BIG = 11,
	FONT_NUM = 12
};

typedef enum {
	btn_circle = 0,
	btn_cross = 1,
	btn_triangle = 2,
	btn_square = 3,
	btn_select = 4,
	btn_start = 5,
	numbuttons = 6
} e_button;

typedef enum {
	dpad_up = 0,
	dpad_down = 1,
	dpad_left = 2,
	dpad_right = 3
} dpad_button;

typedef enum {
	MISCTEX_NONE = -1,
	MISCTEX_CIRCLE = 0,
	MISCTEX_PAGEBAR = 1,
	MISCTEX_STDBUTTON_CIRCLE = 2,
	MISCTEX_STDBUTTON_CROSS = 3,
	MISCTEX_STDBUTTON_TRIANGLE = 4,
	MISCTEX_STDBUTTON_SQUARE = 5,
	MISCTEX_STDBUTTON_SELECT = 6,
	MISCTEX_BUTTONS = 7,
	MISCTEX_DPAD = 8,
	MISCTEX_CONTROLLER = 9,
	MISCTEX_CONTROLLERGLOW = 10,
	MISCTEX_CROSSHAIR_CIRCLE = 11,
	MISCTEX_CROSSHAIR_ARROW = 12,
	MISCTEX_CROSSHAIR_TRIANGLE = 13,
	MISCTEX_SCOPEEDGE = 14,
	MISCTEX_HUDBACK = 15,
	MISCTEX_RADAR = 16,
	MISCTEX_RADARBAR = 17,
	MISCTEX_RADARSPOT = 18,
	MISCTEX_HUDPAIN = 19,
	MISCTEX_KEYCARD = 20,
	MISCTEX_AMOUNTBAR = 21,
	MISCTEX_TS2LOGO = 22,
	MISCTEX_EIDOSLOGO = 23,
	MISCTEX_FRDLOGO = 24,
	MISCTEX_IGMTEX = 25,
	MISCTEX_OPTIONBAR = 26,
	MISCTEX_ARCOUTLINE = 27,
	MISCTEX_ARCGLOW = 28,
	MISCTEX_ARCBAR = 29,
	MISCTEX_ARCBACK = 30,
	MISCTEX_FADECIRCLE = 31,
	MISCTEX_NUM = 32
};

typedef enum {
	STAT_KILLS = 0,
	STAT_KILLED = 1,
	STAT_SUICIDES = 2,
	STAT_KILLSOTHERS = 3,
	STAT_KILLEDOTHERS = 4,
	STAT_SUCCESIVEKILLS = 5,
	STAT_MAXMULTIKILL = 6,
	STAT_MAXREPEATKILL = 7,
	STAT_SHOTS = 8,
	STAT_HITS = 9,
	STAT_ACCURACY = 10,
	STAT_INACCURACY = 11,
	STAT_DEADHITS = 12,
	STAT_HEADHITS = 13,
	STAT_PUNCHES = 14,
	STAT_BODYHITS = 15,
	STAT_ARMHITS = 16,
	STAT_LEGHITS = 17,
	STAT_HEADHITSRATIO = 18,
	STAT_BODYHITSRATIO = 19,
	STAT_ARMHITSRATIO = 20,
	STAT_LEGHITSRATIO = 21,
	STAT_DEADHITSRATIO = 22,
	STAT_HEADSKNOCKEDOFF = 23,
	STAT_HEADSPUNCHEDOFF = 24,
	STAT_FRIENDHITS = 25,
	STAT_HIT = 26,
	STAT_HEADHIT = 27,
	STAT_PUNCHED = 28,
	STAT_OWNHEADKNOCKEDOFF = 29,
	STAT_OWNHEADPUNCHEDOFF = 30,
	STAT_FRIENDHIT = 31,
	STAT_GLASSHIT = 32,
	STAT_HEALTH = 33,
	STAT_ARMOUR = 34,
	STAT_AMMO = 35,
	STAT_BAGTIME = 36,
	STAT_BAGPICKED = 37,
	STAT_BAGRETURNED = 38,
	STAT_BAGSCORED = 39,
	STAT_LEADTIME = 40,
	STAT_LASTTIME = 41,
	STAT_AVERAGEWEAPONPOWERRATIO = 42,
	STAT_FAVOURITEGUN = 43,
	STAT_FAVOURITEGUNSHOTS = 44,
	STAT_FAVOURITEGUNRATIO = 45,
	STAT_DISTMOVED = 46,
	STAT_DISTFORWARD = 47,
	STAT_DISTBACKWARD = 48,
	STAT_DISTBACKWARDRATIO = 49,
	STAT_DISTSTRAFE = 50,
	STAT_DISTSTRAFERATIO = 51,
	STAT_FALLTIME = 52,
	STAT_FALLTIMERATIO = 53,
	STAT_CROUCHTIME = 54,
	STAT_CROUCHTIMERATIO = 55,
	STAT_AIMTIME = 56,
	STAT_AIMTIMERATIO = 57,
	STAT_TOTALTIMEVISIBLE = 58,
	STAT_PICKUPRATIO = 59,
	STAT_CHANGEDGUN = 60,
	STAT_RICOCHETHITS = 61,
	STAT_FIXEDGUNSHOTS = 62,
	STAT_FIXEDGUNTIME = 63,
	STAT_TIMESPLITTERSKILLED = 64,
	STAT_TIMEALIVE = 65,
	STAT_SHORTESTTIMEALIVE = 66,
	STAT_LONGESTTIMEALIVE = 67,
	STAT_KILLSUSINGAIM = 68,
	NUM_STAT = 69
};

typedef enum {
	STAT_GUN_SHOTS = 0,
	STAT_GUN_KILLS = 1,
	STAT_GUN_HITS = 2,
	STAT_GUN_TIME = 3,
	STAT_GUN_PICKED = 4,
	NUM_STAT_GUN = 5
};

typedef enum {
	STAT_CHAR_KILLS = 0,
	STAT_CHAR_KILLED = 1,
	STAT_CHAR_HITS = 2,
	STAT_CHAR_HIT = 3,
	STAT_CHAR_TIMEVISIBLE = 4,
	STAT_CHAR_TIMEVISIBLERATIO = 5,
	NUM_STAT_CHAR = 6
};

typedef enum {
	MEDAL_NONE = -1,
	MEDAL_LETHAL = 0,
	MEDAL_KILLED = 1,
	MEDAL_SUICIDAL = 2,
	MEDAL_SUCCESIVEKILLS = 3,
	MEDAL_MULTIKILL = 4,
	MEDAL_REPEATKILL = 5,
	MEDAL_ACCURACY = 6,
	MEDAL_INACCURACY = 7,
	MEDAL_DEADHITS = 8,
	MEDAL_HEADHITS = 9,
	MEDAL_PUNCHES = 10,
	MEDAL_PUNCHED = 11,
	MEDAL_HEADSKNOCKEDOFF = 12,
	MEDAL_HEADSPUNCHEDOFF = 13,
	MEDAL_FRIENDHITS = 14,
	MEDAL_GLASSHITS = 15,
	MEDAL_HEALTHY = 16,
	MEDAL_ARMOUR = 17,
	MEDAL_NOHEALTH = 18,
	MEDAL_NOARMOUR = 19,
	MEDAL_CAMPER = 20,
	MEDAL_LAZY = 21,
	MEDAL_HYPERACTIVE = 22,
	MEDAL_RUNAWAY = 23,
	MEDAL_SKILLEDSTRAFER = 24,
	MEDAL_FALL = 25,
	MEDAL_HIDING = 26,
	MEDAL_COWARDLY = 27,
	MEDAL_DODGING = 28,
	MEDAL_OUTGUNNED = 29,
	MEDAL_EQUIPPED = 30,
	MEDAL_LEADBUTLOST = 31,
	MEDAL_CHANGEDGUNS = 32,
	MEDAL_BAGRETURNER = 33,
	MEDAL_BESTBAGGER = 34,
	MEDAL_WORSTBAGGER = 35,
	MEDAL_RICOCHETHITS = 36,
	MEDAL_KAMIKAZE = 37,
	MEDAL_VICTIM = 38,
	MEDAL_BULLY = 39,
	MEDAL_PEACEFUL = 40,
	MEDAL_DISHONOURABLE = 41,
	MEDAL_EXCITED = 42,
	MEDAL_LONELY = 43,
	MEDAL_SHORTESTTIMEALIVE = 44,
	MEDAL_LONGESTTIMEALIVE = 45,
	MEDAL_SURVIVOR = 46,
	MEDAL_KILLSUSINGAIM = 47,
	MAX_MEDALS = 48
};

typedef enum {
	COMPLETE_NEVER = 0,
	COMPLETE_ALWAYS = 1,
	COMPLETE_STORY = 2,
	COMPLETE_STORY123 = 3,
	COMPLETE_STORY456 = 4,
	COMPLETE_STORY789 = 5,
	COMPLETE_CHALLENGE = 6,
	NUM_CONDITIONTYPES = 7
};

typedef enum {
	DTYPE_INT_LESSISGOOD = 0,
	DTYPE_INT_MOREISGOOD = 1,
	DTYPE_INT_NOTZEROISGOOD = 2,
	DTYPE_NUM = 3
};

typedef enum {
	CHEAT_BIGHEADS = 0,
	CHEAT_SMALLHEADS = 1,
	CHEAT_BIGGUNS = 2,
	CHEAT_INFINITEAMMO = 3,
	CHEAT_PAINTBALL = 4,
	CHEAT_GUNSOUND = 5,
	CHEAT_ENEMYROCKETS = 6,
	CHEAT_ENEMYBRICKS = 7,
	CHEAT_ENEMYBONUS1 = 8,
	CHEAT_ENEMYBONUS2 = 9,
	CHEAT_ENEMYBONUS3 = 10,
	CHEAT_ENEMYBONUS4 = 11,
	CHEAT_ENEMYBONUS5 = 12,
	CHEAT_HEADLESS = 13,
	CHEAT_HEADSREMOVABLE = 14,
	CHEAT_NUM = 15
};

typedef enum {
	GUNSET_DAM = 0,
	GUNSET_TOMB = 1,
	GUNSET_VILLAGE = 2,
	GUNSET_MANSION = 3,
	GUNSET_CHINESE = 4,
	GUNSET_INDUSTRIAL = 5,
	GUNSET_SCIFI = 6,
	GUNSET_PLANET = 7,
	GUNSET_RFACTORY = 8,
	GUNSET_DEFAULT = 9,
	GUNSET_RETRO = 10,
	GUNSET_HEAT = 11,
	GUNSET_PLASMA = 12,
	GUNSET_HANDGUNS = 13,
	GUNSET_REMOTEMINES = 14,
	GUNSET_PROXIMITYMINES = 15,
	GUNSET_TIMEDMINES = 16,
	GUNSET_BRICKS = 17,
	GUNSET_TEST = 18,
	NUM_GUNSETS = 19
};

typedef enum {
	CHRSET_TOMB = 0,
	CHRSET_VILLAGE = 1,
	CHRSET_MANSION = 2,
	CHRSET_CHINESE = 3,
	CHRSET_INDUSTRIAL = 4,
	CHRSET_DOCKS = 5,
	CHRSET_SCIFI = 6,
	CHRSET_PLANET = 7,
	CHRSET_RFACTORY = 8,
	CHRSET_DEFAULT = 9,
	CHRSET_PERIOD = 10,
	CHRSET_CRIME = 11,
	CHRSET_SCIFI1 = 12,
	CHRSET_SHOCKER = 13,
	CHRSET_JUSTICE = 14,
	CHRSET_ZOMBIES = 15,
	CHRSET_SPLITTERS = 16,
	NUM_CHRSETS = 17
};

typedef enum {
	LVBTNTYPE_TOGGLE = 0,
	LVBTNTYPE_ONEPRESS = 1,
	LVBTNTYPE_TIMED = 2,
	LVBTNTYPE_MULTIPRESS = 3,
	NUM_LVBTNTYPES = 4
};

typedef enum {
	LVBTNFLAG_NONE = 0,
	LVBTNFLAG_DISABLED = 1
};

typedef enum {
	TEAM_NONE = 0,
	TEAM_A = 1,
	TEAM_B = 2,
	TEAM_C = 3,
	TEAM_D = 4,
	TEAM_BAG = 5
};

typedef enum {
	DOORFLAG_NONE = 0,
	DOORFLAG_LOCKED = 1,
	DOORFLAG_NOFRONTLOCK = 2,
	DOORFLAG_NOBACKLOCK = 4,
	DOORFLAG_AUTO = 8,
	DOORFLAG_STARTOPEN = 16,
	DOORFLAG_HASBUTTON = 32
};

typedef enum {
	GUNSET_GUN1 = 0,
	GUNSET_GUN2 = 1,
	GUNSET_GUN3 = 2,
	GUNSET_GUN4 = 3,
	GUNSET_GUN5 = 4,
	GUNSET_GUN6 = 5,
	GUNSET_GUN7 = 6,
	GUNSET_GUN8 = 7,
	GUNSET_GUN9 = 8,
	GUNSET_GUN10 = 9,
	GUNSET_GUN11 = 10,
	GUNSET_GUN12 = 11,
	GUNSET_GUN13 = 12,
	GUNSET_GUN14 = 13,
	GUNSET_GUN15 = 14
};

struct propspawninfo_s {
	int numspawned;
};

typedef propspawninfo_s propspawninfo;

struct npcspawninfo_s {
	int numspawned;
	int numactive;
	float timerCountDown;
	boolean triggerset;
};

typedef npcspawninfo_s npcspawninfo;

typedef enum {
	CHALLENGE1_A = 0,
	CHALLENGE1_B = 1,
	CHALLENGE1_C = 2,
	CHALLENGE2_A = 3,
	CHALLENGE2_B = 4,
	CHALLENGE2_C = 5,
	CHALLENGE3_A = 6,
	CHALLENGE3_B = 7,
	CHALLENGE3_C = 8,
	CHALLENGE4_A = 9,
	CHALLENGE4_B = 10,
	CHALLENGE4_C = 11,
	CHALLENGE5_A = 12,
	CHALLENGE5_B = 13,
	CHALLENGE5_C = 14,
	CHALLENGE6_A = 15,
	CHALLENGE6_B = 16,
	CHALLENGE6_C = 17,
	CHALLENGE7_A = 18,
	CHALLENGE7_B = 19,
	CHALLENGE7_C = 20,
	CHALLENGE8_A = 21,
	CHALLENGE8_B = 22,
	CHALLENGE8_C = 23,
	CHALLENGE9_A = 24,
	CHALLENGE9_B = 25,
	CHALLENGE9_C = 26,
	NUM_CHALLENGES = 27
};

typedef int (*chfunc_t)(/* parameters unknown */);

typedef enum {
	CHATTR_TIME = 0,
	CHATTR_RANKCHR = 1,
	CHATTR_RANKTEAM = 2,
	CHATTR_HEALTH = 3,
	CHATTR_KILLS = 4,
	CHATTR_LOSSES = 5,
	CHATTR_TEAMSCORE = 6,
	CHATTR_STAT = 7,
	CHATTR_FUNCTION = 8
};

typedef enum {
	STYPE_NONE = 0,
	STYPE_TIME = 1,
	STYPE_KILLS = 2,
	STYPE_HEALTH = 3,
	STYPE_HEADSKNOCKEDOFF = 4
};

typedef enum {
	CHCOMP_LESS = 0,
	CHCOMP_LESSEQUAL = 1,
	CHCOMP_EQUAL = 2,
	CHCOMP_MORE = 3,
	CHCOMP_MOREEQUAL = 4
};

struct challengeplayerstart_s {
	int spawnpad;
	int guncombo;
};

typedef challengeplayerstart_s challengeplayerstart;

struct challengechrset_s {
	int chrtype;
	float DamageScaleIn;
	float DamageScaleOut;
	int team;
};

typedef challengechrset_s challengechrset;

typedef enum {
	MEMDYNAMIC_FREE = 0,
	MEMDYNAMIC_SHORTSTAY = 1,
	MEMDYNAMIC_RESIDENT = 2
};

typedef enum {
	LOADBAR_PRELOAD_STAGE = 0,
	LOADBAR_SOUND_STAGE = 1,
	LOADBAR_STAGE_NUM = 2
};

typedef enum {
	SCE_DEMO_ENDREASON_ATTRACT_INTERRUPTED = 0,
	SCE_DEMO_ENDREASON_ATTRACT_COMPLETE = 1,
	SCE_DEMO_ENDREASON_PLAYABLE_INACTIVITY_TIMEOUT = 2,
	SCE_DEMO_ENDREASON_PLAYABLE_GAMEPLAY_TIMEOUT = 3,
	SCE_DEMO_ENDREASON_PLAYABLE_COMPLETE = 4,
	SCE_DEMO_ENDREASON_PLAYABLE_QUIT = 5
} sceDemoEndReason;

typedef enum {
	PARTORDER_BASE = 0,
	PARTORDER_HIPS = 1,
	PARTORDER_WAIST = 2,
	PARTORDER_NECK = 3,
	PARTORDER_HEAD = 4,
	PARTORDER_RBLADE = 5,
	PARTORDER_RSHOULDER = 6,
	PARTORDER_RELBOW = 7,
	PARTORDER_RWRIST = 8,
	PARTORDER_LBLADE = 9,
	PARTORDER_LSHOULDER = 10,
	PARTORDER_LELBOW = 11,
	PARTORDER_LWRIST = 12,
	PARTORDER_RHIP = 13,
	PARTORDER_RKNEE = 14,
	PARTORDER_RHEEL = 15,
	PARTORDER_LHIP = 16,
	PARTORDER_LKNEE = 17,
	PARTORDER_LHEEL = 18,
	PARTORDER_NUM = 19
};

struct jointanimframe_s {
	float trans[3];
	float rot[3];
};

typedef jointanimframe_s jointanimframe;

struct jointanimframequat_s {
	float trans[3];
	quaternion q;
};

typedef jointanimframequat_s jointanimframequat;

struct keyframe_s {
	float time;
	keyframe_s *next;
	jointanimframe data[0];
};

typedef keyframe_s keyframe;

struct anim_s {
	int numjoints;
	int numkeyframes;
	float length;
	keyframe *firstkeyframe;
	float rootTrans[3];
};

typedef anim_s anim;

typedef enum {
	ANIM_NONE = 0,
	ANIM_SOFTWARE = 1,
	ANIM_BIND_POSE = 2,
	ANIM_STAND = 3,
	ANIM_RUN = 4,
	ANIM_RUNBACK = 5,
	ANIM_RUNLEFT = 6,
	ANIM_RUNRIGHT = 7,
	ANIM_WALK = 8,
	ANIM_WALKBACK = 9,
	ANIM_WALKLEFT = 10,
	ANIM_WALKRIGHT = 11,
	ANIM_PATROL = 12,
	ANIM_PATROL2 = 13,
	ANIM_PATROL3 = 14,
	ANIM_PATROL4 = 15,
	ANIM_SEARCHINGPATROL = 16,
	ANIM_SEARCHINGPATROL2 = 17,
	ANIM_SEARCHINGPATROL3 = 18,
	ANIM_SEARCHINGPATROL4 = 19,
	ANIM_ACTINGPATROL = 20,
	ANIM_PATROLREACTION = 21,
	ANIM_PATROLREACTSHORT = 22,
	ANIM_PATROLWALKTOSTAND = 23,
	ANIM_PATROLIDLE1 = 24,
	ANIM_PATROLIDLE2 = 25,
	ANIM_PATROLIDLE3 = 26,
	ANIM_PATROLSTANDTOWALKLEFT = 27,
	ANIM_PATROLSTANDTOWALKRIGHT = 28,
	ANIM_PATROLSTANDTOWALK180 = 29,
	ANIM_PATROLSTANDTOWALK = 30,
	ANIM_PATROLTURN90LEFT = 31,
	ANIM_PATROLTURN90LEFT2 = 32,
	ANIM_PATROLTURN90RIGHT = 33,
	ANIM_PATROLTURN90RIGHT2 = 34,
	ANIM_PATROLTURN90RIGHT3 = 35,
	ANIM_PATROLTURN90RIGHT4 = 36,
	ANIM_DIVE = 37,
	ANIM_SHUFFLE_LEFT = 38,
	ANIM_SHUFFLE = 39,
	ANIM_SIDESTEP_RIGHT = 40,
	ANIM_SIDESTEP_RIGHTLITTLE = 41,
	ANIM_SLIDE = 42,
	ANIM_SUMMERSAULT = 43,
	ANIM_LOWLEFT = 44,
	ANIM_BACKFLIP = 45,
	ANIM_CARTWHEEL = 46,
	ANIM_DIAGBACKRIGHT2 = 47,
	ANIM_DIAGFORLEFT = 48,
	ANIM_DIAGLEFTRIGHT = 49,
	ANIM_DOUBLEDODGE = 50,
	ANIM_DOUBLEDODGE_FLIPPED = 51,
	ANIM_ROLLRIGHT = 52,
	ANIM_ROLLLEFT_FLIPPED = 53,
	ANIM_STEPRIGHT = 54,
	ANIM_SMALLSTEP10 = 55,
	ANIM_SMALLSTEP9 = 56,
	ANIM_STEPBACK5 = 57,
	ANIM_SMALLSTEPBACK = 58,
	ANIM_FAINTLEFT = 59,
	ANIM_FAINTRIGHT_FLIPPED = 60,
	ANIM_STRAFEFARRIGHT = 61,
	ANIM_DODGELEFTRIGHT = 62,
	ANIM_STRAFEFARLEFT = 63,
	ANIM_TURNANDRUN = 64,
	ANIM_RETREAT = 65,
	ANIM_MOVEFORWARD = 66,
	ANIM_MOVELEFT = 67,
	ANIM_MOVERIGHT = 68,
	ANIM_STANDFEINTLEFT = 69,
	ANIM_STANDFEINTRIGHT = 70,
	ANIM_DROPTOKNEE = 71,
	ANIM_ONKNEE = 72,
	ANIM_STANDFROMKNEE = 73,
	ANIM_AMBUSH_SAL = 74,
	ANIM_AMBUSH_SALB = 75,
	ANIM_AMBUSH_STANDPOSE_FLIP = 76,
	ANIM_AMBUSH_STANDPOSE = 77,
	ANIM_AMBUSH_CRATE_TOSTAND = 78,
	ANIM_AMBUSH_CRATE_TOCROUCH = 79,
	ANIM_AMBUSH_CRATE_STAND = 80,
	ANIM_AMBUSH_CRATE_CROUCH = 81,
	ANIM_AMBUSH_CRATE_GRENADE = 82,
	ANIM_AMBUSH_CRATE_SHOOTOVER = 83,
	ANIM_AMBUSH_CROUCHATTACK_BACK_FLIP = 84,
	ANIM_AMBUSH_CROUCHATTACK_BACK = 85,
	ANIM_AMBUSH_CROUCHATTACK_FLIP = 86,
	ANIM_AMBUSH_CROUCHATTACK = 87,
	ANIM_AMBUSH_ROLLATTACK_BACK_FLIP = 88,
	ANIM_AMBUSH_ROLLATTACK_BACK = 89,
	ANIM_AMBUSH_ROLLATTACK_FLIP = 90,
	ANIM_AMBUSH_ROLLATTACK = 91,
	ANIM_AMBUSH_SPRAYATTACK_BACK_FLIP = 92,
	ANIM_AMBUSH_SPRAYATTACK_BACK = 93,
	ANIM_AMBUSH_SPRAYATTACK_FLIP = 94,
	ANIM_AMBUSH_SPRAYATTACK = 95,
	ANIM_AMBUSH_WALL1_BACK_FLIP = 96,
	ANIM_AMBUSH_WALL1_BACK = 97,
	ANIM_AMBUSH_WALL1_FLIP = 98,
	ANIM_AMBUSH_WALL1 = 99,
	ANIM_AMBUSH_WALL2_BACK = 100,
	ANIM_AMBUSH_WALL2_FLIP = 101,
	ANIM_AMBUSH_WALL2 = 102,
	ANIM_AMBUSH_WALL3_BACK_FLIP = 103,
	ANIM_AMBUSH_WALL3_BACK = 104,
	ANIM_AMBUSH_WALL3_FLIP = 105,
	ANIM_AMBUSH_WALL3 = 106,
	ANIM_HR_LEFTSHOULDER = 107,
	ANIM_HR_LEFTSTOMACH = 108,
	ANIM_HR_RIGHTLEG = 109,
	ANIM_HR_RIGHTSHOULDER = 110,
	ANIM_HR_RIGHTSTOMACH = 111,
	ANIM_SHOTHEAD = 112,
	ANIM_SHOTHEAD2 = 113,
	ANIM_SHOTHEAD3 = 114,
	ANIM_SHOTSHOULDER = 115,
	ANIM_CHESTSHOT1 = 116,
	ANIM_CHESTSHOT2 = 117,
	ANIM_HEARTSHOT = 118,
	ANIM_RIGHTFRONT = 119,
	ANIM_SHOTSHOULDER2 = 120,
	ANIM_OVERWRITE = 121,
	ANIM_OVERWRITE2 = 122,
	ANIM_BARRELOVERWRITE = 123,
	ANIM_PUNCH = 124,
	ANIM_CUTSCENE = 125,
	ANIM_CS_INTRO_DAM_1 = 126,
	ANIM_CS_INTRO_DAM_2 = 127,
	ANIM_CS_INTRO_DAM_3 = 128,
	ANIM_CS_INTRO_DAM_4 = 129,
	ANIM_CS_INTRO_DAM_5 = 130,
	ANIM_CS_INTRO_DAM_6 = 131,
	ANIM_CS_INTRO_DAM_7 = 132,
	ANIM_CS_INTRO_DAM_8 = 133,
	ANIM_CS_INTRO_DAM_9 = 134,
	ANIM_CS_INTRO_DAM_10 = 135,
	ANIM_CS_INTRO_DAM_11 = 136,
	ANIM_CS_INTRO_DAM_12 = 137,
	ANIM_CS_INTRO_DAM_13 = 138,
	ANIM_CS_INTRO_DAM_14 = 139,
	ANIM_CS_INTRO_DAM_15 = 140,
	ANIM_CS_INTRO_DAM_16 = 141,
	ANIM_CS_INTRO_DAM_17 = 142,
	ANIM_CS_INTRO_DAM_18 = 143,
	ANIM_BARRELWALK = 144,
	ANIM_BARRELTOTURRET = 145,
	ANIM_BARRELDROPTOTURN = 146,
	ANIM_BARRELENDTURN = 147,
	ANIM_BARRELSTANDTOWALK = 148,
	ANIM_BARRELSTARTTURN = 149,
	ANIM_BARRELTURNTOSTAND = 150,
	ANIM_BARRELTURRETTOSTAND = 151,
	ANIM_ZOMBIESTAND = 152,
	ANIM_ZOMBIESTAND2 = 153,
	ANIM_ZOMBIEGETUP1 = 154,
	ANIM_ZOMBIEGETUP2 = 155,
	ANIM_ZOMBIESWIPE1 = 156,
	ANIM_ZOMBIESWIPE2 = 157,
	ANIM_ZOMBIESWIPE3 = 158,
	ANIM_ZOMBIESWIPE4 = 159,
	ANIM_ZOMBIEWALK1 = 160,
	ANIM_ZOMBIEWALK2 = 161,
	ANIM_ZOMBIEWALK3 = 162,
	ANIM_NUM = 163
};

typedef enum {
	ANIM_FE_NONE = 163,
	ANIM_FE_SOFTWARE = 164,
	ANIM_FE_BIND_POSE = 165,
	ANIM_FE_STAND = 166,
	ANIM_FE_FSTAND = 167,
	ANIM_FE_NUM = 168,
	ANIM_ALL_NUM = 168
};

typedef enum {
	ANIMPROP_NULL = 0,
	ANIMPROP_LOOPING = 1,
	ANIMPROP_ROOT_TRANSLATE = 2,
	ANIMPROP_NOTAG = 4,
	ANIMPROP_NOINTERRUPT = 8,
	ANIMPROP_NOTWEENFROM = 16,
	ANIMPROP_DEATH = 32,
	ANIMPROP_POINTING = 256,
	ANIMPROP_TRAVERSAL = 512,
	ANIMPROP_ANGLE_L90 = 1024,
	ANIMPROP_ANGLE_R90 = 2048,
	ANIMPROP_ANGLE_180 = 4096,
	ANIMPROP_PATROLCANROTATE = 8192,
	ANIMPROP_NOROTATE = 16384,
	ANIMPROP_TAGAIMING = 32768,
	ANIMPROP_NUM = 32769
};

struct bulletSparkData_s {
	float startpos[3];
	float vel[46][3];
};

typedef bulletSparkData_s bulletSparkData;

struct spriteSparkData_s {
	int type;
	float startpos[3];
	float vel[30][3];
};

typedef spriteSparkData_s spriteSparkData;

struct impactExplosionData_s {
	int type;
	u32 colour;
	float explosionSize[3];
	float explosionRot[3];
	float explosionTime[3];
	float explosionPos[3][3];
};

typedef impactExplosionData_s impactExplosionData;

struct blastExplosionData_s {
	int type;
	u32 colour;
	float size;
	float point[23][3];
	float time[23];
	float psize[23];
	float vel[23][3];
	float rotSpeed[23];
};

typedef blastExplosionData_s blastExplosionData;

struct bulletSmokeData_s {
	float pos[3];
	float size;
	u32 col;
	float rot[5];
};

typedef bulletSmokeData_s bulletSmokeData;

struct pulseData_s {
	int type;
	float pos[3];
	float dir[3];
	float rot[20];
};

typedef pulseData_s pulseData;

typedef enum {
	TRACER_YELLOW = 0,
	TRACER_NUM = 1
};

struct tracerData_s {
	int subtype;
	float pos[3];
	float dir[3];
};

typedef tracerData_s tracerData;

struct spriteStreamData_s {
	float currentparticle;
	float points[100][3];
	float vel[100][3];
	float timeafter[100];
	float rot[100];
};

typedef spriteStreamData_s spriteStreamData;

struct spriteTrailData_s {
	float points[100][3];
	float rot[100];
	float vel[100][3];
	float timeafter[100];
	float previoustime;
};

typedef spriteTrailData_s spriteTrailData;

struct stripTrailData_s {
	float currentparticle;
	float points[17][3];
	float timeafter[17];
	float axis1[17][3];
	float axis2[17][3];
	float disappearRatePerSecond;
};

typedef stripTrailData_s stripTrailData;

struct straightTrailData_s {
	float dir[3];
	float currentparticle;
	float points[17][3];
	float timeafter[17];
	float axis1[3];
	float axis2[3];
	float disappearRatePerSecond;
};

typedef straightTrailData_s straightTrailData;

struct spriteBurstData_s {
	float points[100][4];
	float vel[100][3];
	float rot[100];
};

typedef spriteBurstData_s spriteBurstData;

struct spriteManualData_s {
	mtx_u particlematrix;
	float points[100][3];
	u32 col[100];
	float rot[100];
};

typedef spriteManualData_s spriteManualData;

struct sparkBurstData_s {
	float points[46][2][4];
	float vel[46][3];
};

typedef sparkBurstData_s sparkBurstData;

struct sparkStreamData_s {
	float currentparticle;
	float points[100][2][4];
	float vel[100][3];
	float timeafter[100];
};

typedef sparkStreamData_s sparkStreamData;

struct spriteData_t {
	boolean aligned;
	float rot;
	float normal[3];
	float axisRight[3];
	float axisUp[3];
};

typedef spriteData_t spriteData;

struct glowData_t {
	float dir[3];
};

typedef glowData_t glowData;

typedef enum {
	OWNER_PLAYER = 1,
	OWNER_CHARACTER = 2,
	OWNER_REMOTE = 3,
	OWNER_PLAYERREMOTE = 4,
	OWNER_DAMAPACHE = 5,
	OWNER_PROP = 6
};

typedef enum {
	BULLETTYPE_NONE = -1,
	BULLETTYPE_PUNCH = 0,
	BULLETTYPE_SMALLBULLET = 1,
	BULLETTYPE_BIGBULLET = 2,
	BULLETTYPE_SHELL = 3,
	BULLETTYPE_ROCKET = 4,
	BULLETTYPE_FIXEDROCKET = 5,
	BULLETTYPE_MULTIROCKET = 6,
	BULLETTYPE_GUIDEDROCKET = 7,
	BULLETTYPE_APACHEROCKET = 8,
	BULLETTYPE_TIMED_GRENADE = 9,
	BULLETTYPE_GAS_GRENADE = 10,
	BULLETTYPE_CLUSTER_GRENADE = 11,
	BULLETTYPE_EMP_GRENADE = 12,
	BULLETTYPE_REMOTEMINE = 13,
	BULLETTYPE_TIMEDMINE = 14,
	BULLETTYPE_PROXIMITYMINE = 15,
	BULLETTYPE_TNT_NORMAL = 16,
	BULLETTYPE_TNT_ALT = 17,
	BULLETTYPE_BRICK = 18,
	BULLETTYPE_FLAME = 19,
	BULLETTYPE_PETROL = 20,
	BULLETTYPE_FOAM = 21,
	BULLETTYPE_EXPLOSION = 22,
	BULLETTYPE_LASERCOILS = 23,
	BULLETTYPE_ELECTRIC = 24,
	BULLETTYPE_ELECTROROCKET = 25,
	BULLETTYPE_WALLHUGGER = 26,
	BULLETTYPE_GREENLASERBOLT = 27,
	BULLETTYPE_PURPLELASERBOLT = 28,
	BULLETTYPE_ORANGELASERBOLT = 29,
	BULLETTYPE_BLUELASERBOLT = 30,
	BULLETTYPE_REDLASERBOLT = 31,
	BULLETTYPE_ARCLASER = 32,
	BULLETTYPE_DISC = 33,
	BULLETTYPE_FLARE = 34,
	BULLETTYPE_NUM = 35
};

typedef enum {
	EXPLOSION_ROCKET = 0,
	EXPLOSION_NORMAL = 1,
	EXPLOSION_MUSHROOM = 2,
	EXPLOSION_MUSHROOM2 = 3,
	EXPLOSION_BLUEROCKET = 4,
	NUM_EXPLOSION_TYPES = 5
};

typedef enum {
	BULLETFLAG_SILENCED = 1,
	BULLETFLAG_EXPLOSIVE = 2,
	BULLETFLAG_DESTROYGLASS = 4,
	BULLETFLAG_LIGHT = 8,
	BULLETFLAG_EXCLUDENOHITSPROP = 16
};

typedef enum {
	BLOOD_NORMAL = 0,
	BLOOD_THICK = 1
};

typedef enum {
	DEATHFLAG_NONE = 0,
	DEATHFLAG_EXPLOSION = 1,
	DEATHFLAG_ALWAYSKILL = 2
};

struct padv1_s {
	int extref;
	u32 flags;
	short int hallnum;
	short int room;
	float pos[3];
	float roty;
};

typedef padfile_s padfile;

struct propio_s {
	int extref;
	int num;
	float pos[3];
	float roty;
};

typedef propio_s propio;

typedef enum {
	STATE_NULL = 0,
	STATE_ATTACK = 1,
	STATE_DEFEND = 2,
	STATE_TRACK_TARGET = 4,
	STATE_DYING = 8,
	STATE_SPAWN = 16,
	STATE_ARM = 32,
	STATE_SELECT_TARGET = 64,
	STATE_FINDBEARINGS = 128,
	STATE_FINDMYPAD = 256,
	STATE_FOLLOW_PASSIVE = 512,
	STATE_SLEEP = 1024,
	STATE_AMBUSH = 2048,
	STATE_PATROL = 4096,
	STATE_AWAKE = 8192,
	STATE_NOSLEEP = 16384,
	STATE_AMBUSHCROUCH = 32768,
	STATE_SNIPE1 = 65536,
	STATE_PILLARALIEN = 131072,
	STATE_NOROUTE = 262144,
	STATE_RUNAWAY = 524288,
	STATE_SNIPE = 1048576,
	STATE_BARRELROBOT = 2097152,
	STATE_GETHEALTH = 4194304,
	STATE_LIFT = 8388608,
	STATE_GAMEOVER = 16777216,
	STATE_GETARMOUR = 33554432,
	STATE_PLAYDEAD = 67108864,
	STATE_ONFIRE = 134217728,
	STATE_PRESSBUTTON = 268435456,
	STATE_STANDSHOOT = 536870912,
	STATE_CHARGE = 1073741824,
	STATE_MAX = 1073741825
} enemyState;

typedef enum {
	canSeePlayer = 1
};

typedef enum {
	AIFLAG_NULL = 0,
	AIFLAG_NOPROGRESS = 1,
	AIFLAG_SHOOTING = 2,
	AIFLAG_NOINFORM = 4,
	AIFLAG_ARM_GOFORFAVE = 8,
	AIFLAG_PICKEDUPHEALTH = 16,
	AIFLAG_NOHEAR = 32,
	AIFLAG_CTFTARGETBAG = 64,
	AIFLAG_CTFTARGETDROP = 128,
	AIFLAG_NOALERT = 256,
	AIFLAG_OFFSCREENMOVING = 512,
	AIFLAG_NOGRENADES = 1024,
	AIFLAG_SENTTOSLEEP = 2048,
	AIFLAG_PRESSBUTTON = 4096,
	AIFLAG_DEATHFALLEN = 8192,
	AIFLAG_NOVISIBLESPAWN = 16384,
	AIFLAG_NOCRATESHOOT = 32768,
	AIFLAG_BLOCKED = 65536,
	AIFLAG_PICKEDUPGUN = 131072,
	AIFLAG_NOBREAKCOVER = 262144,
	AIFLAG_ONFIRE = 524288,
	AIFLAG_PARTIALALERT = 1048576,
	AIFLAG_ALERT = 2097152,
	AIFLAG_PATROLNOTURNANIM = 4194304,
	AIFLAG_CANBECLONED = 8388608,
	AIFLAG_ISACLONE = 16777216,
	AIFLAG_RUNTOPATROL = 33554432,
	AIFLAG_OUTDOOR = 67108864,
	AIFLAG_CANZOMBIFY = 134217728,
	AIFLAG_INSTANTGETUP = 268435456,
	AIFLAG_TARGETSPROP = 536870912,
	AIFLAG_SEENBYAPLAYER = 1073741824,
	AIFLAG_PICKEDUPARMOUR = -2147483648
};

typedef enum {
	TEAMFLAG_NULL = 0,
	TEAMFLAG_GOTOPPONENTSBAG = 1,
	TEAMFLAG_GOTOURBAG = 2,
	TEAMFLAG_OPPONENTSGOTOURBAG = 4,
	TEAMFLAG_OPPONENTSGOTTHEIRBAG = 8,
	TEAMFLAG_ESCORT = 16,
	TEAMFLAG_ASSASSIN = 32
};

typedef enum {
	ST_NULL = 0,
	ST_BYSIGHT = 1,
	ST_BYCOLLISION = 2,
	ST_BYDAMAGE = 3,
	ST_BYTRIGGER = 4
};

typedef enum {
	EPA_PILLAR = 0,
	EPA_AWAKENING = 1,
	EPA_AWOKEN = 2
};

typedef enum {
	AOT_UNAWARE = 0,
	AOT_SIGHTACTIVATED = 1,
	AOT_SOUNDACTIVATED = 2,
	AOT_PARTIALLYAWARE = 3
};

struct triggerpad_s {
	int pad;
	int id;
};

typedef triggerpad_s triggerpad;

struct communicationList_s {
	int numactive;
	prop *p[12];
};

typedef communicationList_s communicationList;

typedef enum {
	ALARMSTATE_OFF = 0,
	ALARMSTATE_ON = 1
};

typedef enum {
	INFTYPE_CHR = 0,
	INFTYPE_ALARM = 1
};

typedef enum {
	EP_SETUPPATROL = 0,
	EP_UNAWARE = 1,
	EP_CURIOUS = 2,
	EP_PARTIALALERT = 3,
	EP_ALERT = 4,
	EP_REACT = 5,
	EP_RUNTOPATROL = 6
};

typedef enum {
	FOLLOW_USEPADS = 0,
	FOLLOW_USELOS = 1,
	FOLLOW_STOPPED = 2,
	FOLLOW_GETOUTOFWAY = 4,
	FOLLOW_GOAHEAD = 8,
	FOLLOW_GOTOPAD = 16,
	FOLLOW_WAIT = 32,
	FOLLOW_COWER = 64
};

typedef enum {
	AI_SFX_INFORMALERT = 0,
	AI_SFX_REACT = 1
};

typedef enum {
	WEATHER_NORMAL = 0,
	WEATHER_RAIN = 1,
	WEATHER_STORM = 2,
	WEATHER_SNOW = 3,
	WEATHER_FIREFLIES = 4
};

struct bumpmapData_s {
	int numPlanes;
	bumpmapPlane planes[6];
};

typedef bumpmapData_s bumpmapData;
typedef int (*sceSdTransIntrHandler)(/* parameters unknown */);
typedef int (*sceSdSpu2IntrHandler)(/* parameters unknown */);

typedef struct {
	u_short func;
	u_short entry;
	u_int value;
} sceSdBatch;

typedef struct {
	int core;
	int mode;
	short int depth_L;
	short int depth_R;
	int delay;
	int feedback;
} sceSdEffectAttr;

typedef enum {
	ROOMLIGHT_FIXED = 0,
	ROOMLIGHT_SINE = 1,
	ROOMLIGHT_SQUARE = 2,
	ROOMLIGHT_RANDOM = 3,
	ROOMLIGHT_NUM = 4
};

typedef void devguiresponder_t(/* parameters unknown */);
typedef char* devguigetstr_t(/* parameters unknown */);

typedef enum {
	DEVGUIMSGTYPE_MENUCLICK = 1,
	DEVGUIMSGTYPE_LEFTCLICK = 2,
	DEVGUIMSGTYPE_MIDDLECLICK = 3,
	DEVGUIMSGTYPE_LEFTCLICKHOLD = 4,
	DEVGUIMSGTYPE_MIDDLECLICKHOLD = 5
};

struct devguimsg_s {
	int type;
	devguiwin_s *window;
	int winclickx;
	int winclicky;
	devguimnu_s *menu;
	devguibtn_s *button;
	int btnclickx;
	int btnclicky;
};

typedef devguimsg_s devguimsg_t;

typedef enum {
	DEVGUIBTNTYPE_LABEL = 0,
	DEVGUIBTNTYPE_BUTTON = 1,
	DEVGUIBTNTYPE_CHECKBOX = 2,
	DEVGUIBTNTYPE_PUSHBUTTON = 3,
	DEVGUIBTNTYPE_RADIOBUTTON = 4,
	DEVGUIBTNTYPE_LIST = 5,
	DEVGUIBTNTYPE_ARROWUP = 6,
	DEVGUIBTNTYPE_ARROWDOWN = 7,
	DEVGUIBTNTYPE_SLIDER = 8,
	DEVGUIBTNTYPE_NUM = 9
};

typedef enum {
	ID_USER = 2000
};

struct devguibtn_s {
	int id;
	int type;
	int left;
	int top;
	int width;
	int height;
	u8 *caption;
	union {
		devguilistinfo_s *listinfo;
		devguibtn_s *parent;
		int state;
	} data;
	boolean focus;
	devguibtn_s *next;
	devguibtn_s *sub;
};

typedef devguibtn_s devguibtn_t;

struct devguilistinfo_s {
	int count;
	int index;
	int selected;
	devguigetstr_t *getstr;
	devguibtn_t toparrow;
	devguibtn_t slider;
	devguibtn_t downarrow;
};

typedef devguilistinfo_s devguilistinfo_t;

struct devguimnu_s {
	devguibtn_s *buttons;
};

typedef devguimnu_s devguimnu_t;

struct devguiwin_s {
	u8 *title;
	int left;
	int top;
	int width;
	int height;
	devguiresponder_t *responder;
	void (*drawer)(/* parameters unknown */);
	devguimnu_s *menu;
	devguibtn_s *buttons;
	boolean visible;
	int borderleft;
	int bordertop;
	int borderright;
	int borderbottom;
	devguibtn_s titlebtn;
};

typedef devguiwin_s devguiwin_t;

typedef enum {
	ANIMINFO_RIGHTFOOT_IMPORTED = -2147483648
};

typedef enum {
	KEYFRAMETAG_LEFTFOOT = 1,
	KEYFRAMETAG_RIGHTFOOT = 2,
	KEYFRAMETAG_NOSHOOT = 4,
	KEYFRAMETAG_NOTWEEN = 8,
	KEYFRAMETAG_NOINTERRUPT = 16,
	KEYFRAMETAG_TRIGGERSFX = 32,
	KEYFRAMETAG_TRIGGERGFX = 64,
	KEYFRAMETAG_NOCOLLISION = 128,
	KEYFRAMETAG_ROTATE = 256,
	KEYFRAMETAG_SHOOT = 512,
	KEYFRAMETAG_NUM = 10
};

struct corpsedata_s {
	float shootdirx;
	float shootdiry;
	float animscale;
	float time;
	float burnEndTime;
	float fadeStartTime;
	float fadeDuration;
	boolean overportal;
	boolean burning;
	int limbflag;
};

typedef corpsedata_s corpsedata;

typedef enum {
	TILESET_VIRTUAL = 0,
	TILESET_INDUSTRIAL = 1,
	TILESET_GOTHIC = 2,
	TILESET_ALIEN = 3,
	TILESET_SPACEPORT = 4,
	TILESET_NUM = 5
};

typedef enum {
	TILE_CORRIDOR_2 = 0,
	TILE_CORNER = 1,
	TILE_CORRIDOR_1 = 2,
	TILE_ROOM_2_2 = 3,
	TILE_TJUNC = 4,
	TILE_STAIR_2_2 = 5,
	TILE_LAUNCHBAY = 6,
	TILE_LARGE_DBL1_TRENCH = 7,
	TILE_CORE_2_2 = 8,
	TILE_TJUNC_1_1 = 9,
	TILE_ADAPTER2 = 10,
	TILE_LARGE_DBL1_BRIDGE = 11,
	TILE_LARGE_DBL1_CORNER = 12,
	TILE_LARGE_DBL1_CROSS = 13,
	TILE_CORRIDOR_RAMP = 14,
	TILE_BASE1 = 15,
	TILE_LARGE_DBL1_OPEN = 16,
	TILE_OPEN_SMALL = 17,
	TILE_ADAPTER = 18,
	TILE_LARGE_DBL1_RING = 19,
	TILE_LARGE_BUNKER_CORNER_ALT = 20,
	TILE_LARGE_DBL1_RAMP = 21,
	TILE_LARGE_BUNKER_CORNER = 22,
	TILE_LARGE_BUNKER_WALL = 23,
	TILE_LARGE_BRIDGE_OPEN = 24,
	TILE_LARGE_DBL1_TRENCH_FLAT = 25,
	TILE_LARGE_DBL1_RAMP_WIDE = 26,
	TILE_LARGE_PIT = 27,
	TILE_ROOM_BOX1 = 28,
	TILE_ADAPTER3_RAMP = 29,
	TILE_NUM = 30
};

struct tilelighttype_s {
	short int desc;
	u8 mask;
};

typedef tilelighttype_s tilelighttype_t;

typedef enum {
	LT_SLOW = 0,
	LT_MEDIUM = 1,
	LT_FAST = 2,
	LT_SPEED_NUM = 3
};

typedef enum {
	LT_FIXED = 0,
	LT_FLICKERING = 4,
	LT_SWITCHING = 8,
	LT_PULSING = 12,
	LT_TYPE_NUM = 4
};

typedef enum {
	PF_NORTH = 1,
	PF_EAST = 2,
	PF_SOUTH = 3,
	PF_WEST = 4
};

typedef enum {
	TIMERTYPE_COUNTDOWN = 0,
	TIMERTYPE_REPEAT = 1,
	TIMERTYPE_COMPLETED = 2
};

typedef enum {
	CARMODE_ABSOLUTE_SINE = 0,
	CARMODE_RELATIVE_SINE = 1,
	CARMODE_SPLINE = 2
};

typedef enum {
	CARFLAGS_USESTARTANGLE = 1
};

typedef enum {
	CARPATH_START = 0,
	CARPATH_STOP = 1,
	CARPATH_LOOP = 2,
	CARPATH_EVENT = 3,
	CARPATH_WAIT = 4,
	CARPATH_FORWARD = 5,
	CARPATH_BACKWARD = 6,
	CARPATH_TURNLEFT = 7,
	CARPATH_TURNRIGHT = 8,
	CARPATH_JUMP = 9
};

struct cardata_s {
	int mode;
	int flags;
	carpath *paths;
	int numPaths;
	carPathTracker trackers[3];
	float turningPos[3];
	float prevPos[3];
	float rot[3];
	float wait;
	float speed;
	float angleAroundTurningPos;
	float turningAngleAdjust;
	float bumpiness;
	float damageRot[3];
	int pad;
	float rotorAngle;
	float bodyRotate[2];
	float wheelRotate;
	float wheelTurn;
	float trailingPos1[3];
	float trailingPos2[3];
	float lastTrailingPos1[3];
	float lastTrailingPos2[3];
	int voice;
	float totalDistance;
};

typedef cardata_s cardata;

struct specialdata_s {
	void *ref;
	void (*callback)(/* parameters unknown */);
	float *extra;
	float intensity;
	float textureoffset[2];
	float scalar;
	float xzscalar;
	float ascalar[2];
	float start[3];
	float dest[3];
	float specialcol[6];
	gfxpointers override[3];
	int section;
	float time;
	float timeChange;
	int state;
	float rotaxis[3];
	float normal[3];
	float hitSensitivity;
	float windSensitivity;
	float weight;
	float frictionExp;
	float rotationRestriction;
	float leverageDistanceSq;
	float rotaxial;
	float rotaxialvel;
	float rotnonaxialX;
	float rotnonaxialZ;
	float rotnonaxialvelX;
	float rotnonaxialvelZ;
	float soundTime;
	int soundVoice;
	particlegroup_s *pg;
};

typedef specialdata_s specialdata;

typedef enum {
	SWITCH_OFF = 0,
	SWITCH_ON = 1
};

typedef enum {
	DAM_TURBINE_OFF = 0,
	DAM_TURBINE_ON = 1,
	DAM_TURBINE_BROKEN = 2
};

typedef enum {
	DAM_RADAR_OFF = 0,
	DAM_RADAR_ON = 1,
	DAM_RADAR_BROKEN = 2
};

typedef enum {
	SPECIALFX_NONE = -1,
	SPECIALFX_PICKUPSPAWN = 0,
	SPECIALFX_FLAMETORCH = 1,
	SPECIALFX_FLAMETORCH_PROTO = 2,
	SPECIALFX_OCCASIONALROCKETSMOKE = 3,
	SPECIALFX_DAMTUNNEL_THICKSTEAM = 4,
	SPECIALFX_DAMSTAIRCASE_THICKSTEAM = 5,
	SPECIALFX_THICKCHIMNEYSMOKE = 6,
	SPECIALFX_HYDRANTSPRAY = 7,
	SPECIALFX_MANHOLESMOKE_PROTO = 8,
	SPECIALFX_MANHOLESMOKE = 9,
	SPECIALFX_SHOWER = 10,
	SPECIALFX_TIMEPORTAL = 11,
	SPECIALFX_LASERBEAM = 12,
	NUM_SPECIALFX = 13
};

typedef enum {
	SPECIALFXFLAGS_UPDATEONLYIFVISIBLE = 65536,
	SPECIALFXFLAGS_DISABLED = 131072
};

typedef enum {
	LASERBEAM_TRIGGER = 0,
	LASERBEAM_FORCEFIELD = 1
};

typedef enum {
	DAMAGETYPE_NONE = -1,
	DAMAGETYPE_SMALLBULLET = 0,
	DAMAGETYPE_BIGBULLET = 1,
	DAMAGETYPE_SHELL = 2,
	DAMAGETYPE_BRICK = 3,
	DAMAGETYPE_LASERCOILS = 4,
	DAMAGETYPE_ELECTRIC = 5,
	DAMAGETYPE_LASERBOLT = 6,
	DAMAGETYPE_ARCLASER = 7,
	DAMAGETYPE_DISC = 8,
	DAMAGETYPE_APACHEROCKET = 9,
	DAMAGETYPE_APACHEBULLET = 10,
	DAMAGETYPE_FIXEDGUNROCKET = 11,
	DAMAGETYPE_FIXEDGUNBULLET = 12,
	DAMAGETYPE_FLAME = 13,
	DAMAGETYPE_FLARE = 14,
	DAMAGE_TYPES = 15
};

typedef enum {
	DAMAGEPARTGROUP_HEAD = 0,
	DAMAGEPARTGROUP_BODY = 1,
	DAMAGEPARTGROUP_ARMSLEGS = 2,
	NUM_DAMAGEPARTGROUPS = 3
};

typedef enum {
	MMFILE_VERSION = 20071974,
	MMFILE_INFO = 20071975,
	MMFILE_TILES = 20071976,
	MMFILE_EOF = 20071977,
	MMFILE_DOORS = 20071978,
	MMFILE_PATROL = 20071979,
	MMFILE_LIGHTPALETTE = 20071980
};

struct mmfilechunk_s {
	int id;
	int length;
};

typedef mmfilechunk_s mmfilechunk;

struct mmfileinfo_s {
	int setupflags;
	int numtiles;
	u16 tileset;
	u16 tunenum;
	s16 weaponset;
	s16 weapons[15];
	u8 mapname[32];
	u8 mapdesc[128];
};

typedef mmfileinfo_s mmfileinfo;

struct mmfiletile_s {
	int tilenum;
	s8 x;
	s8 y;
	s8 z;
	s8 rot;
	u16 seals;
	u16 numitems;
	u32 lightcolour;
	u8 lighttype;
	u8 lightphase;
	u16 unused;
};

typedef mmfiletile_s mmfiletile;

struct mmfileitem_s {
	s16 itemnum;
	s16 padextref;
	int angle;
};

typedef mmfileitem_s mmfileitem;

struct mmfiledoor_s {
	s8 x;
	s8 y;
	s8 z;
	s8 rot;
	u16 key;
	u16 unused;
	u16 tileref1;
	u16 plugref1;
	u16 tileref2;
	u16 plugref2;
};

typedef mmfiledoor_s mmfiledoor;

typedef struct {
	u16 padref;
	u16 tileref;
} mmpatrolnode_t;

struct mmfilepatrol_s {
	u16 length;
	u16 mode;
	mmpatrolnode_t nodes[0];
};

typedef mmfilepatrol_s mmfilepatrol;

typedef enum {
	ECM_NULL = 0,
	ECM_ATTACK_DROP = 1,
	ECM_DEFEND_DROP = 2,
	ECM_CAPTURED_DROP = 4,
	ECM_DIED = 8,
	ECM_CANCEL = 16
};

typedef enum {
	CARTRIDGEFLAGS_FIRSTPERSON = 1,
	CARTRIDGEFLAGS_THIRDPERSON = 2
};

typedef enum {
	CARTRIDGETYPE_NONE = -1,
	CARTRIDGETYPE_LARGE = 0,
	CARTRIDGETYPE_SMALL = 1,
	CARTRIDGETYPE_ASSAULT_SHOTGUN = 2,
	CARTRIDGETYPE_SCIFI = 3,
	CARTRIDGETYPE_GOLD = 4,
	NUM_CARTRIDGETYPE = 5
};

typedef enum {
	DECAL_BULLETTYPE_NONE = 0,
	DECAL_BULLETTYPE_BULLET = 1,
	DECAL_BULLETTYPE_SCIFI = 2,
	DECAL_BULLETTYPE_EXPLODE = 3,
	DECAL_BULLETTYPE_PETROL = 4
};

typedef enum {
	SPRAYTYPE_NONE = 0,
	SPRAYTYPE_FLOOR = 1,
	SPRAYTYPE_CHAR = 2
};

typedef enum {
	CLOUD_DENSITY_NONE = 0,
	CLOUD_DENSITY_LIGHT = 1,
	CLOUD_DENSITY_MEDIUM = 2,
	CLOUD_DENSITY_HIGH = 3,
	CLOUD_DENSITY_FULL = 4,
	CLOUD_DENSITY_TYPES = 5
};

typedef enum {
	GUNFX_FIRE = 0,
	GUNFX_EXTINGUISH = 1,
	GUNFX_NUM = 2
};

typedef enum {
	REMOTEDEVICE_PLAYERCONTROLLED = 1,
	REMOTEDEVICE_CAMERA = 2,
	REMOTEDEVICE_GUN = 4,
	REMOTEDEVICE_SIDEMOUNTED = 8,
	REMOTEDEVICE_CEILINGMOUNTED = 16,
	REMOTEDEVICE_FLOORMOUNTED = 32,
	REMOTEDEVICE_FIXED_GUN = 64,
	REMOTEDEVICE_HAS_BUTTON = 128
};

typedef enum {
	REMOTESTATE_SLEEP = 0,
	REMOTESTATE_SWEEP = 1,
	REMOTESTATE_LOCKON = 2,
	REMOTESTATE_BACKTOSWEEP = 3,
	REMOTESTATE_WAIT_FOR_CHR = 4,
	REMOTESTATE_LINEUP_WITH_CHR = 5,
	REMOTESTATE_CONTROLLED_BY_CHR = 6,
	REMOTESTATE_OFF = 7,
	REMOTESTATE_BROKEN = 8
};

typedef enum {
	REMOTETEAM_ANYPLAYER = 0
};

typedef enum {
	FRONTFX_NORMAL = 0,
	FRONTFX_STARTPAGE = 1,
	FRONTFX_CHRPAGE = 2,
	FRONTFX_MAIN = 3,
	FRONTFX_GOODIES = 4,
	FRONTFX_STATSPAGE = 5
};

typedef enum {
	MSGBOX_STATE_BUSY = 0,
	MSGBOX_STATE_YES = 1,
	MSGBOX_STATE_NO = 2
};

typedef enum {
	MAPGEN_TYPE_DEATHMATCH = 0,
	MAPGEN_TYPE_STORY = 1,
	MAPGEN_TYPE_LABYRINTH = 2,
	MAPGEN_TYPE_NUM = 3
};

typedef enum {
	MAPGEN_SIZE_SMALL = 0,
	MAPGEN_SIZE_MEDIUM = 1,
	MAPGEN_SIZE_LARGE = 2,
	MAPGEN_SIZE_NUM = 3
};

typedef enum {
	MAPGEN_LIGHTS_DARK = 0,
	MAPGEN_LIGHTS_BRIGHT = 1,
	MAPGEN_LIGHTS_DISCO = 2,
	MAPGEN_LIGHTS_NUM = 3
};

typedef enum {
	ICON_O = 0,
	ICON_X = 1,
	ICON_GUN = 2,
	ICON_AMMO = 3,
	ICON_BAG = 4,
	ICON_START = 5,
	ICON_HEALTH = 6,
	ICON_ARMOUR_LO = 7,
	ICON_ARMOUR_HI = 8,
	ICON_DROP1 = 9,
	ICON_DROP2 = 10,
	ICON_DROP3 = 11,
	ICON_DROP4 = 12,
	ICON_KEY1 = 13,
	ICON_KEY2 = 14,
	ICON_KEY3 = 15,
	ICON_KEY4 = 16,
	ICON_POWERUP = 17,
	ICON_AUTOGUN = 18,
	ICON_FIXEDGUN = 19,
	ICON_NPC = 20,
	ICON_NUM = 21
};

typedef enum {
	POINTER_MAPVIEW = 0,
	POINTER_TILEPAGE = 1,
	POINTER_ZOOMTILE = 2,
	POINTER_COLOURWHEEL = 3,
	POINTER_NUM = 4
};

typedef enum {
	EDITMODE_TILE = 0,
	EDITMODE_ITEM = 1,
	EDITMODE_LIGHT = 2,
	EDITMODE_PATROL = 3,
	EDITMODE_NUM = 4
};

typedef enum {
	ANIMPERS_NORMAL = 0,
	ANIMPERS_BULKY = 1,
	ANIMPERS_ACROBATIC = 2,
	ANIMPERS_NORMAL_AGRESSIVE = 3,
	ANIMPERS_BULKY_AGRESSIVE = 4,
	ANIMPERS_ACROBATIC_AGRESSIVE = 5,
	ANIMPERS_NORMAL_CAUTIOUS = 6,
	ANIMPERS_BULKY_CAUTIOUS = 7,
	ANIMPERS_ACROBATIC_CAUTIOUS = 8,
	ANIMPERS_MIL_STORY1 = 9,
	ANIMPERS_NUM = 10
};

typedef enum {
	ATTACK_PHASE_FIRSTSIGHT = 0,
	ATTACK_PHASE_ATTACK = 1,
	ATTACK_PHASE_CLOSEIN = 2,
	ATTACK_PHASE_BACKOFF = 3,
	ATTACK_PHASE_SEEK = 4,
	NUM_ATTACKANIM_PHASES = 5
};

struct attackaniminfo_s {
	float frequency;
	float skill;
	float mindist;
	float maxdist;
};

typedef attackaniminfo_s attackaniminfo;

typedef enum {
	ANIMSEQ_NONE = -1,
	ANIMSEQ_DIVE = 0,
	ANIMSEQ_SHUFFLE_LEFT = 1,
	ANIMSEQ_SHUFFLE = 2,
	ANIMSEQ_SIDESTEP_RIGHT = 3,
	ANIMSEQ_SIDESTEP_RIGHTLITTLE = 4,
	ANIMSEQ_SLIDE = 5,
	ANIMSEQ_SUMMERSAULT = 6,
	ANIMSEQ_LOWLEFT = 7,
	ANIMSEQ_BACKFLIP = 8,
	ANIMSEQ_CARTWHEEL = 9,
	ANIMSEQ_DIAGBACKRIGHT2 = 10,
	ANIMSEQ_DIAGFORLEFT = 11,
	ANIMSEQ_DIAGLEFTRIGHT = 12,
	ANIMSEQ_ROLLRIGHT = 13,
	ANIMSEQ_ROLLLEFT_FLIPPED = 14,
	ANIMSEQ_STEPRIGHT = 15,
	ANIMSEQ_SMALLSTEP10 = 16,
	ANIMSEQ_SMALLSTEP9 = 17,
	ANIMSEQ_STEPBACK5 = 18,
	ANIMSEQ_SMALLSTEPBACK = 19,
	ANIMSEQ_FAINTLEFT = 20,
	ANIMSEQ_FAINTRIGHT_FLIPPED = 21,
	ANIMSEQ_STRAFEFARRIGHT = 22,
	ANIMSEQ_DOUBLEDODGE = 23,
	ANIMSEQ_DOUBLEDODGE_FLIPPED = 24,
	ANIMSEQ_DODGELEFTRIGHT = 25,
	ANIMSEQ_STRAFEFARLEFT = 26,
	ANIMSEQ_TURNANDRUN = 27,
	ANIMSEQ_RETREAT = 28,
	ANIMSEQ_NA_STRAFE_LR = 29,
	ANIMSEQ_NA_STRAFE_RL = 30,
	ANIMSEQ_NA_STATIONARY1 = 31,
	ANIMSEQ_NA_FORWARD1 = 32,
	ANIMSEQ_NA_FORWARD2 = 33,
	ANIMSEQ_NA_FORWARD3 = 34,
	ANIMSEQ_NA_FORWARD4 = 35,
	ANIMSEQ_NA_FORWARD5 = 36,
	ANIMSEQ_NC_BACK1 = 37,
	ANIMSEQ_NC_BACK2 = 38,
	ANIMSEQ_NC_BACK3 = 39,
	ANIMSEQ_NC_BACK4 = 40,
	ANIMSEQ_NC_BACK5 = 41,
	ANIMSEQ_NC_BACK6 = 42,
	ANIMSEQ_NC_BACK7 = 43,
	ANIMSEQ_B_STATIONARY1 = 44,
	ANIMSEQ_B_STATIONARY2 = 45,
	ANIMSEQ_B_STATIONARY3 = 46,
	ANIMSEQ_B_STATIONARY4 = 47,
	ANIMSEQ_B_FORWARD1 = 48,
	ANIMSEQ_B_BACK1 = 49,
	ANIMSEQ_A_STATIONARY1 = 50,
	ANIMSEQ_A_BACK1 = 51,
	ANIMSEQ_A_BACK2 = 52,
	ANIMSEQ_A_FORWARD1 = 53,
	ANIMSEQ_A_FORWARD2 = 54,
	ANIMSEQ_STAND = 55,
	ANIMSEQ_REACTION = 56,
	ANIMSEQ_REACTSHORT = 57,
	ANIMSEQ_RUNL = 58,
	ANIMSEQ_RUNR = 59,
	ANIMSEQ_RUNBACK_SINGLE = 60,
	ANIMSEQ_WALKLEFT = 61,
	ANIMSEQ_WALKRIGHT = 62,
	ANIMSEQ_RUN = 63,
	ANIMSEQ_RUN1 = 64,
	ANIMSEQ_MOVEFORWARD = 65,
	ANIMSEQ_MOVELEFT = 66,
	ANIMSEQ_MOVERIGHT = 67,
	ANIMSEQ_STANDFEINTLEFT = 68,
	ANIMSEQ_STANDFEINTRIGHT = 69,
	ANIMSEQ_NUM = 70
};

typedef enum {
	__no_type_class = -1,
	__void_type_class = 0,
	__integer_type_class = 1,
	__char_type_class = 2,
	__enumeral_type_class = 3,
	__boolean_type_class = 4,
	__pointer_type_class = 5,
	__reference_type_class = 6,
	__offset_type_class = 7,
	__real_type_class = 8,
	__complex_type_class = 9,
	__function_type_class = 10,
	__method_type_class = 11,
	__record_type_class = 12,
	__union_type_class = 13,
	__array_type_class = 14,
	__string_type_class = 15,
	__set_type_class = 16,
	__file_type_class = 17,
	__lang_type_class = 18
};

typedef enum {
	SCE1394ERR_OK = 0,
	SCE1394ERR_ERROR = -1,
	SCE1394ERR_NOT_INITIALIZED = -1000,
	SCE1394ERR_NOT_SUPPORTED = -1001,
	SCE1394ERR_NO_MEMORY = -1002,
	SCE1394ERR_RESOURCE_UNAVAILABLE = -1003,
	SCE1394ERR_INVALID_ID = -1004,
	SCE1394ERR_INVALID_REQUEST = -1005,
	SCE1394ERR_INVALID_ARGUMENT = -1006,
	SCE1394ERR_INVALID_SIZE = -1007,
	SCE1394ERR_INVALID_ADDRESS = -1008,
	SCE1394ERR_TRANSACTION_ERROR = -1020,
	SCE1394ERR_RESET_DETECTED = -1021,
	SCE1394ERR_REQUEST_DISABLED = -1022,
	SCE1394ERR_FAILED_RESPONSE = -1023,
	SCE1394ERR_TIMEOUT = -1024,
	SCE1394ERR_ACK_MISSING = -1025,
	SCE1394ERR_RETRY_LIMIT = -1026,
	SCE1394ERR_DATA_ERROR = -1027,
	SCE1394ERR_INVALID_PARAMETER = -1028,
	SCE1394ERR_RESPONSE_DATA_ERROR = -1041,
	SCE1394ERR_RESPONSE_FORMAT_ERROR = -1042,
	SCE1394ERR_REQUEST_DATA_ERROR = -1043,
	SCE1394ERR_RESPONSE_ACK_MISSING = -1044,
	SCE1394ERR_UNSOLICITED_RESPONSE = -1045,
	SCE1394ERR_RESPONSE_RETRY_LIMIT = -1046,
	SCE1394ERR_HEADER_CRC_ERROR = -1061,
	SCE1394ERR_UNKNOWN_TCODE = -1062,
	SCE1394ERR_CYCLE_TOO_LONG = -1063,
	SCE1394ERR_NO_MANAGER = -1081
} Sce1394ErrorCode;

typedef int (*sce1394TrDataIndProc)(/* parameters unknown */);

typedef struct {
	int iov_len;
	void *iov_base;
} sce1394Iov;

typedef unsigned int sceILsock_addr_t;

typedef union {
	double value;
	struct {
		__uint32_t lsw;
		__uint32_t msw;
	} parts;
} ieee_double_shape_type;

typedef union {
	float value;
	__uint32_t word;
} ieee_float_shape_type;

typedef enum {
	CMP_SI = 0,
	CMP_DI = 1,
	CMP_SF = 2,
	CMP_DF = 3,
	CMP_MAX = 4
} cmp_type;

typedef enum {
	DELAY_NONE = 0,
	DELAY_LOAD = 1,
	DELAY_HILO = 2,
	DELAY_HILO1 = 3,
	DELAY_FCMP = 4
} delay_type;

typedef enum {
	PROCESSOR_DEFAULT = 0,
	PROCESSOR_R3000 = 1,
	PROCESSOR_R3900 = 2,
	PROCESSOR_R6000 = 3,
	PROCESSOR_R4000 = 4,
	PROCESSOR_R4100 = 5,
	PROCESSOR_R4300 = 6,
	PROCESSOR_R4600 = 7,
	PROCESSOR_R4650 = 8,
	PROCESSOR_R5000 = 9,
	PROCESSOR_R5400 = 10,
	PROCESSOR_R5900 = 11,
	PROCESSOR_R8000 = 12
} processor_type;

typedef enum {
	MIPS_ABICALLS_NO = 0,
	MIPS_ABICALLS_YES = 1
} mips_abicalls_type;

typedef enum {
	BLOCK_MOVE_NORMAL = 0,
	BLOCK_MOVE_NOT_LAST = 1,
	BLOCK_MOVE_LAST = 2
} block_move_type;

typedef enum {
	NO_REGS = 0,
	M16_NA_REGS = 1,
	M16_REGS = 2,
	T_REG = 3,
	M16_T_REGS = 4,
	GR_REGS = 5,
	FP_REGS = 6,
	HI_REG = 7,
	LO_REG = 8,
	HILO_REG = 9,
	MD_REGS = 10,
	HI_AND_GR_REGS = 11,
	LO_AND_GR_REGS = 12,
	HILO_AND_GR_REGS = 13,
	HI1_REG = 14,
	LO1_REG = 15,
	HILO1_REG = 16,
	MD1_REGS = 17,
	HI1_AND_GR_REGS = 18,
	LO1_AND_GR_REGS = 19,
	HILO1_AND_GR_REGS = 20,
	HI01_REG = 21,
	LO01_REG = 22,
	HILO01_REG = 23,
	MD01_REGS = 24,
	HI01_AND_GR_REGS = 25,
	LO01_AND_GR_REGS = 26,
	HILO01_AND_GR_REGS = 27,
	ST_REGS = 28,
	ALL_REGS = 29,
	LIM_REG_CLASSES = 30
} reg_class;

struct mips_frame_info {
	long int total_size;
	long int var_size;
	long int args_size;
	long int extra_size;
	int gp_reg_size;
	int fp_reg_size;
	long int mask;
	long int fmask;
	long int gp_save_offset;
	long int fp_save_offset;
	long int gp_sp_offset;
	long int fp_sp_offset;
	int initialized;
	int num_gp;
	int num_fp;
	long int insns_len;
};

struct mips_args {
	int gp_reg_found;
	int arg_number;
	int arg_words;
	int fp_arg_words;
	int last_arg_fp;
	int fp_code;
	int num_adjusts;
	rtx_def *adjust[8];
};

typedef mips_args CUMULATIVE_ARGS;

typedef enum {
	VOIDmode = 0,
	PQImode = 1,
	QImode = 2,
	PHImode = 3,
	HImode = 4,
	PSImode = 5,
	SImode = 6,
	PDImode = 7,
	DImode = 8,
	TImode = 9,
	OImode = 10,
	QFmode = 11,
	HFmode = 12,
	TQFmode = 13,
	SFmode = 14,
	DFmode = 15,
	XFmode = 16,
	TFmode = 17,
	QCmode = 18,
	HCmode = 19,
	SCmode = 20,
	DCmode = 21,
	XCmode = 22,
	TCmode = 23,
	CQImode = 24,
	CHImode = 25,
	CSImode = 26,
	CDImode = 27,
	CTImode = 28,
	COImode = 29,
	BLKmode = 30,
	CCmode = 31,
	MAX_MACHINE_MODE = 32
} machine_mode;

typedef enum {
	MODE_RANDOM = 0,
	MODE_INT = 1,
	MODE_FLOAT = 2,
	MODE_PARTIAL_INT = 3,
	MODE_CC = 4,
	MODE_COMPLEX_INT = 5,
	MODE_COMPLEX_FLOAT = 6,
	MAX_MODE_CLASS = 7
} mode_class;

typedef int ptrdiff_t;
typedef unsigned int wint_t;
typedef unsigned char UQItype;
typedef long int word_type;

struct DIstruct {
	SItype low;
	SItype high;
};

typedef union {
	DIstruct s;
	DItype ll;
} DIunion;

typedef short int HItype;

typedef enum {
	CLASS_SNAN = 0,
	CLASS_QNAN = 1,
	CLASS_ZERO = 2,
	CLASS_NUMBER = 3,
	CLASS_INFINITY = 4
} fp_class_type;

typedef short unsigned int ushort;
typedef unsigned int uint;
typedef long int daddr_t;
typedef char *caddr_t;
typedef short unsigned int ino_t;
typedef short int dev_t;
typedef short unsigned int uid_t;
typedef short unsigned int gid_t;
typedef int pid_t;
typedef long int key_t;
typedef long int ssize_t;
typedef unsigned int mode_t;
typedef short unsigned int nlink_t;
typedef long int fd_mask;

typedef struct {
	fd_mask fds_bits[1];
} _types_fd_set;

typedef malloc_chunk *mchunkptr;

struct stat {
	dev_t st_dev;
	ino_t st_ino;
	mode_t st_mode;
	nlink_t st_nlink;
	uid_t st_uid;
	gid_t st_gid;
	dev_t st_rdev;
	off_t st_size;
	time_t st_atime;
	long int st_spare1;
	time_t st_mtime;
	long int st_spare2;
	time_t st_ctime;
	long int st_spare3;
	long int st_blksize;
	long int st_blocks;
	long int st_spare4[2];
};

// warning: multiple differing types with the same name (type name not equal)
typedef unsigned int ULong;

typedef union {
	double value;
	struct {
		unsigned int fraction1;
		unsigned int fraction0 : 20;
		unsigned int exponent : 11;
		unsigned int sign : 1;
	} number;
	struct {
		unsigned int function1;
		unsigned int function0 : 19;
		unsigned int quiet : 1;
		unsigned int exponent : 11;
		unsigned int sign : 1;
	} nan;
	struct {
		long unsigned int lsw;
		long unsigned int msw;
	} parts;
	long int aslong[2];
} __ieee_double_shape_type;

typedef union {
	float value;
	struct {
		unsigned int fraction0 : 7;
		unsigned int fraction1 : 16;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	} number;
	struct {
		unsigned int function1 : 16;
		unsigned int function0 : 6;
		unsigned int quiet : 1;
		unsigned int exponent : 8;
		unsigned int sign : 1;
	} nan;
	long int p1;
} __ieee_float_shape_type;

typedef int fp_rnd;
typedef int fp_except;
typedef int fp_rdi;

union double_union {
	double d;
	__uint32_t i[2];
};

typedef enum {
	OCT = 0,
	DEC = 1,
	HEX = 2
};

typedef long unsigned int sigset_t;

struct sigaction {
	void (*sa_handler)(/* parameters unknown */);
	sigset_t sa_mask;
	int sa_flags;
};

typedef int sig_atomic_t;
struct rtx_def;
