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
 145;
 -3.69725;17.28970;-8.00820;,
 -3.71975;20.41470;-12.26070;,
 -7.02324;18.59320;-13.04120;,
 -7.36074;15.18620;-9.14920;,
 -8.62924;10.17070;-16.00470;,
 -7.63074;15.52270;-21.88120;,
 -7.01725;3.61970;-23.61620;,
 -7.20524;0.01070;-17.18170;,
 -5.79625;-5.44130;-6.05070;,
 -3.89675;-2.72330;-18.43020;,
 -0.00025;22.06570;-35.55770;,
 -2.64575;22.53070;-30.07320;,
 -1.57775;23.12520;-30.14070;,
 -3.29625;19.66570;-28.50570;,
 -3.19125;21.60820;-29.78320;,
 -9.26525;9.88870;-14.84620;,
 -1.73525;18.75570;-28.90670;,
 -3.11075;14.40520;-27.97570;,
 -5.60224;15.51020;-27.55320;,
 -5.93375;21.38270;-24.89420;,
 -4.04825;23.23070;-26.55270;,
 -3.58974;7.72670;-27.16720;,
 -6.65325;10.26870;-26.30020;,
 -3.85774;1.66670;-24.39620;,
 -6.27124;21.63420;-18.17720;,
 -5.39375;23.68770;-22.26170;,
 -6.64324;20.33370;-22.57420;,
 -6.47825;19.61570;-24.45620;,
 -6.68725;19.09720;-23.42120;,
 -0.00025;-3.24880;-18.43020;,
 -2.58224;6.38070;7.25030;,
 -0.00025;17.55970;-8.08070;,
 -0.00025;18.69070;-28.90670;,
 -0.00025;24.63370;-26.63570;,
 -0.00025;23.48570;-30.14070;,
 -3.30025;-6.54830;-6.05070;,
 -3.03775;24.74720;-22.09220;,
 -2.63025;24.19770;-26.63570;,
 -3.38324;23.30120;-17.14270;,
 3.69725;17.28970;-8.00820;,
 7.36025;15.18620;-9.14920;,
 7.02325;18.59320;-13.04120;,
 3.38325;23.30120;-17.14270;,
 7.01675;3.61970;-23.61620;,
 7.63025;15.52270;-21.88120;,
 8.62925;10.17070;-16.00470;,
 7.20475;0.01070;-17.18170;,
 3.89625;-2.72330;-18.43020;,
 5.79575;-5.44180;-6.05070;,
 1.57725;23.12520;-30.14070;,
 2.64525;22.53070;-30.07320;,
 3.19075;21.60820;-29.78320;,
 3.29575;19.66570;-28.50570;,
 9.26525;9.88870;-14.84620;,
 5.60175;15.51020;-27.55320;,
 3.58975;7.72670;-27.16720;,
 1.73525;18.75570;-28.90670;,
 5.93325;21.38270;-24.89420;,
 4.04776;23.23070;-26.55270;,
 6.65275;10.26870;-26.30020;,
 3.85775;1.66670;-24.39620;,
 6.27075;21.63420;-18.17720;,
 6.64275;20.33370;-22.57420;,
 5.39375;23.68770;-22.26170;,
 6.47825;19.61570;-24.45620;,
 6.68725;19.09720;-23.42120;,
 -0.00025;-8.72480;-0.93320;,
 2.58226;6.38070;7.25030;,
 3.03725;24.74720;-22.09220;,
 2.62975;24.19770;-26.63570;,
 6.51625;4.04370;1.12730;,
 8.12625;6.01270;-8.00320;,
 23.40425;17.46720;0.16380;,
 8.14275;5.01020;-8.21770;,
 -23.40475;17.46720;0.16380;,
 -6.51675;4.04370;1.12730;,
 -8.12674;6.01270;-8.00320;,
 -8.14324;5.01020;-8.21770;,
 1.20775;0.18470;19.05880;,
 2.74475;-1.71980;13.26230;,
 -2.74525;-1.71980;13.26230;,
 -1.20825;0.18470;19.05880;,
 -4.84375;-8.88430;-1.71220;,
 -1.11874;-8.79930;-0.95620;,
 -2.72224;-17.73730;-5.50020;,
 -4.05974;-7.67080;2.09430;,
 -3.26074;-17.72930;-5.49970;,
 -2.14125;-3.62380;6.81180;,
 -0.00025;-4.29330;6.15830;,
 -0.00025;-5.43330;15.71880;,
 3.26025;-17.72930;-5.49970;,
 4.05925;-7.67080;2.09430;,
 1.11825;-8.79930;-0.95620;,
 4.84375;-8.88430;-1.71220;,
 -0.00025;-8.06430;1.07130;,
 -4.28224;-3.62380;7.46580;,
 1.20675;-2.38780;14.47980;,
 1.20775;-2.66680;20.27730;,
 -1.20825;-2.66680;20.27730;,
 -1.20725;-2.38780;14.47980;,
 4.28175;-3.62380;7.46580;,
 24.04475;17.67020;-5.55820;,
 24.92875;20.50120;-10.33570;,
 41.73175;28.90120;6.75430;,
 22.48675;18.33970;-5.37670;,
 -24.92875;20.50120;-10.33570;,
 -22.48725;18.33970;-5.37670;,
 -41.73175;28.90120;6.75430;,
 -24.04475;17.67020;-5.55820;,
 41.72876;29.37820;6.73280;,
 -41.72924;29.37820;6.73280;,
 -0.00025;23.75670;-17.14270;,
 -0.44824;-7.40730;1.07130;,
 2.72175;-17.73730;-5.50020;,
 -1.13524;-5.62580;34.49630;,
 -0.00025;-2.98730;14.47980;,
 1.13475;-6.51830;34.90630;,
 1.13475;-5.62580;34.49630;,
 -0.00025;-7.22630;35.69430;,
 -1.13524;-6.51830;34.90630;,
 -0.00025;25.22920;-22.09220;,
 5.62375;-19.07780;-9.21120;,
 2.28675;-19.08530;-4.16820;,
 0.63575;-19.14880;-9.37970;,
 2.95275;-19.07230;-10.42970;,
 -5.62424;-19.07780;-9.21120;,
 -2.95325;-19.07230;-10.42970;,
 -0.63624;-19.14880;-9.37970;,
 -2.28724;-19.08530;-4.16820;,
 2.14075;-3.62380;6.81180;,
 0.44775;-7.40730;1.07130;,
 -0.29875;-2.38780;14.47980;,
 7.04025;20.07220;-24.36220;,
 7.14375;20.37270;-23.10670;,
 -7.14425;20.37270;-23.10670;,
 -7.04025;20.07220;-24.36220;,
 -2.84875;-19.59680;0.15330;,
 2.84875;-19.59680;0.15330;,
 6.61925;20.81670;-24.59270;,
 5.89825;20.23220;-25.20270;,
 -5.89875;20.23220;-25.20270;,
 -6.61925;20.81670;-24.59270;,
 -0.00025;-3.28180;20.27730;,
 41.02776;29.26920;6.88930;,
 -41.02774;29.26920;6.88930;;
 
 286;
 3;0,1,2;,
 3;2,3,0;,
 3;4,5,6;,
 3;6,7,4;,
 3;8,7,9;,
 3;10,11,12;,
 3;10,13,14;,
 3;15,3,4;,
 3;13,16,17;,
 3;17,18,13;,
 3;11,14,19;,
 3;19,20,11;,
 3;21,22,18;,
 3;23,6,22;,
 3;2,24,5;,
 3;24,25,26;,
 3;25,20,19;,
 3;13,18,27;,
 3;18,22,28;,
 3;29,9,23;,
 3;30,31,0;,
 3;32,16,10;,
 3;33,34,12;,
 3;1,0,31;,
 3;35,9,29;,
 3;10,12,34;,
 3;16,32,17;,
 3;9,7,6;,
 3;6,23,9;,
 3;0,3,30;,
 3;16,13,10;,
 3;20,25,36;,
 3;11,20,37;,
 3;37,12,11;,
 3;25,24,38;,
 3;24,2,1;,
 3;39,40,41;,
 3;41,42,39;,
 3;43,44,45;,
 3;45,46,43;,
 3;47,46,48;,
 3;49,50,10;,
 3;51,52,10;,
 3;45,40,53;,
 3;52,54,55;,
 3;55,56,52;,
 3;57,51,50;,
 3;50,58,57;,
 3;54,59,55;,
 3;59,43,60;,
 3;44,61,41;,
 3;62,63,61;,
 3;57,58,63;,
 3;64,54,52;,
 3;65,59,54;,
 3;60,47,29;,
 3;39,31,30;,
 3;10,56,32;,
 3;49,34,33;,
 3;31,39,42;,
 3;29,47,66;,
 3;34,49,10;,
 3;17,32,56;,
 3;47,60,43;,
 3;43,46,47;,
 3;67,40,39;,
 3;10,52,56;,
 3;68,63,58;,
 3;50,49,69;,
 3;69,58,50;,
 3;42,61,63;,
 3;42,41,61;,
 3;3,2,5;,
 3;5,4,3;,
 3;10,14,11;,
 3;4,7,15;,
 3;19,14,13;,
 3;22,6,5;,
 3;44,41,40;,
 3;40,45,44;,
 3;53,46,45;,
 3;51,57,52;,
 3;44,43,59;,
 3;53,40,67;,
 3;30,3,15;,
 3;70,71,67;,
 3;72,70,73;,
 3;48,46,53;,
 3;71,70,72;,
 3;15,7,8;,
 3;74,75,76;,
 3;77,75,74;,
 3;30,76,75;,
 3;70,78,79;,
 3;80,81,75;,
 3;82,83,84;,
 3;83,85,86;,
 3;87,88,89;,
 3;9,35,8;,
 3;48,73,70;,
 3;90,91,92;,
 3;91,90,93;,
 3;94,88,87;,
 3;75,77,8;,
 3;95,80,75;,
 3;96,78,97;,
 3;98,81,99;,
 3;70,79,100;,
 3;70,100,48;,
 3;101,102,103;,
 3;104,102,53;,
 3;15,105,106;,
 3;107,105,108;,
 3;72,101,103;,
 3;109,102,104;,
 3;106,105,110;,
 3;107,108,74;,
 3;33,69,49;,
 3;42,111,31;,
 3;112,95,85;,
 3;8,95,75;,
 3;48,66,47;,
 3;113,92,93;,
 3;29,23,60;,
 3;56,55,17;,
 3;30,67,39;,
 3;78,81,114;,
 3;63,62,57;,
 3;54,64,65;,
 3;19,26,25;,
 3;28,27,18;,
 3;115,96,116;,
 3;80,95,89;,
 3;114,117,78;,
 3;115,118,119;,
 3;38,36,25;,
 3;68,120,111;,
 3;121,122,123;,
 3;124,90,121;,
 3;125,86,126;,
 3;127,128,125;,
 3;23,21,55;,
 3;22,21,23;,
 3;8,77,15;,
 3;108,105,15;,
 3;53,102,101;,
 3;53,73,48;,
 3;75,81,30;,
 3;30,81,78;,
 3;89,100,79;,
 3;89,96,115;,
 3;63,68,42;,
 3;111,42,68;,
 3;60,55,59;,
 3;55,60,23;,
 3;100,129,130;,
 3;129,100,89;,
 3;67,78,70;,
 3;67,30,78;,
 3;131,99,89;,
 3;119,99,131;,
 3;132,133,65;,
 3;62,61,44;,
 3;28,134,135;,
 3;5,24,26;,
 3;85,82,86;,
 3;82,85,95;,
 3;127,84,128;,
 3;125,136,86;,
 3;122,113,123;,
 3;90,137,121;,
 3;36,37,20;,
 3;69,33,120;,
 3;138,139,62;,
 3;64,132,65;,
 3;26,140,141;,
 3;28,135,27;,
 3;130,92,91;,
 3;92,66,48;,
 3;142,117,114;,
 3;119,118,142;,
 3;91,100,130;,
 3;100,91,93;,
 3;116,97,142;,
 3;97,116,96;,
 3;89,95,87;,
 3;112,87,95;,
 3;8,66,83;,
 3;85,83,112;,
 3;101,73,53;,
 3;73,101,72;,
 3;74,108,77;,
 3;15,77,108;,
 3;99,119,98;,
 3;142,98,119;,
 3;83,82,8;,
 3;95,8,82;,
 3;48,93,92;,
 3;93,48,100;,
 3;67,71,53;,
 3;53,71,104;,
 3;15,76,30;,
 3;106,76,15;,
 3;36,38,111;,
 3;31,111,1;,
 3;44,59,65;,
 3;65,62,44;,
 3;28,22,5;,
 3;5,26,28;,
 3;142,97,117;,
 3;78,117,97;,
 3;92,130,66;,
 3;87,112,94;,
 3;19,13,140;,
 3;26,19,140;,
 3;139,57,62;,
 3;139,52,57;,
 3;124,121,123;,
 3;123,113,124;,
 3;126,84,127;,
 3;127,125,126;,
 3;79,78,96;,
 3;79,96,89;,
 3;89,99,80;,
 3;99,81,80;,
 3;81,98,114;,
 3;114,98,142;,
 3;26,134,28;,
 3;141,134,26;,
 3;65,133,62;,
 3;62,133,138;,
 3;103,143,72;,
 3;72,143,109;,
 3;74,144,107;,
 3;110,144,74;,
 3;74,106,110;,
 3;76,106,74;,
 3;109,104,72;,
 3;72,104,71;,
 3;120,68,69;,
 3;58,69,68;,
 3;86,84,83;,
 3;86,84,126;,
 3;84,86,82;,
 3;84,86,136;,
 3;137,90,113;,
 3;93,90,113;,
 3;92,113,90;,
 3;124,113,90;,
 3;66,112,83;,
 3;66,94,112;,
 3;111,120,36;,
 3;37,36,120;,
 3;120,33,37;,
 3;12,37,33;,
 3;116,118,115;,
 3;142,118,116;,
 3;52,139,64;,
 3;132,64,139;,
 3;27,140,13;,
 3;140,27,135;,
 3;89,88,129;,
 3;129,88,94;,
 3;18,17,21;,
 3;21,17,55;,
 3;131,89,115;,
 3;119,131,115;,
 3;136,125,128;,
 3;84,136,128;,
 3;122,121,137;,
 3;122,137,113;,
 3;135,141,140;,
 3;135,134,141;,
 3;139,138,132;,
 3;138,133,132;,
 3;107,110,105;,
 3;144,110,107;,
 3;102,109,103;,
 3;103,109,143;,
 3;29,66,35;,
 3;66,8,35;,
 3;130,94,66;,
 3;94,130,129;,
 3;1,38,24;,
 3;38,1,111;,
 3;50,51,10;;
 
 MeshMaterialList {
  1;
  286;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  237;
  -0.347194;0.749549;0.563589;,
  -0.300654;0.807563;0.507394;,
  -0.777108;0.544201;0.316148;,
  -0.884477;0.419230;0.204809;,
  -0.968239;0.121304;-0.218628;,
  -0.986285;0.125709;-0.106954;,
  -0.848117;-0.335637;-0.409932;,
  -0.892317;-0.370802;-0.257443;,
  -0.881883;-0.470631;-0.028073;,
  -0.437102;-0.808357;-0.394336;,
  0.000000;0.955207;-0.295940;,
  -0.680971;0.610934;-0.403780;,
  -0.309517;0.896319;-0.317508;,
  -0.687589;-0.141086;-0.712262;,
  -0.874063;0.042069;-0.483987;,
  -0.980745;-0.148455;-0.126886;,
  -0.247177;-0.535997;-0.807224;,
  -0.110879;-0.147199;-0.982872;,
  -0.654222;-0.000655;-0.756302;,
  -0.884744;0.240441;-0.399270;,
  -0.635384;0.712417;-0.297908;,
  -0.225991;-0.231626;-0.946191;,
  -0.766483;-0.113965;-0.632072;,
  -0.237616;-0.567970;-0.788003;,
  -0.813202;0.551284;0.186515;,
  -0.724779;0.688352;-0.029457;,
  -0.966126;0.228090;-0.120729;,
  -0.793926;-0.191291;-0.577139;,
  -0.974330;-0.169393;-0.148282;,
  -0.028016;-0.887974;-0.459039;,
  -0.374190;0.773107;0.512140;,
  0.018697;0.818148;0.574703;,
  0.000111;-0.611154;-0.791511;,
  0.000000;0.965656;-0.259823;,
  0.000000;0.959251;-0.282556;,
  -0.274505;-0.930326;-0.243188;,
  -0.311746;0.948902;0.048983;,
  -0.350006;0.901229;-0.255502;,
  -0.364294;0.865865;0.342882;,
  0.278294;0.780525;0.559761;,
  0.884480;0.419221;0.204813;,
  0.773849;0.554535;0.306021;,
  0.331985;0.853107;0.402485;,
  0.848120;-0.335633;-0.409929;,
  0.986291;0.125707;-0.106903;,
  0.968234;0.121316;-0.218646;,
  0.892303;-0.370823;-0.257459;,
  0.422119;-0.815663;-0.395612;,
  0.918645;-0.394932;-0.010974;,
  0.309517;0.896319;-0.317508;,
  0.680971;0.610934;-0.403779;,
  0.874064;0.042070;-0.483987;,
  0.687563;-0.139789;-0.712542;,
  0.980745;-0.148470;-0.126869;,
  0.731680;0.022632;-0.681272;,
  0.174848;-0.232001;-0.956872;,
  0.186700;-0.464922;-0.865443;,
  0.884743;0.240410;-0.399289;,
  0.635375;0.712414;-0.297934;,
  0.766502;-0.113975;-0.632047;,
  0.277430;-0.589357;-0.758743;,
  0.858244;0.495513;0.133730;,
  0.966146;0.228054;-0.120640;,
  0.724808;0.688320;-0.029483;,
  0.793898;-0.191173;-0.577216;,
  0.974360;-0.169331;-0.148153;,
  -0.023783;-0.927185;-0.373848;,
  0.647483;0.612742;0.453115;,
  0.311717;0.948912;0.048972;,
  0.350005;0.901230;-0.255502;,
  0.961713;0.105119;0.253096;,
  0.841340;0.452993;0.294863;,
  0.588574;-0.807793;0.032409;,
  0.819018;-0.572508;-0.038012;,
  0.573831;0.818275;-0.033806;,
  0.619035;0.783090;0.059719;,
  0.647061;0.738139;0.190952;,
  -0.819018;-0.572506;-0.038049;,
  0.972715;-0.060514;0.223973;,
  0.859535;-0.238978;0.451762;,
  -0.859535;-0.238978;0.451762;,
  -0.972715;-0.060496;0.223977;,
  0.088359;0.409664;-0.907947;,
  0.171068;0.421948;-0.890334;,
  0.084429;0.873315;-0.479783;,
  0.330207;-0.716692;0.614260;,
  0.276379;-0.487644;0.828141;,
  -0.252779;-0.939633;0.230634;,
  0.000000;-0.963662;0.267126;,
  -0.196329;-0.978952;-0.055743;,
  -0.276380;-0.487644;0.828141;,
  -0.330207;-0.716692;0.614260;,
  -0.205081;-0.685832;0.698267;,
  0.923806;-0.293783;0.245507;,
  -0.465693;-0.774952;0.427293;,
  -0.937594;-0.245970;0.245798;,
  0.922289;-0.180383;0.341827;,
  0.999973;-0.007220;0.001377;,
  -0.999973;-0.007220;0.001377;,
  -0.922289;-0.180383;0.341827;,
  0.937582;-0.245984;0.245828;,
  0.611229;-0.767244;-0.194255;,
  0.706106;-0.526614;-0.473384;,
  0.715024;-0.597316;-0.363254;,
  -0.605926;0.774612;0.181193;,
  0.557439;0.825804;0.085498;,
  0.605929;0.774603;0.181219;,
  -0.714957;-0.597475;-0.363125;,
  -0.611237;-0.767232;-0.194279;,
  -0.503090;0.856887;-0.112448;,
  0.503070;0.856890;-0.112516;,
  -0.000864;0.917816;0.397004;,
  0.162852;-0.812351;0.559969;,
  -0.084424;0.873316;-0.479783;,
  0.000000;0.935901;0.352263;,
  0.159774;-0.967978;-0.193625;,
  0.433695;-0.883538;-0.176830;,
  0.000000;0.935901;0.352263;,
  0.000000;-0.980615;-0.195943;,
  -0.487223;-0.853406;-0.185233;,
  0.000000;0.999973;0.007348;,
  -0.038761;-0.998324;-0.042969;,
  -0.065986;-0.996799;-0.045146;,
  0.014751;-0.999773;-0.015395;,
  -0.013885;0.963680;-0.266697;,
  -0.487669;0.873003;-0.006639;,
  0.013884;0.963680;-0.266697;,
  -0.014751;-0.999773;-0.015395;,
  0.065996;-0.996798;-0.045153;,
  0.252779;-0.939633;0.230634;,
  -0.162852;-0.812351;0.559969;,
  0.360460;0.381602;0.851145;,
  0.831111;-0.214131;-0.513228;,
  0.978576;-0.113955;0.171477;,
  -0.978593;-0.114197;0.171218;,
  -0.831074;-0.214198;-0.513260;,
  -0.405170;0.858894;0.313270;,
  0.405144;0.858918;0.313240;,
  -0.301991;0.926335;0.225176;,
  -0.704394;0.688422;0.172930;,
  0.704695;0.688089;0.173028;,
  0.302213;0.926249;0.225232;,
  0.000000;-0.982270;-0.187469;,
  0.081830;-0.201521;0.976060;,
  -0.081770;-0.201628;0.976043;,
  -0.494310;-0.691036;-0.527378;,
  0.260306;-0.831454;-0.490841;,
  0.875877;0.043980;-0.480527;,
  -0.829757;0.355364;-0.430371;,
  -0.955567;0.027960;0.293446;,
  0.622963;-0.781765;0.027573;,
  -0.647062;0.738142;0.190938;,
  -0.619035;0.783090;0.059718;,
  -0.573845;0.818268;-0.033748;,
  -0.965545;-0.142133;0.217994;,
  -0.588587;-0.807785;0.032377;,
  -0.841283;0.453096;0.294867;,
  -0.760713;0.593779;0.262186;,
  0.205081;-0.685832;0.698267;,
  0.875242;-0.378561;0.301069;,
  0.936005;0.182975;0.300691;,
  -0.557427;0.825816;0.085454;,
  -0.618762;0.764230;0.181895;,
  0.618764;0.764218;0.181940;,
  -0.706061;-0.526802;-0.473242;,
  0.124756;-0.925743;0.356982;,
  -0.171045;0.421953;-0.890336;,
  -0.088347;0.409666;-0.907947;,
  0.000000;0.912434;0.409223;,
  0.437838;-0.881517;-0.176711;,
  0.033244;0.996595;-0.075452;,
  0.487637;0.873021;-0.006665;,
  -0.236170;0.971651;0.010837;,
  0.038768;-0.998324;-0.042973;,
  0.758889;0.011304;0.651122;,
  -0.283430;0.316485;0.905265;,
  -0.218993;0.440908;0.870427;,
  0.255235;0.436910;0.862534;,
  -0.124756;-0.925743;0.356982;,
  0.000000;0.376838;0.926279;,
  0.000000;-0.980161;-0.198201;,
  -0.875348;-0.378426;0.300932;,
  -0.923850;-0.293724;0.245412;,
  -0.917272;-0.283808;0.279403;,
  0.551852;0.833915;-0.006678;,
  0.850214;0.482473;0.210609;,
  -0.850180;0.482511;0.210659;,
  -0.551853;0.833915;-0.006678;,
  -0.106024;-0.782764;-0.613221;,
  0.229283;-0.957295;-0.176112;,
  -0.229283;-0.957295;-0.176112;,
  0.419470;0.878929;0.226998;,
  0.000000;0.968793;0.247870;,
  0.000000;0.968230;0.250061;,
  -0.419470;0.878929;0.226998;,
  -0.441921;0.868033;0.226329;,
  0.999711;-0.023990;-0.001327;,
  0.106039;-0.782715;-0.613280;,
  -0.999711;-0.023990;-0.001327;,
  0.441921;0.868033;0.226329;,
  0.146082;-0.759042;-0.634441;,
  -0.146051;-0.759101;-0.634377;,
  0.446273;-0.876581;-0.180127;,
  0.999981;0.002408;0.005635;,
  -0.301948;-0.823170;0.480852;,
  -0.816264;-0.556598;0.154632;,
  -0.760959;-0.037035;-0.647742;,
  0.760899;-0.036924;-0.647819;,
  0.015524;-0.999137;-0.038539;,
  -0.015524;-0.999137;-0.038539;,
  -0.999981;0.002408;0.005635;,
  -0.446273;-0.876581;-0.180127;,
  -0.683066;-0.396043;0.613653;,
  -0.167190;0.959303;0.227561;,
  0.683129;-0.395817;0.613729;,
  0.167230;0.959288;0.227598;,
  -0.053636;-0.432738;0.899923;,
  -0.254413;0.736847;-0.626363;,
  0.053636;-0.432740;0.899922;,
  0.254258;0.736723;-0.626572;,
  -0.005890;-0.452340;0.891826;,
  0.005004;0.394389;-0.918930;,
  -0.005004;0.394389;-0.918930;,
  0.005890;-0.452340;0.891826;,
  -0.888063;-0.442180;-0.125782;,
  0.145355;-0.984549;-0.097647;,
  0.878002;0.448516;0.167169;,
  -0.145335;-0.984554;-0.097633;,
  -0.877942;0.448596;0.167270;,
  -0.799331;0.288872;-0.526900;,
  0.799343;0.288888;-0.526872;,
  -0.719524;-0.027502;-0.693923;,
  -0.210835;0.045118;0.976480;,
  0.719359;-0.026764;-0.694123;,
  0.210945;0.045336;0.976446;,
  0.816264;-0.556598;0.154632;,
  0.812324;-0.553911;0.182519;;
  286;
  3;0,1,2;,
  3;2,3,0;,
  3;4,5,6;,
  3;6,7,4;,
  3;8,7,9;,
  3;10,11,12;,
  3;145,13,14;,
  3;15,3,4;,
  3;13,16,17;,
  3;17,18,13;,
  3;11,14,19;,
  3;19,20,11;,
  3;21,22,18;,
  3;23,6,22;,
  3;2,24,5;,
  3;24,25,26;,
  3;25,20,19;,
  3;13,18,27;,
  3;18,22,28;,
  3;29,9,23;,
  3;30,31,0;,
  3;32,16,146;,
  3;33,34,12;,
  3;1,0,31;,
  3;35,9,29;,
  3;10,12,34;,
  3;16,32,17;,
  3;9,7,6;,
  3;6,23,9;,
  3;0,3,30;,
  3;16,13,145;,
  3;20,25,36;,
  3;11,20,37;,
  3;37,12,11;,
  3;25,24,38;,
  3;24,2,1;,
  3;39,40,41;,
  3;41,42,39;,
  3;43,44,45;,
  3;45,46,43;,
  3;47,46,48;,
  3;49,50,10;,
  3;51,52,147;,
  3;45,40,53;,
  3;52,54,55;,
  3;55,56,52;,
  3;57,51,50;,
  3;50,58,57;,
  3;54,59,55;,
  3;59,43,60;,
  3;44,61,41;,
  3;62,63,61;,
  3;57,58,63;,
  3;64,54,52;,
  3;65,59,54;,
  3;60,47,29;,
  3;39,31,30;,
  3;145,56,32;,
  3;49,34,33;,
  3;31,39,42;,
  3;29,47,66;,
  3;34,49,10;,
  3;17,32,56;,
  3;47,60,43;,
  3;43,46,47;,
  3;67,40,39;,
  3;146,52,56;,
  3;68,63,58;,
  3;50,49,69;,
  3;69,58,50;,
  3;42,61,63;,
  3;42,41,61;,
  3;3,2,5;,
  3;5,4,3;,
  3;148,14,11;,
  3;4,7,15;,
  3;19,14,13;,
  3;22,6,5;,
  3;44,41,40;,
  3;40,45,44;,
  3;53,46,45;,
  3;51,57,52;,
  3;44,43,59;,
  3;53,40,67;,
  3;149,3,15;,
  3;70,71,67;,
  3;72,150,73;,
  3;48,46,53;,
  3;151,152,153;,
  3;15,7,8;,
  3;74,75,76;,
  3;77,154,155;,
  3;30,156,157;,
  3;70,78,79;,
  3;80,81,154;,
  3;82,83,84;,
  3;158,85,86;,
  3;87,88,89;,
  3;9,35,8;,
  3;48,73,70;,
  3;90,91,92;,
  3;159,160,93;,
  3;94,88,87;,
  3;154,77,8;,
  3;95,80,154;,
  3;96,78,97;,
  3;98,81,99;,
  3;70,79,100;,
  3;70,100,48;,
  3;101,102,103;,
  3;104,161,162;,
  3;163,105,106;,
  3;107,164,108;,
  3;72,101,103;,
  3;109,161,104;,
  3;106,105,110;,
  3;107,108,155;,
  3;33,69,49;,
  3;42,111,31;,
  3;112,165,85;,
  3;8,95,154;,
  3;48,66,47;,
  3;113,166,167;,
  3;29,23,60;,
  3;56,55,17;,
  3;30,67,39;,
  3;168,168,114;,
  3;63,62,57;,
  3;54,64,65;,
  3;19,26,25;,
  3;28,27,18;,
  3;115,169,116;,
  3;80,95,89;,
  3;114,117,168;,
  3;115,118,119;,
  3;38,36,25;,
  3;68,120,111;,
  3;121,122,123;,
  3;124,170,171;,
  3;125,172,126;,
  3;127,128,173;,
  3;23,21,55;,
  3;22,21,23;,
  3;8,77,15;,
  3;108,164,15;,
  3;53,102,101;,
  3;53,73,48;,
  3;154,81,30;,
  3;30,168,168;,
  3;174,100,79;,
  3;175,176,177;,
  3;63,68,42;,
  3;111,42,68;,
  3;60,55,59;,
  3;55,60,23;,
  3;178,129,130;,
  3;129,178,89;,
  3;67,78,70;,
  3;67,30,168;,
  3;131,179,175;,
  3;119,180,180;,
  3;132,133,65;,
  3;62,61,44;,
  3;28,134,135;,
  3;5,24,26;,
  3;181,182,183;,
  3;182,181,95;,
  3;184,185,185;,
  3;125,136,172;,
  3;186,186,187;,
  3;160,137,171;,
  3;36,37,20;,
  3;69,33,120;,
  3;138,139,138;,
  3;64,132,65;,
  3;141,140,141;,
  3;28,135,27;,
  3;130,92,91;,
  3;188,66,188;,
  3;142,189,190;,
  3;191,192,193;,
  3;91,178,130;,
  3;100,159,93;,
  3;194,195,193;,
  3;97,196,96;,
  3;89,165,87;,
  3;112,87,165;,
  3;197,66,197;,
  3;85,158,112;,
  3;101,73,53;,
  3;73,101,72;,
  3;155,108,77;,
  3;15,77,108;,
  3;99,198,98;,
  3;193,199,191;,
  3;197,200,197;,
  3;95,8,182;,
  3;188,201,188;,
  3;93,48,100;,
  3;67,71,53;,
  3;162,151,104;,
  3;15,156,30;,
  3;106,76,163;,
  3;36,38,111;,
  3;31,111,1;,
  3;44,59,65;,
  3;65,62,44;,
  3;28,22,5;,
  3;5,26,28;,
  3;142,202,189;,
  3;78,203,97;,
  3;92,130,204;,
  3;87,205,94;,
  3;19,13,206;,
  3;26,19,206;,
  3;207,57,62;,
  3;207,52,57;,
  3;208,121,123;,
  3;187,113,124;,
  3;126,84,184;,
  3;127,173,209;,
  3;79,78,96;,
  3;79,96,174;,
  3;175,99,80;,
  3;99,81,80;,
  3;81,98,210;,
  3;190,211,142;,
  3;212,134,28;,
  3;141,213,141;,
  3;65,133,214;,
  3;138,215,138;,
  3;143,143,216;,
  3;153,217,109;,
  3;218,144,144;,
  3;110,219,74;,
  3;74,106,110;,
  3;76,106,74;,
  3;109,104,153;,
  3;153,104,151;,
  3;120,68,69;,
  3;58,69,68;,
  3;86,220,158;,
  3;172,84,126;,
  3;84,221,82;,
  3;84,172,136;,
  3;137,170,113;,
  3;167,222,113;,
  3;92,223,90;,
  3;124,113,170;,
  3;204,112,158;,
  3;204,94,205;,
  3;111,120,36;,
  3;37,36,120;,
  3;120,33,37;,
  3;12,37,33;,
  3;116,118,115;,
  3;193,192,194;,
  3;52,207,64;,
  3;132,64,207;,
  3;27,206,13;,
  3;206,27,135;,
  3;89,88,129;,
  3;129,88,94;,
  3;18,17,21;,
  3;21,17,55;,
  3;131,174,177;,
  3;119,224,224;,
  3;225,173,128;,
  3;185,226,185;,
  3;122,121,227;,
  3;186,228,186;,
  3;135,229,206;,
  3;135,134,229;,
  3;207,230,132;,
  3;230,133,132;,
  3;107,231,164;,
  3;144,232,144;,
  3;102,233,103;,
  3;143,234,143;,
  3;29,66,35;,
  3;66,8,35;,
  3;235,235,236;,
  3;235,235,129;,
  3;1,38,24;,
  3;38,1,111;,
  3;50,51,147;;
 }
 MeshTextureCoords {
  145;
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;;
 }
}
