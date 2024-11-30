// STATUS: NOT STARTED

#include "particle.h"

char *particleTextureName[18] = {
	/* [0] = */ 0x450bb0,
	/* [1] = */ 0x450b88,
	/* [2] = */ 0x450b60,
	/* [3] = */ 0x450b38,
	/* [4] = */ 0x450b10,
	/* [5] = */ 0x450af0,
	/* [6] = */ 0x450ad0,
	/* [7] = */ 0x450aa8,
	/* [8] = */ 0x450a88,
	/* [9] = */ 0x450a60,
	/* [10] = */ 0x450a38,
	/* [11] = */ 0x450a18,
	/* [12] = */ 0x4509f0,
	/* [13] = */ 0x4509c8,
	/* [14] = */ 0x4509a8,
	/* [15] = */ 0x450988,
	/* [16] = */ 0x450968,
	/* [17] = */ 0x450940
};

static char *impactExplosionTextureName[8] = {
	/* [0] = */ 0x450ce8,
	/* [1] = */ 0x450cc0,
	/* [2] = */ 0x450c98,
	/* [3] = */ 0x450c70,
	/* [4] = */ 0x450c48,
	/* [5] = */ 0x450c20,
	/* [6] = */ 0x450bf8,
	/* [7] = */ 0x450bd0
};

particleTypeInfo particleTypeInfos[27] = {
	/* [0] = */ {
		/* .name = */ 0x450ed8,
		/* .autoend = */ 1,
		/* .maximum = */ 15,
		/* .size = */ 564
	},
	/* [1] = */ {
		/* .name = */ 0x450ec8,
		/* .autoend = */ 1,
		/* .maximum = */ -1,
		/* .size = */ 376
	},
	/* [2] = */ {
		/* .name = */ 0x450eb8,
		/* .autoend = */ 1,
		/* .maximum = */ 35,
		/* .size = */ 40
	},
	/* [3] = */ {
		/* .name = */ 0x45dc20,
		/* .autoend = */ 1,
		/* .maximum = */ -1,
		/* .size = */ 28
	},
	/* [4] = */ {
		/* .name = */ 0x450ea0,
		/* .autoend = */ 1,
		/* .maximum = */ -1,
		/* .size = */ 3200
	},
	/* [5] = */ {
		/* .name = */ 0x450e88,
		/* .autoend = */ 1,
		/* .maximum = */ -1,
		/* .size = */ 3200
	},
	/* [6] = */ {
		/* .name = */ 0x450e70,
		/* .autoend = */ 0,
		/* .maximum = */ -1,
		/* .size = */ 3204
	},
	/* [7] = */ {
		/* .name = */ 0x450e58,
		/* .autoend = */ 0,
		/* .maximum = */ -1,
		/* .size = */ 3204
	},
	/* [8] = */ {
		/* .name = */ 0x450e40,
		/* .autoend = */ 0,
		/* .maximum = */ 30,
		/* .size = */ 3204
	},
	/* [9] = */ {
		/* .name = */ 0x450e28,
		/* .autoend = */ 0,
		/* .maximum = */ 30,
		/* .size = */ 3204
	},
	/* [10] = */ {
		/* .name = */ 0x45dc18,
		/* .autoend = */ 1,
		/* .maximum = */ 12,
		/* .size = */ 19856
	},
	/* [11] = */ {
		/* .name = */ 0x450e10,
		/* .autoend = */ 1,
		/* .maximum = */ -1,
		/* .size = */ 2064
	},
	/* [12] = */ {
		/* .name = */ 0x450df8,
		/* .autoend = */ 1,
		/* .maximum = */ -1,
		/* .size = */ 2064
	},
	/* [13] = */ {
		/* .name = */ 0x45dc10,
		/* .autoend = */ 1,
		/* .maximum = */ -1,
		/* .size = */ 12
	},
	/* [14] = */ {
		/* .name = */ 0x45dc08,
		/* .autoend = */ 1,
		/* .maximum = */ -1,
		/* .size = */ 44
	},
	/* [15] = */ {
		/* .name = */ 0x450de8,
		/* .autoend = */ 1,
		/* .maximum = */ 15,
		/* .size = */ 80
	},
	/* [16] = */ {
		/* .name = */ 0x450dd8,
		/* .autoend = */ 1,
		/* .maximum = */ 10,
		/* .size = */ 840
	},
	/* [17] = */ {
		/* .name = */ 0x45dc00,
		/* .autoend = */ 1,
		/* .maximum = */ -1,
		/* .size = */ 108
	},
	/* [18] = */ {
		/* .name = */ 0x450dc8,
		/* .autoend = */ 1,
		/* .maximum = */ -1,
		/* .size = */ 2032
	},
	/* [19] = */ {
		/* .name = */ 0x450db0,
		/* .autoend = */ 1,
		/* .maximum = */ -1,
		/* .size = */ 2032
	},
	/* [20] = */ {
		/* .name = */ 0x450d98,
		/* .autoend = */ 1,
		/* .maximum = */ -1,
		/* .size = */ 4816
	},
	/* [21] = */ {
		/* .name = */ 0x450d80,
		/* .autoend = */ 1,
		/* .maximum = */ -1,
		/* .size = */ 4816
	},
	/* [22] = */ {
		/* .name = */ 0x450d68,
		/* .autoend = */ 1,
		/* .maximum = */ -1,
		/* .size = */ 4816
	},
	/* [23] = */ {
		/* .name = */ 0x450d58,
		/* .autoend = */ 0,
		/* .maximum = */ -1,
		/* .size = */ 688
	},
	/* [24] = */ {
		/* .name = */ 0x450d40,
		/* .autoend = */ 0,
		/* .maximum = */ -1,
		/* .size = */ 688
	},
	/* [25] = */ {
		/* .name = */ 0x450d28,
		/* .autoend = */ 0,
		/* .maximum = */ -1,
		/* .size = */ 316
	},
	/* [26] = */ {
		/* .name = */ 0x450d10,
		/* .autoend = */ 0,
		/* .maximum = */ -1,
		/* .size = */ 316
	}
};

particleInfo particleInfos[60] = {
	/* [0] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 1,
		/* .number = */ 100,
		/* .abgr = */ 20303,
		/* .timeData = */ {
			/* .lifeTime = */ 3.5f,
			/* .fadeInTime = */ 0.25f,
			/* .fadeOutTime = */ 2.5f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 350.f,
			/* .sizey = */ 350.f,
			/* .screenSizeMax = */ 250.f,
			/* .screenSizeMaxy = */ 250.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 1.1f,
				/* [1] = */ 1.1f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 250.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.015f,
				/* [1] = */ 0.025f,
				/* [2] = */ 0.015f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [1] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 1,
		/* .number = */ 100,
		/* .abgr = */ 20319,
		/* .timeData = */ {
			/* .lifeTime = */ 3.f,
			/* .fadeInTime = */ 0.3f,
			/* .fadeOutTime = */ 2.5f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 650.f,
			/* .sizey = */ 650.f,
			/* .screenSizeMax = */ 250.f,
			/* .screenSizeMaxy = */ 250.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.5f,
				/* [1] = */ 0.5f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.015f,
				/* [1] = */ 0.025f,
				/* [2] = */ 0.015f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [2] = */ {
		/* .particleTextureIndex = */ 5,
		/* .blendMode = */ 1,
		/* .number = */ 100,
		/* .abgr = */ 28511,
		/* .timeData = */ {
			/* .lifeTime = */ 0.7f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.7f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 20.f,
			/* .sizey = */ 20.f,
			/* .screenSizeMax = */ 10000.f,
			/* .screenSizeMaxy = */ 10000.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 1.4f,
				/* [1] = */ 1.4f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ -1.15f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.5f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.5f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [3] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 1,
		/* .number = */ 100,
		/* .abgr = */ 16223,
		/* .timeData = */ {
			/* .lifeTime = */ 3.f,
			/* .fadeInTime = */ 0.5f,
			/* .fadeOutTime = */ 2.5f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 650.f,
			/* .sizey = */ 650.f,
			/* .screenSizeMax = */ 250.f,
			/* .screenSizeMaxy = */ 250.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.5f,
				/* [1] = */ 0.5f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.015f,
				/* [1] = */ 0.025f,
				/* [2] = */ 0.015f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [4] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 1,
		/* .number = */ 100,
		/* .abgr = */ 16207,
		/* .timeData = */ {
			/* .lifeTime = */ 2.5f,
			/* .fadeInTime = */ 0.5f,
			/* .fadeOutTime = */ 2.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 650.f,
			/* .sizey = */ 650.f,
			/* .screenSizeMax = */ 250.f,
			/* .screenSizeMaxy = */ 250.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.8f,
				/* [1] = */ 0.8f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.015f,
				/* [1] = */ 0.03f,
				/* [2] = */ 0.015f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [5] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 1,
		/* .number = */ 100,
		/* .abgr = */ 24383,
		/* .timeData = */ {
			/* .lifeTime = */ 2.5f,
			/* .fadeInTime = */ 0.5f,
			/* .fadeOutTime = */ 2.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 650.f,
			/* .sizey = */ 650.f,
			/* .screenSizeMax = */ 250.f,
			/* .screenSizeMaxy = */ 250.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.8f,
				/* [1] = */ 0.8f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.015f,
				/* [1] = */ 0.03f,
				/* [2] = */ 0.015f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [6] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 1,
		/* .number = */ 100,
		/* .abgr = */ 20303,
		/* .timeData = */ {
			/* .lifeTime = */ 2.5f,
			/* .fadeInTime = */ 0.5f,
			/* .fadeOutTime = */ 2.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 650.f,
			/* .sizey = */ 650.f,
			/* .screenSizeMax = */ 250.f,
			/* .screenSizeMaxy = */ 250.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.8f,
				/* [1] = */ 0.8f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.015f,
				/* [1] = */ 0.03f,
				/* [2] = */ 0.015f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [7] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 1,
		/* .number = */ 50,
		/* .abgr = */ 28527,
		/* .timeData = */ {
			/* .lifeTime = */ 4.f,
			/* .fadeInTime = */ 0.5f,
			/* .fadeOutTime = */ 3.5f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 1500.f,
			/* .sizey = */ 1500.f,
			/* .screenSizeMax = */ 1500.f,
			/* .screenSizeMaxy = */ 1500.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.5f,
				/* [1] = */ 0.5f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ -1.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 3.f,
				/* [1] = */ 0.f,
				/* [2] = */ 3.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.015f,
				/* [1] = */ 0.03f,
				/* [2] = */ 0.15f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [8] = */ {
		/* .particleTextureIndex = */ 6,
		/* .blendMode = */ 2,
		/* .number = */ 20,
		/* .abgr = */ 65535,
		/* .timeData = */ {
			/* .lifeTime = */ 2.3f,
			/* .fadeInTime = */ 0.05f,
			/* .fadeOutTime = */ 1.7f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 60.f,
			/* .sizey = */ 600.f,
			/* .screenSizeMax = */ 200.f,
			/* .screenSizeMaxy = */ 200.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.4f,
				/* [1] = */ 0.4f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 75.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [9] = */ {
		/* .particleTextureIndex = */ 6,
		/* .blendMode = */ 2,
		/* .number = */ 35,
		/* .abgr = */ 65535,
		/* .timeData = */ {
			/* .lifeTime = */ 3.5f,
			/* .fadeInTime = */ 0.4f,
			/* .fadeOutTime = */ 3.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 40.f,
			/* .sizey = */ 40.f,
			/* .screenSizeMax = */ 200.f,
			/* .screenSizeMaxy = */ 200.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.3f,
				/* [1] = */ 0.3f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 75.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [10] = */ {
		/* .particleTextureIndex = */ 6,
		/* .blendMode = */ 2,
		/* .number = */ 20,
		/* .abgr = */ 65535,
		/* .timeData = */ {
			/* .lifeTime = */ 1.8f,
			/* .fadeInTime = */ 0.4f,
			/* .fadeOutTime = */ 1.5f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 40.f,
			/* .sizey = */ 40.f,
			/* .screenSizeMax = */ 200.f,
			/* .screenSizeMaxy = */ 200.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.6f,
				/* [1] = */ 0.6f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 75.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [11] = */ {
		/* .particleTextureIndex = */ 5,
		/* .blendMode = */ 2,
		/* .number = */ 20,
		/* .abgr = */ 65535,
		/* .timeData = */ {
			/* .lifeTime = */ 1.8f,
			/* .fadeInTime = */ 0.4f,
			/* .fadeOutTime = */ 1.5f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 40.f,
			/* .sizey = */ 40.f,
			/* .screenSizeMax = */ 200.f,
			/* .screenSizeMaxy = */ 200.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.6f,
				/* [1] = */ 0.6f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 75.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [12] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 1,
		/* .number = */ 4,
		/* .abgr = */ 12079,
		/* .timeData = */ {
			/* .lifeTime = */ 5.f,
			/* .fadeInTime = */ 0.5f,
			/* .fadeOutTime = */ 3.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 500.f,
			/* .sizey = */ 500.f,
			/* .screenSizeMax = */ 250.f,
			/* .screenSizeMaxy = */ 250.f,
			/* .zBias = */ 100.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.4f,
				/* [1] = */ 0.4f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.5f,
				/* [1] = */ 0.6f,
				/* [2] = */ 0.5f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 1.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.015f,
				/* [1] = */ 0.03f,
				/* [2] = */ 0.015f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [13] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 1,
		/* .number = */ 4,
		/* .abgr = */ 20303,
		/* .timeData = */ {
			/* .lifeTime = */ 5.f,
			/* .fadeInTime = */ 0.5f,
			/* .fadeOutTime = */ 3.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 500.f,
			/* .sizey = */ 500.f,
			/* .screenSizeMax = */ 250.f,
			/* .screenSizeMaxy = */ 250.f,
			/* .zBias = */ 100.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.4f,
				/* [1] = */ 0.4f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.5f,
				/* [1] = */ 0.6f,
				/* [2] = */ 0.5f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 1.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.015f,
				/* [1] = */ 0.03f,
				/* [2] = */ 0.015f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [14] = */ {
		/* .particleTextureIndex = */ 2,
		/* .blendMode = */ 2,
		/* .number = */ 46,
		/* .abgr = */ 20351,
		/* .timeData = */ {
			/* .lifeTime = */ 0.7f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.5f,
			/* .deltaTime = */ -0.1f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.065f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -17.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 3.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 7.f,
				/* [1] = */ 6.f,
				/* [2] = */ 7.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 1.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 1.f,
			/* .bounceElasticityY = */ 0.4f
		}
	},
	/* [15] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 1,
		/* .number = */ 5,
		/* .abgr = */ 20303,
		/* .timeData = */ {
			/* .lifeTime = */ 5.f,
			/* .fadeInTime = */ 0.5f,
			/* .fadeOutTime = */ 3.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 620.f,
			/* .sizey = */ 620.f,
			/* .screenSizeMax = */ 250.f,
			/* .screenSizeMaxy = */ 250.f,
			/* .zBias = */ 100.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.2f,
				/* [1] = */ 0.2f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.7f,
				/* [1] = */ 0.7f,
				/* [2] = */ 0.7f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 1.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.015f,
				/* [1] = */ 0.03f,
				/* [2] = */ 0.015f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [16] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 1,
		/* .number = */ 10,
		/* .abgr = */ 20303,
		/* .timeData = */ {
			/* .lifeTime = */ 5.f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 3.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 700.f,
			/* .sizey = */ 700.f,
			/* .screenSizeMax = */ 250.f,
			/* .screenSizeMaxy = */ 250.f,
			/* .zBias = */ 100.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.2f,
				/* [1] = */ 0.2f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.7f,
				/* [1] = */ 0.7f,
				/* [2] = */ 0.7f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 1.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.1f,
				/* [1] = */ 0.3f,
				/* [2] = */ 0.1f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [17] = */ {
		/* .particleTextureIndex = */ 5,
		/* .blendMode = */ 2,
		/* .number = */ 35,
		/* .abgr = */ 65535,
		/* .timeData = */ {
			/* .lifeTime = */ 3.5f,
			/* .fadeInTime = */ 0.4f,
			/* .fadeOutTime = */ 3.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 20.f,
			/* .sizey = */ 20.f,
			/* .screenSizeMax = */ 200.f,
			/* .screenSizeMaxy = */ 200.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.3f,
				/* [1] = */ 0.3f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 75.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [18] = */ {
		/* .particleTextureIndex = */ 3,
		/* .blendMode = */ 1,
		/* .number = */ 25,
		/* .abgr = */ 32559,
		/* .timeData = */ {
			/* .lifeTime = */ 2.f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 1.6f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 100.f,
			/* .sizey = */ 100.f,
			/* .screenSizeMax = */ 200.f,
			/* .screenSizeMaxy = */ 200.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.5f,
				/* [1] = */ 0.5f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ -0.02f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.3f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.1f,
				/* [1] = */ 0.3f,
				/* [2] = */ 0.1f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.7f,
			/* .bounceElasticityY = */ 0.5f
		}
	},
	/* [19] = */ {
		/* .particleTextureIndex = */ 5,
		/* .blendMode = */ 2,
		/* .number = */ 0,
		/* .abgr = */ 5397,
		/* .timeData = */ {
			/* .lifeTime = */ 1.4f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 1.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 100.f,
			/* .sizey = */ 100.f,
			/* .screenSizeMax = */ 200.f,
			/* .screenSizeMaxy = */ 200.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.7f,
				/* [1] = */ 0.7f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ -0.02f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.3f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.1f,
				/* [1] = */ 0.3f,
				/* [2] = */ 0.1f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.7f,
			/* .bounceElasticityY = */ 0.5f
		}
	},
	/* [20] = */ {
		/* .particleTextureIndex = */ 3,
		/* .blendMode = */ 1,
		/* .number = */ 40,
		/* .abgr = */ 28527,
		/* .timeData = */ {
			/* .lifeTime = */ 1.f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.5f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 20.f,
			/* .sizey = */ 20.f,
			/* .screenSizeMax = */ 200.f,
			/* .screenSizeMaxy = */ 200.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 1.f,
				/* [1] = */ 1.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -3.5f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 1.25f,
				/* [1] = */ 0.1f,
				/* [2] = */ 1.25f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.7f,
			/* .bounceElasticityY = */ 0.5f
		}
	},
	/* [21] = */ {
		/* .particleTextureIndex = */ 6,
		/* .blendMode = */ 1,
		/* .number = */ 40,
		/* .abgr = */ 20351,
		/* .timeData = */ {
			/* .lifeTime = */ 1.f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.5f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 20.f,
			/* .sizey = */ 20.f,
			/* .screenSizeMax = */ 200.f,
			/* .screenSizeMaxy = */ 200.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 1.f,
				/* [1] = */ 1.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -3.5f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 1.25f,
				/* [1] = */ 0.1f,
				/* [2] = */ 1.25f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.7f,
			/* .bounceElasticityY = */ 0.5f
		}
	},
	/* [22] = */ {
		/* .particleTextureIndex = */ 2,
		/* .blendMode = */ 2,
		/* .number = */ 46,
		/* .abgr = */ 16383,
		/* .timeData = */ {
			/* .lifeTime = */ 0.4f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.f,
			/* .deltaTime = */ -0.04f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.075f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -10.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 3.f,
				/* [1] = */ 1.f,
				/* [2] = */ 3.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ -0.5f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [23] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 1,
		/* .number = */ 80,
		/* .abgr = */ 16191,
		/* .timeData = */ {
			/* .lifeTime = */ 8.f,
			/* .fadeInTime = */ 0.5f,
			/* .fadeOutTime = */ 2.5f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 1500.f,
			/* .sizey = */ 1500.f,
			/* .screenSizeMax = */ 1500.f,
			/* .screenSizeMaxy = */ 1500.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.5f,
				/* [1] = */ 0.5f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 2.5f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 2.5f,
				/* [1] = */ 0.5f,
				/* [2] = */ 2.5f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.4f,
				/* [1] = */ 1.f,
				/* [2] = */ -0.7f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [24] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 1,
		/* .number = */ 9,
		/* .abgr = */ 16191,
		/* .timeData = */ {
			/* .lifeTime = */ 8.f,
			/* .fadeInTime = */ 0.5f,
			/* .fadeOutTime = */ 2.5f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 400.f,
			/* .sizey = */ 400.f,
			/* .screenSizeMax = */ 800.f,
			/* .screenSizeMaxy = */ 800.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.2f,
				/* [1] = */ 0.2f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.2f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.2f,
				/* [1] = */ 0.2f,
				/* [2] = */ 0.2f
			},
			/* .velocityBias = */ {
				/* [0] = */ -0.5f,
				/* [1] = */ 1.f,
				/* [2] = */ -0.5f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [25] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 2,
		/* .number = */ 80,
		/* .abgr = */ 40927,
		/* .timeData = */ {
			/* .lifeTime = */ 1.1f,
			/* .fadeInTime = */ 0.1f,
			/* .fadeOutTime = */ 1.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 100.f,
			/* .sizey = */ 100.f,
			/* .screenSizeMax = */ 300.f,
			/* .screenSizeMaxy = */ 300.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 12.f,
				/* [1] = */ 12.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 1.f,
				/* [2] = */ -5.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 1.5f,
				/* [1] = */ 0.5f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [26] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 2,
		/* .number = */ 80,
		/* .abgr = */ 32639,
		/* .timeData = */ {
			/* .lifeTime = */ 0.9f,
			/* .fadeInTime = */ 0.1f,
			/* .fadeOutTime = */ 0.8f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 100.f,
			/* .sizey = */ 100.f,
			/* .screenSizeMax = */ 300.f,
			/* .screenSizeMaxy = */ 300.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 8.f,
				/* [1] = */ 8.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ -1.2f,
				/* [2] = */ -3.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 1.5f,
				/* [1] = */ -0.5f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [27] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 2,
		/* .number = */ 80,
		/* .abgr = */ 32639,
		/* .timeData = */ {
			/* .lifeTime = */ 0.9f,
			/* .fadeInTime = */ 0.1f,
			/* .fadeOutTime = */ 0.8f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 100.f,
			/* .sizey = */ 100.f,
			/* .screenSizeMax = */ 300.f,
			/* .screenSizeMaxy = */ 300.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 8.f,
				/* [1] = */ 8.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ -1.2f,
				/* [2] = */ -3.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 1.5f,
				/* [1] = */ -0.5f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [28] = */ {
		/* .particleTextureIndex = */ 6,
		/* .blendMode = */ 2,
		/* .number = */ 20,
		/* .abgr = */ 23151,
		/* .timeData = */ {
			/* .lifeTime = */ 1.5f,
			/* .fadeInTime = */ 0.2f,
			/* .fadeOutTime = */ 1.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 40.f,
			/* .sizey = */ 40.f,
			/* .screenSizeMax = */ 2000.f,
			/* .screenSizeMaxy = */ 2000.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.8f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.5f,
				/* [1] = */ 0.5f,
				/* [2] = */ 0.5f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [29] = */ {
		/* .particleTextureIndex = */ 2,
		/* .blendMode = */ 2,
		/* .number = */ 14,
		/* .abgr = */ 19039,
		/* .timeData = */ {
			/* .lifeTime = */ 2.3f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 2.f,
			/* .deltaTime = */ -0.03f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.075f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -17.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 5.f,
				/* [1] = */ 7.f,
				/* [2] = */ 5.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 3.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.7f,
			/* .bounceElasticityY = */ 0.3f
		}
	},
	/* [30] = */ {
		/* .particleTextureIndex = */ 14,
		/* .blendMode = */ 1,
		/* .number = */ 12,
		/* .abgr = */ 16448,
		/* .timeData = */ {
			/* .lifeTime = */ 0.4f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.2f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 15.f,
			/* .sizey = */ 15.f,
			/* .screenSizeMax = */ 100.f,
			/* .screenSizeMaxy = */ 100.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.3f,
				/* [1] = */ 0.3f,
				/* [2] = */ 0.3f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 1.f,
			/* .bounceElasticityY = */ 0.4f
		}
	},
	/* [31] = */ {
		/* .particleTextureIndex = */ 2,
		/* .blendMode = */ 1,
		/* .number = */ 12,
		/* .abgr = */ 16170,
		/* .timeData = */ {
			/* .lifeTime = */ 0.7f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.6f,
			/* .deltaTime = */ -0.06f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.2f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -4.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 2.f,
				/* [1] = */ 3.f,
				/* [2] = */ 2.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 1.4f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 1.f,
			/* .bounceElasticityY = */ 0.4f
		}
	},
	/* [32] = */ {
		/* .particleTextureIndex = */ 2,
		/* .blendMode = */ 2,
		/* .number = */ 12,
		/* .abgr = */ 16191,
		/* .timeData = */ {
			/* .lifeTime = */ 0.7f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.6f,
			/* .deltaTime = */ -0.06f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.2f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -4.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 2.f,
				/* [1] = */ 3.f,
				/* [2] = */ 2.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 1.4f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 1.f,
			/* .bounceElasticityY = */ 0.4f
		}
	},
	/* [33] = */ {
		/* .particleTextureIndex = */ 2,
		/* .blendMode = */ 2,
		/* .number = */ 12,
		/* .abgr = */ 19039,
		/* .timeData = */ {
			/* .lifeTime = */ 0.7f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.6f,
			/* .deltaTime = */ -0.06f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.2f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -4.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 2.f,
				/* [1] = */ 3.f,
				/* [2] = */ 2.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 1.4f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 1.f,
			/* .bounceElasticityY = */ 0.4f
		}
	},
	/* [34] = */ {
		/* .particleTextureIndex = */ 2,
		/* .blendMode = */ 1,
		/* .number = */ 46,
		/* .abgr = */ 6735,
		/* .timeData = */ {
			/* .lifeTime = */ 0.7f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.6f,
			/* .deltaTime = */ -0.1f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.16f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -8.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 6.f,
				/* [1] = */ 4.f,
				/* [2] = */ 4.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.3f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 1.f,
			/* .bounceElasticityY = */ 0.4f
		}
	},
	/* [35] = */ {
		/* .particleTextureIndex = */ 2,
		/* .blendMode = */ 1,
		/* .number = */ 46,
		/* .abgr = */ 16170,
		/* .timeData = */ {
			/* .lifeTime = */ 0.7f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.6f,
			/* .deltaTime = */ -0.1f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.16f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -8.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 6.f,
				/* [1] = */ 4.f,
				/* [2] = */ 4.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.3f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 1.f,
			/* .bounceElasticityY = */ 0.4f
		}
	},
	/* [36] = */ {
		/* .particleTextureIndex = */ 2,
		/* .blendMode = */ 2,
		/* .number = */ 46,
		/* .abgr = */ 16191,
		/* .timeData = */ {
			/* .lifeTime = */ 0.7f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.6f,
			/* .deltaTime = */ -0.1f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.16f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -8.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 6.f,
				/* [1] = */ 4.f,
				/* [2] = */ 4.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.3f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 1.f,
			/* .bounceElasticityY = */ 0.4f
		}
	},
	/* [37] = */ {
		/* .particleTextureIndex = */ 2,
		/* .blendMode = */ 2,
		/* .number = */ 46,
		/* .abgr = */ 19039,
		/* .timeData = */ {
			/* .lifeTime = */ 0.7f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.6f,
			/* .deltaTime = */ -0.1f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.16f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -6.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 6.f,
				/* [1] = */ 4.f,
				/* [2] = */ 4.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.3f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 1.f,
			/* .bounceElasticityY = */ 0.4f
		}
	},
	/* [38] = */ {
		/* .particleTextureIndex = */ 10,
		/* .blendMode = */ 2,
		/* .number = */ 1,
		/* .abgr = */ 32639,
		/* .timeData = */ {
			/* .lifeTime = */ 1.f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.7f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 600.f,
			/* .sizey = */ 250.f,
			/* .screenSizeMax = */ 3000.f,
			/* .screenSizeMaxy = */ 600.f,
			/* .zBias = */ 100.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [39] = */ {
		/* .particleTextureIndex = */ 10,
		/* .blendMode = */ 2,
		/* .number = */ 1,
		/* .abgr = */ 32639,
		/* .timeData = */ {
			/* .lifeTime = */ 4.f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 3.5f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 700.f,
			/* .sizey = */ 150.f,
			/* .screenSizeMax = */ 3000.f,
			/* .screenSizeMaxy = */ 600.f,
			/* .zBias = */ 200.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [40] = */ {
		/* .particleTextureIndex = */ 12,
		/* .blendMode = */ 2,
		/* .number = */ 1,
		/* .abgr = */ 8063,
		/* .timeData = */ {
			/* .lifeTime = */ 0.8f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.5f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 700.f,
			/* .sizey = */ 190.f,
			/* .screenSizeMax = */ 3000.f,
			/* .screenSizeMaxy = */ 600.f,
			/* .zBias = */ 100.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [41] = */ {
		/* .particleTextureIndex = */ 14,
		/* .blendMode = */ 1,
		/* .number = */ 1,
		/* .abgr = */ 24415,
		/* .timeData = */ {
			/* .lifeTime = */ 0.2f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.1f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 50.f,
			/* .sizey = */ 50.f,
			/* .screenSizeMax = */ 60.f,
			/* .screenSizeMaxy = */ 60.f,
			/* .zBias = */ 100.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 3.f,
				/* [1] = */ 3.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [42] = */ {
		/* .particleTextureIndex = */ 8,
		/* .blendMode = */ 2,
		/* .number = */ 7,
		/* .abgr = */ 32543,
		/* .timeData = */ {
			/* .lifeTime = */ 2.3f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 2.f,
			/* .deltaTime = */ -0.03f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.2f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -17.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 5.f,
				/* [1] = */ 7.f,
				/* [2] = */ 5.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 3.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.7f,
			/* .bounceElasticityY = */ 0.3f
		}
	},
	/* [43] = */ {
		/* .particleTextureIndex = */ 8,
		/* .blendMode = */ 2,
		/* .number = */ 7,
		/* .abgr = */ 24383,
		/* .timeData = */ {
			/* .lifeTime = */ 2.3f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 2.f,
			/* .deltaTime = */ -0.03f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.2f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -17.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 5.f,
				/* [1] = */ 7.f,
				/* [2] = */ 5.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 3.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.7f,
			/* .bounceElasticityY = */ 0.3f
		}
	},
	/* [44] = */ {
		/* .particleTextureIndex = */ 8,
		/* .blendMode = */ 2,
		/* .number = */ 7,
		/* .abgr = */ 12095,
		/* .timeData = */ {
			/* .lifeTime = */ 2.3f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 2.f,
			/* .deltaTime = */ -0.03f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.2f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -17.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 5.f,
				/* [1] = */ 7.f,
				/* [2] = */ 5.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 3.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.7f,
			/* .bounceElasticityY = */ 0.3f
		}
	},
	/* [45] = */ {
		/* .particleTextureIndex = */ 8,
		/* .blendMode = */ 2,
		/* .number = */ 7,
		/* .abgr = */ 20351,
		/* .timeData = */ {
			/* .lifeTime = */ 2.3f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 2.f,
			/* .deltaTime = */ -0.03f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.2f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -17.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 5.f,
				/* [1] = */ 7.f,
				/* [2] = */ 5.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 3.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.7f,
			/* .bounceElasticityY = */ 0.3f
		}
	},
	/* [46] = */ {
		/* .particleTextureIndex = */ 8,
		/* .blendMode = */ 2,
		/* .number = */ 7,
		/* .abgr = */ 8063,
		/* .timeData = */ {
			/* .lifeTime = */ 2.3f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 2.f,
			/* .deltaTime = */ -0.03f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.2f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -17.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 5.f,
				/* [1] = */ 7.f,
				/* [2] = */ 5.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 3.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.7f,
			/* .bounceElasticityY = */ 0.3f
		}
	},
	/* [47] = */ {
		/* .particleTextureIndex = */ 8,
		/* .blendMode = */ 2,
		/* .number = */ 17,
		/* .abgr = */ 16170,
		/* .timeData = */ {
			/* .lifeTime = */ 0.f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.3f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [48] = */ {
		/* .particleTextureIndex = */ 8,
		/* .blendMode = */ 2,
		/* .number = */ 17,
		/* .abgr = */ 20319,
		/* .timeData = */ {
			/* .lifeTime = */ 0.f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.3f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [49] = */ {
		/* .particleTextureIndex = */ 8,
		/* .blendMode = */ 2,
		/* .number = */ 17,
		/* .abgr = */ 16170,
		/* .timeData = */ {
			/* .lifeTime = */ 0.f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.3f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [50] = */ {
		/* .particleTextureIndex = */ 8,
		/* .blendMode = */ 2,
		/* .number = */ 17,
		/* .abgr = */ 32639,
		/* .timeData = */ {
			/* .lifeTime = */ 0.75f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.3f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [51] = */ {
		/* .particleTextureIndex = */ 8,
		/* .blendMode = */ 2,
		/* .number = */ 17,
		/* .abgr = */ 14975,
		/* .timeData = */ {
			/* .lifeTime = */ 0.f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.3f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [52] = */ {
		/* .particleTextureIndex = */ 12,
		/* .blendMode = */ 2,
		/* .number = */ 1,
		/* .abgr = */ 14975,
		/* .timeData = */ {
			/* .lifeTime = */ 0.8f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.5f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 700.f,
			/* .sizey = */ 190.f,
			/* .screenSizeMax = */ 3000.f,
			/* .screenSizeMaxy = */ 600.f,
			/* .zBias = */ 100.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.7f,
				/* [1] = */ 0.7f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [53] = */ {
		/* .particleTextureIndex = */ 8,
		/* .blendMode = */ 2,
		/* .number = */ 17,
		/* .abgr = */ 32570,
		/* .timeData = */ {
			/* .lifeTime = */ 0.f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.1f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [54] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 1,
		/* .number = */ 100,
		/* .abgr = */ 32639,
		/* .timeData = */ {
			/* .lifeTime = */ 1.5f,
			/* .fadeInTime = */ 0.25f,
			/* .fadeOutTime = */ 0.25f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 50.f,
			/* .sizey = */ 50.f,
			/* .screenSizeMax = */ 250.f,
			/* .screenSizeMaxy = */ 250.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 1.2f,
				/* [1] = */ 1.2f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 250.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.3f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.3f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.015f,
				/* [1] = */ 0.025f,
				/* [2] = */ 0.015f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [55] = */ {
		/* .particleTextureIndex = */ 2,
		/* .blendMode = */ 2,
		/* .number = */ 7,
		/* .abgr = */ 16383,
		/* .timeData = */ {
			/* .lifeTime = */ 2.3f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 2.f,
			/* .deltaTime = */ -0.03f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.1f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -17.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 3.f,
				/* [1] = */ 3.f,
				/* [2] = */ 3.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 1.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.7f,
			/* .bounceElasticityY = */ 0.6f
		}
	},
	/* [56] = */ {
		/* .particleTextureIndex = */ 2,
		/* .blendMode = */ 2,
		/* .number = */ 7,
		/* .abgr = */ 19039,
		/* .timeData = */ {
			/* .lifeTime = */ 2.3f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 2.f,
			/* .deltaTime = */ -0.03f
		},
		/* .sizeData = */ {
			/* .size = */ 0.f,
			/* .sizey = */ 0.f,
			/* .screenSizeMax = */ 0.f,
			/* .screenSizeMaxy = */ 0.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.1f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 0.f,
			/* .gravity = */ -17.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 3.f,
				/* [1] = */ 3.f,
				/* [2] = */ 3.f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 1.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.7f,
			/* .bounceElasticityY = */ 0.6f
		}
	},
	/* [57] = */ {
		/* .particleTextureIndex = */ 0,
		/* .blendMode = */ 1,
		/* .number = */ 10,
		/* .abgr = */ 20303,
		/* .timeData = */ {
			/* .lifeTime = */ 5.f,
			/* .fadeInTime = */ 0.5f,
			/* .fadeOutTime = */ 3.f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 500.f,
			/* .sizey = */ 500.f,
			/* .screenSizeMax = */ 250.f,
			/* .screenSizeMaxy = */ 250.f,
			/* .zBias = */ 100.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.4f,
				/* [1] = */ 0.4f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 0.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 0.5f,
				/* [1] = */ 0.6f,
				/* [2] = */ 0.5f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 1.f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.015f,
				/* [1] = */ 0.03f,
				/* [2] = */ 0.015f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [58] = */ {
		/* .particleTextureIndex = */ 3,
		/* .blendMode = */ 2,
		/* .number = */ 100,
		/* .abgr = */ 25941,
		/* .timeData = */ {
			/* .lifeTime = */ 0.5f,
			/* .fadeInTime = */ 0.f,
			/* .fadeOutTime = */ 0.2f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 15.f,
			/* .sizey = */ 50.f,
			/* .screenSizeMax = */ 200.f,
			/* .screenSizeMaxy = */ 600.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ -20.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 2.5f,
				/* [1] = */ 1.f,
				/* [2] = */ 2.5f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ -0.5f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	},
	/* [59] = */ {
		/* .particleTextureIndex = */ 3,
		/* .blendMode = */ 2,
		/* .number = */ 100,
		/* .abgr = */ 25941,
		/* .timeData = */ {
			/* .lifeTime = */ 0.5f,
			/* .fadeInTime = */ 0.2f,
			/* .fadeOutTime = */ 0.45f,
			/* .deltaTime = */ 0.f
		},
		/* .sizeData = */ {
			/* .size = */ 12.f,
			/* .sizey = */ 40.f,
			/* .screenSizeMax = */ 200.f,
			/* .screenSizeMaxy = */ 600.f,
			/* .zBias = */ 0.f,
			/* .aspect = */ 0.f,
			/* .expansionRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f
			}
		},
		/* .moveData = */ {
			/* .rotation = */ 70.f,
			/* .gravity = */ 20.f,
			/* .velocity = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .velocityRandom = */ {
				/* [0] = */ 2.5f,
				/* [1] = */ 1.f,
				/* [2] = */ 2.5f
			},
			/* .velocityBias = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.5f,
				/* [2] = */ 0.f
			},
			/* .trailDispersalRate = */ {
				/* [0] = */ 0.f,
				/* [1] = */ 0.f,
				/* [2] = */ 0.f
			},
			/* .bounceElasticityXZ = */ 0.f,
			/* .bounceElasticityY = */ 0.f
		}
	}
};

tracerDef tracerDefs[1] = {
	/* [0] = */ {
		/* .colour = */ 65535,
		/* .particleTextureIndex = */ 11,
		/* .lengthFP = */ 0.55f,
		/* .lengthTP = */ 0.8f,
		/* .screenWidthFP = */ 30.f,
		/* .screenWidthTP = */ 30.f
	}
};

pulseDef pulseDefs[0] = {
};

static particlegroup *particleGroups = NULL;
static particlegroup *freeParticleGroups = NULL;
float particleNumScale = 0.f;

int particleTextureNum[18] = {
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
	/* [17] = */ 0
};

int impactExplosionTextureNum[8] = {
	/* [0] = */ 0,
	/* [1] = */ 0,
	/* [2] = */ 0,
	/* [3] = */ 0,
	/* [4] = */ 0,
	/* [5] = */ 0,
	/* [6] = */ 0,
	/* [7] = */ 0
};

static particlegroup *usedParticleGroups[27];
static int usedParticleGroupSizes[27];
float particleSizeScale = 0.f;

int particleGetTextureNum(int particleTexture) {}

void particlePreload() {
	int t;
}

void particleRestart() {
	int i;
	int t;
	int e;
}

void particleReset() {}

void particleEnd() {}

void particlePrintList(particlegroup *list) {}

void particlePrintSizes() {
	int i;
}

void particleFree(particlegroup *pg) {}

particlegroup* particleGetLastInUsedList(int type) {
	particlegroup *pg;
}

void particleDebug() {}

static particlegroup* particleGetGroup(int type, boolean allocateData) {
	particlegroup *pg;
	int tmptype;
}

void particleSetClones(particlegroup *pg, particleClone *clones) {}

void particleSetViewmask(particlegroup *pg, int viewMask) {}

void particleSetDelay(particlegroup *pg, float delay) {}

void particleUpdateVelocity(particlegroup *pg, float *velocity) {}

void particleUpdateVelocityRandom(particlegroup *pg, float *velocityRandom) {}

void particleUpdateVelocityBias(particlegroup *pg, float *velocityBias) {}

void particleUpdateRate(particlegroup *pg, float ratePerSecond) {}

void particleUpdatePos(particlegroup *pg, float *pos) {}

void particleMoveSpriteStream(particlegroup *pg, float *pos) {
	spriteStreamData *sd;
	int i;
	float moved[3];
}

void particleUpdateGroundHeight(particlegroup *pg, float groundHeight) {}

boolean particleIsTrailFull(particlegroup *pg) {
	particleInfo *pi;
}

boolean particleGroupIsVisible(particlegroup *pg, int flag) {}

boolean particleCloneIsVisible(particlegroup *pg, particleClone *clone, int flag) {}

particlegroup* particleNewBulletSparks(void *ref, float *startpos, float *bias) {
	int i;
	particlegroup *pg;
	bulletSparkData *sd;
	float vel0;
	float vel1;
	float vel0sq;
	float vel1sq;
	float hidist0;
	float hidist1;
	float halfatsq;
	float lodist0;
	float lodist1;
}

particlegroup* particleNewSpriteSparks(void *ref, int type, float *startpos, float *bias) {
	int i;
	particlegroup *pg;
	spriteSparkData *ssd;
}

particlegroup* particleNewBlastExplosion(void *ref, int explosionrendertype, float *startpos, u32 colour, float size) {
	int i;
	float scale;
	particlegroup *pg;
	blastExplosionData *ed;
	float rotSpeedDeg;
	float rotSpeedDeg;
}

void particleBlastExplosionTick(particlegroup *pg) {}

static void particleBlastExplosionGfx(particlegroup *pg) {
	blastExplosionData *ed;
	int texture;
	int texwidth;
	int texheight;
	int i;
	int numsofar;
	u32 *startref;
	u32 col;
	u32 alpha;
	float pos[3];
	float newpos[4];
	float newpos3extended;
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	int size;
	int s;
	int c;
	float thistime;
	u32 *ref;
	float scale;
	float alphascale;
	u32 thisalpha;
	float rot;
	void *addr;
	void *addr;
	float pos[3];
	float newpos[4];
	float newpos3extended;
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	int size;
	int s;
	int c;
	float thistime;
	u32 *ref;
	float scale;
	float alphascale;
	u32 thisalpha;
	float rot;
	void *addr;
	void *addr;
}

particlegroup* particleNewImpactExplosion(void *ref, int explosionrendertype, float *startpos, u32 colour, float size) {
	particlegroup *pg;
	impactExplosionData *ed;
}

void particleImpactExplosionTick(particlegroup *pg) {}

static void particleImpactExplosionGfx(particlegroup *pg) {
	impactExplosionData *ed;
	u32 col;
	u32 alpha;
	int layer;
	float time;
	float timeScalar;
	float pos[3];
	float newpos[4];
	float newpos3extended;
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	float sizePerspect;
	int s;
	int c;
	float alphascale;
	float texAnimf;
	int texAnim;
	int texture[2];
	float blend[2];
	float contrastAmount;
	int texwidth;
	int texheight;
	u32 abgr;
}

particlegroup* particleNewBulletSmoke(void *ref, float *startpos) {
	int i;
	particlegroup *pg;
	bulletSmokeData *sd;
}

particlegroup* particleNewPulse(void *ref, int type, float *startpos, float *dir, int viewMask) {
	particlegroup *pg;
	pulseData *pd;
	int t;
}

particlegroup* particleNewTracer(void *ref, int subtype, float *pos, float *dir, int viewMask) {
	particlegroup *pg;
	tracerData *td;
}

void particleTracerTick(particlegroup *pg) {
	float secpassed;
	tracerData *td;
	float dist;
}

particlegroup* particleNewSpriteTrail(void *ref, int particleID, int flags, float *pos) {
	particlegroup *pg;
	particleInfo *pi;
	int particleType;
	float lowVelX;
	float upVelX;
	float lowVelZ;
	float upVelZ;
	float vel0Y;
	float vel1Y;
	float vel0Ysq;
	float vel1Ysq;
	float gravityM2Inv;
	float hidist0;
	float hidist1;
	float totalTime;
	float halfatsq;
	float lodist0;
	float lodist1;
}

particlegroup* particleNewSpriteManual(void *ref, int particleID, int flags, float *pos) {
	particlegroup *pg;
	particleInfo *pi;
	int particleType;
}

particlegroup* particleNewSpriteBurst(void *ref, int particleID, int flags, float *pos, float *velocityBias, float groundHeight) {
	int i;
	particlegroup *pg;
	int particleType;
	spriteBurstData *bd;
	particleInfo *pi;
	float loVelX;
	float upVelX;
	float loVelY;
	float upVelY;
	float loVelZ;
	float upVelZ;
	float totalTime;
	float gravityDist;
	float minGravityDist;
	float maxGravityDist;
	float loDistX;
	float upDistX;
	float loDistY;
	float upDistY;
	float loDistZ;
	float upDistZ;
	float lowestHeight;
}

particlegroup* particleNewSpriteStream(void *ref, int particleID, int flags, float *pos, float *velocity, float *velocityRandom, float *velocityBias, float groundHeight) {
	particlegroup *pg;
	int particleType;
	spriteStreamData *sd;
	particleInfo *pi;
	float loVelX;
	float upVelX;
	float loVelY;
	float upVelY;
	float loVelZ;
	float upVelZ;
	float totalTime;
	float gravityDist;
	float minGravityDist;
	float maxGravityDist;
	float loDistX;
	float upDistX;
	float loDistY;
	float upDistY;
	float loDistZ;
	float upDistZ;
	float lowestHeight;
}

particlegroup* particleNewSparkBurst(void *ref, int particleID, int flags, float *pos, float *velocityBias, float groundHeight) {
	int i;
	particlegroup *pg;
	int particleType;
	sparkBurstData *sd;
	particleInfo *pi;
	float loVelX;
	float upVelX;
	float vel0Y;
	float vel1Y;
	float loVelZ;
	float upVelZ;
	float vel0Ysq;
	float vel1Ysq;
	float gravityM2Inv;
	float hidist0;
	float hidist1;
	float totalTime;
	float halfatsq;
	float lodist0;
	float lodist1;
	float loDistX;
	float upDistX;
	float loDistY;
	float upDistY;
	float loDistZ;
	float upDistZ;
	float lowestHeight;
}

particlegroup* particleNewSparkStream(void *ref, int particleID, int flags, float *pos, float *velocityBias, float groundHeight) {
	particlegroup *pg;
	int particleType;
	sparkStreamData *sd;
	particleInfo *pi;
	float loVelX;
	float upVelX;
	float vel0Y;
	float vel1Y;
	float loVelZ;
	float upVelZ;
	float vel0Ysq;
	float vel1Ysq;
	float gravityM2Inv;
	float hidist0;
	float hidist1;
	float totalTime;
	float halfatsq;
	float lodist0;
	float lodist1;
	float loDistX;
	float upDistX;
	float loDistY;
	float upDistY;
	float loDistZ;
	float upDistZ;
	float lowestHeight;
}

particlegroup* particleNewStripTrail(void *ref, int particleID, int flags, float *pos) {
	particlegroup *pg;
	particleInfo *pi;
	int particleType;
	stripTrailData *td;
}

void particleStripTrailTick(particlegroup *pg) {
	particleInfo *pi;
	stripTrailData *td;
	int currentparticlei;
	int newpoints;
	int mostrecent;
	boolean found;
	float secpassed;
	float lifetime;
	float newPointIndex;
	int newPointIndexI;
	float normal[3];
	float dir[3];
	float leninv;
	float up[3];
	int oldestparticle;
	float time;
}

static void particleStripTrailGfx(particlegroup *pg) {
	stripTrailData *td;
	particleInfo *pi;
	int texture;
	u32 col;
	u32 alpha;
	float lifetime;
	float overallFade;
	int extraPoint;
	int startparticle;
	int a;
	u32 *ref;
	u32 *xyzwRef;
	u32 *stqRef;
	int totalPoints;
	int quadWordSize;
	int num;
	emTexture *pTex;
	void *addr;
	int qwc;
	void *addr;
	int i;
	float axis1[3];
	float axis2[3];
	float *axptr1;
	float *axptr2;
	float angle;
	float cosangle;
	float sinangle;
	float cosRadius;
	float sinRadius;
	boolean firstPoint;
	int particle;
	float *thispos;
	float *nextpos;
	float pos1[3];
	float pos2[3];
	float timeScalar;
	float alphaScalar;
	float fadeScalar;
	u32 abgr;
	float normal[3];
	float dir[3];
	float leninv;
	float up[3];
	int nextparticle;
}

particlegroup* particleNewStraightTrail(void *ref, int particleID, int flags, float *pos, float *dir) {
	particlegroup *pg;
	straightTrailData *td;
	int particleType;
	particleInfo *pi;
	float normal[3];
	float leninv;
	float up[3];
}

void particleStraightTrailTick(particlegroup *pg) {
	straightTrailData *td;
	particleInfo *pi;
	int currentparticlei;
	int newpoints;
	int mostrecent;
	boolean found;
	float secpassed;
	float lifetime;
	float newPointIndex;
	int newPointIndexI;
	int oldestparticle;
	float time;
}

void particleStraightTrailGfx(particlegroup *pg) {
	straightTrailData *td;
	particleInfo *pi;
	int texture;
	float lifetime;
	float overallFade;
	u32 alpha;
	u32 col;
	int extraPoint;
	int startparticle;
	int a;
	u32 *ref;
	u32 *xyzwRef;
	u32 *stqRef;
	int totalPoints;
	int quadWordSize;
	int num;
	emTexture *pTex;
	void *addr;
	int qwc;
	void *addr;
	int i;
	float angle;
	float cosangle;
	float sinangle;
	float cosRadius;
	float sinRadius;
	boolean firstPoint;
	int particle;
	float *thispos;
	float pos1[3];
	float pos2[3];
	float timeScalar;
	float alphaScalar;
	float fadeScalar;
	u32 abgr;
	int nextparticle;
}

void glassSetQuad(glassData *gd, int trianglenum, glasspointdef *point1, glasspointdef *point2, glasspointdef *point3, glasspointdef *point4, float *dir1, float *dir2, float *vertice1, float *vertice2, float *vertice3, float *vertice4, float *hitpos, float *smashamount, float *averageline, int endpiece, int flags) {
	float *vertice1;
	float *averageline;
	int flags;
	float scalarpos[2];
	float verticeadj1[2];
	float verticeadj2[2];
	float verticeadj3[2];
	float verticeadj4[2];
	float verticew1[3];
	float verticew2[3];
	float verticew3[3];
	float verticew4[3];
	float center[3];
	float stdiff1[2];
	float stdiff2[2];
	float bi1;
	float bi2;
	float distfromhit[3];
	float distance;
	float distmove;
	float distrot[2];
	float distexp;
}

particlegroup* particleNewGlass(void *pgref, int flags, int texnum, int reflect, float *velocity, glasspointdef *point1, glasspointdef *point2, glasspointdef *point3, glasspointdef *point4, float *hitpos, float *smashdir, float amount, float *specialcol, float *hitnorm) {
	float *hitpos;
	float *smashdir;
	float *hitnorm;
	int i;
	float dir1[3];
	float dir2[3];
	float smashnorm[3];
	float ismashdirlength;
	float smashamount[3];
	particlegroup *pg;
	glassData *gd;
	float dot;
	float destpos[16][2];
	float linedir[16][2];
	int shards;
	int nexts;
	int next;
	float averageline[2];
	float vertice1[2];
	float vertice2[2];
	float vertice3[2];
	float vertice4[2];
	float rot;
	float cosrot;
	float sinrot;
	float cosrotnext;
	float sinrotnext;
	float scalarpoint1;
	float scalarpoint2;
	float scalarpoint3;
	float scalarpoint4;
	float scalarpoint6;
	float scalarpoint8;
	int t;
}

particlegroup* particleNewSprite(void *ref, int particleID, int flags, float *pos, float *normal) {
	particlegroup *pg;
	particleInfo *pi;
	spriteData *sd;
	float up[3];
	float right[3];
}

particlegroup* particleNewGlow(void *ref, int particleID, int flags, float *pos, float *dir, int viewMask) {
	particlegroup *pg;
	particleInfo *pi;
	glowData *gd;
}

void particleGlowTick(particlegroup *pg) {
	glowData *gd;
}

void particleGlowGfx(particlegroup *pg) {
	particleInfo *pi;
	int texture;
	float scrpos[3];
	float q;
	float sizePerspectx;
	float sizePerspecty;
	float newpos[4];
	float size;
}

void particleSpriteTrailTick(particlegroup *pg) {
	int i;
	int newpoints;
	spriteTrailData *td;
	particleInfo *pi;
	float rateinterval;
	float currentinterval;
	float newpointsf;
}

void particleSpriteManualTick(particlegroup *pg) {}

void particleSpriteBurstTick(particlegroup *pg) {
	int i;
	spriteBurstData *bd;
	particleInfo *pi;
}

void particleSpriteStreamTick(particlegroup *pg) {
	spriteStreamData *sd;
	int cparticle;
	int lastparticle;
	int i;
	float secpassed;
	particleInfo *pi;
}

void particleSparkBurstTick(particlegroup *pg) {
	int i;
	sparkBurstData *sd;
	particleInfo *pi;
	float secpassed;
}

void particleSparkStreamTick(particlegroup *pg) {
	sparkStreamData *sd;
	int cparticle;
	int lastparticle;
	int i;
	float secpassed;
	particleInfo *pi;
}

void particleGlassTick(particlegroup *pg) {
	int i;
	int t;
	glassData *gd;
	float secpassed;
	float x;
	float y;
	float z;
	float scalar;
	u32 alpha;
}

void particleTick() {
	int type;
	int rIndex;
	particlegroup *pg;
	float secpassed;
	particleClone *clone;
	int i;
	ViewDef *pView;
	int i;
	ViewDef *pView;
	int t;
	pulseData *pd;
}

static void particleBulletSparkGroupGfx(particlegroup *pg, int flag) {
	int texture;
	int texwidth;
	int texheight;
	u32 col;
	float nexttime;
	float halfatsquared;
	float nexthalfatsquared;
	int i;
	int numsofar;
	u32 *startref;
	bulletSparkData *sd;
	u32 abgr;
	float pos1[3];
	float pos2[3];
	float newpos1[4];
	float newpos2[4];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q1;
	float q2;
	float dx;
	float dy;
	u32 *ref;
	void *addr;
	void *addr;
}

static void particleSpriteSparkGfx(particlegroup *pg) {
	spriteSparkData *ssd;
	int texture;
	u8 alpha;
	u32 col;
	float halfatsquared;
	int i;
	float scale;
	int curnum;
	int mod;
	u32 *ref;
	int num;
	emTexture *pTex;
	void *addr;
	int qwc;
	void *addr;
}

static void particleBulletSmokeGroupGfx(particlegroup *pg, int flag) {
	int i;
	int texture;
	u32 col;
	bulletSmokeData *sd;
	u32 *pos;
	int num;
	float time;
	float posrot;
	float alphascale;
	int thisnum;
	u32 *ref;
	int num;
	emTexture *pTex;
	void *addr;
	int qwc;
	void *addr;
}

static void particleTracerGfx(particlegroup *pg) {
	tracerData *td;
	tracerDef *def;
	float pos1[3];
	float pos2[3];
	float newpos1[4];
	float newpos2[4];
	float scr1[3];
	float scr2[3];
	float q1;
	float q2;
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float dx;
	float dy;
	float ndx;
	float ndy;
	float rlen;
	float size1;
	float size2;
	float np13scaled;
	float np23scaled;
	u32 *ref;
	u32 col;
	boolean thirdPerson;
	float length;
	float tracerScreenWidth;
	void *addr;
}

static void particlePulseGfx(particlegroup *pg) {
	pulseData *pulse;
	u32 col;
	int particleTexture;
	int texwidth;
	int texheight;
	int i;
	float pos[3];
	float newpos[4];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	int size;
	u32 *ref;
	float s;
	float c;
	float rot;
	void *addr;
}

static void particleSpriteTrailGfx(particlegroup *pg) {
	spriteTrailData *td;
	particleInfo *pi;
	int texture;
	int texwidth;
	int texheight;
	int i;
	int numsofar;
	u32 *ref;
	u32 *startref;
	u32 col;
	u32 alpha;
	float pos[3];
	float newpos[4];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	float time;
	float rottime;
	float posrot;
	float alphascale;
	u32 abgr;
	float sinrot;
	float cosrot;
	float scale;
	int sizex;
	int sizey;
	int maxSize;
	void *addr;
	void *addr;
}

static void particleSpriteBurstGfx(particlegroup *pg, mtx_u *matrix) {
	spriteBurstData *bd;
	particleInfo *pi;
	int texture;
	int texwidth;
	int texheight;
	int i;
	int numsofar;
	u32 *ref;
	u32 *startref;
	u32 col;
	u32 alpha;
	float time;
	float alphascale;
	u32 abgr;
	float pos[3];
	float newpos[4];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	float scale;
	int sizex;
	int sizey;
	float sinrot;
	float cosrot;
	float rottime;
	int maxSize;
	void *addr;
	void *addr;
}

static void particleSpriteStreamGfx(particlegroup *pg, mtx_u *matrix) {
	spriteStreamData *sd;
	particleInfo *pi;
	int texture;
	int texwidth;
	int texheight;
	int i;
	int numsofar;
	u32 *ref;
	u32 *startref;
	u32 col;
	u32 alpha;
	float pos[3];
	float newpos[4];
	float newpos3extended;
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	float time;
	float alphascale;
	u32 abgr;
	float sinrotx;
	float cosrotx;
	float sinroty;
	float cosroty;
	float rottime;
	float sinamount;
	float cosamount;
	float scalex;
	float scaley;
	int sizex;
	int sizey;
	int maxSize;
	void *addr;
	void *addr;
}

static void particleSpriteManualGfx(particlegroup *pg, mtx_u *matrix) {
	mtx_u newmat;
	spriteManualData *md;
	particleInfo *pi;
	int texture;
	int texwidth;
	int texheight;
	int i;
	int numsofar;
	u32 *ref;
	u32 *startref;
	float pos[3];
	float newpos[4];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	float time;
	float alphascale;
	float rottime;
	u32 col;
	u32 alpha;
	u32 abgr;
	float sinrot;
	float cosrot;
	float scale;
	int sizex;
	int sizey;
	int maxSize;
	void *addr;
	void *addr;
}

void particleSparkBurstGfx(particlegroup *pg, mtx_u *matrix) {
	sparkBurstData *sd;
	particleInfo *pi;
	int texture;
	int texwidth;
	int texheight;
	int i;
	int numsofar;
	float aspect;
	u32 *ref;
	u32 *startref;
	u32 alpha;
	u32 col;
	u32 abgr;
	float newpos1[4];
	float newpos2[4];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q1;
	float q2;
	float dx;
	float dy;
	void *addr;
	void *addr;
}

void particleSparkStreamGfx(particlegroup *pg, mtx_u *matrix) {
	sparkStreamData *sd;
	particleInfo *pi;
	int texture;
	int texwidth;
	int texheight;
	int i;
	int numsofar;
	float aspect;
	u32 *ref;
	u32 *startref;
	u32 alpha;
	u32 col;
	float newpos1[4];
	float newpos2[4];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q1;
	float q2;
	float time;
	float dx;
	float dy;
	u32 abgr;
	void *addr;
	void *addr;
}

void particleDraw(int texwidth, int texheight, u32 abgr, float *scrpos1, float *scrpos2, float *scrpos3, float *scrpos4) {
	u32 *ref;
	void *addr;
}

void particleRender(int texture, float *passpos, float size, float rot, u32 abgr) {
	float pos[3];
	float newpos[4];
	float newpos3extended;
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	float sinamount;
	float cosamount;
	float sinrot;
	float cosrot;
	float scale;
}

static void particleGlassGfx(particlegroup *pg) {
	int i;
	glassData *gd;
	u32 *ref;
	mtx_u *finalmtx;
	void *addr;
	int num;
	emTexture *pTex;
	void *addr;
	void *addr;
	u32 vif1;
}

void particleSpriteGfx(particlegroup *pg) {
	particleInfo *pi;
	spriteData *sd;
	int texture;
	int texwidth;
	int texheight;
	u32 abgr;
	float alphascale;
	float posTL[3];
	float posTR[3];
	float posBL[3];
	float posBR[3];
	float axisRightSize[3];
	float axisUpSize[3];
	float rad;
	float si;
	float co;
	float sizex;
	float sizey;
	float scrpos[3];
	float scrpos1[3];
	float scrpos2[3];
	float scrpos3[3];
	float scrpos4[3];
	float q;
	float sizePerspectx;
	float sizePerspecty;
	float newpos[4];
	float size;
}

void particleBeamGfx(float *startpos, float *normal, float *axis1, float *axis2, float length, float radius, float angle, u32 abgr, float *fadeScalarArray) {
	int particleTexture;
	int a;
	int n;
	u32 *ref;
	u32 *xyzwRef;
	u32 *stqRef;
	int totalPoints;
	int quadWordSize;
	int num;
	emTexture *pTex;
	void *addr;
	int qwc;
	void *addr;
	float cosRadius;
	float sinRadius;
	float rightangle;
	float pos1[3];
	float pos2[3];
	float pos[3];
	float scalar;
	u32 finalAbgr;
}

void particleGfx() {
	int oldzbmode;
	int flag;
	particlegroup *pg;
	void *addr;
	particleClone *clone;
	mtx_u matrix;
	particleClone *clone;
	mtx_u matrix;
	particleClone *clone;
	mtx_u matrix;
	particleClone *clone;
	mtx_u matrix;
	particleClone *clone;
	mtx_u matrix;
	particleClone *clone;
	mtx_u matrix;
	particleClone *clone;
	mtx_u matrix;
	particleClone *clone;
	mtx_u matrix;
	particleClone *clone;
	mtx_u matrix;
	particleClone *clone;
	mtx_u matrix;
	int e;
}

void particleGetClosestLight(obinst *inst, int InstID, float *pos, int PosRoom, bglighttest **Lights) {
	static bglighttest LightTest[6];
	bglighttest *pLightTest[5];
	bglighttest *pTest;
	int i;
	int FrameID;
	particlegroup *pg;
	particlegroup *pg;
	particlegroup *pg;
	particlegroup *pg;
	float Scale;
	u32 Col;
	float Frac;
	float RDist;
	impactExplosionData *ed;
	float ThisTime;
	blastExplosionData *ed;
	int b;
	float ThisTime;
}

void fxBBGfx(float *pos, float *bb[3]) {
	int oldzbmode;
	float v1[3];
	float v2[3];
	float v3[3];
	float v4[3];
	float v5[3];
	float v6[3];
	float v7[3];
	float v8[3];
	mtx_u *pView;
}
