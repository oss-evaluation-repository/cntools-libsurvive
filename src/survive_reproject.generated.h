 // NOTE: Auto-generated code; see tools/generate_reprojection_functions 
#include <math.h>
static inline void gen_reproject_jac_obj_p(FLT* out, const FLT *obj, const FLT *sensor, const FLT *lh, FLT phase_scale, FLT phase_0, FLT phase_1, FLT tilt_scale, FLT tilt_0, FLT tilt_1, FLT curve_scale, FLT curve_0, FLT curve_1, FLT gib_scale, FLT gibPhase_0, FLT gibPhase_1, FLT gibMag_0, FLT gibMag_1) {
	FLT obj_px = *(obj++);
	FLT obj_py = *(obj++);
	FLT obj_pz = *(obj++);
	FLT obj_qw = *(obj++);
	FLT obj_qi = *(obj++);
	FLT obj_qj = *(obj++);
	FLT obj_qk = *(obj++);
	FLT sensor_x = *(sensor++);
	FLT sensor_y = *(sensor++);
	FLT sensor_z = *(sensor++);
	FLT lh_px = *(lh++);
	FLT lh_py = *(lh++);
	FLT lh_pz = *(lh++);
	FLT lh_qw = *(lh++);
	FLT lh_qi = *(lh++);
	FLT lh_qj = *(lh++);
	FLT lh_qk = *(lh++);
	FLT x0 = tan(tilt_0*tilt_scale);
	FLT x1 = lh_qi*lh_qj;
	FLT x2 = lh_qk*lh_qw;
	FLT x3 = x1 - x2;
	FLT x4 = (lh_qi * lh_qi);
	FLT x5 = (lh_qj * lh_qj);
	FLT x6 = x4 + x5;
	FLT x7 = (lh_qk * lh_qk);
	FLT x8 = sqrt((lh_qw * lh_qw) + x6 + x7);
	FLT x9 = lh_qi*lh_qk;
	FLT x10 = lh_qj*lh_qw;
	FLT x11 = x10 + x9;
	FLT x12 = 2*lh_px*x8;
	FLT x13 = lh_qj*lh_qk;
	FLT x14 = lh_qi*lh_qw;
	FLT x15 = x13 - x14;
	FLT x16 = 2*lh_py*x8;
	FLT x17 = 2*x8;
	FLT x18 = x17*x6 - 1;
	FLT x19 = obj_qi*obj_qk;
	FLT x20 = obj_qj*obj_qw;
	FLT x21 = sensor_z*(x19 + x20);
	FLT x22 = (obj_qi * obj_qi);
	FLT x23 = (obj_qj * obj_qj);
	FLT x24 = x22 + x23;
	FLT x25 = (obj_qk * obj_qk);
	FLT x26 = sqrt((obj_qw * obj_qw) + x24 + x25);
	FLT x27 = 2*x26;
	FLT x28 = obj_qi*obj_qj;
	FLT x29 = obj_qk*obj_qw;
	FLT x30 = sensor_y*(x28 - x29);
	FLT x31 = x23 + x25;
	FLT x32 = obj_px - sensor_x*(x27*x31 - 1) + x21*x27 + x27*x30;
	FLT x33 = 2*x32*x8;
	FLT x34 = sensor_x*(x28 + x29);
	FLT x35 = obj_qj*obj_qk;
	FLT x36 = obj_qi*obj_qw;
	FLT x37 = sensor_z*(x35 - x36);
	FLT x38 = x22 + x25;
	FLT x39 = obj_py - sensor_y*(x27*x38 - 1) + x27*x34 + x27*x37;
	FLT x40 = 2*x39*x8;
	FLT x41 = sensor_y*(x35 + x36);
	FLT x42 = sensor_x*(x19 - x20);
	FLT x43 = obj_pz - sensor_z*(x24*x27 - 1) + x27*x41 + x27*x42;
	FLT x44 = lh_pz*x18 - x11*x12 + x11*x33 - x15*x16 + x15*x40 - x18*x43;
	FLT x45 = 1.0/x44;
	FLT x46 = 2*x45*x8;
	FLT x47 = x13 + x14;
	FLT x48 = 2*lh_pz*x8;
	FLT x49 = x17*(x4 + x7) - 1;
	FLT x50 = 2*x43*x8;
	FLT x51 = lh_py*x49 - x12*x3 + x3*x33 - x39*x49 - x47*x48 + x47*x50;
	FLT x52 = 1. / (x44 * x44);
	FLT x53 = 4*curve_0*curve_scale*x51*x52*x8;
	FLT x54 = x11*x52;
	FLT x55 = (x51*x51);
	FLT x56 = curve_0*x55;
	FLT x57 = 1. / (x44*x44*x44);
	FLT x58 = 4*curve_scale*x11*x57*x8;
	FLT x59 = x1 + x2;
	FLT x60 = -x10 + x9;
	FLT x61 = x17*(x5 + x7) - 1;
	FLT x62 = lh_px*x61 - x16*x59 - x32*x61 + x40*x59 - x48*x60 + x50*x60;
	FLT x63 = (x62 * x62);
	FLT x64 = 1.0/(x52*x63 + 1);
	FLT x65 = x45*x61;
	FLT x66 = 2*x54*x62*x8;
	FLT x67 = x64*(x65 + x66);
	FLT x68 = gibMag_0*gib_scale*cos(gibPhase_0 + atan(x45*x62));
	FLT x69 = x45*x49;
	FLT x70 = 2*x15*x8;
	FLT x71 = x51*x52;
	FLT x72 = x70*x71;
	FLT x73 = 4*curve_scale*x15*x57*x8;
	FLT x74 = 2*x64;
	FLT x75 = x45*x8;
	FLT x76 = x74*(-x15*x52*x62*x8 + x59*x75);
	FLT x77 = x46*x47;
	FLT x78 = x18*x71;
	FLT x79 = 2*curve_scale*x18*x57;
	FLT x80 = x46*x60;
	FLT x81 = x52*x62;
	FLT x82 = x18*x81;
	FLT x83 = x64*(x80 + x82);
	FLT x84 = 2*x0;
	FLT x85 = obj_qj*x26;
	FLT x86 = sensor_x*x85;
	FLT x87 = obj_qi*x26;
	FLT x88 = sensor_y*x87;
	FLT x89 = sensor_z*x24;
	FLT x90 = 1.0/x26;
	FLT x91 = obj_qw*x90;
	FLT x92 = -x41*x91 - x42*x91 + x86 - x88 + x89*x91;
	FLT x93 = 2*x8*x92;
	FLT x94 = obj_qk*x26;
	FLT x95 = sensor_y*x94;
	FLT x96 = sensor_z*x85;
	FLT x97 = sensor_x*x31;
	FLT x98 = -x21*x91 - x30*x91 + x91*x97 + x95 - x96;
	FLT x99 = 2*x8*x98;
	FLT x100 = sensor_x*x94;
	FLT x101 = sensor_z*x87;
	FLT x102 = sensor_y*x38;
	FLT x103 = x100 - x101 - x102*x91 + x34*x91 + x37*x91;
	FLT x104 = x103*x49 + x3*x99 + x47*x93;
	FLT x105 = x104*x45;
	FLT x106 = 4*curve_0*curve_scale*x51*x52;
	FLT x107 = -x103*x70 + x11*x99 - x18*x92;
	FLT x108 = x107*x71;
	FLT x109 = 4*curve_scale*x107*x57;
	FLT x110 = 2*x59*x8;
	FLT x111 = x103*x110 - x60*x93 + x61*x98;
	FLT x112 = x74*(x107*x81 + x111*x45);
	FLT x113 = sensor_y*x85;
	FLT x114 = sensor_z*x94;
	FLT x115 = obj_qi*x90;
	FLT x116 = -x113 - x114 - x115*x21 - x115*x30 + x115*x97;
	FLT x117 = 2*x116*x8;
	FLT x118 = obj_qw*x26;
	FLT x119 = sensor_y*x118;
	FLT x120 = obj_qi*x27;
	FLT x121 = -sensor_z*(x115*x24 + x120) + x100 + x115*x41 + x115*x42 + x119;
	FLT x122 = 2*x121*x8;
	FLT x123 = sensor_z*x118;
	FLT x124 = -sensor_y*(x115*x38 + x120) + x115*x34 + x115*x37 - x123 + x86;
	FLT x125 = x117*x3 - x122*x47 + x124*x49;
	FLT x126 = x125*x45;
	FLT x127 = x11*x117 + x121*x18 - x124*x70;
	FLT x128 = x127*x71;
	FLT x129 = 4*curve_0*curve_scale*x55*x57;
	FLT x130 = x110*x124 + x116*x61 + x122*x60;
	FLT x131 = x74*(x127*x81 + x130*x45);
	FLT x132 = sensor_x*x87;
	FLT x133 = obj_qj*x90;
	FLT x134 = -x102*x133 + x114 + x132 + x133*x34 + x133*x37;
	FLT x135 = obj_qj*x27;
	FLT x136 = -sensor_x*(x133*x31 + x135) + x123 + x133*x21 + x133*x30 + x88;
	FLT x137 = 2*x136*x8;
	FLT x138 = sensor_x*x118;
	FLT x139 = -sensor_z*(x133*x24 + x135) + x133*x41 + x133*x42 - x138 + x95;
	FLT x140 = 2*x139*x8;
	FLT x141 = -x134*x49 + x137*x3 + x140*x47;
	FLT x142 = x141*x45;
	FLT x143 = x11*x137 + x134*x70 - x139*x18;
	FLT x144 = x143*x71;
	FLT x145 = x110*x134 - x136*x61 + x140*x60;
	FLT x146 = x74*(-x143*x81 + x145*x45);
	FLT x147 = obj_qk*x90;
	FLT x148 = x113 + x132 + x147*x41 + x147*x42 - x147*x89;
	FLT x149 = 2*x148*x8;
	FLT x150 = obj_qk*x27;
	FLT x151 = -sensor_x*(x147*x31 + x150) + x101 - x119 + x147*x21 + x147*x30;
	FLT x152 = 2*x151*x8;
	FLT x153 = -sensor_y*(x147*x38 + x150) + x138 + x147*x34 + x147*x37 + x96;
	FLT x154 = x149*x47 + x152*x3 - x153*x49;
	FLT x155 = x154*x45;
	FLT x156 = x11*x152 - x148*x18 + x153*x70;
	FLT x157 = x156*x71;
	FLT x158 = x110*x153 + x149*x60 - x151*x61;
	FLT x159 = x74*(-x156*x81 + x158*x45);
	FLT x160 = tan(tilt_1*tilt_scale);
	FLT x161 = curve_1*x63;
	FLT x162 = 1.0/(x52*x55 + 1);
	FLT x163 = 2*x162;
	FLT x164 = x163*(x3*x75 - x51*x54*x8);
	FLT x165 = gibMag_1*gib_scale*cos(gibPhase_1 - atan(x45*x51));
	FLT x166 = 4*curve_1*curve_scale*x52*x62*x8;
	FLT x167 = x162*(x69 + x72);
	FLT x168 = x162*(x77 + x78);
	FLT x169 = 2*x160*x45;
	FLT x170 = 4*curve_1*curve_scale*x52*x62;
	FLT x171 = 2*x160*x52*x62;
	FLT x172 = x163*(-x105 + x108);
	FLT x173 = 4*curve_1*curve_scale*x57*x63;
	FLT x174 = x163*(-x126 + x128);
	FLT x175 = x163*(x142 - x144);
	FLT x176 = x163*(x155 - x157);
	*(out++) = x0*x3*x46 - 2*x0*x51*x54*x8 - x3*x53 + x56*x58 + x67*x68 - x67;
	*(out++) = 2*curve_0*curve_scale*x49*x51*x52 - x0*x69 - x0*x72 + x56*x73 - x68*x76 + x76;
	*(out++) = x0*x77 + x0*x78 - x47*x53 - x56*x79 - x68*x83 + x83;
	*(out++) = x104*x106 - x105*x84 + x108*x84 - x109*x56 - x112*x68 + x112;
	*(out++) = x106*x125 - x126*x84 - x127*x129 + x128*x84 - x131*x68 + x131;
	*(out++) = -x106*x141 + x129*x143 + x142*x84 - x144*x84 - x146*x68 + x146;
	*(out++) = -x106*x154 + x129*x156 + x155*x84 - x157*x84 - x159*x68 + x159;
	*(out++) = 2*curve_1*curve_scale*x52*x61*x62 + x160*x65 + x160*x66 + x161*x58 + x164*x165 - x164;
	*(out++) = -x110*x160*x45 + x160*x52*x62*x70 + x161*x73 - x165*x167 - x166*x59 + x167;
	*(out++) = -x160*x80 - x160*x82 - x161*x79 + x165*x168 - x166*x60 - x168;
	*(out++) = -x107*x171 - x109*x161 - x111*x169 - x111*x170 + x165*x172 - x172;
	*(out++) = -x127*x171 - x127*x173 - x130*x169 - x130*x170 + x165*x174 - x174;
	*(out++) = x143*x171 + x143*x173 - x145*x169 - x145*x170 + x165*x175 - x175;
	*(out++) = x156*x171 + x156*x173 - x158*x169 - x158*x170 + x165*x176 - x176;
}

