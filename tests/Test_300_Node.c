#include <stdio.h>
#include "salmalloc.h"
#include <stdint.h>

/*
  This test adds 200 nodes and verifies if
  skip nodes are updated correctly.
*/


void print_free_mem()
{
        sNode *temp = copy_list(4);
	smem_blk_seg *seg = temp->memSegment;
	ssize_t i = 0;
        while (temp != NULL) {
	  	//int ch = temp->numNodesAhead;
	  	seg = temp->memSegment;
		if (seg->isFree == TRUE) { printf("i == %zu and isFree: %zd.\n", i, seg->isFree); }
		i++;
		temp = (sNode*) temp->next;
	}

}

ssize_t testList() 
{
 		sNode *temp = copy_list(4);
		ssize_t count = 0;
       		while(temp != NULL) {
       			ssize_t *compare = temp->memSegment + sizeof(smem_blk_seg);
			if (*compare != count) {
				printf("Test failed at count %zd when compare was %zd.\n", count, *compare);
       				return FALSE;
       			}
       			temp = (sNode*)temp->next;
        		count++;
       		}
       		return TRUE;
}




ssize_t testSkipNodes()
{
        size_t i = 0;
        sNode *temp = copy_list(4);
        while (temp != NULL) {
	  	int ch = temp->numNodesAhead;
	        printf("i == %zu and ch: %zd.\n", i, ch);
		//if (ch != 100 && ch != 3) {printf("Test case failed. Skip nodes are not correct.\n"); return FALSE;}
		temp = temp->skipNodes.fwd_hundredSpecialNode;
        	i++;
        }
        return TRUE;
}


int main()
{
  ssize_t *a0, *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8, *a9, *a10, *a11, *a12, *a13, *a14, *a15, *a16, *a17, *a18, *a19, *a20, *a21, *a22, *a23, *a24, *a25, *a26, *a27, *a28, *a29, *a30, *a31, *a32, *a33, *a34, *a35, *a36, *a37, *a38, *a39, *a40, *a41, *a42, *a43, *a44, *a45, *a46, *a47, *a48, *a49, *a50, *a51, *a52, *a53, *a54, *a55, *a56, *a57, *a58, *a59, *a60, *a61, *a62, *a63, *a64, *a65, *a66, *a67, *a68, *a69, *a70, *a71, *a72, *a73, *a74, *a75, *a76, *a77, *a78, *a79, *a80, *a81, *a82, *a83, *a84, *a85, *a86, *a87, *a88, *a89, *a90, *a91, *a92, *a93, *a94, *a95, *a96, *a97, *a98, *a99, *a100, *a101, *a102, *a103, *a104, *a105, *a106, *a107, *a108, *a109, *a110, *a111, *a112, *a113, *a114, *a115, *a116, *a117, *a118, *a119, *a120, *a121, *a122, *a123, *a124, *a125, *a126, *a127, *a128, *a129, *a130, *a131, *a132, *a133, *a134, *a135, *a136, *a137, *a138, *a139, *a140, *a141, *a142, *a143, *a144, *a145, *a146, *a147, *a148, *a149, *a150, *a151, *a152, *a153, *a154, *a155, *a156, *a157, *a158, *a159, *a160, *a161, *a162, *a163, *a164, *a165, *a166, *a167, *a168, *a169, *a170, *a171, *a172, *a173, *a174, *a175, *a176, *a177, *a178, *a179, *a180, *a181, *a182, *a183, *a184, *a185, *a186, *a187, *a188, *a189, *a190, *a191, *a192, *a193, *a194, *a195, *a196, *a197, *a198, *a199, *a200;

 	uint64_t *a201, *a202;

        sNode *temp;


	a0 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a0 = 0;

	a1 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a1 = 1;

	a2 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a2 = 2;

	a3 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a3 = 3;

	a4 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a4 = 4;

	a5 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a5 = 5;

	a6 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a6 = 6;

	a7 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a7 = 7;

	a8 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a8 = 8;

	a9 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a9 = 9;

	a10 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a10 = 10;

	a11 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a11 = 11;

	a12 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a12 = 12;

	a13 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a13 = 13;

	a14 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a14 = 14;

	a15 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a15 = 15;

	a16 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a16 = 16;

	a17 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a17 = 17;

	a18 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a18 = 18;

	a19 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a19 = 19;

	a20 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a20 = 20;

	a21 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a21 = 21;

	a22 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a22 = 22;

	a23 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a23 = 23;

	a24 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a24 = 24;

	a25 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a25 = 25;

	a26 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a26 = 26;

	a27 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a27 = 27;

	a28 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a28 = 28;

	a29 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a29 = 29;

	a30 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a30 = 30;

	a31 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a31 = 31;

	a32 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a32 = 32;

	a33 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a33 = 33;

	a34 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a34 = 34;

	a35 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a35 = 35;

	a36 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a36 = 36;

	a37 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a37 = 37;

	a38 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a38 = 38;

	a39 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a39 = 39;

	a40 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a40 = 40;

	a41 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a41 = 41;

	a42 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a42 = 42;

	a43 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a43 = 43;

	a44 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a44 = 44;

	a45 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a45 = 45;

	a46 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a46 = 46;

	a47 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a47 = 47;

	a48 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a48 = 48;

	a49 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a49 = 49;

	a50 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a50 = 50;

	a51 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a51 = 51;

	a52 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a52 = 52;

	a53 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a53 = 53;

	a54 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a54 = 54;

	a55 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a55 = 55;

	a56 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a56 = 56;

	a57 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a57 = 57;

	a58 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a58 = 58;

	a59 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a59 = 59;

	a60 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a60 = 60;

	a61 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a61 = 61;

	a62 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a62 = 62;

	a63 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a63 = 63;

	a64 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a64 = 64;

	a65 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a65 = 65;

	a66 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a66 = 66;

	a67 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a67 = 67;

	a68 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a68 = 68;

	a69 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a69 = 69;

	a70 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a70 = 70;

	a71 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a71 = 71;

	a72 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a72 = 72;

	a73 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a73 = 73;

	a74 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a74 = 74;

	a75 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a75 = 75;

	a76 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a76 = 76;

	a77 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a77 = 77;

	a78 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a78 = 78;

	a79 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a79 = 79;

	a80 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a80 = 80;

	a81 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a81 = 81;

	a82 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a82 = 82;

	a83 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a83 = 83;

	a84 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a84 = 84;

	a85 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a85 = 85;

	a86 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a86 = 86;

	a87 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a87 = 87;

	a88 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a88 = 88;

	a89 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a89 = 89;

	a90 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a90 = 90;

	a91 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a91 = 91;

	a92 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a92 = 92;

	a93 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a93 = 93;

	a94 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a94 = 94;

	a95 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a95 = 95;

	a96 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a96 = 96;

	a97 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a97 = 97;

	a98 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a98 = 98;

	a99 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a99 = 99;

	a100 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a100 = 100;

	a101 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a101 = 101;

	a102 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a102 = 102;

	a103 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a103 = 103;

	a104 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a104 = 104;

	a105 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a105 = 105;

	a106 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a106 = 106;

	a107 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a107 = 107;

	a108 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a108 = 108;

	a109 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a109 = 109;

	a110 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a110 = 110;

	a111 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a111 = 111;

	a112 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a112 = 112;

	a113 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a113 = 113;

	a114 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a114 = 114;

	a115 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a115 = 115;

	a116 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a116 = 116;

	a117 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a117 = 117;

	a118 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a118 = 118;

	a119 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a119 = 119;

	a120 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a120 = 120;

	a121 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a121 = 121;

	a122 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a122 = 122;

	a123 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a123 = 123;

	a124 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a124 = 124;

	a125 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a125 = 125;

	a126 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a126 = 126;

	a127 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a127 = 127;

	a128 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a128 = 128;

	a129 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a129 = 129;

	a130 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a130 = 130;

	a131 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a131 = 131;

	a132 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a132 = 132;

	a133 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a133 = 133;

	a134 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a134 = 134;

	a135 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a135 = 135;

	a136 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a136 = 136;

	a137 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a137 = 137;

	a138 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a138 = 138;

	a139 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a139 = 139;

	a140 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a140 = 140;

	a141 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a141 = 141;

	a142 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a142 = 142;

	a143 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a143 = 143;

	a144 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a144 = 144;

	a145 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a145 = 145;

	a146 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a146 = 146;

	a147 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a147 = 147;

	a148 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a148 = 148;

	a149 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a149 = 149;

	a150 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a150 = 150;

	a151 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a151 = 151;

	a152 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a152 = 152;

	a153 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a153 = 153;

	a154 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a154 = 154;

	a155 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a155 = 155;

	a156 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a156 = 156;

	a157 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a157 = 157;

	a158 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a158 = 158;

	a159 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a159 = 159;

	a160 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a160 = 160;

	a161 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a161 = 161;

	a162 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a162 = 162;

	a163 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a163 = 163;

	a164 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a164 = 164;

	a165 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a165 = 165;

	a166 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a166 = 166;

	a167 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a167 = 167;

	a168 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a168 = 168;

	a169 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a169 = 169;

	a170 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a170 = 170;

	a171 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a171 = 171;

	a172 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a172 = 172;

	a173 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a173 = 173;

	a174 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a174 = 174;

	a175 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a175 = 175;

	a176 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a176 = 176;

	a177 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a177 = 177;

	a178 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a178 = 178;

	a179 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a179 = 179;

	a180 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a180 = 180;

	a181 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a181 = 181;

	a182 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a182 = 182;

	a183 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a183 = 183;

	a184 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a184 = 184;

	a185 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a185 = 185;

	a186 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a186 = 186;

	a187 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a187 = 187;

	a188 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a188 = 188;

	a189 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a189 = 189;

	a190 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a190 = 190;

	a191 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a191 = 191;

	a192 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a192 = 192;

	a193 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a193 = 193;

	a194 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a194 = 194;

	a195 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a195 = 195;

	a196 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a196 = 196;

	a197 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a197 = 197;

	a198 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a198 = 198;

	a199 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a199 = 199;

	a200 =  (ssize_t *) salmalloc(sizeof(ssize_t));
	*a200 = 200;

	a201 =  (uint64_t *) salmalloc(sizeof(uint64_t));
	*a201 = 201;

	a202 =  (uint64_t *) salmalloc(sizeof(uint64_t));
	*a202 = 202;

	temp = (sNode *) copy_list(4);

	printf("head has this many nodes ahead: %d.\n", temp->numNodesAhead);

	if (testList() != TRUE) {
	  return FALSE;
	}

	printf("Test part 1 was successful.\n");

	if (testSkipNodes() != TRUE) {
	  return FALSE;
	}

	printf("Test part 2 was successful.\n");


	/* now free some memory */
	salfree(a0);
	salfree(a1);
	salfree(a68);
	salfree(a69);
	salfree(a70);

	print_free_mem();

	testSkipNodes();

	return TRUE;

	salfree(a71);
	salfree(a99);
	salfree(a100);
	salfree(a101);
	salfree(a198);
	salfree(a199);
	salfree(a200);
	salfree(a201);
	salfree(a202);


	return TRUE;

}


