// STATUS: NOT STARTED

#include "hittest.h"

float hittestMoveCircleToPoint(float cx, float cy, float cr, float dx, float dy, float px, float py, float *hitnorm) {
	float vd;
	float pd;
	float vx;
	float vy;
	float Len;
}

float hittestMoveCircleToLine(float cx, float cy, float cr, float dx, float dy, float ax, float ay, float bx, float by, float *hitnorm) {
	float dlen1;
	float ex;
	float ey;
	float elensq;
	float ClosestPoint;
	float dist;
	float dist1;
	float dist2;
	float hn2[3];
	float elen;
	float enormx;
	float enormy;
}

float hittestMoveCircleToCircle(float c1x, float c1y, float c1r, float dx, float dy, float c2x, float c2y, float c2r, float *HitNorm) {
	float dlen;
	float Dist;
}

int hittestBoxBox(float *b1min, float *b1max, float *b2min, float *b2max) {}

int hittestLineBox(float *point, float *dir, float *bmin, float *bmax) {
	float xdir;
	float x1dist;
	float x2dist;
	float x1temp;
	float x2temp;
	float ydir;
	float y1dist;
	float y2dist;
	float y1temp;
	float y2temp;
	float zdir;
	float z1dist;
	float z2dist;
	float z1temp;
	float fartemp;
	float fardist;
	float fardir;
	float neardist;
	float neardir;
	float temp;
	float temp;
	float temp;
}

int hittestLineTri(float *point, float *dir, float *v1, float *v2, float *v3, float *hitpos, float *hitnorm) {
	float d1[3];
	float d2[3];
	float abc[3];
	float pos[3];
	float cp1[3];
	float cp2[3];
	float denom;
	float m;
	float d;
}

int hittestLinePoly(float *point, float *dir, float DirSq, float MaxDistSq, float *pVertex, ColPoly *pPoly, boolean SingleSided, float *hitpos) {
	float denom;
	float m;
	int i;
	float *v1;
	float *v2;
	int x;
	int y;
	int z;
	float posx;
	float posy;
}

int hittestLineCyl(float cx, float cy, float cz, float cr, float ch, float dx, float dy, float dz, float px, float py, float pz, float *hitpos, float *hitnorm) {
	float px;
	float py;
	float pz;
	float vd;
	float pd;
	float vx;
	float vz;
	float rdlen2d;
	float p1;
	float p2;
	float h1;
	float h2;
	int o1;
	int o2;
}

boolean HitTestLineCylinder(float *LinePoint, float *LineDirection, float *CylinderStart, float *CylinderEnd, float CylinderRadiusSquared, float *HitPos, float *HitNorm) {
	float LC[3];
	float d;
	float t;
	float s;
	float n[3];
	float D[3];
	float O[3];
	float ln;
	float CylinderAxis[3];
	float In;
	float Out;
	float frac;
	float d2;
	float InvCylinderAxis[3];
	float TmpHitPos[3];
	float TmpHitPos1[3];
	float Vector[3];
	float Vector1[3];
	float InvCylinderAxis[3];
	float d1;
	float frac;
	float AxisHitPos[3];
}

boolean HitTestLineSphere(float *LinePoint, float *LineDirection, float *SphereCenter, float SphereRadiusSquared, float *HitPos, float *HitNorm) {
	float Vector[3];
	float bsq;
	float u;
	float disc;
	float TmpHitPos[3];
	float t;
}

boolean HitTestLineBox(float *LinePoint, float *LineDirection, float *BoxMin, float *BoxMax, float *HitPos, float *HitNorm) {
	boolean Inside;
	int Quadrant[3];
	int i;
	int WhichPlane;
	float MaxT[3];
	float CandidatePlane[3];
	float Hit[3];
	float *pHitPos;
}

float HitTestDistancePointToLineSquared(float *Point, float *LinePoint, float *LineDirection, float *LineNearestPos) {
	float Vector[3];
	float LineDist[3];
	float t;
}

float HitTestDistancePointToLineSegmentSquared(float *Point, float *LinePoint1, float *LinePoint2, float *LineNearestPos) {
	float Vector[3];
	float LineDirection[3];
	float t;
	float DirectionSize;
}

float HitTestDistanceLineSegmentToPlane(float *LinePoint1, float *LinePoint2, float *PlanePoint, float *PlaneNormal, float *LineNearestPos, float *PlaneNearestPos) {
	float Vector[3];
	float Dist1;
	float Dist2;
	boolean Nearest1;
	boolean Nearest2;
	float Dist;
	float Intersect[3];
}

float HitTestDistanceLineSegmentToLineSegmentSquared(float *Line1Point1, float *Line1Point2, float *Line2Point1, float *Line2Point2, float *Line1NearestPos, float *Line2NearestPos) {
	float Diff[3];
	float Line1Direction[3];
	float Line2Direction[3];
	float A00;
	float A01;
	float A11;
	float B0;
	float C;
	float Det;
	float B1;
	float S;
	float T;
	float SqrDist;
	float Tmp;
	float InvDet;
}

boolean hittestDistGlass(float *point, float *dir, float maxdistsq, glasspointdef *glassPoints, int numPoints, float *hitpos, float *hitnorm) {
	float d1[4];
	float d2[4];
	float pos[3];
	float cp1[4];
	float cp2[4];
	float denom;
	float m;
	float d;
	int i;
	float *v1;
	float *v2;
	float norm[3];
	float frac;
}
