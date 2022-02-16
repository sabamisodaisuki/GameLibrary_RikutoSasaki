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
 -16.79850;10.08054;-9.78351;,
 16.79850;10.08054;-9.78351;,
 16.79850;8.77379;-9.78351;,
 -16.79850;8.77379;-9.78351;,
 16.79850;10.08054;-9.78351;,
 16.79850;10.08054;10.21652;,
 16.79850;8.77379;10.21652;,
 16.79850;8.77379;-9.78351;,
 16.79850;10.08054;10.21652;,
 -16.79850;10.08054;10.21652;,
 -16.79850;8.77379;10.21652;,
 16.79850;8.77379;10.21652;,
 -16.79850;10.08054;10.21652;,
 -16.79850;10.08054;-9.78351;,
 -16.79850;8.77379;-9.78351;,
 -16.79850;8.77379;10.21652;,
 16.79850;10.08054;-9.78351;,
 -16.79850;10.08054;-9.78351;,
 -16.79850;8.77379;-9.78351;,
 16.79850;8.77379;-9.78351;,
 14.56983;8.77689;-9.83655;,
 16.79807;8.77689;-9.83655;,
 16.79807;-1.48549;6.38584;,
 14.56983;-1.48549;6.38584;,
 16.79807;8.77689;-9.83655;,
 16.79807;9.90782;-6.05182;,
 16.79807;-0.35455;10.17057;,
 16.79807;-1.48549;6.38584;,
 16.79807;9.90782;-6.05182;,
 14.56983;9.90782;-6.05182;,
 14.56983;-0.35455;10.17057;,
 16.79807;-0.35455;10.17057;,
 14.56983;9.90782;-6.05182;,
 14.56983;8.77689;-9.83655;,
 14.56983;-1.48549;6.38584;,
 14.56983;-0.35455;10.17057;,
 16.79807;8.77689;-9.83655;,
 14.56983;8.77689;-9.83655;,
 14.56983;-1.48549;6.38584;,
 16.79807;-1.48549;6.38584;,
 -16.76644;8.77689;-9.83655;,
 -14.53819;8.77689;-9.83655;,
 -14.53819;-1.48549;6.38584;,
 -16.76644;-1.48549;6.38584;,
 -14.53819;8.77689;-9.83655;,
 -14.53819;9.90782;-6.05182;,
 -14.53819;-0.35455;10.17057;,
 -14.53819;-1.48549;6.38584;,
 -14.53819;9.90782;-6.05182;,
 -16.76644;9.90782;-6.05182;,
 -16.76644;-0.35455;10.17057;,
 -14.53819;-0.35455;10.17057;,
 -16.76644;9.90782;-6.05182;,
 -16.76644;8.77689;-9.83655;,
 -16.76644;-1.48549;6.38584;,
 -16.76644;-0.35455;10.17057;,
 -14.53819;8.77689;-9.83655;,
 -16.76644;8.77689;-9.83655;,
 -16.76644;-1.48549;6.38584;,
 -14.53819;-1.48549;6.38584;,
 -16.76644;-1.48548;-6.80300;,
 -14.53819;-1.48548;-6.80300;,
 -14.53819;8.77688;9.41935;,
 -16.76644;8.77688;9.41935;,
 -14.53819;-1.48548;-6.80300;,
 -14.53819;-0.35455;-10.58775;,
 -14.53819;9.90782;5.63461;,
 -14.53819;8.77688;9.41935;,
 -14.53819;-0.35455;-10.58775;,
 -16.76644;-0.35455;-10.58775;,
 -16.76644;9.90782;5.63461;,
 -14.53819;9.90782;5.63461;,
 -16.76644;-0.35455;-10.58775;,
 -16.76644;-1.48548;-6.80300;,
 -16.76644;8.77688;9.41935;,
 -16.76644;9.90782;5.63461;,
 -14.53819;-1.48548;-6.80300;,
 -16.76644;-1.48548;-6.80300;,
 -16.76644;8.77688;9.41935;,
 -14.53819;8.77688;9.41935;,
 14.56557;-1.48548;-6.80300;,
 16.79382;-1.48548;-6.80300;,
 16.79382;8.77688;9.41935;,
 14.56557;8.77688;9.41935;,
 16.79382;-1.48548;-6.80300;,
 16.79382;-0.35455;-10.58775;,
 16.79382;9.90782;5.63461;,
 16.79382;8.77688;9.41935;,
 16.79382;-0.35455;-10.58775;,
 14.56557;-0.35455;-10.58775;,
 14.56557;9.90782;5.63461;,
 16.79382;9.90782;5.63461;,
 14.56557;-0.35455;-10.58775;,
 14.56557;-1.48548;-6.80300;,
 14.56557;8.77688;9.41935;,
 14.56557;9.90782;5.63461;,
 16.79382;-1.48548;-6.80300;,
 14.56557;-1.48548;-6.80300;,
 14.56557;8.77688;9.41935;,
 16.79382;8.77688;9.41935;;
 
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
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;-0.845097;-0.534613;,
  0.000000;-0.990652;-0.136413;,
  1.000000;0.000000;-0.000000;,
  0.000000;0.990652;0.136413;,
  0.000000;0.845097;0.534613;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.958138;-0.286307;,
  0.000000;-0.958137;0.286308;,
  0.000000;-0.845097;-0.534613;,
  0.000000;-0.990652;-0.136413;,
  1.000000;0.000000;-0.000000;,
  0.000000;0.990652;0.136413;,
  0.000000;0.845097;0.534613;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.958138;-0.286307;,
  0.000000;-0.958137;0.286308;,
  0.000000;-0.990652;0.136414;,
  0.000000;-0.845097;0.534614;,
  1.000000;0.000000;0.000000;,
  0.000000;0.845097;-0.534613;,
  0.000000;0.990652;-0.136414;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.958139;-0.286305;,
  0.000000;0.958138;0.286306;,
  0.000000;-0.990652;0.136414;,
  0.000000;-0.845097;0.534614;,
  1.000000;0.000000;0.000000;,
  0.000000;0.845097;-0.534613;,
  0.000000;0.990652;-0.136414;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.958139;-0.286305;,
  0.000000;0.958138;0.286306;;
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
