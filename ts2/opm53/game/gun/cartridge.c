// STATUS: NOT STARTED

#include "cartridge.h"

struct cartridge_s {
	mtx_u rotationmatrix;
	prop_s *prop;
	float rotvel[3];
	int time;
	float baseHeightWhenFired;
	int drawflags;
};

typedef cartridge_s cartridge;

struct cartridgeGroup_s {
	cartridge cartridges[10];
	int startCartridge;
	int numCartridges;
};

typedef cartridgeGroup_s cartridgeGroup;

int cartridgeProps[5] = {
	/* [0] = */ 219,
	/* [1] = */ 220,
	/* [2] = */ 221,
	/* [3] = */ 222,
	/* [4] = */ 223
};

cartridgeGroup cartridgeGroups[2] = {
	/* [0] = */ {
		/* .cartridges = */ {
			/* [0] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [1] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [2] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [3] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [4] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [5] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [6] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [7] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [8] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [9] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			}
		},
		/* .startCartridge = */ 0,
		/* .numCartridges = */ 0
	},
	/* [1] = */ {
		/* .cartridges = */ {
			/* [0] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [1] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [2] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [3] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [4] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [5] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [6] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [7] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [8] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			},
			/* [9] = */ {
				/* .rotationmatrix = */ {
					/* .f = */ {
						/* [0] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [1] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [2] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						},
						/* [3] = */ {
							/* [0] = */ 0.f,
							/* [1] = */ 0.f,
							/* [2] = */ 0.f,
							/* [3] = */ 0.f
						}
					},
					/* .l = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0
					},
					/* .s = */ {
						/* [0] = */ 0,
						/* [1] = */ 0,
						/* [2] = */ 0,
						/* [3] = */ 0,
						/* [4] = */ 0,
						/* [5] = */ 0,
						/* [6] = */ 0,
						/* [7] = */ 0,
						/* [8] = */ 0,
						/* [9] = */ 0,
						/* [10] = */ 0,
						/* [11] = */ 0,
						/* [12] = */ 0,
						/* [13] = */ 0,
						/* [14] = */ 0,
						/* [15] = */ 0,
						/* [16] = */ 0,
						/* [17] = */ 0,
						/* [18] = */ 0,
						/* [19] = */ 0,
						/* [20] = */ 0,
						/* [21] = */ 0,
						/* [22] = */ 0,
						/* [23] = */ 0,
						/* [24] = */ 0,
						/* [25] = */ 0,
						/* [26] = */ 0,
						/* [27] = */ 0,
						/* [28] = */ 0,
						/* [29] = */ 0,
						/* [30] = */ 0,
						/* [31] = */ 0
					}
				},
				/* .prop = */ NULL,
				/* .rotvel = */ {
					/* [0] = */ 0.f,
					/* [1] = */ 0.f,
					/* [2] = */ 0.f
				},
				/* .time = */ 0,
				/* .baseHeightWhenFired = */ 0.f,
				/* .drawflags = */ 0
			}
		},
		/* .startCartridge = */ 0,
		/* .numCartridges = */ 0
	}
};

void cartridgePreload() {
	int c;
}

void cartridgeRestart() {}

void cartridgeReset() {}

void cartridgeEnd() {
	int c;
	int i;
}

void cartridgeNew(int player, int flags, int type, chrgun_s *gun, playergun_s *pgun, gunInfo_s *gi, fireInfo_s *fi, chrdata_s *cd) {
	cartridge *newCartridge;
	int endCartridge;
	float cartridgevel[3];
	float cartridgevar[3];
	float dir[3];
	cartridgeGroup *group;
	mtx_u rotmatrix;
	float trajectoryDiff[3];
	float trajectoryLen;
	mtx_u rotmatrix;
}

void cartridgeTick() {
	int i;
	int s;
	int num;
	int c;
	cartridgeGroup *group;
	cartridge *cart;
	mtx_u rotmatrix;
	int j;
}