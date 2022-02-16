xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 100;
 54.33296;35.73641;-25.14902;,
 55.76159;35.73641;21.59208;,
 55.76159;31.79658;21.59208;,
 54.33296;31.79658;-25.14902;,
 55.76159;35.73641;21.59208;,
 -58.94563;35.73641;24.16551;,
 -58.94563;31.79658;24.16551;,
 55.76159;31.79658;21.59208;,
 -58.94563;35.73641;24.16551;,
 -60.37424;35.73641;-22.57559;,
 -60.37424;31.79658;-22.57559;,
 -58.94563;31.79658;24.16551;,
 -60.37424;35.73641;-22.57559;,
 54.33296;35.73641;-25.14902;,
 54.33296;31.79658;-25.14902;,
 -60.37424;31.79658;-22.57559;,
 55.76159;35.73641;21.59208;,
 54.33296;35.73641;-25.14902;,
 54.33296;31.79658;-25.14902;,
 55.76159;31.79658;21.59208;,
 55.97100;31.80592;18.48466;,
 56.06578;31.80592;21.58467;,
 -36.97538;0.86486;23.67201;,
 -37.07012;0.86486;20.57201;,
 56.06578;31.80592;21.58467;,
 34.35903;35.21564;22.07165;,
 -58.68214;4.27462;24.15899;,
 -36.97538;0.86486;23.67201;,
 34.35903;35.21564;22.07165;,
 34.26426;35.21564;18.97163;,
 -58.77691;4.27462;21.05900;,
 -58.68214;4.27462;24.15899;,
 34.26426;35.21564;18.97163;,
 55.97100;31.80592;18.48466;,
 -37.07012;0.86486;20.57201;,
 -58.77691;4.27462;21.05900;,
 56.06578;31.80592;21.58467;,
 55.97100;31.80592;18.48466;,
 -37.07012;0.86486;20.57201;,
 -36.97538;0.86486;23.67201;,
 54.63852;31.80592;-25.11125;,
 54.73326;31.80592;-22.01124;,
 -38.30787;0.86486;-19.92389;,
 -38.40260;0.86486;-23.02390;,
 54.73326;31.80592;-22.01124;,
 33.02652;35.21564;-21.52425;,
 -60.01464;4.27462;-19.43690;,
 -38.30787;0.86486;-19.92389;,
 33.02652;35.21564;-21.52425;,
 32.93175;35.21564;-24.62425;,
 -60.10940;4.27462;-22.53694;,
 -60.01464;4.27462;-19.43690;,
 32.93175;35.21564;-24.62425;,
 54.63852;31.80592;-25.11125;,
 -38.40260;0.86486;-23.02390;,
 -60.10940;4.27462;-22.53694;,
 54.73326;31.80592;-22.01124;,
 54.63852;31.80592;-25.11125;,
 -38.40260;0.86486;-23.02390;,
 -38.30787;0.86486;-19.92389;,
 37.24004;0.86488;-24.72091;,
 37.33478;0.86488;-21.62091;,
 -55.70613;31.80589;-19.53358;,
 -55.80084;31.80589;-22.63357;,
 37.33478;0.86488;-21.62091;,
 59.04166;4.27462;-22.10790;,
 -33.99927;35.21564;-20.02057;,
 -55.70613;31.80589;-19.53358;,
 59.04166;4.27462;-22.10790;,
 58.94692;4.27462;-25.20792;,
 -34.09401;35.21564;-23.12056;,
 -33.99927;35.21564;-20.02057;,
 58.94692;4.27462;-25.20792;,
 37.24004;0.86488;-24.72091;,
 -55.80084;31.80589;-22.63357;,
 -34.09401;35.21564;-23.12056;,
 37.33478;0.86488;-21.62091;,
 37.24004;0.86488;-24.72091;,
 -55.80084;31.80589;-22.63357;,
 -55.70613;31.80589;-19.53358;,
 38.57235;0.86488;18.86907;,
 38.66708;0.86488;21.96907;,
 -54.37381;31.80589;24.05641;,
 -54.46857;31.80589;20.95641;,
 38.66708;0.86488;21.96907;,
 60.37400;4.27462;21.48208;,
 -32.66696;35.21564;23.56943;,
 -54.37381;31.80589;24.05641;,
 60.37400;4.27462;21.48208;,
 60.27922;4.27462;18.38208;,
 -32.76173;35.21564;20.46942;,
 -32.66696;35.21564;23.56943;,
 60.27922;4.27462;18.38208;,
 38.57235;0.86488;18.86907;,
 -54.46857;31.80589;20.95641;,
 -32.76173;35.21564;20.46942;,
 38.66708;0.86488;21.96907;,
 38.57235;0.86488;18.86907;,
 -54.46857;31.80589;20.95641;,
 -54.37381;31.80589;24.05641;;
 
 30;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;12,5,16,17;,
 4;18,19,6,15;,
 4;20,21,22,23;,
 4;24,25,26,27;,
 4;28,29,30,31;,
 4;32,33,34,35;,
 4;32,25,36,37;,
 4;38,39,26,35;,
 4;40,41,42,43;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;52,53,54,55;,
 4;52,45,56,57;,
 4;58,59,46,55;,
 4;60,61,62,63;,
 4;64,65,66,67;,
 4;68,69,70,71;,
 4;72,73,74,75;,
 4;72,65,76,77;,
 4;78,79,66,75;,
 4;80,81,82,83;,
 4;84,85,86,87;,
 4;88,89,90,91;,
 4;92,93,94,95;,
 4;92,85,96,97;,
 4;98,99,86,95;;
 
 MeshMaterialList {
  2;
  30;
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   0.620800;0.248000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.640000;0.329600;0.034400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  38;
  0.999533;0.000000;-0.030550;,
  0.022429;0.000000;0.999748;,
  -0.999533;0.000000;0.030550;,
  -0.022429;0.000000;-0.999748;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.315351;-0.948926;-0.009640;,
  0.082471;-0.996590;-0.002521;,
  0.022429;0.000000;0.999748;,
  -0.082471;0.996590;0.002521;,
  -0.315351;0.948926;0.009640;,
  -0.022429;-0.000000;-0.999748;,
  0.155073;0.987892;-0.004741;,
  -0.155074;-0.987891;0.004740;,
  0.315351;-0.948926;-0.009637;,
  0.082471;-0.996590;-0.002520;,
  0.022429;-0.000000;0.999748;,
  -0.082471;0.996590;0.002521;,
  -0.315351;0.948926;0.009640;,
  -0.022429;-0.000000;-0.999748;,
  0.155073;0.987892;-0.004740;,
  -0.155074;-0.987891;0.004740;,
  -0.082472;-0.996590;0.002520;,
  -0.315352;-0.948926;0.009636;,
  0.022429;0.000000;0.999748;,
  0.315352;0.948926;-0.009637;,
  0.082471;0.996590;-0.002521;,
  -0.022429;-0.000001;-0.999748;,
  0.155072;-0.987892;-0.004739;,
  -0.155073;0.987892;0.004738;,
  -0.082472;-0.996590;0.002520;,
  -0.315352;-0.948926;0.009638;,
  0.022429;-0.000000;0.999748;,
  0.315352;0.948926;-0.009641;,
  0.082471;0.996590;-0.002522;,
  -0.022429;-0.000000;-0.999748;,
  0.155072;-0.987892;-0.004740;,
  -0.155073;0.987892;0.004740;;
  30;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;6,6,7,7;,
  4;8,8,8,8;,
  4;9,9,10,10;,
  4;11,11,11,11;,
  4;9,9,12,12;,
  4;7,7,13,13;,
  4;14,14,15,15;,
  4;16,16,16,16;,
  4;17,17,18,18;,
  4;19,19,19,19;,
  4;17,17,20,20;,
  4;15,15,21,21;,
  4;22,22,23,23;,
  4;24,24,24,24;,
  4;25,25,26,26;,
  4;27,27,27,27;,
  4;28,28,22,22;,
  4;29,29,26,26;,
  4;30,30,31,31;,
  4;32,32,32,32;,
  4;33,33,34,34;,
  4;35,35,35,35;,
  4;36,36,30,30;,
  4;37,37,34,34;;
 }
 MeshTextureCoords {
  100;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;;
 }
}
