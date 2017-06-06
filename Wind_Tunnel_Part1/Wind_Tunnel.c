//By llw0411@gmail.com

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_LEN (519)

FILE *fd_out, *fd_out_All_AVG, *fd_out_All_SD, *fd_out_Pos_AVG, *fd_out_Pos_SD, *fd_out_Neg_AVG, *fd_out_Neg_SD;

char Save_Data[66][9];
char File_Name[12];
char buf[MAX_LEN], *ptr;

//總樣本數 
int Samples;

//總樣本數 > 0 
int Samples_U_1=0,Samples_U_2=0,Samples_U_3=0,Samples_U_4=0,Samples_U_5=0,Samples_U_6=0,Samples_U_7=0,Samples_U_8=0,
Samples_U_9=0,Samples_U_10=0,Samples_U_11=0,Samples_U_12=0,Samples_U_13=0,Samples_U_14=0,Samples_U_15=0,Samples_U_16=0,
Samples_U_17=0,Samples_U_18=0,Samples_U_19=0,Samples_U_20=0,Samples_U_21=0,Samples_U_22=0,Samples_U_23=0,Samples_U_24=0,
Samples_U_25=0,Samples_U_26=0,Samples_U_27=0,Samples_U_28=0,Samples_U_29=0,Samples_U_30=0,Samples_U_31=0,Samples_U_32=0,
Samples_U_33=0,Samples_U_34=0,Samples_U_35=0,Samples_U_36=0,Samples_U_37=0,Samples_U_38=0,Samples_U_39=0,Samples_U_40=0,
Samples_U_41=0,Samples_U_42=0,Samples_U_43=0,Samples_U_44=0,Samples_U_45=0,Samples_U_46=0,Samples_U_47=0,Samples_U_48=0,
Samples_U_49=0,Samples_U_50=0,Samples_U_51=0,Samples_U_52=0,Samples_U_53=0,Samples_U_54=0,Samples_U_55=0,Samples_U_56=0,
Samples_U_57=0,Samples_U_58=0,Samples_U_59=0,Samples_U_60=0,Samples_U_61=0,Samples_U_62=0,Samples_U_63=0,Samples_U_64=0;

//總樣本數 < 0 
int Samples_D_1=0,Samples_D_2=0,Samples_D_3=0,Samples_D_4=0,Samples_D_5=0,Samples_D_6=0,Samples_D_7=0,Samples_D_8=0,
Samples_D_9=0,Samples_D_10=0,Samples_D_11=0,Samples_D_12=0,Samples_D_13=0,Samples_D_14=0,Samples_D_15=0,Samples_D_16=0,
Samples_D_17=0,Samples_D_18=0,Samples_D_19=0,Samples_D_20=0,Samples_D_21=0,Samples_D_22=0,Samples_D_23=0,Samples_D_24=0,
Samples_D_25=0,Samples_D_26=0,Samples_D_27=0,Samples_D_28=0,Samples_D_29=0,Samples_D_30=0,Samples_D_31=0,Samples_D_32=0,
Samples_D_33=0,Samples_D_34=0,Samples_D_35=0,Samples_D_36=0,Samples_D_37=0,Samples_D_38=0,Samples_D_39=0,Samples_D_40=0,
Samples_D_41=0,Samples_D_42=0,Samples_D_43=0,Samples_D_44=0,Samples_D_45=0,Samples_D_46=0,Samples_D_47=0,Samples_D_48=0,
Samples_D_49=0,Samples_D_50=0,Samples_D_51=0,Samples_D_52=0,Samples_D_53=0,Samples_D_54=0,Samples_D_55=0,Samples_D_56=0,
Samples_D_57=0,Samples_D_58=0,Samples_D_59=0,Samples_D_60=0,Samples_D_61=0,Samples_D_62=0,Samples_D_63=0,Samples_D_64=0;

//=========================================================================================//

//AVG Buf
float SV_1=0,SV_2=0,SV_3=0,SV_4=0,SV_5=0,SV_6=0,SV_7=0,SV_8=0,
SV_9=0,SV_10=0,SV_11=0,SV_12=0,SV_13=0,SV_14=0,SV_15=0,SV_16=0,
SV_17=0,SV_18=0,SV_19=0,SV_20=0,SV_21=0,SV_22=0,SV_23=0,SV_24=0,
SV_25=0,SV_26=0,SV_27=0,SV_28=0,SV_29=0,SV_30=0,SV_31=0,SV_32=0,
SV_33=0,SV_34=0,SV_35=0,SV_36=0,SV_37=0,SV_38=0,SV_39=0,SV_40=0,
SV_41=0,SV_42=0,SV_43=0,SV_44=0,SV_45=0,SV_46=0,SV_47=0,SV_48=0,
SV_49=0,SV_50=0,SV_51=0,SV_52=0,SV_53=0,SV_54=0,SV_55=0,SV_56=0,
SV_57=0,SV_58=0,SV_59=0,SV_60=0,SV_61=0,SV_62=0,SV_63=0,SV_64=0;

//AVG > 0 Buf
float SV_1_U=0,SV_2_U=0,SV_3_U=0,SV_4_U=0,SV_5_U=0,SV_6_U=0,SV_7_U=0,SV_8_U=0,
SV_9_U=0,SV_10_U=0,SV_11_U=0,SV_12_U=0,SV_13_U=0,SV_14_U=0,SV_15_U=0,SV_16_U=0,
SV_17_U =0,SV_18_U =0,SV_19_U =0,SV_20_U =0,SV_21_U =0,SV_22_U =0,SV_23_U =0,SV_24_U =0,
SV_25_U =0,SV_26_U =0,SV_27_U =0,SV_28_U =0,SV_29_U =0,SV_30_U =0,SV_31_U =0,SV_32_U =0,
SV_33_U =0,SV_34_U =0,SV_35_U =0,SV_36_U =0,SV_37_U =0,SV_38_U =0,SV_39_U =0,SV_40_U =0,
SV_41_U =0,SV_42_U =0,SV_43_U =0,SV_44_U =0,SV_45_U =0,SV_46_U =0,SV_47_U =0,SV_48_U =0,
SV_49_U =0,SV_50_U =0,SV_51_U =0,SV_52_U =0,SV_53_U =0,SV_54_U =0,SV_55_U =0,SV_56_U =0,
SV_57_U =0,SV_58_U =0,SV_59_U =0,SV_60_U =0,SV_61_U =0,SV_62_U =0,SV_63_U =0,SV_64_U =0;

//AVG < 0 Buf
float SV_1_D=0,SV_2_D=0,SV_3_D=0,SV_4_D=0,SV_5_D=0,SV_6_D=0,SV_7_D=0,SV_8_D=0,
SV_9_D=0,SV_10_D=0,SV_11_D=0,SV_12_D=0,SV_13_D=0,SV_14_D=0,SV_15_D=0,SV_16_D=0,
SV_17_D =0,SV_18_D =0,SV_19_D =0,SV_20_D =0,SV_21_D =0,SV_22_D =0,SV_23_D =0,SV_24_D =0,
SV_25_D =0,SV_26_D =0,SV_27_D =0,SV_28_D =0,SV_29_D =0,SV_30_D =0,SV_31_D =0,SV_32_D =0,
SV_33_D =0,SV_34_D =0,SV_35_D =0,SV_36_D =0,SV_37_D =0,SV_38_D =0,SV_39_D =0,SV_40_D =0,
SV_41_D =0,SV_42_D =0,SV_43_D =0,SV_44_D =0,SV_45_D =0,SV_46_D =0,SV_47_D =0,SV_48_D =0,
SV_49_D =0,SV_50_D =0,SV_51_D =0,SV_52_D =0,SV_53_D =0,SV_54_D =0,SV_55_D =0,SV_56_D =0,
SV_57_D =0,SV_58_D =0,SV_59_D =0,SV_60_D =0,SV_61_D =0,SV_62_D =0,SV_63_D =0,SV_64_D =0;

//AVG Save By Compute Finsh 
float AVG_1=0,AVG_2=0,AVG_3=0,AVG_4=0,AVG_5=0,AVG_6=0,AVG_7=0,AVG_8=0,
AVG_9=0,AVG_10=0,AVG_11=0,AVG_12=0,AVG_13=0,AVG_14=0,AVG_15=0,AVG_16=0,
AVG_17=0,AVG_18=0,AVG_19=0,AVG_20=0,AVG_21=0,AVG_22=0,AVG_23=0,AVG_24=0,
AVG_25=0,AVG_26=0,AVG_27=0,AVG_28=0,AVG_29=0,AVG_30=0,AVG_31=0,AVG_32=0,
AVG_33=0,AVG_34=0,AVG_35=0,AVG_36=0,AVG_37=0,AVG_38=0,AVG_39=0,AVG_40=0,
AVG_41=0,AVG_42=0,AVG_43=0,AVG_44=0,AVG_45=0,AVG_46=0,AVG_47=0,AVG_48=0,
AVG_49=0,AVG_50=0,AVG_51=0,AVG_52=0,AVG_53=0,AVG_54=0,AVG_55=0,AVG_56=0,
AVG_57=0,AVG_58=0,AVG_59=0,AVG_60=0,AVG_61=0,AVG_62=0,AVG_63=0,AVG_64=0;

//=========================================================================================//

//SD Buf 
double sv_1=0,sv_2=0,sv_3=0,sv_4=0,sv_5=0,sv_6=0,sv_7=0,sv_8=0,
sv_9=0,sv_10=0,sv_11=0,sv_12=0,sv_13=0,sv_14=0,sv_15=0,sv_16=0,
sv_17=0,sv_18=0,sv_19=0,sv_20=0,sv_21=0,sv_22=0,sv_23=0,sv_24=0,
sv_25=0,sv_26=0,sv_27=0,sv_28=0,sv_29=0,sv_30=0,sv_31=0,sv_32=0,
sv_33=0,sv_34=0,sv_35=0,sv_36=0,sv_37=0,sv_38=0,sv_39=0,sv_40=0,
sv_41=0,sv_42=0,sv_43=0,sv_44=0,sv_45=0,sv_46=0,sv_47=0,sv_48=0,
sv_49=0,sv_50=0,sv_51=0,sv_52=0,sv_53=0,sv_54=0,sv_55=0,sv_56=0,
sv_57=0,sv_58=0,sv_59=0,sv_60=0,sv_61=0,sv_62=0,sv_63=0,sv_64=0;

//SD > 0 Buf
double sv_1_U=0,sv_2_U=0,sv_3_U=0,sv_4_U=0,sv_5_U=0,sv_6_U=0,sv_7_U=0,sv_8_U=0,
sv_9_U=0,sv_10_U=0,sv_11_U=0,sv_12_U=0,sv_13_U=0,sv_14_U=0,sv_15_U=0,sv_16_U=0,
sv_17_U =0,sv_18_U =0,sv_19_U =0,sv_20_U =0,sv_21_U =0,sv_22_U =0,sv_23_U =0,sv_24_U =0,
sv_25_U =0,sv_26_U =0,sv_27_U =0,sv_28_U =0,sv_29_U =0,sv_30_U =0,sv_31_U =0,sv_32_U =0,
sv_33_U =0,sv_34_U =0,sv_35_U =0,sv_36_U =0,sv_37_U =0,sv_38_U =0,sv_39_U =0,sv_40_U =0,
sv_41_U =0,sv_42_U =0,sv_43_U =0,sv_44_U =0,sv_45_U =0,sv_46_U =0,sv_47_U =0,sv_48_U =0,
sv_49_U =0,sv_50_U =0,sv_51_U =0,sv_52_U =0,sv_53_U =0,sv_54_U =0,sv_55_U =0,sv_56_U =0,
sv_57_U =0,sv_58_U =0,sv_59_U =0,sv_60_U =0,sv_61_U =0,sv_62_U =0,sv_63_U =0,sv_64_U =0;


//SD < 0 Buf
double sv_1_D=0,sv_2_D=0,sv_3_D=0,sv_4_D=0,sv_5_D=0,sv_6_D=0,sv_7_D=0,sv_8_D=0,
sv_9_D=0,sv_10_D=0,sv_11_D=0,sv_12_D=0,sv_13_D=0,sv_14_D=0,sv_15_D=0,sv_16_D=0,
sv_17_D =0,sv_18_D =0,sv_19_D =0,sv_20_D =0,sv_21_D =0,sv_22_D =0,sv_23_D =0,sv_24_D =0,
sv_25_D =0,sv_26_D =0,sv_27_D =0,sv_28_D =0,sv_29_D =0,sv_30_D =0,sv_31_D =0,sv_32_D =0,
sv_33_D =0,sv_34_D =0,sv_35_D =0,sv_36_D =0,sv_37_D =0,sv_38_D =0,sv_39_D =0,sv_40_D =0,
sv_41_D =0,sv_42_D =0,sv_43_D =0,sv_44_D =0,sv_45_D =0,sv_46_D =0,sv_47_D =0,sv_48_D =0,
sv_49_D =0,sv_50_D =0,sv_51_D =0,sv_52_D =0,sv_53_D =0,sv_54_D =0,sv_55_D =0,sv_56_D =0,
sv_57_D =0,sv_58_D =0,sv_59_D =0,sv_60_D =0,sv_61_D =0,sv_62_D =0,sv_63_D =0,sv_64_D =0;


//SD Save By Compute Finsh
double SD_1=0,SD_2=0,SD_3=0,SD_4=0,SD_5=0,SD_6=0,SD_7=0,SD_8=0,
SD_9=0,SD_10=0,SD_11=0,SD_12=0,SD_13=0,SD_14=0,SD_15=0,SD_16=0,
SD_17=0,SD_18=0,SD_19=0,SD_20=0,SD_21=0,SD_22=0,SD_23=0,SD_24=0,
SD_25=0,SD_26=0,SD_27=0,SD_28=0,SD_29=0,SD_30=0,SD_31=0,SD_32=0,
SD_33=0,SD_34=0,SD_35=0,SD_36=0,SD_37=0,SD_38=0,SD_39=0,SD_40=0,
SD_41=0,SD_42=0,SD_43=0,SD_44=0,SD_45=0,SD_46=0,SD_47=0,SD_48=0,
SD_49=0,SD_50=0,SD_51=0,SD_52=0,SD_53=0,SD_54=0,SD_55=0,SD_56=0,
SD_57=0,SD_58=0,SD_59=0,SD_60=0,SD_61=0,SD_62=0,SD_63=0,SD_64=0;

//=========================================================================================//

//AVG Buf for SD Count
double SVD_1=0,SVD_2=0,SVD_3=0,SVD_4=0,SVD_5=0,SVD_6=0,SVD_7=0,SVD_8=0,
SVD_9=0,SVD_10=0,SVD_11=0,SVD_12=0,SVD_13=0,SVD_14=0,SVD_15=0,SVD_16=0,
SVD_17=0,SVD_18=0,SVD_19=0,SVD_20=0,SVD_21=0,SVD_22=0,SVD_23=0,SVD_24=0,
SVD_25=0,SVD_26=0,SVD_27=0,SVD_28=0,SVD_29=0,SVD_30=0,SVD_31=0,SVD_32=0,
SVD_33=0,SVD_34=0,SVD_35=0,SVD_36=0,SVD_37=0,SVD_38=0,SVD_39=0,SVD_40=0,
SVD_41=0,SVD_42=0,SVD_43=0,SVD_44=0,SVD_45=0,SVD_46=0,SVD_47=0,SVD_48=0,
SVD_49=0,SVD_50=0,SVD_51=0,SVD_52=0,SVD_53=0,SVD_54=0,SVD_55=0,SVD_56=0,
SVD_57=0,SVD_58=0,SVD_59=0,SVD_60=0,SVD_61=0,SVD_62=0,SVD_63=0,SVD_64=0;

//AVG > 0 Buf for SD Count
double SVD_1_U=0,SVD_2_U=0,SVD_3_U=0,SVD_4_U=0,SVD_5_U=0,SVD_6_U=0,SVD_7_U=0,SVD_8_U=0,
SVD_9_U=0,SVD_10_U=0,SVD_11_U=0,SVD_12_U=0,SVD_13_U=0,SVD_14_U=0,SVD_15_U=0,SVD_16_U=0,
SVD_17_U =0,SVD_18_U =0,SVD_19_U =0,SVD_20_U =0,SVD_21_U =0,SVD_22_U =0,SVD_23_U =0,SVD_24_U =0,
SVD_25_U =0,SVD_26_U =0,SVD_27_U =0,SVD_28_U =0,SVD_29_U =0,SVD_30_U =0,SVD_31_U =0,SVD_32_U =0,
SVD_33_U =0,SVD_34_U =0,SVD_35_U =0,SVD_36_U =0,SVD_37_U =0,SVD_38_U =0,SVD_39_U =0,SVD_40_U =0,
SVD_41_U =0,SVD_42_U =0,SVD_43_U =0,SVD_44_U =0,SVD_45_U =0,SVD_46_U =0,SVD_47_U =0,SVD_48_U =0,
SVD_49_U =0,SVD_50_U =0,SVD_51_U =0,SVD_52_U =0,SVD_53_U =0,SVD_54_U =0,SVD_55_U =0,SVD_56_U =0,
SVD_57_U =0,SVD_58_U =0,SVD_59_U =0,SVD_60_U =0,SVD_61_U =0,SVD_62_U =0,SVD_63_U =0,SVD_64_U =0;

//AVG < 0 Buf for SD Count
float SVD_1_D=0,SVD_2_D=0,SVD_3_D=0,SVD_4_D=0,SVD_5_D=0,SVD_6_D=0,SVD_7_D=0,SVD_8_D=0,
SVD_9_D=0,SVD_10_D=0,SVD_11_D=0,SVD_12_D=0,SVD_13_D=0,SVD_14_D=0,SVD_15_D=0,SVD_16_D=0,
SVD_17_D =0,SVD_18_D =0,SVD_19_D =0,SVD_20_D =0,SVD_21_D =0,SVD_22_D =0,SVD_23_D =0,SVD_24_D =0,
SVD_25_D =0,SVD_26_D =0,SVD_27_D =0,SVD_28_D =0,SVD_29_D =0,SVD_30_D =0,SVD_31_D =0,SVD_32_D =0,
SVD_33_D =0,SVD_34_D =0,SVD_35_D =0,SVD_36_D =0,SVD_37_D =0,SVD_38_D =0,SVD_39_D =0,SVD_40_D =0,
SVD_41_D =0,SVD_42_D =0,SVD_43_D =0,SVD_44_D =0,SVD_45_D =0,SVD_46_D =0,SVD_47_D =0,SVD_48_D =0,
SVD_49_D =0,SVD_50_D =0,SVD_51_D =0,SVD_52_D =0,SVD_53_D =0,SVD_54_D =0,SVD_55_D =0,SVD_56_D =0,
SVD_57_D =0,SVD_58_D =0,SVD_59_D =0,SVD_60_D =0,SVD_61_D =0,SVD_62_D =0,SVD_63_D =0,SVD_64_D =0;

//AVG Save By Compute Finsh for SD Count
double AVGD_1=0,AVGD_2=0,AVGD_3=0,AVGD_4=0,AVGD_5=0,AVGD_6=0,AVGD_7=0,AVGD_8=0,
AVGD_9=0,AVGD_10=0,AVGD_11=0,AVGD_12=0,AVGD_13=0,AVGD_14=0,AVGD_15=0,AVGD_16=0,
AVGD_17=0,AVGD_18=0,AVGD_19=0,AVGD_20=0,AVGD_21=0,AVGD_22=0,AVGD_23=0,AVGD_24=0,
AVGD_25=0,AVGD_26=0,AVGD_27=0,AVGD_28=0,AVGD_29=0,AVGD_30=0,AVGD_31=0,AVGD_32=0,
AVGD_33=0,AVGD_34=0,AVGD_35=0,AVGD_36=0,AVGD_37=0,AVGD_38=0,AVGD_39=0,AVGD_40=0,
AVGD_41=0,AVGD_42=0,AVGD_43=0,AVGD_44=0,AVGD_45=0,AVGD_46=0,AVGD_47=0,AVGD_48=0,
AVGD_49=0,AVGD_50=0,AVGD_51=0,AVGD_52=0,AVGD_53=0,AVGD_54=0,AVGD_55=0,AVGD_56=0,
AVGD_57=0,AVGD_58=0,AVGD_59=0,AVGD_60=0,AVGD_61=0,AVGD_62=0,AVGD_63=0,AVGD_64=0;

//=========================================================================================//

//初始化 
void Initialization()
{
 int CLR_1,CLR_2;
 for(CLR_1=0;CLR_1<=66;CLR_1++)
 {
     for(CLR_2=0;CLR_2<=9;CLR_2++)
     {
         Save_Data[CLR_1][CLR_2] = (char) 0;
     }
 }
 
 int CLR_3;
 for(CLR_3=0;CLR_3<=519;CLR_3++)
 {
     buf[CLR_3]=(char) 0;
 }
 
 int CLR_4;
 for(CLR_4=0;CLR_4<=12;CLR_4++)
 {
     File_Name[CLR_4]=(char) 0;
 }  
}

//全Data計算 & 分別輸出AVG與SD各自的表單 
void All_AVG_SD()
{       
     AVG_1=SV_1/Samples;
     AVGD_1=SVD_1/Samples;
     SD_1=(sv_1/(Samples))-((AVGD_1)*(AVGD_1));
     SD_1=pow(SD_1,0.5);
     fprintf(fd_out,"1: %f %lf\n",AVG_1,SD_1);
     
     AVG_2=SV_2/Samples;
     AVGD_2=SVD_2/Samples;
     SD_2=(sv_2/(Samples))-((AVGD_2)*(AVGD_2));
     SD_2=pow(SD_2,0.5);
     fprintf(fd_out,"2: %f %lf\n",AVG_2,SD_2);
     
     AVG_3=SV_3/Samples;
     AVGD_3=SVD_3/Samples;
     SD_3=(sv_3/(Samples))-((AVGD_3)*(AVGD_3));
     SD_3=pow(SD_3,0.5);
     fprintf(fd_out,"3: %f %lf\n",AVG_3,SD_3);
    
     AVG_4=SV_4/Samples;
     AVGD_4=SVD_4/Samples;
     SD_4=(sv_4/(Samples))-((AVGD_4)*(AVGD_4));
     SD_4=pow(SD_4,0.5);
     fprintf(fd_out,"4: %f %lf\n",AVG_4,SD_4);
  
     AVG_5=SV_5/Samples;
     AVGD_5=SVD_5/Samples;
     SD_5=(sv_5/(Samples))-((AVGD_5)*(AVGD_5));
     SD_5=pow(SD_5,0.5);
     fprintf(fd_out,"5: %f %lf\n",AVG_5,SD_5);

     AVG_6=SV_6/Samples;
     AVGD_6=SVD_6/Samples;
     SD_6=(sv_6/(Samples))-((AVGD_6)*(AVGD_6));
     SD_6=pow(SD_6,0.5);
     fprintf(fd_out,"6: %f %lf\n",AVG_6,SD_6);
 
     AVG_7=SV_7/Samples;
     AVGD_7=SVD_7/Samples;
     SD_7=(sv_7/(Samples))-((AVGD_7)*(AVGD_7));
     SD_7=pow(SD_7,0.5);
     fprintf(fd_out,"7: %f %lf\n",AVG_7,SD_7);
 
     AVG_8=SV_8/Samples;
     AVGD_8=SVD_8/Samples;
     SD_8=(sv_8/(Samples))-((AVGD_8)*(AVGD_8));
     SD_8=pow(SD_8,0.5);
     fprintf(fd_out,"8: %f %lf\n",AVG_8,SD_8);
 
     AVG_9=SV_9/Samples;
     AVGD_9=SVD_9/Samples;
     SD_9=(sv_9/(Samples))-((AVGD_9)*(AVGD_9));
     SD_9=pow(SD_9,0.5);
     fprintf(fd_out,"9: %f %lf\n",AVG_9,SD_9);

     AVG_10=SV_10/Samples;
     AVGD_10=SVD_10/Samples;
     SD_10=(sv_10/(Samples))-((AVGD_10)*(AVGD_10));
     SD_10=pow(SD_10,0.5);
     fprintf(fd_out,"10: %f %lf\n",AVG_10,SD_10);
 
     AVG_11=SV_11/Samples;
     AVGD_11=SVD_11/Samples;
     SD_11=(sv_11/(Samples))-((AVGD_11)*(AVGD_11));
     SD_11=pow(SD_11,0.5);
     fprintf(fd_out,"11: %f %lf\n",AVG_11,SD_11);
   
     AVG_12=SV_12/Samples;
     AVGD_12=SVD_12/Samples;
     SD_12=(sv_12/(Samples))-((AVGD_12)*(AVGD_12));
     SD_12=pow(SD_12,0.5);
     fprintf(fd_out,"12: %f %lf\n",AVG_12,SD_12);
    
     AVG_13=SV_13/Samples;
     AVGD_13=SVD_13/Samples;
     SD_13=(sv_13/(Samples))-((AVGD_13)*(AVGD_13));
     SD_13=pow(SD_13,0.5);
     fprintf(fd_out,"13: %f %lf\n",AVG_13,SD_13);
    
     AVG_14=SV_14/Samples;
     AVGD_14=SVD_14/Samples;
     SD_14=(sv_14/(Samples))-((AVGD_14)*(AVGD_14));
     SD_14=pow(SD_14,0.5);
     fprintf(fd_out,"14: %f %lf\n",AVG_14,SD_14);
    
     AVG_15=SV_15/Samples;
     AVGD_15=SVD_15/Samples;
     SD_15=(sv_15/(Samples))-((AVGD_15)*(AVGD_15));
     SD_15=pow(SD_15,0.5);
     fprintf(fd_out,"15: %f %lf\n",AVG_15,SD_15);

     AVG_16=SV_16/Samples;
     AVGD_16=SVD_16/Samples;
     SD_16=(sv_16/(Samples))-((AVGD_16)*(AVGD_16));
     SD_16=pow(SD_16,0.5);
     fprintf(fd_out,"16: %f %lf\n",AVG_16,SD_16);

     AVG_17=SV_17/Samples;
     AVGD_17=SVD_17/Samples;
     SD_17=(sv_17/(Samples))-((AVGD_17)*(AVGD_17));
     SD_17=pow(SD_17,0.5);
     fprintf(fd_out,"17: %f %lf\n",AVG_17,SD_17);

     AVG_18=SV_18/Samples;
     AVGD_18=SVD_18/Samples;
     SD_18=(sv_18/(Samples))-((AVGD_18)*(AVGD_18));
     SD_18=pow(SD_18,0.5);
     fprintf(fd_out,"18: %f %lf\n",AVG_18,SD_18);
     
     AVG_19=SV_19/Samples;
     AVGD_19=SVD_19/Samples;
     SD_19=(sv_19/(Samples))-((AVGD_19)*(AVGD_19));
     SD_19=pow(SD_19,0.5);
     fprintf(fd_out,"19: %f %lf\n",AVG_19,SD_19);

     AVG_20=SV_20/Samples;
     AVGD_20=SVD_20/Samples;
     SD_20=(sv_20/(Samples))-((AVGD_20)*(AVGD_20));
     SD_20=pow(SD_20,0.5);
     fprintf(fd_out,"20: %f %lf\n",AVG_20,SD_20);
     
     AVG_21=SV_21/Samples;
     AVGD_21=SVD_21/Samples;
     SD_21=(sv_21/(Samples))-((AVGD_21)*(AVGD_21));
     SD_21=pow(SD_21,0.5);
     fprintf(fd_out,"21: %f %lf\n",AVG_21,SD_21);

     AVG_22=SV_22/Samples;
     AVGD_22=SVD_22/Samples;
     SD_22=(sv_22/(Samples))-((AVGD_22)*(AVGD_22));
     SD_22=pow(SD_22,0.5);
     fprintf(fd_out,"22: %f %lf\n",AVG_22,SD_22);

     AVG_23=SV_23/Samples;
     AVGD_23=SVD_23/Samples;
     SD_23=(sv_23/(Samples))-((AVGD_23)*(AVGD_23));
     SD_23=pow(SD_23,0.5);
     fprintf(fd_out,"23: %f %lf\n",AVG_23,SD_23);
     
     AVG_24=SV_24/Samples;
     AVGD_24=SVD_24/Samples;
     SD_24=(sv_24/(Samples))-((AVGD_24)*(AVGD_24));
     SD_24=pow(SD_24,0.5);
     fprintf(fd_out,"24: %f %lf\n",AVG_24,SD_24);
     
     AVG_25=SV_25/Samples;
     AVGD_25=SVD_25/Samples;
     SD_25=(sv_25/(Samples))-((AVGD_25)*(AVGD_25));
     SD_25=pow(SD_25,0.5);
     fprintf(fd_out,"25: %f %lf\n",AVG_25,SD_25);
    
     AVG_26=SV_26/Samples;
     AVGD_26=SVD_26/Samples;
     SD_26=(sv_26/(Samples))-((AVGD_26)*(AVGD_26));
     SD_26=pow(SD_26,0.5);
     fprintf(fd_out,"26: %f %lf\n",AVG_26,SD_26);
     
     AVG_27=SV_27/Samples;
     AVGD_27=SVD_27/Samples;
     SD_27=(sv_27/(Samples))-((AVGD_27)*(AVGD_27));
     SD_27=pow(SD_27,0.5);
     fprintf(fd_out,"27: %f %lf\n",AVG_27,SD_27);
     
     AVG_28=SV_28/Samples;
     AVGD_28=SVD_28/Samples;
     SD_28=(sv_28/(Samples))-((AVGD_28)*(AVGD_28));
     SD_28=pow(SD_28,0.5);
     fprintf(fd_out,"28: %f %lf\n",AVG_28,SD_28);
    
     AVG_29=SV_29/Samples;
     AVGD_29=SVD_29/Samples;
     SD_29=(sv_29/(Samples))-((AVGD_29)*(AVGD_29));
     SD_29=pow(SD_29,0.5);
     fprintf(fd_out,"29: %f %lf\n",AVG_29,SD_29);
 
     AVG_30=SV_30/Samples;
     AVGD_30=SVD_30/Samples;
     SD_30=(sv_30/(Samples))-((AVGD_30)*(AVGD_30));
     SD_30=pow(SD_30,0.5);
     fprintf(fd_out,"30: %f %lf\n",AVG_30,SD_30);
 
     AVG_31=SV_31/Samples;
     AVGD_31=SVD_31/Samples;
     SD_31=(sv_31/(Samples))-((AVGD_31)*(AVGD_31));
     SD_31=pow(SD_31,0.5);
     fprintf(fd_out,"31: %f %lf\n",AVG_31,SD_31);
     
     AVG_32=SV_32/Samples;
     AVGD_32=SVD_32/Samples;
     SD_32=(sv_32/(Samples))-((AVGD_32)*(AVGD_32));
     SD_32=pow(SD_32,0.5);
     fprintf(fd_out,"32: %f %lf\n",AVG_32,SD_32);
 
     AVG_33=SV_33/Samples;
     AVGD_33=SVD_33/Samples;
     SD_33=(sv_33/(Samples))-((AVGD_33)*(AVGD_33));
     SD_33=pow(SD_33,0.5);
     fprintf(fd_out,"33: %f %lf\n",AVG_33,SD_33);
     
     AVG_34=SV_34/Samples;
     AVGD_34=SVD_34/Samples;
     SD_34=(sv_34/(Samples))-((AVGD_34)*(AVGD_34));
     SD_34=pow(SD_34,0.5);
     fprintf(fd_out,"34: %f %lf\n",AVG_34,SD_34);
     
     AVG_35=SV_35/Samples;
     AVGD_35=SVD_35/Samples;
     SD_35=(sv_35/(Samples))-((AVGD_35)*(AVGD_35));
     SD_35=pow(SD_35,0.5);
     fprintf(fd_out,"35: %f %lf\n",AVG_35,SD_35);
  
     AVG_36=SV_36/Samples;
     AVGD_36=SVD_36/Samples;
     SD_36=(sv_36/(Samples))-((AVGD_36)*(AVGD_36));
     SD_36=pow(SD_36,0.5);
     fprintf(fd_out,"36: %f %lf\n",AVG_36,SD_36);
  
     AVG_37=SV_37/Samples;
     AVGD_37=SVD_37/Samples;
     SD_37=(sv_37/(Samples))-((AVGD_37)*(AVGD_37));
     SD_37=pow(SD_37,0.5);
     fprintf(fd_out,"37: %f %lf\n",AVG_37,SD_37);
     
     AVG_38=SV_38/Samples;
     AVGD_38=SVD_38/Samples;
     SD_38=(sv_38/(Samples))-((AVGD_38)*(AVGD_38));
     SD_38=pow(SD_38,0.5);
     fprintf(fd_out,"38: %f %lf\n",AVG_38,SD_38);
     
     AVG_39=SV_39/Samples;
     AVGD_39=SVD_39/Samples;
     SD_39=(sv_39/(Samples))-((AVGD_39)*(AVGD_39));
     SD_39=pow(SD_39,0.5);
     fprintf(fd_out,"39: %f %lf\n",AVG_39,SD_39);
      
     AVG_40=SV_40/Samples;
     AVGD_40=SVD_40/Samples;
     SD_40=(sv_40/(Samples))-((AVGD_40)*(AVGD_40));
     SD_40=pow(SD_40,0.5);
     fprintf(fd_out,"40: %f %lf\n",AVG_40,SD_40);
     
     AVG_41=SV_41/Samples;
     AVGD_41=SVD_41/Samples;
     SD_41=(sv_41/(Samples))-((AVGD_41)*(AVGD_41));
     SD_41=pow(SD_41,0.5);
     fprintf(fd_out,"41: %f %lf\n",AVG_41,SD_41);
     
     AVG_42=SV_42/Samples;
     AVGD_42=SVD_42/Samples;
     SD_42=(sv_42/(Samples))-((AVGD_42)*(AVGD_42));
     SD_42=pow(SD_42,0.5);
     fprintf(fd_out,"42: %f %lf\n",AVG_42,SD_42);
     
     AVG_43=SV_43/Samples;
     AVGD_43=SVD_43/Samples;
     SD_43=(sv_43/(Samples))-((AVGD_43)*(AVGD_43));
     SD_43=pow(SD_43,0.5);
     fprintf(fd_out,"43: %f %lf\n",AVG_43,SD_43);
     
     AVG_44=SV_44/Samples;
     AVGD_44=SVD_44/Samples;
     SD_44=(sv_44/(Samples))-((AVGD_44)*(AVGD_44));
     SD_44=pow(SD_44,0.5);
     fprintf(fd_out,"44: %f %lf\n",AVG_44,SD_44);
     
     AVG_45=SV_45/Samples;
     AVGD_45=SVD_45/Samples;
     SD_45=(sv_45/(Samples))-((AVGD_45)*(AVGD_45));
     SD_45=pow(SD_45,0.5);
     fprintf(fd_out,"45: %f %lf\n",AVG_45,SD_45);
     
     AVG_46=SV_46/Samples;
     AVGD_46=SVD_46/Samples;
     SD_46=(sv_46/(Samples))-((AVGD_46)*(AVGD_46));
     SD_46=pow(SD_46,0.5);
     fprintf(fd_out,"46: %f %lf\n",AVG_46,SD_46);
     
     AVG_47=SV_47/Samples;
     AVGD_47=SVD_47/Samples;
     SD_47=(sv_47/(Samples))-((AVGD_47)*(AVGD_47));
     SD_47=pow(SD_47,0.5);
     fprintf(fd_out,"47: %f %lf\n",AVG_47,SD_47);
     
     AVG_48=SV_48/Samples;
     AVGD_48=SVD_48/Samples;
     SD_48=(sv_48/(Samples))-((AVGD_48)*(AVGD_48));
     SD_48=pow(SD_48,0.5);
     fprintf(fd_out,"48: %f %lf\n",AVG_48,SD_48);
     
     AVG_49=SV_49/Samples;
     AVGD_49=SVD_49/Samples;
     SD_49=(sv_49/(Samples))-((AVGD_49)*(AVGD_49));
     SD_49=pow(SD_49,0.5);
     fprintf(fd_out,"49: %f %lf\n",AVG_49,SD_49);
     
     AVG_50=SV_50/Samples;
     AVGD_50=SVD_50/Samples;
     SD_50=(sv_50/(Samples))-((AVGD_50)*(AVGD_50));
     SD_50=pow(SD_50,0.5);
     fprintf(fd_out,"50: %f %lf\n",AVG_50,SD_50);
     
     AVG_51=SV_51/Samples;
     AVGD_51=SVD_51/Samples;
     SD_51=(sv_51/(Samples))-((AVGD_51)*(AVGD_51));
     SD_51=pow(SD_51,0.5);
     fprintf(fd_out,"51: %f %lf\n",AVG_51,SD_51);
     
     AVG_52=SV_52/Samples;
     AVGD_52=SVD_52/Samples;
     SD_52=(sv_52/(Samples))-((AVGD_52)*(AVGD_52));
     SD_52=pow(SD_52,0.5);
     fprintf(fd_out,"52: %f %lf\n",AVG_52,SD_52);
     
     AVG_53=SV_53/Samples;
     AVGD_53=SVD_53/Samples;
     SD_53=(sv_53/(Samples))-((AVGD_53)*(AVGD_53));
     SD_53=pow(SD_53,0.5);
     fprintf(fd_out,"53: %f %lf\n",AVG_53,SD_53);
    
     AVG_54=SV_54/Samples;
     AVGD_54=SVD_54/Samples;
     SD_54=(sv_54/(Samples))-((AVGD_54)*(AVGD_54));
     SD_54=pow(SD_54,0.5);
     fprintf(fd_out,"54: %f %lf\n",AVG_54,SD_54);
     
     AVG_55=SV_55/Samples;
     AVGD_55=SVD_55/Samples;
     SD_55=(sv_55/(Samples))-((AVGD_55)*(AVGD_55));
     SD_55=pow(SD_55,0.5);
     fprintf(fd_out,"55: %f %lf\n",AVG_55,SD_55);
     
     AVG_56=SV_56/Samples;
     AVGD_56=SVD_56/Samples;
     SD_56=(sv_56/(Samples))-((AVGD_56)*(AVGD_56));
     SD_56=pow(SD_56,0.5);
     fprintf(fd_out,"56: %f %lf\n",AVG_56,SD_56);
     
     AVG_57=SV_57/Samples;
     AVGD_57=SVD_57/Samples;
     SD_57=(sv_57/(Samples))-((AVGD_57)*(AVGD_57));
     SD_57=pow(SD_57,0.5);
     fprintf(fd_out,"57: %f %lf\n",AVG_57,SD_57);
     
     AVG_58=SV_58/Samples;
     AVGD_58=SVD_58/Samples;
     SD_58=(sv_58/(Samples))-((AVGD_58)*(AVGD_58));
     SD_58=pow(SD_58,0.5);
     fprintf(fd_out,"58: %f %lf\n",AVG_58,SD_58);
    
     AVG_59=SV_59/Samples;
     AVGD_59=SVD_59/Samples;
     SD_59=(sv_59/(Samples))-((AVGD_59)*(AVGD_59));
     SD_59=pow(SD_59,0.5);
     fprintf(fd_out,"59: %f %lf\n",AVG_59,SD_59);
    
     AVG_60=SV_60/Samples;
     AVGD_60=SVD_60/Samples;
     SD_60=(sv_60/(Samples))-((AVGD_60)*(AVGD_60));
     SD_60=pow(SD_60,0.5);
     fprintf(fd_out,"60: %f %lf\n",AVG_60,SD_60);
     
     AVG_61=SV_61/Samples;
     AVGD_61=SVD_61/Samples;
     SD_61=(sv_61/(Samples))-((AVGD_61)*(AVGD_61));
     SD_61=pow(SD_61,0.5);
     fprintf(fd_out,"61: %f %lf\n",AVG_61,SD_61);
     
     AVG_62=SV_62/Samples;
     AVGD_62=SVD_62/Samples;
     SD_62=(sv_62/(Samples))-((AVGD_62)*(AVGD_62));
     SD_62=pow(SD_62,0.5);
     fprintf(fd_out,"62: %f %lf\n",AVG_62,SD_62);
     
     AVG_63=SV_63/Samples;
     AVGD_63=SVD_63/Samples;
     SD_63=(sv_63/(Samples))-((AVGD_63)*(AVGD_63));
     SD_63=pow(SD_63,0.5);
     fprintf(fd_out,"63: %f %lf\n",AVG_63,SD_63);
     
     AVG_64=SV_64/Samples;
     AVGD_64=SVD_64/Samples;
     SD_64=(sv_64/(Samples))-((AVGD_64)*(AVGD_64));
     SD_64=pow(SD_64,0.5);
     fprintf(fd_out,"64: %f %lf\n",AVG_64,SD_64);
     
     fprintf(fd_out_All_AVG, "%f	%f	%f	%f	%f	%f	%f	%f\n%f	%f	%f	%f	%f	%f	%f	%f\n%f	%f	%f	%f	%f	%f	%f	%f\n%f	%f	%f	%f	%f	%f	%f	%f\n%f	%f	%f	%f	%f	%f	%f	%f\n%f	%f	%f	%f	%f	%f	%f	%f\n%f	%f	%f	%f	%f	%f	%f	%f\n%f	%f	%f	%f	%f	%f	%f	%f\n"
     ,AVG_1,AVG_2,AVG_3,AVG_4,AVG_5,AVG_6,AVG_7,AVG_8,AVG_9,AVG_10,AVG_11,AVG_12,AVG_13,AVG_14,AVG_15,AVG_16,AVG_17,AVG_18,AVG_19,AVG_20,AVG_21,AVG_22,AVG_23,AVG_24,AVG_25,AVG_26,AVG_27,AVG_28,AVG_29,AVG_30,
     AVG_31,AVG_32,AVG_33,AVG_34,AVG_35,AVG_36,AVG_37,AVG_38,AVG_39,AVG_40,AVG_41,AVG_42,AVG_43,AVG_44,AVG_45,AVG_46,AVG_47,AVG_48,AVG_49,AVG_50,AVG_51,AVG_52,AVG_53,AVG_54,AVG_55,AVG_56,AVG_57,AVG_58,AVG_59,
     AVG_60,AVG_61,AVG_62,AVG_63,AVG_64);

     fprintf(fd_out_All_SD, "%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf\n%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf\n%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf\n%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf\n%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf\n%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf\n%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf\n%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf	%.2lf\n"
     ,SD_1,SD_2,SD_3,SD_4,SD_5,SD_6,SD_7,SD_8,SD_9,SD_10,SD_11,SD_12,SD_13,SD_14,SD_15,SD_16,SD_17,SD_18,SD_19,SD_20,SD_21,SD_22,SD_23,SD_24,SD_25,SD_26,SD_27,SD_28,SD_29,SD_30,
     SD_31,SD_32,SD_33,SD_34,SD_35,SD_36,SD_37,SD_38,SD_39,SD_40,SD_41,SD_42,SD_43,SD_44,SD_45,SD_46,SD_47,SD_48,SD_49,SD_50,SD_51,SD_52,SD_53,SD_54,SD_55,SD_56,SD_57,SD_58,SD_59,
     SD_60,SD_61,SD_62,SD_63,SD_64);
}

//全AVG&SD計算(Only > 0)& 分別輸出AVG(Only > 0)與SD(Only > 0)各自的表單  
void Up_AVG_SD()
{
     if(Samples_U_1!=0){
     AVG_1=SV_1_U/Samples_U_1;
     AVGD_1=SVD_1_U/Samples_U_1;
     SD_1=(sv_1_U/(Samples_U_1))-((AVGD_1)*(AVGD_1));
     SD_1=pow(SD_1,0.5);
     fprintf(fd_out,"1: %f %lf\n",AVG_1,SD_1);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_1);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_1);}
     else{
     fprintf(fd_out,"1: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_2!=0){
     AVG_2=SV_2_U/Samples_U_2;
     AVGD_2=SVD_2_U/Samples_U_2;
     SD_2=(sv_2_U/(Samples_U_2))-((AVGD_2)*(AVGD_2));
     SD_2=pow(SD_2,0.5);
     fprintf(fd_out,"2: %f %lf\n",AVG_2,SD_2);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_2);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_2);}
     else{
     fprintf(fd_out,"2: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_U_3!=0){
     AVG_3=SV_3_U/Samples_U_3;
     AVGD_3=SVD_3_U/Samples_U_3;
     SD_3=(sv_3_U/(Samples_U_3))-((AVGD_3)*(AVGD_3));
     SD_3=pow(SD_3,0.5);
     fprintf(fd_out,"3: %f %lf\n",AVG_3,SD_3);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_3);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_3);}
     else{
     fprintf(fd_out,"3: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
    
     if(Samples_U_4!=0){
     AVG_4=SV_4_U/Samples_U_4;
     AVGD_4=SVD_4_U/Samples_U_4;
     SD_4=(sv_4_U/(Samples_U_4))-((AVGD_4)*(AVGD_4));
     SD_4=pow(SD_4,0.5);
     fprintf(fd_out,"4: %f %lf\n",AVG_4,SD_4);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_4);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_4);}
     else{
     fprintf(fd_out,"4: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_5!=0){
     AVG_5=SV_5_U/Samples_U_5;
     AVGD_5=SVD_5_U/Samples_U_5;
     SD_5=(sv_5_U/(Samples_U_5))-((AVGD_5)*(AVGD_5));
     SD_5=pow(SD_5,0.5);
     fprintf(fd_out,"5: %f %lf\n",AVG_5,SD_5);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_5);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_5);}
     else{
     fprintf(fd_out,"5: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_6!=0){
     AVG_6=SV_6_U/Samples_U_6;
     AVGD_6=SVD_6_U/Samples_U_6;
     SD_6=(sv_6_U/(Samples_U_6))-((AVGD_6)*(AVGD_6));
     SD_6=pow(SD_6,0.5);
     fprintf(fd_out,"6: %f %lf\n",AVG_6,SD_6);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_6);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_6);}
     else{
     fprintf(fd_out,"6: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
    
     if(Samples_U_7!=0){
     AVG_7=SV_7_U/Samples_U_7;
     AVGD_7=SVD_7_U/Samples_U_7;
     SD_7=(sv_7_U/(Samples_U_7))-((AVGD_7)*(AVGD_7));
     SD_7=pow(SD_7,0.5);
     fprintf(fd_out,"7: %f %lf\n",AVG_7,SD_7);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_7);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_7);}
     else{
     fprintf(fd_out,"7: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_8!=0){
     AVG_8=SV_8_U/Samples_U_8;
     AVGD_8=SVD_8_U/Samples_U_8;
     SD_8=(sv_8_U/(Samples_U_8))-((AVGD_8)*(AVGD_8));
     SD_8=pow(SD_8,0.5);
     fprintf(fd_out,"8: %f %lf\n",AVG_8,SD_8);
     fprintf(fd_out_Pos_AVG, "%f\n",AVG_8);
     fprintf(fd_out_Pos_SD, "%.2lf\n",SD_8);}
     else{
     fprintf(fd_out,"8: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA\n");
     fprintf(fd_out_Neg_SD, "NA\n");}
 
     if(Samples_U_9!=0){
     AVG_9=SV_9_U/Samples_U_9;
     AVGD_9=SVD_9_U/Samples_U_9;
     SD_9=(sv_9_U/(Samples_U_9))-((AVGD_9)*(AVGD_9));
     SD_9=pow(SD_9,0.5);
     fprintf(fd_out,"9: %f %lf\n",AVG_9,SD_9);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_9);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_9);}
     else{
     fprintf(fd_out,"9: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
 
     if(Samples_U_10!=0){
     AVG_10=SV_10_U/Samples_U_10;
     AVGD_10=SVD_10_U/Samples_U_10;
     SD_10=(sv_10_U/(Samples_U_10))-((AVGD_10)*(AVGD_10));
     SD_10=pow(SD_10,0.5);
     fprintf(fd_out,"10: %f %lf\n",AVG_10,SD_10);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_10);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_10);}
     else{
     fprintf(fd_out,"10: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_11!=0){
     AVG_11=SV_11_U/Samples_U_11;
     AVGD_11=SVD_11_U/Samples_U_11;
     SD_11=(sv_11_U/(Samples_U_11))-((AVGD_11)*(AVGD_11));
     SD_11=pow(SD_11,0.5);
     fprintf(fd_out,"11: %f %lf\n",AVG_11,SD_11);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_11);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_11);}
     else{
     fprintf(fd_out,"11: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
    
     if(Samples_U_12!=0){
     AVG_12=SV_12_U/Samples_U_12;
     AVGD_12=SVD_12_U/Samples_U_12;
     SD_12=(sv_12_U/(Samples_U_12))-((AVGD_12)*(AVGD_12));
     SD_12=pow(SD_12,0.5);
     fprintf(fd_out,"12: %f %lf\n",AVG_12,SD_12);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_12);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_12);}
     else{
     fprintf(fd_out,"12: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_13!=0){
     AVG_13=SV_13_U/Samples_U_13;
     AVGD_13=SVD_13_U/Samples_U_13;
     SD_13=(sv_13_U/(Samples_U_13))-((AVGD_13)*(AVGD_13));
     SD_13=pow(SD_13,0.5);
     fprintf(fd_out,"13: %f %lf\n",AVG_13,SD_13);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_13);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_13);}
     else{
     fprintf(fd_out,"13: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_14!=0){
     AVG_14=SV_14_U/Samples_U_14;
     AVGD_14=SVD_14_U/Samples_U_14;
     SD_14=(sv_14_U/(Samples_U_14))-((AVGD_14)*(AVGD_14));
     SD_14=pow(SD_14,0.5);
     fprintf(fd_out,"14: %f %lf\n",AVG_14,SD_14);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_14);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_14);}
     else{
     fprintf(fd_out,"14: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
    
     if(Samples_U_15!=0){
     AVG_15=SV_15_U/Samples_U_15;
     AVGD_15=SVD_15_U/Samples_U_15;
     SD_15=(sv_15_U/(Samples_U_15))-((AVGD_15)*(AVGD_15));
     SD_15=pow(SD_15,0.5);
     fprintf(fd_out,"15: %f %lf\n",AVG_15,SD_15);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_15);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_15);}
     else{
     fprintf(fd_out,"15: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
  
     if(Samples_U_16!=0){
     AVG_16=SV_16_U/Samples_U_16;
     AVGD_16=SVD_16_U/Samples_U_16;
     SD_16=(sv_16_U/(Samples_U_16))-((AVGD_16)*(AVGD_16));
     SD_16=pow(SD_16,0.5);
     fprintf(fd_out,"16: %f %lf\n",AVG_16,SD_16);
     fprintf(fd_out_Pos_AVG, "%f\n",AVG_16);
     fprintf(fd_out_Pos_SD, "%.2lf\n",SD_16);}
     else{
     fprintf(fd_out,"16: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA\n");
     fprintf(fd_out_Pos_SD, "NA\n");}
  
     if(Samples_U_17!=0){
     AVG_17=SV_17_U/Samples_U_17;
     AVGD_17=SVD_17_U/Samples_U_17;
     SD_17=(sv_17_U/(Samples_U_17))-((AVGD_17)*(AVGD_17));
     SD_17=pow(SD_17,0.5);
     fprintf(fd_out,"17: %f %lf\n",AVG_17,SD_17);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_17);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_17);}
     else{
     fprintf(fd_out,"17: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
  
     if(Samples_U_18!=0){
     AVG_18=SV_18_U/Samples_U_18;
     AVGD_18=SVD_18_U/Samples_U_18;
     SD_18=(sv_18_U/(Samples_U_18))-((AVGD_18)*(AVGD_18));
     SD_18=pow(SD_18,0.5);
     fprintf(fd_out,"18: %f %lf\n",AVG_18,SD_18);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_18);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_18);}
     else{
     fprintf(fd_out,"18: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_19!=0){
     AVG_19=SV_19_U/Samples_U_19;
     AVGD_19=SVD_19_U/Samples_U_19;
     SD_19=(sv_19_U/(Samples_U_19))-((AVGD_19)*(AVGD_19));
     SD_19=pow(SD_19,0.5);
     fprintf(fd_out,"19: %f %lf\n",AVG_19,SD_19);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_19);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_19);}
     else{
     fprintf(fd_out,"19: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
  
     if(Samples_U_20!=0){
     AVG_20=SV_20_U/Samples_U_20;
     AVGD_20=SVD_20_U/Samples_U_20;
     SD_20=(sv_20_U/(Samples_U_20))-((AVGD_20)*(AVGD_20));
     SD_20=pow(SD_20,0.5);
     fprintf(fd_out,"20: %f %lf\n",AVG_20,SD_20);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_20);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_20);}
     else{
     fprintf(fd_out,"20: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_21!=0){
     AVG_21=SV_21_U/Samples_U_21;
     AVGD_21=SVD_21_U/Samples_U_21;
     SD_21=(sv_21_U/(Samples_U_21))-((AVGD_21)*(AVGD_21));
     SD_21=pow(SD_21,0.5);
     fprintf(fd_out,"21: %f %lf\n",AVG_21,SD_21);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_21);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_21);}
     else{
     fprintf(fd_out,"21: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
  
     if(Samples_U_22!=0){
     AVG_22=SV_22_U/Samples_U_22;
     AVGD_22=SVD_22_U/Samples_U_22;
     SD_22=(sv_22_U/(Samples_U_22))-((AVGD_22)*(AVGD_22));
     SD_22=pow(SD_22,0.5);
     fprintf(fd_out,"22: %f %lf\n",AVG_22,SD_22);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_22);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_22);}
     else{
     fprintf(fd_out,"22: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
 
     if(Samples_U_23!=0){
     AVG_23=SV_23_U/Samples_U_23;
     AVGD_23=SVD_23_U/Samples_U_23;
     SD_23=(sv_23_U/(Samples_U_23))-((AVGD_23)*(AVGD_23));
     SD_23=pow(SD_23,0.5);
     fprintf(fd_out,"23: %f %lf\n",AVG_23,SD_23);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_23);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_23);}
     else{
     fprintf(fd_out,"23: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
    
     if(Samples_U_24!=0){
     AVG_24=SV_24_U/Samples_U_24;
     AVGD_24=SVD_24_U/Samples_U_24;
     SD_24=(sv_24_U/(Samples_U_24))-((AVG_24)*(AVG_24));
     SD_24=pow(SD_24,0.5);
     fprintf(fd_out,"24: %f %lf\n",AVG_24,SD_24);
     fprintf(fd_out_Pos_AVG, "%f\n",AVG_24);
     fprintf(fd_out_Pos_SD, "%.2lf\n",SD_24);}
     else{
     fprintf(fd_out,"24: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA\n");
     fprintf(fd_out_Pos_SD, "NA\n");}
    
     if(Samples_U_25!=0){
     AVG_25=SV_25_U/Samples_U_25;
     AVGD_25=SVD_25_U/Samples_U_25;
     SD_25=(sv_25_U/(Samples_U_25))-((AVGD_25)*(AVGD_25));
     SD_25=pow(SD_25,0.5);
     fprintf(fd_out,"25: %f %lf\n",AVG_25,SD_25);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_25);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_25);}
     else{
     fprintf(fd_out,"25: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_26!=0){
     AVG_26=SV_26_U/Samples_U_26;
     AVGD_26=SVD_26_U/Samples_U_26;
     SD_26=(sv_26_U/(Samples_U_26))-((AVGD_26)*(AVGD_26));
     SD_26=pow(SD_26,0.5);
     fprintf(fd_out,"26: %f %lf\n",AVG_26,SD_26);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_26);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_26);}
     else{
     fprintf(fd_out,"26: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_27!=0){
     AVG_27=SV_27_U/Samples_U_27;
     AVGD_27=SVD_27_U/Samples_U_27;
     SD_27=(sv_27_U/(Samples_U_27))-((AVGD_27)*(AVGD_27));
     SD_27=pow(SD_27,0.5);
     fprintf(fd_out,"27: %f %lf\n",AVG_27,SD_27);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_27);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_27);}
     else{
     fprintf(fd_out,"27: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_28!=0){
     AVG_28=SV_28_U/Samples_U_28;
     AVGD_28=SVD_28_U/Samples_U_28;
     SD_28=(sv_28_U/(Samples_U_28))-((AVG_28)*(AVG_28));
     SD_28=pow(SD_28,0.5);
     fprintf(fd_out,"28: %f %lf\n",AVG_28,SD_28);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_28);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_28);}
     else{
     fprintf(fd_out,"28: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_29!=0){
     AVG_29=SV_29_U/Samples_U_29;
     AVGD_29=SVD_29_U/Samples_U_29;
     SD_29=(sv_29_U/(Samples_U_29))-((AVGD_29)*(AVGD_29));
     SD_29=pow(SD_29,0.5);
     fprintf(fd_out,"29: %f %lf\n",AVG_29,SD_29);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_29);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_29);}
     else{
     fprintf(fd_out,"29: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
  
     if(Samples_U_30!=0){
     AVG_30=SV_30_U/Samples_U_30;
     AVGD_30=SVD_30_U/Samples_U_30;
     SD_30=(sv_30_U/(Samples_U_30))-((AVGD_30)*(AVGD_30));
     SD_30=pow(SD_30,0.5);
     fprintf(fd_out,"30: %f %lf\n",AVG_30,SD_30);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_30);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_30);}
     else{
     fprintf(fd_out,"30: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
  
     if(Samples_U_31!=0){
     AVG_31=SV_31_U/Samples_U_31;
     AVGD_31=SVD_31_U/Samples_U_31;
     SD_31=(sv_31_U/(Samples_U_31))-((AVGD_31)*(AVGD_31));
     SD_31=pow(SD_31,0.5);
     fprintf(fd_out,"31: %f %lf\n",AVG_31,SD_31);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_31);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_31);}
     else{
     fprintf(fd_out,"31: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_32!=0){
     AVG_32=SV_32_U/Samples_U_32;
     AVGD_32=SVD_32_U/Samples_U_32;
     SD_32=(sv_32_U/(Samples_U_32))-((AVGD_32)*(AVGD_32));
     SD_32=pow(SD_32,0.5);
     fprintf(fd_out,"32: %f %lf\n",AVG_32,SD_32);
     fprintf(fd_out_Pos_AVG, "%f\n",AVG_32);
     fprintf(fd_out_Pos_SD, "%.2lf\n",SD_32);}
     else{
     fprintf(fd_out,"32: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA\n");
     fprintf(fd_out_Pos_SD, "NA\n");}
  
     if(Samples_U_33!=0){
     AVG_33=SV_33_U/Samples_U_33;
     AVGD_33=SVD_33_U/Samples_U_33;
     SD_33=(sv_33_U/(Samples_U_33))-((AVGD_33)*(AVGD_33));
     SD_33=pow(SD_33,0.5);
     fprintf(fd_out,"33: %f %lf\n",AVG_33,SD_33);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_33);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_33);}
     else{
     fprintf(fd_out,"33: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_34!=0){
     AVG_34=SV_34_U/Samples_U_34;
     AVGD_34=SVD_34_U/Samples_U_34;
     SD_34=(sv_34_U/(Samples_U_34))-((AVGD_34)*(AVGD_34));
     SD_34=pow(SD_34,0.5);
     fprintf(fd_out,"34: %f %lf\n",AVG_34,SD_34);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_34);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_34);}
     else{
     fprintf(fd_out,"34: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
    
     if(Samples_U_35!=0){
     AVG_35=SV_35_U/Samples_U_35;
     SD_35=(sv_35_U/(Samples_U_35))-((AVG_35)*(AVG_35));
     SD_35=pow(SD_35,0.5);
     fprintf(fd_out,"35: %f %lf\n",AVG_35,SD_35);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_35);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_35);}
     else{
     fprintf(fd_out,"35: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}

     if(Samples_U_36!=0){
     AVG_36=SV_36_U/Samples_U_36;
     AVGD_36=SVD_36_U/Samples_U_36;
     SD_36=(sv_36_U/(Samples_U_36))-((AVGD_36)*(AVGD_36));
     SD_36=pow(SD_36,0.5);
     fprintf(fd_out,"36: %f %lf\n",AVG_36,SD_36);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_36);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_36);}
     else{
     fprintf(fd_out,"36: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
 
     if(Samples_U_37!=0){
     AVG_37=SV_37_U/Samples_U_37;
     AVGD_37=SVD_37_U/Samples_U_37;
     SD_37=(sv_37_U/(Samples_U_37))-((AVGD_37)*(AVGD_37));
     SD_37=pow(SD_37,0.5);
     fprintf(fd_out,"37: %f %lf\n",AVG_37,SD_37);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_37);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_37);}
     else{
     fprintf(fd_out,"37: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_38!=0){
     AVG_38=SV_38_U/Samples_U_38;
     AVGD_38=SVD_38_U/Samples_U_38;
     SD_38=(sv_38_U/(Samples_U_38))-((AVGD_38)*(AVGD_38));
     SD_38=pow(SD_38,0.5);
     fprintf(fd_out,"38: %f %lf\n",AVG_38,SD_38);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_38);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_38);}
     else{
     fprintf(fd_out,"38: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_39!=0){
     AVG_39=SV_39_U/Samples_U_39;
     AVGD_39=SVD_39_U/Samples_U_39;
     SD_39=(sv_39_U/(Samples_U_39))-((AVGD_39)*(AVGD_39));
     SD_39=pow(SD_39,0.5);
     fprintf(fd_out,"39: %f %lf\n",AVG_39,SD_39);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_39);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_39);}
     else{
     fprintf(fd_out,"39: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_40!=0){
     AVG_40=SV_40_U/Samples_U_40;
     AVGD_40=SVD_40_U/Samples_U_40;
     SD_40=(sv_40_U/(Samples_U_40))-((AVGD_40)*(AVGD_40));
     SD_40=pow(SD_40,0.5);
     fprintf(fd_out,"40: %f %lf\n",AVG_40,SD_40);
     fprintf(fd_out_Pos_AVG, "%f\n",AVG_40);
     fprintf(fd_out_Pos_SD, "%.2lf\n",SD_40);}
     else{
     fprintf(fd_out,"40: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA\n");
     fprintf(fd_out_Pos_SD, "NA\n");}
    
     if(Samples_U_41!=0){
     AVG_41=SV_41_U/Samples_U_41;
     AVGD_41=SVD_41_U/Samples_U_41;
     SD_41=(sv_41_U/(Samples_U_41))-((AVGD_41)*(AVGD_41));
     SD_41=pow(SD_41,0.5);
     fprintf(fd_out,"41: %f %lf\n",AVG_41,SD_41);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_41);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_41);}
     else{
     fprintf(fd_out,"41: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_42!=0){
     AVG_42=SV_42_U/Samples_U_42;
     AVGD_42=SVD_42_U/Samples_U_42;
     SD_42=(sv_42_U/(Samples_U_42))-((AVGD_42)*(AVGD_42));
     SD_42=pow(SD_42,0.5);
     fprintf(fd_out,"42: %f %lf\n",AVG_42,SD_42);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_42);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_42);}
     else{
     fprintf(fd_out,"42: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_43!=0){
     AVG_43=SV_43_U/Samples_U_43;
     AVGD_43=SVD_43_U/Samples_U_43;
     SD_43=(sv_43_U/(Samples_U_43))-((AVGD_43)*(AVGD_43));
     SD_43=pow(SD_43,0.5);
     fprintf(fd_out,"43: %f %lf\n",AVG_43,SD_43);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_43);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_43);}
     else{
     fprintf(fd_out,"43: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_44!=0){
     AVG_44=SV_44_U/Samples_U_44;
     AVGD_44=SVD_44_U/Samples_U_44;
     SD_44=(sv_44_U/(Samples_U_44))-((AVGD_44)*(AVGD_44));
     SD_44=pow(SD_44,0.5);
     fprintf(fd_out,"44: %f %lf\n",AVG_44,SD_44);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_44);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_44);}
     else{
     fprintf(fd_out,"44: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_45!=0){
     AVG_45=SV_45_U/Samples_U_45;
     AVGD_45=SVD_45_U/Samples_U_45;
     SD_45=(sv_45_U/(Samples_U_45))-((AVGD_45)*(AVGD_45));
     SD_45=pow(SD_45,0.5);
     fprintf(fd_out,"45: %f %lf\n",AVG_45,SD_45);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_45);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_45);}
     else{
     fprintf(fd_out,"45: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_46!=0){
     AVG_46=SV_46_U/Samples_U_46;
     AVGD_46=SVD_46_U/Samples_U_46;
     SD_46=(sv_46_U/(Samples_U_46))-((AVGD_46)*(AVGD_46));
     SD_46=pow(SD_46,0.5);
     fprintf(fd_out,"46: %f %lf\n",AVG_46,SD_46);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_46);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_46);}
     else{
     fprintf(fd_out,"46: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
    
     if(Samples_U_47!=0){
     AVG_47=SV_47_U/Samples_U_47;
     AVGD_47=SVD_47_U/Samples_U_47;
     SD_47=(sv_47_U/(Samples_U_47))-((AVGD_47)*(AVGD_47));
     SD_47=pow(SD_47,0.5);
     fprintf(fd_out,"47: %f %lf\n",AVG_47,SD_47);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_47);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_47);}
     else{
     fprintf(fd_out,"47: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
    
     if(Samples_U_48!=0){
     AVG_48=SV_48_U/Samples_U_48;
     AVGD_48=SVD_48_U/Samples_U_48;
     SD_48=(sv_48_U/(Samples_U_48))-((AVGD_48)*(AVGD_48));
     SD_48=pow(SD_48,0.5);
     fprintf(fd_out,"48: %f %lf\n",AVG_48,SD_48);
     fprintf(fd_out_Pos_AVG, "%f\n",AVG_48);
     fprintf(fd_out_Pos_SD, "%.2lf\n",SD_48);}
     else{
     fprintf(fd_out,"48: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA\n");
     fprintf(fd_out_Pos_SD, "NA\n");}
    
     if(Samples_U_49!=0){
     AVG_49=SV_49_U/Samples_U_49;
     AVGD_49=SVD_49_U/Samples_U_49;
     SD_49=(sv_49_U/(Samples_U_49))-((AVGD_49)*(AVGD_49));
     SD_49=pow(SD_49,0.5);
     fprintf(fd_out,"49: %f %lf\n",AVG_49,SD_49);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_49);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_49);}
     else{
     fprintf(fd_out,"49: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_50!=0){
     AVG_50=SV_50_U/Samples_U_50;
     AVGD_50=SVD_50_U/Samples_U_50;
     SD_50=(sv_50_U/(Samples_U_50))-((AVGD_50)*(AVGD_50));
     SD_50=pow(SD_50,0.5);
     fprintf(fd_out,"50: %f %lf\n",AVG_50,SD_50);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_50);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_50);}
     else{
     fprintf(fd_out,"50: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_51!=0){
     AVG_51=SV_51_U/Samples_U_51;
     AVGD_51=SVD_51_U/Samples_U_51;
     SD_51=(sv_51_U/(Samples_U_51))-((AVGD_51)*(AVGD_51));
     SD_51=pow(SD_51,0.5);
     fprintf(fd_out,"51: %f %lf\n",AVG_51,SD_51);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_51);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_51);}
     else{
     fprintf(fd_out,"51: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_52!=0){
     AVG_52=SV_52_U/Samples_U_52;
     AVGD_52=SVD_52_U/Samples_U_52;
     SD_52=(sv_52_U/(Samples_U_52))-((AVGD_52)*(AVGD_52));
     SD_52=pow(SD_52,0.5);
     fprintf(fd_out,"52: %f %lf\n",AVG_52,SD_52);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_52);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_52);}
     else{
     fprintf(fd_out,"52: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_53!=0){
     AVG_53=SV_53_U/Samples_U_53;
     AVGD_53=SVD_53_U/Samples_U_53;
     SD_53=(sv_53_U/(Samples_U_53))-((AVGD_53)*(AVGD_53));
     SD_53=pow(SD_53,0.5);
     fprintf(fd_out,"53: %f %lf\n",AVG_53,SD_53);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_53);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_53);}
     else{
     fprintf(fd_out,"53: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
    
     if(Samples_U_54!=0){
     AVG_54=SV_54_U/Samples_U_54;
     AVGD_54=SVD_54_U/Samples_U_54;
     SD_54=(sv_54_U/(Samples_U_54))-((AVGD_54)*(AVGD_54));
     SD_54=pow(SD_54,0.5);
     fprintf(fd_out,"54: %f %lf\n",AVG_54,SD_54);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_54);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_54);}
     else{
     fprintf(fd_out,"54: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_55!=0){
     AVG_55=SV_55_U/Samples_U_55;
     AVGD_55=SVD_55_U/Samples_U_55;
     SD_55=(sv_55_U/(Samples_U_55))-((AVGD_55)*(AVGD_55));
     SD_55=pow(SD_55,0.5);
     fprintf(fd_out,"55: %f %lf\n",AVG_55,SD_55);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_55);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_55);}
     else{
     fprintf(fd_out,"55: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_56!=0){
     AVG_56=SV_56_U/Samples_U_56;
     AVGD_56=SVD_56_U/Samples_U_56;
     SD_56=(sv_56_U/(Samples_U_56))-((AVGD_56)*(AVGD_56));
     SD_56=pow(SD_56,0.5);
     fprintf(fd_out,"56: %f %lf\n",AVG_56,SD_56);
     fprintf(fd_out_Pos_AVG, "%f\n",AVG_56);
     fprintf(fd_out_Pos_SD, "%.2lf\n",SD_56);}
     else{
     fprintf(fd_out,"56: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA\n");
     fprintf(fd_out_Pos_SD, "NA\n");}
     
     if(Samples_U_57!=0){
     AVG_57=SV_57_U/Samples_U_57;
     AVGD_57=SVD_57_U/Samples_U_57;
     SD_57=(sv_57_U/(Samples_U_57))-((AVGD_57)*(AVGD_57));
     SD_57=pow(SD_57,0.5);
     fprintf(fd_out,"57: %f %lf\n",AVG_57,SD_57);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_57);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_57);}
     else{
     fprintf(fd_out,"57: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_58!=0){
     AVG_58=SV_58_U/Samples_U_58;
     AVGD_58=SVD_58_U/Samples_U_58;
     SD_58=(sv_58_U/(Samples_U_58))-((AVGD_58)*(AVGD_58));
     SD_58=pow(SD_58,0.5);
     fprintf(fd_out,"58: %f %lf\n",AVG_58,SD_58);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_58);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_58);}
     else{
     fprintf(fd_out,"58: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_59!=0){
     AVG_59=SV_59_U/Samples_U_59;
     AVGD_59=SVD_59_U/Samples_U_59;
     SD_59=(sv_59_U/(Samples_U_59))-((AVGD_59)*(AVGD_59));
     SD_59=pow(SD_59,0.5);
     fprintf(fd_out,"59: %f %lf\n",AVG_59,SD_59);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_59);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_59);}
     else{
     fprintf(fd_out,"59: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_60!=0){
     AVG_60=SV_60_U/Samples_U_60;
     AVGD_60=SVD_60_U/Samples_U_60;
     SD_60=(sv_60_U/(Samples_U_60))-((AVGD_60)*(AVGD_60));
     SD_60=pow(SD_60,0.5);
     fprintf(fd_out,"60: %f %lf\n",AVG_60,SD_60);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_60);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_60);}
     else{
     fprintf(fd_out,"60: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_61!=0){
     AVG_61=SV_61_U/Samples_U_61;
     AVGD_61=SVD_61_U/Samples_U_61;
     SD_61=(sv_61_U/(Samples_U_61))-((AVGD_61)*(AVGD_61));
     SD_61=pow(SD_61,0.5);
     fprintf(fd_out,"61: %f %lf\n",AVG_61,SD_61);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_61);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_61);}
     else{
     fprintf(fd_out,"61: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_62!=0){
     AVG_62=SV_62_U/Samples_U_62;
     AVGD_62=SVD_62_U/Samples_U_62;
     SD_62=(sv_62_U/(Samples_U_62))-((AVGD_62)*(AVGD_62));
     SD_62=pow(SD_62,0.5);
     fprintf(fd_out,"62: %f %lf\n",AVG_62,SD_62);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_62);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_62);}
     else{
     fprintf(fd_out,"62: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_63!=0){
     AVG_63=SV_63_U/Samples_U_63;
     AVGD_63=SVD_63_U/Samples_U_63;
     SD_63=(sv_63_U/(Samples_U_63))-((AVGD_63)*(AVGD_63));
     SD_63=pow(SD_63,0.5);
     fprintf(fd_out,"63: %f %lf\n",AVG_63,SD_63);
     fprintf(fd_out_Pos_AVG, "%f	",AVG_63);
     fprintf(fd_out_Pos_SD, "%.2lf	",SD_63);}
     else{
     fprintf(fd_out,"63: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA	");
     fprintf(fd_out_Pos_SD, "NA	");}
     
     if(Samples_U_64!=0){
     AVG_64=SV_64_U/Samples_U_64;
     AVGD_64=SVD_64_U/Samples_U_64;
     SD_64=(sv_64_U/(Samples_U_64))-((AVGD_64)*(AVGD_64));
     SD_64=pow(SD_64,0.5);
     fprintf(fd_out,"64: %f %lf\n",AVG_64,SD_64);
     fprintf(fd_out_Pos_AVG, "%f\n",AVG_64);
     fprintf(fd_out_Pos_SD, "%.2lf\n",SD_64);}
     else{
     fprintf(fd_out,"64: NA NA\n");
     fprintf(fd_out_Pos_AVG, "NA\n");
     fprintf(fd_out_Pos_SD, "NA\n");}
}

//全AVG&SD計算(Only < 0)& 分別輸出AVG(Only < 0)與SD(Only < 0)各自的表單
void Down_AVG_SD()
{
     if(Samples_D_1!=0){
     AVG_1=SV_1_D/Samples_D_1;
     AVGD_1=SVD_1_D/Samples_D_1;
     SD_1=(sv_1_D/(Samples_D_1))-((AVGD_1)*(AVGD_1));
     SD_1=pow(SD_1,0.5);
     fprintf(fd_out,"1: %f %lf\n",AVG_1,SD_1);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_1);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_1);}
     else{
     fprintf(fd_out,"1: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_2!=0){
     AVG_2=SV_2_D/Samples_D_2;
     AVGD_2=SVD_2_D/Samples_D_2;
     SD_2=(sv_2_D/(Samples_D_2))-((AVGD_2)*(AVGD_2));
     SD_2=pow(SD_2,0.5);
     fprintf(fd_out,"2: %f %lf\n",AVG_2,SD_2);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_2);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_2);}
     else{
     fprintf(fd_out,"2: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_3!=0){
     AVG_3=SV_3_D/Samples_D_3;
     AVGD_3=SVD_3_D/Samples_D_3;
     SD_3=(sv_3_D/(Samples_D_3))-((AVGD_3)*(AVGD_3));
     SD_3=pow(SD_3,0.5);
     fprintf(fd_out,"3: %f %lf\n",AVG_3,SD_3);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_3);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_3);}
     else{
     fprintf(fd_out,"3: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
    
     if(Samples_D_4!=0){
     AVG_4=SV_4_D/Samples_D_4;
     AVGD_4=SVD_4_D/Samples_D_4;
     SD_4=(sv_4_D/(Samples_D_4))-((AVGD_4)*(AVGD_4));
     SD_4=pow(SD_4,0.5);
     fprintf(fd_out,"4: %f %lf\n",AVG_4,SD_4);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_4);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_4);}
     else{
     fprintf(fd_out,"4: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_5!=0){
     AVG_5=SV_5_D/Samples_D_5;
     AVGD_5=SVD_5_D/Samples_D_5;
     SD_5=(sv_5_D/(Samples_D_5))-((AVGD_5)*(AVGD_5));
     SD_5=pow(SD_5,0.5);
     fprintf(fd_out,"5: %f %lf\n",AVG_5,SD_5);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_5);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_5);}
     else{
     fprintf(fd_out,"5: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_6!=0){
     AVG_6=SV_6_D/Samples_D_6;
     AVGD_6=SVD_6_D/Samples_D_6;
     SD_6=(sv_6_D/(Samples_D_6))-((AVGD_6)*(AVGD_6));
     SD_6=pow(SD_6,0.5);
     fprintf(fd_out,"6: %f %lf\n",AVG_6,SD_6);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_6);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_6);}
     else{
     fprintf(fd_out,"6: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
    
     if(Samples_D_7!=0){
     AVG_7=SV_7_D/Samples_D_7;
     AVGD_7=SVD_7_D/Samples_D_7;
     SD_7=(sv_7_D/(Samples_D_7))-((AVGD_7)*(AVGD_7));
     SD_7=pow(SD_7,0.5);
     fprintf(fd_out,"7: %f %lf\n",AVG_7,SD_7);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_7);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_7);}
     else{
     fprintf(fd_out,"7: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_8!=0){
     AVG_8=SV_8_D/Samples_D_8;
     AVGD_8=SVD_8_D/Samples_D_8;
     SD_8=(sv_8_D/(Samples_D_8))-((AVGD_8)*(AVGD_8));
     SD_8=pow(SD_8,0.5);
     fprintf(fd_out,"8: %f %lf\n",AVG_8,SD_8);
     fprintf(fd_out_Neg_AVG, "%f\n",AVG_8);
     fprintf(fd_out_Neg_SD, "%.2lf\n",SD_8);}
     else{
     fprintf(fd_out,"8: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA\n");
     fprintf(fd_out_Neg_SD, "NA\n");}
 
     if(Samples_D_9!=0){
     AVG_9=SV_9_D/Samples_D_9;
     AVGD_9=SVD_9_D/Samples_D_9;
     SD_9=(sv_9_D/(Samples_D_9))-((AVGD_9)*(AVGD_9));
     SD_9=pow(SD_9,0.5);
     fprintf(fd_out,"9: %f %lf\n",AVG_9,SD_9);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_9);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_9);}
     else{
     fprintf(fd_out,"9: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
 
     if(Samples_D_10!=0){
     AVG_10=SV_10_D/Samples_D_10;
     AVGD_10=SVD_10_D/Samples_D_10;
     SD_10=(sv_10_D/(Samples_D_10))-((AVGD_10)*(AVGD_10));
     SD_10=pow(SD_10,0.5);
     fprintf(fd_out,"10: %f %lf\n",AVG_10,SD_10);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_10);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_10);}
     else{
     fprintf(fd_out,"10: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_11!=0){
     AVG_11=SV_11_D/Samples_D_11;
     AVGD_11=SVD_11_D/Samples_D_11;
     SD_11=(sv_11_D/(Samples_D_11))-((AVGD_11)*(AVGD_11));
     SD_11=pow(SD_11,0.5);
     fprintf(fd_out,"11: %f %lf\n",AVG_11,SD_11);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_11);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_11);}
     else{
     fprintf(fd_out,"11: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
    
     if(Samples_D_12!=0){
     AVG_12=SV_12_D/Samples_D_12;
     AVGD_12=SVD_12_D/Samples_D_12;
     SD_12=(sv_12_D/(Samples_D_12))-((AVGD_12)*(AVGD_12));
     SD_12=pow(SD_12,0.5);
     fprintf(fd_out,"12: %f %lf\n",AVG_12,SD_12);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_12);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_12);}
     else{
     fprintf(fd_out,"12: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_13!=0){
     AVG_13=SV_13_D/Samples_D_13;
     AVGD_13=SVD_13_D/Samples_D_13;
     SD_13=(sv_13_D/(Samples_D_13))-((AVGD_13)*(AVGD_13));
     SD_13=pow(SD_13,0.5);
     fprintf(fd_out,"13: %f %lf\n",AVG_13,SD_13);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_13);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_13);}
     else{
     fprintf(fd_out,"13: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_14!=0){
     AVG_14=SV_14_D/Samples_D_14;
     AVGD_14=SVD_14_D/Samples_D_14;
     SD_14=(sv_14_D/(Samples_D_14))-((AVGD_14)*(AVGD_14));
     SD_14=pow(SD_14,0.5);
     fprintf(fd_out,"14: %f %lf\n",AVG_14,SD_14);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_14);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_14);}
     else{
     fprintf(fd_out,"14: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
    
     if(Samples_D_15!=0){
     AVG_15=SV_15_D/Samples_D_15;
     AVGD_15=SVD_15_D/Samples_D_15;
     SD_15=(sv_15_D/(Samples_D_15))-((AVGD_15)*(AVGD_15));
     SD_15=pow(SD_15,0.5);
     fprintf(fd_out,"15: %f %lf\n",AVG_15,SD_15);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_15);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_15);}
     else{
     fprintf(fd_out,"15: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
  
     if(Samples_D_16!=0){
     AVG_16=SV_16_D/Samples_D_16;
     AVGD_16=SVD_16_D/Samples_D_16;
     SD_16=(sv_16_D/(Samples_D_16))-((AVGD_16)*(AVGD_16));
     SD_16=pow(SD_16,0.5);
     fprintf(fd_out,"16: %f %lf\n",AVG_16,SD_16);
     fprintf(fd_out_Neg_AVG, "%f\n",AVG_16);
     fprintf(fd_out_Neg_SD, "%.2lf\n",SD_16);}
     else{
     fprintf(fd_out,"16: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA\n");
     fprintf(fd_out_Neg_SD, "NA\n");}
  
     if(Samples_D_17!=0){
     AVG_17=SV_17_D/Samples_D_17;
     AVGD_17=SVD_17_D/Samples_D_17;
     SD_17=(sv_17_D/(Samples_D_17))-((AVGD_17)*(AVGD_17));
     SD_17=pow(SD_17,0.5);
     fprintf(fd_out,"17: %f %lf\n",AVG_17,SD_17);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_17);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_17);}
     else{
     fprintf(fd_out,"17: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
  
     if(Samples_D_18!=0){
     AVG_18=SV_18_D/Samples_D_18;
     AVGD_18=SVD_18_D/Samples_D_18;
     SD_18=(sv_18_D/(Samples_D_18))-((AVGD_18)*(AVGD_18));
     SD_18=pow(SD_18,0.5);
     fprintf(fd_out,"18: %f %lf\n",AVG_18,SD_18);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_18);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_18);}
     else{
     fprintf(fd_out,"18: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_19!=0){
     AVG_19=SV_19_D/Samples_D_19;
     AVGD_19=SVD_19_D/Samples_D_19;
     SD_19=(sv_19_D/(Samples_D_19))-((AVGD_19)*(AVGD_19));
     SD_19=pow(SD_19,0.5);
     fprintf(fd_out,"19: %f %lf\n",AVG_19,SD_19);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_19);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_19);}
     else{
     fprintf(fd_out,"19: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
  
     if(Samples_D_20!=0){
     AVG_20=SV_20_D/Samples_D_20;
     AVGD_20=SVD_20_D/Samples_D_20;
     SD_20=(sv_20_D/(Samples_D_20))-((AVGD_20)*(AVGD_20));
     SD_20=pow(SD_20,0.5);
     fprintf(fd_out,"20: %f %lf\n",AVG_20,SD_20);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_20);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_20);}
     else{
     fprintf(fd_out,"20: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_21!=0){
     AVG_21=SV_21_D/Samples_D_21;
     AVGD_21=SVD_21_D/Samples_D_21;
     SD_21=(sv_21_D/(Samples_D_21))-((AVGD_21)*(AVGD_21));
     SD_21=pow(SD_21,0.5);
     fprintf(fd_out,"21: %f %lf\n",AVG_21,SD_21);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_21);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_21);}
     else{
     fprintf(fd_out,"21: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
  
     if(Samples_D_22!=0){
     AVG_22=SV_22_D/Samples_D_22;
     AVGD_22=SVD_22_D/Samples_D_22;
     SD_22=(sv_22_D/(Samples_D_22))-((AVGD_22)*(AVGD_22));
     SD_22=pow(SD_22,0.5);
     fprintf(fd_out,"22: %f %lf\n",AVG_22,SD_22);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_22);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_22);}
     else{
     fprintf(fd_out,"22: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
 
     if(Samples_D_23!=0){
     AVG_23=SV_23_D/Samples_D_23;
     AVGD_23=SVD_23_D/Samples_D_23;
     SD_23=(sv_23_D/(Samples_D_23))-((AVGD_23)*(AVGD_23));
     SD_23=pow(SD_23,0.5);
     fprintf(fd_out,"23: %f %lf\n",AVG_23,SD_23);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_23);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_23);}
     else{
     fprintf(fd_out,"23: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
    
     if(Samples_D_24!=0){
     AVG_24=SV_24_D/Samples_D_24;
     AVGD_24=SVD_24_D/Samples_D_24;
     SD_24=(sv_24_D/(Samples_D_24))-((AVGD_24)*(AVGD_24));
     SD_24=pow(SD_24,0.5);
     fprintf(fd_out,"24: %f %lf\n",AVG_24,SD_24);
     fprintf(fd_out_Neg_AVG, "%f\n",AVG_24);
     fprintf(fd_out_Neg_SD, "%.2lf\n",SD_24);}
     else{
     fprintf(fd_out,"24: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA\n");
     fprintf(fd_out_Neg_SD, "NA\n");}
    
     if(Samples_D_25!=0){
     AVG_25=SV_25_D/Samples_D_25;
     AVGD_25=SVD_25_D/Samples_D_25;
     SD_25=(sv_25_D/(Samples_D_25))-((AVGD_25)*(AVGD_25));
     SD_25=pow(SD_25,0.5);
     fprintf(fd_out,"25: %f %lf\n",AVG_25,SD_25);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_25);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_25);}
     else{
     fprintf(fd_out,"25: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_26!=0){
     AVG_26=SV_26_D/Samples_D_26;
     AVGD_26=SVD_26_D/Samples_D_26;
     SD_26=(sv_26_D/(Samples_D_26))-((AVGD_26)*(AVGD_26));
     SD_26=pow(SD_26,0.5);
     fprintf(fd_out,"26: %f %lf\n",AVG_26,SD_26);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_26);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_26);}
     else{
     fprintf(fd_out,"26: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_27!=0){
     AVG_27=SV_27_D/Samples_D_27;
     AVGD_27=SVD_27_D/Samples_D_27;
     SD_27=(sv_27_D/(Samples_D_27))-((AVGD_27)*(AVGD_27));
     SD_27=pow(SD_27,0.5);
     fprintf(fd_out,"27: %f %lf\n",AVG_27,SD_27);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_27);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_27);}
     else{
     fprintf(fd_out,"27: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_28!=0){
     AVG_28=SV_28_D/Samples_D_28;
     AVGD_28=SVD_28_D/Samples_D_28;
     SD_28=(sv_28_D/(Samples_D_28))-((AVGD_28)*(AVGD_28));
     SD_28=pow(SD_28,0.5);
     fprintf(fd_out,"28: %f %lf\n",AVG_28,SD_28);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_28);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_28);}
     else{
     fprintf(fd_out,"28: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_29!=0){
     AVG_29=SV_29_D/Samples_D_29;
     AVGD_29=SVD_29_D/Samples_D_29;
     SD_29=(sv_29_D/(Samples_D_29))-((AVGD_29)*(AVGD_29));
     SD_29=pow(SD_29,0.5);
     fprintf(fd_out,"29: %f %lf\n",AVG_29,SD_29);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_29);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_29);}
     else{
     fprintf(fd_out,"29: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
  
     if(Samples_D_30!=0){
     AVG_30=SV_30_D/Samples_D_30;
     AVGD_30=SVD_30_D/Samples_D_30;
     SD_30=(sv_30_D/(Samples_D_30))-((AVGD_30)*(AVGD_30));
     SD_30=pow(SD_30,0.5);
     fprintf(fd_out,"30: %f %lf\n",AVG_30,SD_30);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_30);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_30);}
     else{
     fprintf(fd_out,"30: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
  
     if(Samples_D_31!=0){
     AVG_31=SV_31_D/Samples_D_31;
     AVGD_31=SVD_31_D/Samples_D_31;
     SD_31=(sv_31_D/(Samples_D_31))-((AVGD_31)*(AVGD_31));
     SD_31=pow(SD_31,0.5);
     fprintf(fd_out,"31: %f %lf\n",AVG_31,SD_31);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_31);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_31);}
     else{
     fprintf(fd_out,"31: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_32!=0){
     AVG_32=SV_32_D/Samples_D_32;
     AVGD_32=SVD_32_D/Samples_D_32;
     SD_32=(sv_32_D/(Samples_D_32))-((AVGD_32)*(AVGD_32));
     SD_32=pow(SD_32,0.5);
     fprintf(fd_out,"32: %f %lf\n",AVG_32,SD_32);
     fprintf(fd_out_Neg_AVG, "%f\n",AVG_32);
     fprintf(fd_out_Neg_SD, "%.2lf\n",SD_32);}
     else{
     fprintf(fd_out,"32: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA\n");
     fprintf(fd_out_Neg_SD, "NA\n");}
  
     if(Samples_D_33!=0){
     AVG_33=SV_33_D/Samples_D_33;
     AVGD_33=SVD_33_D/Samples_D_33;
     SD_33=(sv_33_D/(Samples_D_33))-((AVGD_33)*(AVGD_33));
     SD_33=pow(SD_33,0.5);
     fprintf(fd_out,"33: %f %lf\n",AVG_33,SD_33);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_33);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_33);}
     else{
     fprintf(fd_out,"33: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_34!=0){
     AVG_34=SV_34_D/Samples_D_34;
     AVGD_34=SVD_34_D/Samples_D_34;
     SD_34=(sv_34_D/(Samples_D_34))-((AVGD_34)*(AVGD_34));
     SD_34=pow(SD_34,0.5);
     fprintf(fd_out,"34: %f %lf\n",AVG_34,SD_34);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_34);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_34);}
     else{
     fprintf(fd_out,"34: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
    
     if(Samples_D_35!=0){
     AVG_35=SV_35_D/Samples_D_35;
     AVGD_35=SVD_35_D/Samples_D_35;
     SD_35=(sv_35_D/(Samples_D_35))-((AVGD_35)*(AVGD_35));
     SD_35=pow(SD_35,0.5);
     fprintf(fd_out,"35: %f %lf\n",AVG_35,SD_35);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_35);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_35);}
     else{
     fprintf(fd_out,"35: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}

     if(Samples_D_36!=0){
     AVG_36=SV_36_D/Samples_D_36;
     AVGD_36=SVD_36_D/Samples_D_36;
     SD_36=(sv_36_D/(Samples_D_36))-((AVGD_36)*(AVGD_36));
     SD_36=pow(SD_36,0.5);
     fprintf(fd_out,"36: %f %lf\n",AVG_36,SD_36);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_36);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_36);}
     else{
     fprintf(fd_out,"36: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
 
     if(Samples_D_37!=0){
     AVG_37=SV_37_D/Samples_D_37;
     AVGD_37=SVD_37_D/Samples_D_37;
     SD_37=(sv_37_D/(Samples_D_37))-((AVGD_37)*(AVGD_37));
     SD_37=pow(SD_37,0.5);
     fprintf(fd_out,"37: %f %lf\n",AVG_37,SD_37);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_37);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_37);}
     else{
     fprintf(fd_out,"37: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_38!=0){
     AVG_38=SV_38_D/Samples_D_38;
     AVGD_38=SVD_38_D/Samples_D_38;
     SD_38=(sv_38_D/(Samples_D_38))-((AVGD_38)*(AVGD_38));
     SD_38=pow(SD_38,0.5);
     fprintf(fd_out,"38: %f %lf\n",AVG_38,SD_38);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_38);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_38);}
     else{
     fprintf(fd_out,"38: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_39!=0){
     AVG_39=SV_39_D/Samples_D_39;
     AVGD_39=SVD_39_D/Samples_D_39;
     SD_39=(sv_39_D/(Samples_D_39))-((AVGD_39)*(AVGD_39));
     SD_39=pow(SD_39,0.5);
     fprintf(fd_out,"39: %f %lf\n",AVG_39,SD_39);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_39);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_39);}
     else{
     fprintf(fd_out,"39: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_40!=0){
     AVG_40=SV_40_D/Samples_D_40;
     AVGD_40=SVD_40_D/Samples_D_40;
     SD_40=(sv_40_D/(Samples_D_40))-((AVGD_40)*(AVGD_40));
     SD_40=pow(SD_40,0.5);
     fprintf(fd_out,"40: %f %lf\n",AVG_40,SD_40);
     fprintf(fd_out_Neg_AVG, "%f\n",AVG_40);
     fprintf(fd_out_Neg_SD, "%.2lf\n",SD_40);}
     else{
     fprintf(fd_out,"40: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA\n");
     fprintf(fd_out_Neg_SD, "NA\n");}
    
     if(Samples_D_41!=0){
     AVG_41=SV_41_D/Samples_D_41;
     AVGD_41=SVD_41_D/Samples_D_41;
     SD_41=(sv_41_D/(Samples_D_41))-((AVGD_41)*(AVGD_41));
     SD_41=pow(SD_41,0.5);
     fprintf(fd_out,"41: %f %lf\n",AVG_41,SD_41);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_41);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_41);}
     else{
     fprintf(fd_out,"41: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_42!=0){
     AVG_42=SV_42_D/Samples_D_42;
     AVGD_42=SVD_42_D/Samples_D_42;
     SD_42=(sv_42_D/(Samples_D_42))-((AVGD_42)*(AVGD_42));
     SD_42=pow(SD_42,0.5);
     fprintf(fd_out,"42: %f %lf\n",AVG_42,SD_42);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_42);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_42);}
     else{
     fprintf(fd_out,"42: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_43!=0){
     AVG_43=SV_43_D/Samples_D_43;
     AVGD_43=SVD_43_D/Samples_D_43;
     SD_43=(sv_43_D/(Samples_D_43))-((AVGD_43)*(AVGD_43));
     SD_43=pow(SD_43,0.5);
     fprintf(fd_out,"43: %f %lf\n",AVG_43,SD_43);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_43);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_43);}
     else{
     fprintf(fd_out,"43: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_44!=0){
     AVG_44=SV_44_D/Samples_D_44;
     AVGD_44=SVD_44_D/Samples_D_44;
     SD_44=(sv_44_D/(Samples_D_44))-((AVGD_44)*(AVGD_44));
     SD_44=pow(SD_44,0.5);
     fprintf(fd_out,"44: %f %lf\n",AVG_44,SD_44);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_44);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_44);}
     else{
     fprintf(fd_out,"44: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_45!=0){
     AVG_45=SV_45_D/Samples_D_45;
     AVGD_45=SVD_45_D/Samples_D_45;
     SD_45=(sv_45_D/(Samples_D_45))-((AVGD_45)*(AVGD_45));
     SD_45=pow(SD_45,0.5);
     fprintf(fd_out,"45: %f %lf\n",AVG_45,SD_45);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_45);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_45);}
     else{
     fprintf(fd_out,"45: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_46!=0){
     AVG_46=SV_46_D/Samples_D_46;
     AVGD_46=SVD_46_D/Samples_D_46;
     SD_46=(sv_46_D/(Samples_D_46))-((AVGD_46)*(AVGD_46));
     SD_46=pow(SD_46,0.5);
     fprintf(fd_out,"46: %f %lf\n",AVG_46,SD_46);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_46);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_46);}
     else{
     fprintf(fd_out,"46: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
    
     if(Samples_D_47!=0){
     AVG_47=SV_47_D/Samples_D_47;
     AVGD_47=SVD_47_D/Samples_D_47;
     SD_47=(sv_47_D/(Samples_D_47))-((AVGD_47)*(AVGD_47));
     SD_47=pow(SD_47,0.5);
     fprintf(fd_out,"47: %f %lf\n",AVG_47,SD_47);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_47);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_47);}
     else{
     fprintf(fd_out,"47: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
    
     if(Samples_D_48!=0){
     AVG_48=SV_48_D/Samples_D_48;
     AVGD_48=SVD_48_D/Samples_D_48;
     SD_48=(sv_48_D/(Samples_D_48))-((AVGD_48)*(AVGD_48));
     SD_48=pow(SD_48,0.5);
     fprintf(fd_out,"48: %f %lf\n",AVG_48,SD_48);
     fprintf(fd_out_Neg_AVG, "%f\n",AVG_48);
     fprintf(fd_out_Neg_SD, "%.2lf\n",SD_48);}
     else{
     fprintf(fd_out,"48: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA\n");
     fprintf(fd_out_Neg_SD, "NA\n");}
    
     if(Samples_D_49!=0){
     AVG_49=SV_49_D/Samples_D_49;
     AVGD_49=SVD_49_D/Samples_D_49;
     SD_49=(sv_49_D/(Samples_D_49))-((AVGD_49)*(AVGD_49));
     SD_49=pow(SD_49,0.5);
     fprintf(fd_out,"49: %f %lf\n",AVG_49,SD_49);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_49);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_49);}
     else{
     fprintf(fd_out,"49: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_50!=0){
     AVG_50=SV_50_D/Samples_D_50;
     AVGD_50=SVD_50_D/Samples_D_50;
     SD_50=(sv_50_D/(Samples_D_50))-((AVGD_50)*(AVGD_50));
     SD_50=pow(SD_50,0.5);
     fprintf(fd_out,"50: %f %lf\n",AVG_50,SD_50);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_50);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_50);}
     else{
     fprintf(fd_out,"50: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_51!=0){
     AVG_51=SV_51_D/Samples_D_51;
     AVGD_51=SVD_51_D/Samples_D_51;
     SD_51=(sv_51_D/(Samples_D_51))-((AVGD_51)*(AVGD_51));
     SD_51=pow(SD_51,0.5);
     fprintf(fd_out,"51: %f %lf\n",AVG_51,SD_51);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_51);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_51);}
     else{
     fprintf(fd_out,"51: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_52!=0){
     AVG_52=SV_52_D/Samples_D_52;
     AVGD_52=SVD_52_D/Samples_D_52;
     SD_52=(sv_52_D/(Samples_D_52))-((AVGD_52)*(AVGD_52));
     SD_52=pow(SD_52,0.5);
     fprintf(fd_out,"52: %f %lf\n",AVG_52,SD_52);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_52);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_52);}
     else{
     fprintf(fd_out,"52: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_53!=0){
     AVG_53=SV_53_D/Samples_D_53;
     AVGD_53=SVD_53_D/Samples_D_53;
     SD_53=(sv_53_D/(Samples_D_53))-((AVGD_53)*(AVGD_53));
     SD_53=pow(SD_53,0.5);
     fprintf(fd_out,"53: %f %lf\n",AVG_53,SD_53);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_53);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_53);}
     else{
     fprintf(fd_out,"53: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
    
     if(Samples_D_54!=0){
     AVG_54=SV_54_D/Samples_D_54;
     AVGD_54=SVD_54_D/Samples_D_54;
     SD_54=(sv_54_D/(Samples_D_54))-((AVGD_54)*(AVGD_54));
     SD_54=pow(SD_54,0.5);
     fprintf(fd_out,"54: %f %lf\n",AVG_54,SD_54);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_54);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_54);}
     else{
     fprintf(fd_out,"54: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_55!=0){
     AVG_55=SV_55_D/Samples_D_55;
     AVGD_55=SVD_55_D/Samples_D_55;
     SD_55=(sv_55_D/(Samples_D_55))-((AVGD_55)*(AVGD_55));
     SD_55=pow(SD_55,0.5);
     fprintf(fd_out,"55: %f %lf\n",AVG_55,SD_55);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_55);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_55);}
     else{
     fprintf(fd_out,"55: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_56!=0){
     AVG_56=SV_56_D/Samples_D_56;
     AVGD_56=SVD_56_D/Samples_D_56;
     SD_56=(sv_56_D/(Samples_D_56))-((AVGD_56)*(AVGD_56));
     SD_56=pow(SD_56,0.5);
     fprintf(fd_out,"56: %f %lf\n",AVG_56,SD_56);
     fprintf(fd_out_Neg_AVG, "%f\n",AVG_56);
     fprintf(fd_out_Neg_SD, "%.2lf\n",SD_56);}
     else{
     fprintf(fd_out,"56: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA\n");
     fprintf(fd_out_Neg_SD, "NA\n");}
     
     if(Samples_D_57!=0){
     AVG_57=SV_57_D/Samples_D_57;
     AVGD_57=SVD_57_D/Samples_D_57;
     SD_57=(sv_57_D/(Samples_D_57))-((AVGD_57)*(AVGD_57));
     SD_57=pow(SD_57,0.5);
     fprintf(fd_out,"57: %f %lf\n",AVG_57,SD_57);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_57);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_57);}
     else{
     fprintf(fd_out,"57: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_58!=0){
     AVG_58=SV_58_D/Samples_D_58;
     AVGD_58=SVD_58_D/Samples_D_58;
     SD_58=(sv_58_D/(Samples_D_58))-((AVGD_58)*(AVGD_58));
     SD_58=pow(SD_58,0.5);
     fprintf(fd_out,"58: %f %lf\n",AVG_58,SD_58);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_58);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_58);}
     else{
     fprintf(fd_out,"58: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_59!=0){
     AVG_59=SV_59_D/Samples_D_59;
     AVGD_59=SVD_59_D/Samples_D_59;
     SD_59=(sv_59_D/(Samples_D_59))-((AVGD_59)*(AVGD_59));
     SD_59=pow(SD_59,0.5);
     fprintf(fd_out,"59: %f %lf\n",AVG_59,SD_59);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_59);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_59);}
     else{
     fprintf(fd_out,"59: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_60!=0){
     AVG_60=SV_60_D/Samples_D_60;
     AVGD_60=SVD_60_D/Samples_D_60;
     SD_60=(sv_60_D/(Samples_D_60))-((AVGD_60)*(AVGD_60));
     SD_60=pow(SD_60,0.5);
     fprintf(fd_out,"60: %f %lf\n",AVG_60,SD_60);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_60);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_60);}
     else{
     fprintf(fd_out,"60: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_61!=0){
     AVG_61=SV_61_D/Samples_D_61;
     AVGD_61=SVD_61_D/Samples_D_61;
     SD_61=(sv_61_D/(Samples_D_61))-((AVGD_61)*(AVGD_61));
     SD_61=pow(SD_61,0.5);
     fprintf(fd_out,"61: %f %lf\n",AVG_61,SD_61);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_61);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_61);}
     else{
     fprintf(fd_out,"61: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_62!=0){
     AVG_62=SV_62_D/Samples_D_62;
     AVGD_62=SVD_62_D/Samples_D_62;
     SD_62=(sv_62_D/(Samples_D_62))-((AVGD_62)*(AVGD_62));
     SD_62=pow(SD_62,0.5);
     fprintf(fd_out,"62: %f %lf\n",AVG_62,SD_62);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_62);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_62);}
     else{
     fprintf(fd_out,"62: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_63!=0){
     AVG_63=SV_63_D/Samples_D_63;
     AVGD_63=SVD_63_D/Samples_D_63;
     SD_63=(sv_63_D/(Samples_D_63))-((AVGD_63)*(AVGD_63));
     SD_63=pow(SD_63,0.5);
     fprintf(fd_out,"63: %f %lf\n",AVG_63,SD_63);
     fprintf(fd_out_Neg_AVG, "%f	",AVG_63);
     fprintf(fd_out_Neg_SD, "%.2lf	",SD_63);}
     else{
     fprintf(fd_out,"63: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA	");
     fprintf(fd_out_Neg_SD, "NA	");}
     
     if(Samples_D_64!=0){
     AVG_64=SV_64_D/Samples_D_64;
     AVGD_64=SVD_64_D/Samples_D_64;
     SD_64=(sv_64_D/(Samples_D_64))-((AVGD_64)*(AVGD_64));
     SD_64=pow(SD_64,0.5);
     fprintf(fd_out,"64: %f %lf\n",AVG_64,SD_64);
     fprintf(fd_out_Neg_AVG, "%f\n",AVG_64);
     fprintf(fd_out_Neg_SD, "%.2lf\n",SD_64);}
     else{
     fprintf(fd_out,"64: NA NA\n");
     fprintf(fd_out_Neg_AVG, "NA");
     fprintf(fd_out_Neg_SD, "NA");}
}

int main ()
{   
    printf("By llw0411@gmail.com \n\n");
    
    printf("Enter File Name (EX:SCANXXX.DAT)\n");
    scanf("%s",&File_Name);
    
    printf("Enter Tolal Samples \n");
    scanf("%d",&Samples);
    
    FILE *fd_in = fopen(File_Name, "r");
    fd_out = fopen("Report_Form.txt", "w");
    fd_out_All_AVG = fopen("Report_Form_Totol_AVG.txt", "w");
    fd_out_All_SD = fopen("Report_Form_Totol_SD.txt", "w");
    fd_out_Pos_AVG = fopen("Report_Form_Pos_AVG.txt", "w");
    fd_out_Pos_SD = fopen("Report_Form_Pos_SD.txt", "w");
    fd_out_Neg_AVG = fopen("Report_Form_Neg_AVG.txt", "w");
    fd_out_Neg_SD = fopen("Report_Form_Neg_SD.txt", "w");
    
    int Total,Data;
    int Index=0;
    int CharBit=0;
    
    while (!feof(fd_in))
    {
          
       Initialization();
       //讀一整行進來
       fgets(buf, MAX_LEN, fd_in);
       
       //由於每筆資料(每一行)純數字(含正負小數點)不超過9個bit,且含編號共有65個數值,另外519代表每一行字元數皆不超過519
       if(buf != NULL)
       {
          for(Data=0;Data<=519;Data++)
          {
             if(buf[Data] != ',' )
             {
                 Save_Data[Index][CharBit]= buf[Data];
                 CharBit++;
                 if(buf[Data+1]== (char) 0 || buf[Data+1] == '\0')
                 {
                     Data=520;
                     Index=0;
                     CharBit=0;
                 }

                 if(CharBit>=9)
                 {
                     CharBit=0;
                 }
             }
             else if(buf[Data] == ',')
             {
                  Index++;
                  CharBit=0;       
             }
               
          }      
          
//轉換成Float,並計算總Totol值後存至各自的Buf(依序為AVG, SD, AVG(>0), SD(>0), AVG(<0), SD(<0) {PS : SV起頭者為AVG的Buf且只做(N1+N2+...+Nn)後續的除總樣本數則交由其他副程序 ; sv頭者為SD的Buf且只做(N1^2+N2^2+...+Nn^2)後續的除N減AVG的平方則交由其他副程序} 
          float Save_Data_1 = atof (Save_Data[1]);
          SV_1=(SV_1+Save_Data_1);
          SVD_1=(SVD_1+Save_Data_1);
          sv_1=sv_1+((Save_Data_1)*(Save_Data_1));
          if(Save_Data_1>0)
          {
              Samples_U_1++;
              SV_1_U=(SV_1_U+Save_Data_1);
              SVD_1_U=(SVD_1_U+Save_Data_1);
              sv_1_U=sv_1_U+((Save_Data_1)*(Save_Data_1));
          }
          if(Save_Data_1<0)
          {
              Samples_D_1++;
              SV_1_D=(SV_1_D+Save_Data_1);
              SVD_1_D=(SVD_1_D+Save_Data_1);
              sv_1_D=sv_1_D+((Save_Data_1)*(Save_Data_1));
          }
         
          float Save_Data_2 = atof (Save_Data[2]);
          SV_2=(SV_2+Save_Data_2);
          SVD_2=(SVD_2+Save_Data_2);
          sv_2=sv_2+((Save_Data_2)*(Save_Data_2));
          if(Save_Data_2>0)
          {
              Samples_U_2++;
              SV_2_U=(SV_2_U+Save_Data_2);
              SVD_2_U=(SVD_2_U+Save_Data_2);
              sv_2_U=sv_2_U+((Save_Data_2)*(Save_Data_2));
          }
          if(Save_Data_2<0)
          {
              Samples_D_2++;
              SV_2_D=(SV_2_D+Save_Data_2);
              SVD_2_D=(SVD_2_D+Save_Data_2);
              sv_2_D=sv_2_D+((Save_Data_2)*(Save_Data_2));
          }

          float Save_Data_3 = atof (Save_Data[3]);
          SV_3=(SV_3+Save_Data_3);
          SVD_3=(SVD_3+Save_Data_3);
          sv_3=sv_3+((Save_Data_3)*(Save_Data_3));
          if(Save_Data_3>0)
          {
              Samples_U_3++;
              SV_3_U=(SV_3_U+Save_Data_3);
              SVD_3_U=(SVD_3_U+Save_Data_3);
              sv_3_U=sv_3_U+((Save_Data_3)*(Save_Data_3));
          }
          if(Save_Data_3<0)
          {
              Samples_D_3++;
              SV_3_D=(SV_3_D+Save_Data_3);
              SVD_3_D=(SVD_3_D+Save_Data_3);
              sv_3_D=sv_3_D+((Save_Data_3)*(Save_Data_3));
          }
          
          float Save_Data_4 = atof (Save_Data[4]);
          SV_4=(SV_4+Save_Data_4);
          SVD_4=(SVD_4+Save_Data_4);
          sv_4=sv_4+((Save_Data_4)*(Save_Data_4));
          if(Save_Data_4>0)
          {
              Samples_U_4++;
              SV_4_U=(SV_4_U+Save_Data_4);
              SVD_4_U=(SVD_4_U+Save_Data_4);
              sv_4_U=sv_4_U+((Save_Data_4)*(Save_Data_4));
          }
          if(Save_Data_4<0)
          {
              Samples_D_4++;
              SV_4_D=(SV_4_D+Save_Data_4);
              SVD_4_D=(SVD_4_D+Save_Data_4);
              sv_4_D=sv_4_D+((Save_Data_4)*(Save_Data_4));
          }
          
          float Save_Data_5 = atof (Save_Data[5]);
          SV_5=(SV_5+Save_Data_5);
          SVD_5=(SVD_5+Save_Data_5);
          sv_5=sv_5+((Save_Data_5)*(Save_Data_5));
          if(Save_Data_5>0)
          {
              Samples_U_5++;
              SV_5_U=(SV_5_U+Save_Data_5);
              SVD_5_U=(SVD_5_U+Save_Data_5);
              sv_5_U=sv_5_U+((Save_Data_5)*(Save_Data_5));
          }
          if(Save_Data_5<0)
          {
              Samples_D_5++;
              SV_5_D=(SV_5_D+Save_Data_5);
              SVD_5_D=(SVD_5_D+Save_Data_5);
              sv_5_D=sv_5_D+((Save_Data_5)*(Save_Data_5));
          }
          
          float Save_Data_6 = atof (Save_Data[6]);
          SV_6=(SV_6+Save_Data_6);
          SVD_6=(SVD_6+Save_Data_6);
          sv_6=sv_6+((Save_Data_6)*(Save_Data_6));
          if(Save_Data_6>0)
          {
              Samples_U_6++;
              SV_6_U=(SV_6_U+Save_Data_6);
              SVD_6_U=(SVD_6_U+Save_Data_6);
              sv_6_U=sv_6_U+((Save_Data_6)*(Save_Data_6));
          }
          if(Save_Data_6<0)
          {
              Samples_D_6++;
              SV_6_D=(SV_6_D+Save_Data_6);
              SVD_6_D=(SVD_6_D+Save_Data_6);
              sv_6_D=sv_6_D+((Save_Data_6)*(Save_Data_6));
          }
          
          float Save_Data_7 = atof (Save_Data[7]);
          SV_7=(SV_7+Save_Data_7);
          SVD_7=(SVD_7+Save_Data_7);
          sv_7=sv_7+((Save_Data_7)*(Save_Data_7));
          if(Save_Data_7>0)
          {
              Samples_U_7++;
              SV_7_U=(SV_7_U+Save_Data_7);
              SVD_7_U=(SVD_7_U+Save_Data_7);
              sv_7_U=sv_7_U+((Save_Data_7)*(Save_Data_7));
          }
          if(Save_Data_7<0)
          {
              Samples_D_7++;
              SV_7_D=(SV_7_D+Save_Data_7);
              SVD_7_D=(SVD_7_D+Save_Data_7);
              sv_7_D=sv_7_D+((Save_Data_7)*(Save_Data_7));
          }
          
          float Save_Data_8 = atof (Save_Data[8]);
          SV_8=(SV_8+Save_Data_8);
          SVD_8=(SVD_8+Save_Data_8);
          sv_8=sv_8+((Save_Data_8)*(Save_Data_8));
          if(Save_Data_8>0)
          {
              Samples_U_8++;
              SV_8_U=(SV_8_U+Save_Data_8);
              SVD_8_U=(SVD_8_U+Save_Data_8);
              sv_8_U=sv_8_U+((Save_Data_8)*(Save_Data_8));
          }
          if(Save_Data_8<0)
          {
              Samples_D_8++;
              SV_8_D=(SV_8_D+Save_Data_8);
              SVD_8_D=(SVD_8_D+Save_Data_8);
              sv_8_D=sv_8_D+((Save_Data_8)*(Save_Data_8));
          }
          
          float Save_Data_9 = atof (Save_Data[9]);
          SV_9=(SV_9+Save_Data_9);
          SVD_9=(SVD_9+Save_Data_9);
          sv_9=sv_9+((Save_Data_9)*(Save_Data_9));
          if(Save_Data_9>0)
          {
              Samples_U_9++;
              SV_9_U=(SV_9_U+Save_Data_9);
              SVD_9_U=(SVD_9_U+Save_Data_9);
              sv_9_U=sv_9_U+((Save_Data_9)*(Save_Data_9));
          }
          if(Save_Data_9<0)
          {
              Samples_D_9++;
              SV_9_D=(SV_9_D+Save_Data_9);
              SVD_9_D=(SVD_9_D+Save_Data_9);
              sv_9_D=sv_9_D+((Save_Data_9)*(Save_Data_9));
          }
          
          float Save_Data_10 = atof (Save_Data[10]);
          SV_10=(SV_10+Save_Data_10);
          SVD_10=(SVD_10+Save_Data_10);
          sv_10=sv_10+((Save_Data_10)*(Save_Data_10));
          if(Save_Data_10>0)
          {
              Samples_U_10++;
              SV_10_U=(SV_10_U+Save_Data_10);
              SVD_10_U=(SVD_10_U+Save_Data_10);
              sv_10_U=sv_10_U+((Save_Data_10)*(Save_Data_10));
          }
          if(Save_Data_10<0)
          {
              Samples_D_10++;
              SV_10_D=(SV_10_D+Save_Data_10);
              SVD_10_D=(SVD_10_D+Save_Data_10);
              sv_10_D=sv_10_D+((Save_Data_10)*(Save_Data_10));
          }
          
          float Save_Data_11 = atof (Save_Data[11]);
          SV_11=(SV_11+Save_Data_11);
          SVD_11=(SVD_11+Save_Data_11);
          sv_11=sv_11+((Save_Data_11)*(Save_Data_11));
          if(Save_Data_11>0)
          {
              Samples_U_11++;
              SV_11_U=(SV_11_U+Save_Data_11);
              SVD_11_U=(SVD_11_U+Save_Data_11);
              sv_11_U=sv_11_U+((Save_Data_11)*(Save_Data_11));
          }
          if(Save_Data_11<0)
          {
              Samples_D_11++;
              SV_11_D=(SV_11_D+Save_Data_11);
              SVD_11_D=(SVD_11_D+Save_Data_11);
              sv_11_D=sv_11_D+((Save_Data_11)*(Save_Data_11));
          }
          
          float Save_Data_12 = atof (Save_Data[12]);
          SV_12=(SV_12+Save_Data_12);
          SVD_12=(SVD_12+Save_Data_12);
          sv_12=sv_12+((Save_Data_12)*(Save_Data_12));
          if(Save_Data_12>0)
          {
              Samples_U_12++;
              SV_12_U=(SV_12_U+Save_Data_12);
              SVD_12_U=(SVD_12_U+Save_Data_12);
              sv_12_U=sv_12_U+((Save_Data_12)*(Save_Data_12));
          }
          if(Save_Data_12<0)
          {
              Samples_D_12++;
              SV_12_D=(SV_12_D+Save_Data_12);
              SVD_12_D=(SVD_12_D+Save_Data_12);
              sv_12_D=sv_12_D+((Save_Data_12)*(Save_Data_12));
          }
          
          float Save_Data_13 = atof (Save_Data[13]);
          SV_13=(SV_13+Save_Data_13);
          SVD_13=(SVD_13+Save_Data_13);
          sv_13=sv_13+((Save_Data_13)*(Save_Data_13));
          if(Save_Data_13>0)
          {
              Samples_U_13++;
              SV_13_U=(SV_13_U+Save_Data_13);
              SVD_13_U=(SVD_13_U+Save_Data_13);
              sv_13_U=sv_13_U+((Save_Data_13)*(Save_Data_13));
          }
          if(Save_Data_13<0)
          {
              Samples_D_13++;
              SV_13_D=(SV_13_D+Save_Data_13);
              SVD_13_D=(SVD_13_D+Save_Data_13);
              sv_13_D=sv_13_D+((Save_Data_13)*(Save_Data_13));
          }
          
          float Save_Data_14 = atof (Save_Data[14]);
          SV_14=(SV_14+Save_Data_14);
          SVD_14=(SVD_14+Save_Data_14);
          sv_14=sv_14+((Save_Data_14)*(Save_Data_14));
          if(Save_Data_14>0)
          {
              Samples_U_14++;
              SV_14_U=(SV_14_U+Save_Data_14);
              SVD_14_U=(SVD_14_U+Save_Data_14);
              sv_14_U=sv_14_U+((Save_Data_14)*(Save_Data_14));
          }
          if(Save_Data_14<0)
          {
              Samples_D_14++;
              SV_14_D=(SV_14_D+Save_Data_14);
              SVD_14_D=(SVD_14_D+Save_Data_14);
              sv_14_D=sv_14_D+((Save_Data_14)*(Save_Data_14));
          }
          
          float Save_Data_15 = atof (Save_Data[15]);
          SV_15=(SV_15+Save_Data_15);
          SVD_15=(SVD_15+Save_Data_15);
          sv_15=sv_15+((Save_Data_15)*(Save_Data_15));
          if(Save_Data_15>0)
          {
              Samples_U_15++;
              SV_15_U=(SV_15_U+Save_Data_15);
              SVD_15_U=(SVD_15_U+Save_Data_15);
              sv_15_U=sv_15_U+((Save_Data_15)*(Save_Data_15));
          }
          if(Save_Data_15<0)
          {
              Samples_D_15++;
              SV_15_D=(SV_15_D+Save_Data_15);
              SVD_15_D=(SVD_15_D+Save_Data_15);
              sv_15_D=sv_15_D+((Save_Data_15)*(Save_Data_15));
          }
          
          float Save_Data_16 = atof (Save_Data[16]);
          SV_16=(SV_16+Save_Data_16);
          SVD_16=(SVD_16+Save_Data_16);
          sv_16=sv_16+((Save_Data_16)*(Save_Data_16));
          if(Save_Data_16>0)
          {
              Samples_U_16++;
              SV_16_U=(SV_16_U+Save_Data_16);
              SVD_16_U=(SVD_16_U+Save_Data_16);
              sv_16_U=sv_16_U+((Save_Data_16)*(Save_Data_16));
          }
          if(Save_Data_16<0)
          {
              Samples_D_16++;
              SV_16_D=(SV_16_D+Save_Data_16);
              SVD_16_D=(SVD_16_D+Save_Data_16);
              sv_16_D=sv_16_D+((Save_Data_16)*(Save_Data_16));
          }
          
          float Save_Data_17 = atof (Save_Data[17]);
          SV_17=(SV_17+Save_Data_17);
          SVD_17=(SVD_17+Save_Data_17);
          sv_17=sv_17+((Save_Data_17)*(Save_Data_17));
          if(Save_Data_17>0)
          {
              Samples_U_17++;
              SV_17_U=(SV_17_U+Save_Data_17);
              SVD_17_U=(SVD_17_U+Save_Data_17);
              sv_17_U=sv_17_U+((Save_Data_17)*(Save_Data_17));
          }
          if(Save_Data_17<0)
          {
              Samples_D_17++;
              SV_17_D=(SV_17_D+Save_Data_17);
              SVD_17_D=(SVD_17_D+Save_Data_17);
              sv_17_D=sv_17_D+((Save_Data_17)*(Save_Data_17));
          }
          
          float Save_Data_18 = atof (Save_Data[18]);
          SV_18=(SV_18+Save_Data_18);
          SVD_18=(SVD_18+Save_Data_18);
          sv_18=sv_18+((Save_Data_18)*(Save_Data_18));
          if(Save_Data_18>0)
          {
              Samples_U_18++;
              SV_18_U=(SV_18_U+Save_Data_18);
              SVD_18_U=(SVD_18_U+Save_Data_18);
              sv_18_U=sv_18_U+((Save_Data_18)*(Save_Data_18));
          }
          if(Save_Data_18<0)
          {
              Samples_D_18++;
              SV_18_D=(SV_18_D+Save_Data_18);
              SVD_18_D=(SVD_18_D+Save_Data_18);
              sv_18_D=sv_18_D+((Save_Data_18)*(Save_Data_18));
          }
          
          float Save_Data_19 = atof (Save_Data[19]);
          SV_19=(SV_19+Save_Data_19);
          SVD_19=(SVD_19+Save_Data_19);
          sv_19=sv_19+((Save_Data_19)*(Save_Data_19));
          if(Save_Data_19>0)
          {
              Samples_U_19++;
              SV_19_U=(SV_19_U+Save_Data_19);
              SVD_19_U=(SVD_19_U+Save_Data_19);
              sv_19_U=sv_19_U+((Save_Data_19)*(Save_Data_19));
          }
          if(Save_Data_19<0)
          {
              Samples_D_19++;
              SV_19_D=(SV_19_D+Save_Data_19);
              SVD_19_D=(SVD_19_D+Save_Data_19);
              sv_19_D=sv_19_D+((Save_Data_19)*(Save_Data_19));
          }
          
          float Save_Data_20 = atof (Save_Data[20]);
          SV_20=(SV_20+Save_Data_20);
          SVD_20=(SVD_20+Save_Data_20);
          sv_20=sv_20+((Save_Data_20)*(Save_Data_20));
          if(Save_Data_20>0)
          {
              Samples_U_20++;
              SV_20_U=(SV_20_U+Save_Data_20);
              SVD_20_U=(SVD_20_U+Save_Data_20);
              sv_20_U=sv_20_U+((Save_Data_20)*(Save_Data_20));
          }
          if(Save_Data_20<0)
          {
              Samples_D_20++;
              SV_20_D=(SV_20_D+Save_Data_20);
              SVD_20_D=(SVD_20_D+Save_Data_20);
              sv_20_D=sv_20_D+((Save_Data_20)*(Save_Data_20));
          }
          
          float Save_Data_21 = atof (Save_Data[21]);
          SV_21=(SV_21+Save_Data_21);
          SVD_21=(SVD_21+Save_Data_21);
          sv_21=sv_21+((Save_Data_21)*(Save_Data_21));
          if(Save_Data_21>0)
          {
              Samples_U_21++;
              SV_21_U=(SV_21_U+Save_Data_21);
              SVD_21_U=(SVD_21_U+Save_Data_21);
              sv_21_U=sv_21_U+((Save_Data_21)*(Save_Data_21));
          }
          if(Save_Data_21<0)
          {
              Samples_D_21++;
              SV_21_D=(SV_21_D+Save_Data_21);
              SVD_21_D=(SVD_21_D+Save_Data_21);
              sv_21_D=sv_21_D+((Save_Data_21)*(Save_Data_21));
          }
          
          float Save_Data_22 = atof (Save_Data[22]);
          SV_22=(SV_22+Save_Data_22);
          SVD_22=(SVD_22+Save_Data_22);
          sv_22=sv_22+((Save_Data_22)*(Save_Data_22));
          if(Save_Data_22>0)
          {
              Samples_U_22++;
              SV_22_U=(SV_22_U+Save_Data_22);
              SVD_22_U=(SVD_22_U+Save_Data_22);
              sv_22_U=sv_22_U+((Save_Data_22)*(Save_Data_22));
          }
          if(Save_Data_22<0)
          {
              Samples_D_22++;
              SV_22_D=(SV_22_D+Save_Data_22);
              SVD_22_D=(SVD_22_D+Save_Data_22);
              sv_22_D=sv_22_D+((Save_Data_22)*(Save_Data_22));
          }
          
          float Save_Data_23 = atof (Save_Data[23]);
          SV_23=(SV_23+Save_Data_23);
          SVD_23=(SVD_23+Save_Data_23);
          sv_23=sv_23+((Save_Data_23)*(Save_Data_23));
          if(Save_Data_23>0)
          {
              Samples_U_23++;
              SV_23_U=(SV_23_U+Save_Data_23);
              SVD_23_U=(SVD_23_U+Save_Data_23);
              sv_23_U=sv_23_U+((Save_Data_23)*(Save_Data_23));
          }
          if(Save_Data_23<0)
          {
              Samples_D_23++;
              SV_23_D=(SV_23_D+Save_Data_23);
              SVD_23_D=(SVD_23_D+Save_Data_23);
              sv_23_D=sv_23_D+((Save_Data_23)*(Save_Data_23));
          }
          
          float Save_Data_24 = atof (Save_Data[24]);
          SV_24=(SV_24+Save_Data_24);
          SVD_24=(SVD_24+Save_Data_24);
          sv_24=sv_24+((Save_Data_24)*(Save_Data_24));
          if(Save_Data_24>0)
          {
              Samples_U_24++;
              SV_24_U=(SV_24_U+Save_Data_24);
              SVD_24_U=(SVD_24_U+Save_Data_24);
              sv_24_U=sv_24_U+((Save_Data_24)*(Save_Data_24));
          }
          if(Save_Data_24<0)
          {
              Samples_D_24++;
              SV_24_D=(SV_24_D+Save_Data_24);
              SVD_24_D=(SVD_24_D+Save_Data_24);
              sv_24_D=sv_24_D+((Save_Data_24)*(Save_Data_24));
          }
          
          float Save_Data_25 = atof (Save_Data[25]);
          SV_25=(SV_25+Save_Data_25);
          SVD_25=(SVD_25+Save_Data_25);
          sv_25=sv_25+((Save_Data_25)*(Save_Data_25));
          if(Save_Data_25>0)
          {
              Samples_U_25++;
              SV_25_U=(SV_25_U+Save_Data_25);
              SVD_25_U=(SVD_25_U+Save_Data_25);
              sv_25_U=sv_25_U+((Save_Data_25)*(Save_Data_25));
          }
          if(Save_Data_25<0)
          {
              Samples_D_25++;
              SV_25_D=(SV_25_D+Save_Data_25);
              SVD_25_D=(SVD_25_D+Save_Data_25);
              sv_25_D=sv_25_D+((Save_Data_25)*(Save_Data_25));
          }
          
          float Save_Data_26 = atof (Save_Data[26]);
          SV_26=(SV_26+Save_Data_26);
          SVD_26=(SVD_26+Save_Data_26);
          sv_26=sv_26+((Save_Data_26)*(Save_Data_26));
          if(Save_Data_26>0)
          {
              Samples_U_26++;
              SV_26_U=(SV_26_U+Save_Data_26);
              SVD_26_U=(SVD_26_U+Save_Data_26);
              sv_26_U=sv_26_U+((Save_Data_26)*(Save_Data_26));
          }
          if(Save_Data_26<0)
          {
              Samples_D_26++;
              SV_26_D=(SV_26_D+Save_Data_26);
              SVD_26_D=(SVD_26_D+Save_Data_26);
              sv_26_D=sv_26_D+((Save_Data_26)*(Save_Data_26));
          }
          
          float Save_Data_27 = atof (Save_Data[27]);
          SV_27=(SV_27+Save_Data_27);
          SVD_27=(SVD_27+Save_Data_27);
          sv_27=sv_27+((Save_Data_27)*(Save_Data_27));
          if(Save_Data_27>0)
          {
              Samples_U_27++;
              SV_27_U=(SV_27_U+Save_Data_27);
              SVD_27_U=(SVD_27_U+Save_Data_27);
              sv_27_U=sv_27_U+((Save_Data_27)*(Save_Data_27));
          }
          if(Save_Data_27<0)
          {
              Samples_D_27++;
              SV_27_D=(SV_27_D+Save_Data_27);
              SVD_27_D=(SVD_27_D+Save_Data_27);
              sv_27_D=sv_27_D+((Save_Data_27)*(Save_Data_27));
          }
          
          float Save_Data_28 = atof (Save_Data[28]);
          SV_28=(SV_28+Save_Data_28);
          SVD_28=(SVD_28+Save_Data_28);
          sv_28=sv_28+((Save_Data_28)*(Save_Data_28));
          if(Save_Data_28>0)
          {
              Samples_U_28++;
              SV_28_U=(SV_28_U+Save_Data_28);
              SVD_28_U=(SVD_28_U+Save_Data_28);
              sv_28_U=sv_28_U+((Save_Data_28)*(Save_Data_28));
          }
          if(Save_Data_28<0)
          {
              Samples_D_28++;
              SV_28_D=(SV_28_D+Save_Data_28);
              SVD_28_D=(SVD_28_D+Save_Data_28);
              sv_28_D=sv_28_D+((Save_Data_28)*(Save_Data_28));
          }
          
          float Save_Data_29 = atof (Save_Data[29]);
          SV_29=(SV_29+Save_Data_29);
          SVD_29=(SVD_29+Save_Data_29);
          sv_29=sv_29+((Save_Data_29)*(Save_Data_29));
          if(Save_Data_29>0)
          {
              Samples_U_29++;
              SV_29_U=(SV_29_U+Save_Data_29);
              SVD_29_U=(SVD_29_U+Save_Data_29);
              sv_29_U=sv_29_U+((Save_Data_29)*(Save_Data_29));
          }
          if(Save_Data_29<0)
          {
              Samples_D_29++;
              SV_29_D=(SV_29_D+Save_Data_29);
              SVD_29_D=(SVD_29_D+Save_Data_29);
              sv_29_D=sv_29_D+((Save_Data_29)*(Save_Data_29));
          }
          
          float Save_Data_30 = atof (Save_Data[30]);
          SV_30=(SV_30+Save_Data_30);
          SVD_30=(SVD_30+Save_Data_30);
          sv_30=sv_30+((Save_Data_30)*(Save_Data_30));
          if(Save_Data_30>0)
          {
              Samples_U_30++;
              SV_30_U=(SV_30_U+Save_Data_30);
              SVD_30_U=(SVD_30_U+Save_Data_30);
              sv_30_U=sv_30_U+((Save_Data_30)*(Save_Data_30));
          }
          if(Save_Data_30<0)
          {
              Samples_D_30++;
              SV_30_D=(SV_30_D+Save_Data_30);
              SVD_30_D=(SVD_30_D+Save_Data_30);
              sv_30_D=sv_30_D+((Save_Data_30)*(Save_Data_30));
          }
          
          float Save_Data_31 = atof (Save_Data[31]);
          SV_31=(SV_31+Save_Data_31);
          SVD_31=(SVD_31+Save_Data_31);
          sv_31=sv_31+((Save_Data_31)*(Save_Data_31));
          if(Save_Data_31>0)
          {
              Samples_U_31++;
              SV_31_U=(SV_31_U+Save_Data_31);
              SVD_31_U=(SVD_31_U+Save_Data_31);
              sv_31_U=sv_31_U+((Save_Data_31)*(Save_Data_31));
          }
          if(Save_Data_31<0)
          {
              Samples_D_31++;
              SV_31_D=(SV_31_D+Save_Data_31);
              SVD_31_D=(SVD_31_D+Save_Data_31);
              sv_31_D=sv_31_D+((Save_Data_31)*(Save_Data_31));
          }
          
          float Save_Data_32 = atof (Save_Data[32]);
          SV_32=(SV_32+Save_Data_32);
          SVD_32=(SVD_32+Save_Data_32);
          sv_32=sv_32+((Save_Data_32)*(Save_Data_32));
          if(Save_Data_32>0)
          {
              Samples_U_32++;
              SV_32_U=(SV_32_U+Save_Data_32);
              SVD_32_U=(SVD_32_U+Save_Data_32);
              sv_32_U=sv_32_U+((Save_Data_32)*(Save_Data_32));
          }
          if(Save_Data_32<0)
          {
              Samples_D_32++;
              SV_32_D=(SV_32_D+Save_Data_32);
              SVD_32_D=(SVD_32_D+Save_Data_32);
              sv_32_D=sv_32_D+((Save_Data_32)*(Save_Data_32));
          }
          
          float Save_Data_33 = atof (Save_Data[33]);
          SV_33=(SV_33+Save_Data_33);
          SVD_33=(SVD_33+Save_Data_33);
          sv_33=sv_33+((Save_Data_33)*(Save_Data_33));
          if(Save_Data_33>0)
          {
              Samples_U_33++;
              SV_33_U=(SV_33_U+Save_Data_33);
              SVD_33_U=(SVD_33_U+Save_Data_33);
              sv_33_U=sv_33_U+((Save_Data_33)*(Save_Data_33));
          }
          if(Save_Data_33<0)
          {
              Samples_D_33++;
              SV_33_D=(SV_33_D+Save_Data_33);
              SVD_33_D=(SVD_33_D+Save_Data_33);
              sv_33_D=sv_33_D+((Save_Data_33)*(Save_Data_33));
          }
          
          float Save_Data_34 = atof (Save_Data[34]);
          SV_34=(SV_34+Save_Data_34);
          SVD_34=(SVD_34+Save_Data_34);
          sv_34=sv_34+((Save_Data_34)*(Save_Data_34));
          if(Save_Data_34>0)
          {
              Samples_U_34++;
              SV_34_U=(SV_34_U+Save_Data_34);
              SVD_34_U=(SVD_34_U+Save_Data_34);
              sv_34_U=sv_34_U+((Save_Data_34)*(Save_Data_34));
          }
          if(Save_Data_34<0)
          {
              Samples_D_34++;
              SV_34_D=(SV_34_D+Save_Data_34);
              SVD_34_D=(SVD_34_D+Save_Data_34);
              sv_34_D=sv_34_D+((Save_Data_34)*(Save_Data_34));
          }
          
          float Save_Data_35 = atof (Save_Data[35]);
          SV_35=(SV_35+Save_Data_35);
          SVD_35=(SVD_35+Save_Data_35);
          sv_35=sv_35+((Save_Data_35)*(Save_Data_35));
          if(Save_Data_35>0)
          {
              Samples_U_35++;
              SV_35_U=(SV_35_U+Save_Data_35);
              SVD_35_U=(SVD_35_U+Save_Data_35);
              sv_35_U=sv_35_U+((Save_Data_35)*(Save_Data_35));
          }
          if(Save_Data_35<0)
          {
              Samples_D_35++;
              SV_35_D=(SV_35_D+Save_Data_35);
              SVD_35_D=(SVD_35_D+Save_Data_35);
              sv_35_D=sv_35_D+((Save_Data_35)*(Save_Data_35));
          }
          
          float Save_Data_36 = atof (Save_Data[36]);
          SV_36=(SV_36+Save_Data_36);
          SVD_36=(SVD_36+Save_Data_36);
          sv_36=sv_36+((Save_Data_36)*(Save_Data_36));
          if(Save_Data_36>0)
          {
              Samples_U_36++;
              SV_36_U=(SV_36_U+Save_Data_36);
              SVD_36_U=(SVD_36_U+Save_Data_36);
              sv_36_U=sv_36_U+((Save_Data_36)*(Save_Data_36));
          }
          if(Save_Data_36<0)
          {
              Samples_D_36++;
              SV_36_D=(SV_36_D+Save_Data_36);
              SVD_36_D=(SVD_36_D+Save_Data_36);
              sv_36_D=sv_36_D+((Save_Data_36)*(Save_Data_36));
          }
          
          float Save_Data_37 = atof (Save_Data[37]);
          SV_37=(SV_37+Save_Data_37);
          SVD_37=(SVD_37+Save_Data_37);
          sv_37=sv_37+((Save_Data_37)*(Save_Data_37));
          if(Save_Data_37>0)
          {
              Samples_U_37++;
              SV_37_U=(SV_37_U+Save_Data_37);
              SVD_37_U=(SVD_37_U+Save_Data_37);
              sv_37_U=sv_37_U+((Save_Data_37)*(Save_Data_37));
          }
          if(Save_Data_37<0)
          {
              Samples_D_37++;
              SV_37_D=(SV_37_D+Save_Data_37);
              SVD_37_D=(SVD_37_D+Save_Data_37);
              sv_37_D=sv_37_D+((Save_Data_37)*(Save_Data_37));
          }
          
          float Save_Data_38 = atof (Save_Data[38]);
          SV_38=(SV_38+Save_Data_38);
          SVD_38=(SVD_38+Save_Data_38);
          sv_38=sv_38+((Save_Data_38)*(Save_Data_38));
          if(Save_Data_38>0)
          {
              Samples_U_38++;
              SV_38_U=(SV_38_U+Save_Data_38);
              SVD_38_U=(SVD_38_U+Save_Data_38);
              sv_38_U=sv_38_U+((Save_Data_38)*(Save_Data_38));
          }
          if(Save_Data_38<0)
          {
              Samples_D_38++;
              SV_38_D=(SV_38_D+Save_Data_38);
              SVD_38_D=(SVD_38_D+Save_Data_38);
              sv_38_D=sv_38_D+((Save_Data_38)*(Save_Data_38));
          }
          
          float Save_Data_39 = atof (Save_Data[39]);
          SV_39=(SV_39+Save_Data_39);
          SVD_39=(SVD_39+Save_Data_39);
          sv_39=sv_39+((Save_Data_39)*(Save_Data_39));
          if(Save_Data_39>0)
          {
              Samples_U_39++;
              SV_39_U=(SV_39_U+Save_Data_39);
              SVD_39_U=(SVD_39_U+Save_Data_39);
              sv_39_U=sv_39_U+((Save_Data_39)*(Save_Data_39));
          }
          if(Save_Data_39<0)
          {
              Samples_D_39++;
              SV_39_D=(SV_39_D+Save_Data_39);
              SVD_39_D=(SVD_39_D+Save_Data_39);
              sv_39_D=sv_39_D+((Save_Data_39)*(Save_Data_39));
          }
          
          float Save_Data_40 = atof (Save_Data[40]);
          SV_40=(SV_40+Save_Data_40);
          SVD_40=(SVD_40+Save_Data_40);
          sv_40=sv_40+((Save_Data_40)*(Save_Data_40));
          if(Save_Data_40>0)
          {
              Samples_U_40++;
              SV_40_U=(SV_40_U+Save_Data_40);
              SVD_40_U=(SVD_40_U+Save_Data_40);
              sv_40_U=sv_40_U+((Save_Data_40)*(Save_Data_40));
          }
          if(Save_Data_40<0)
          {
              Samples_D_40++;
              SV_40_D=(SV_40_D+Save_Data_40);
              SVD_40_D=(SVD_40_D+Save_Data_40);
              sv_40_D=sv_40_D+((Save_Data_40)*(Save_Data_40));
          }
          
          float Save_Data_41 = atof (Save_Data[41]);
          SV_41=(SV_41+Save_Data_41);
          SVD_41=(SVD_41+Save_Data_41);
          sv_41=sv_41+((Save_Data_41)*(Save_Data_41));
          if(Save_Data_41>0)
          {
              Samples_U_41++;
              SV_41_U=(SV_41_U+Save_Data_41);
              SVD_41_U=(SVD_41_U+Save_Data_41);
              sv_41_U=sv_41_U+((Save_Data_41)*(Save_Data_41));
          }
          if(Save_Data_41<0)
          {
              Samples_D_41++;
              SV_41_D=(SV_41_D+Save_Data_41);
              SVD_41_D=(SVD_41_D+Save_Data_41);
              sv_41_D=sv_41_D+((Save_Data_41)*(Save_Data_41));
          }
          
          float Save_Data_42 = atof (Save_Data[42]);
          SV_42=(SV_42+Save_Data_42);
          SVD_42=(SVD_42+Save_Data_42);
          sv_42=sv_42+((Save_Data_42)*(Save_Data_42));
          if(Save_Data_42>0)
          {
              Samples_U_42++;
              SV_42_U=(SV_42_U+Save_Data_42);
              SVD_42_U=(SVD_42_U+Save_Data_42);
              sv_42_U=sv_42_U+((Save_Data_42)*(Save_Data_42));
          }
          if(Save_Data_42<0)
          {
              Samples_D_42++;
              SV_42_D=(SV_42_D+Save_Data_42);
              SVD_42_D=(SVD_42_D+Save_Data_42);
              sv_42_D=sv_42_D+((Save_Data_42)*(Save_Data_42));
          }
          
          float Save_Data_43 = atof (Save_Data[43]);
          SV_43=(SV_43+Save_Data_43);
          SVD_43=(SVD_43+Save_Data_43);
          sv_43=sv_43+((Save_Data_43)*(Save_Data_43));
          if(Save_Data_43>0)
          {
              Samples_U_43++;
              SV_43_U=(SV_43_U+Save_Data_43);
              SVD_43_U=(SVD_43_U+Save_Data_43);
              sv_43_U=sv_43_U+((Save_Data_43)*(Save_Data_43));
          }
          if(Save_Data_43<0)
          {
              Samples_D_43++;
              SV_43_D=(SV_43_D+Save_Data_43);
              SVD_43_D=(SVD_43_D+Save_Data_43);
              sv_43_D=sv_43_D+((Save_Data_43)*(Save_Data_43));
          }
          
          float Save_Data_44 = atof (Save_Data[44]);
          SV_44=(SV_44+Save_Data_44);
          SVD_44=(SVD_44+Save_Data_44);
          sv_44=sv_44+((Save_Data_44)*(Save_Data_44));
          if(Save_Data_44>0)
          {
              Samples_U_44++;
              SV_44_U=(SV_44_U+Save_Data_44);
              SVD_44_U=(SVD_44_U+Save_Data_44);
              sv_44_U=sv_44_U+((Save_Data_44)*(Save_Data_44));
          }
          if(Save_Data_44<0)
          {
              Samples_D_44++;
              SV_44_D=(SV_44_D+Save_Data_44);
              SVD_44_D=(SVD_44_D+Save_Data_44);
              sv_44_D=sv_44_D+((Save_Data_44)*(Save_Data_44));
          }
          
          float Save_Data_45 = atof (Save_Data[45]);
          SV_45=(SV_45+Save_Data_45);
          SVD_45=(SVD_45+Save_Data_45);
          sv_45=sv_45+((Save_Data_45)*(Save_Data_45));
          if(Save_Data_45>0)
          {
              Samples_U_45++;
              SV_45_U=(SV_45_U+Save_Data_45);
              SVD_45_U=(SVD_45_U+Save_Data_45);
              sv_45_U=sv_45_U+((Save_Data_45)*(Save_Data_45));
          }
          if(Save_Data_45<0)
          {
              Samples_D_45++;
              SV_45_D=(SV_45_D+Save_Data_45);
              SVD_45_D=(SVD_45_D+Save_Data_45);
              sv_45_D=sv_45_D+((Save_Data_45)*(Save_Data_45));
          }
          
          float Save_Data_46 = atof (Save_Data[46]);
          SV_46=(SV_46+Save_Data_46);
          SVD_46=(SVD_46+Save_Data_46);
          sv_46=sv_46+((Save_Data_46)*(Save_Data_46));
          if(Save_Data_46>0)
          {
              Samples_U_46++;
              SV_46_U=(SV_46_U+Save_Data_46);
              SVD_46_U=(SVD_46_U+Save_Data_46);
              sv_46_U=sv_46_U+((Save_Data_46)*(Save_Data_46));
          }
          if(Save_Data_46<0)
          {
              Samples_D_46++;
              SV_46_D=(SV_46_D+Save_Data_46);
              SVD_46_D=(SVD_46_D+Save_Data_46);
              sv_46_D=sv_46_D+((Save_Data_46)*(Save_Data_46));
          }
          
          float Save_Data_47 = atof (Save_Data[47]);
          SV_47=(SV_47+Save_Data_47);
          SVD_47=(SVD_47+Save_Data_47);
          sv_47=sv_47+((Save_Data_47)*(Save_Data_47));
          if(Save_Data_47>0)
          {
              Samples_U_47++;
              SV_47_U=(SV_47_U+Save_Data_47);
              SVD_47_U=(SVD_47_U+Save_Data_47);
              sv_47_U=sv_47_U+((Save_Data_47)*(Save_Data_47));
          }
          if(Save_Data_47<0)
          {
              Samples_D_47++;
              SV_47_D=(SV_47_D+Save_Data_47);
              SVD_47_D=(SVD_47_D+Save_Data_47);
              sv_47_D=sv_47_D+((Save_Data_47)*(Save_Data_47));
          }
          
          float Save_Data_48 = atof (Save_Data[48]);
          SV_48=(SV_48+Save_Data_48);
          SVD_48=(SVD_48+Save_Data_48);
          sv_48=sv_48+((Save_Data_48)*(Save_Data_48));
          if(Save_Data_48>0)
          {
              Samples_U_48++;
              SV_48_U=(SV_48_U+Save_Data_48);
              SVD_48_U=(SVD_48_U+Save_Data_48);
              sv_48_U=sv_48_U+((Save_Data_48)*(Save_Data_48));
          }
          if(Save_Data_48<0)
          {
              Samples_D_48++;
              SV_48_D=(SV_48_D+Save_Data_48);
              SVD_48_D=(SVD_48_D+Save_Data_48);
              sv_48_D=sv_48_D+((Save_Data_48)*(Save_Data_48));
          }
          
          float Save_Data_49 = atof (Save_Data[49]);
          SV_49=(SV_49+Save_Data_49);
          SVD_49=(SVD_49+Save_Data_49);
          sv_49=sv_49+((Save_Data_49)*(Save_Data_49));
          if(Save_Data_49>0)
          {
              Samples_U_49++;
              SV_49_U=(SV_49_U+Save_Data_49);
              SVD_49_U=(SVD_49_U+Save_Data_49);
              sv_49_U=sv_49_U+((Save_Data_49)*(Save_Data_49));
          }
          if(Save_Data_49<0)
          {
              Samples_D_49++;
              SV_49_D=(SV_49_D+Save_Data_49);
              SVD_49_D=(SVD_49_D+Save_Data_49);
              sv_49_D=sv_49_D+((Save_Data_49)*(Save_Data_49));
          }
          
          float Save_Data_50 = atof (Save_Data[50]);
          SV_50=(SV_50+Save_Data_50);
          SVD_50=(SVD_50+Save_Data_50);
          sv_50=sv_50+((Save_Data_50)*(Save_Data_50));
          if(Save_Data_50>0)
          {
              Samples_U_50++;
              SV_50_U=(SV_50_U+Save_Data_50);
              SVD_50_U=(SVD_50_U+Save_Data_50);
              sv_50_U=sv_50_U+((Save_Data_50)*(Save_Data_50));
          }
          if(Save_Data_50<0)
          {
              Samples_D_50++;
              SV_50_D=(SV_50_D+Save_Data_50);
              SVD_50_D=(SVD_50_D+Save_Data_50);
              sv_50_D=sv_50_D+((Save_Data_50)*(Save_Data_50));
          }
          
          float Save_Data_51 = atof (Save_Data[51]);
          SV_51=(SV_51+Save_Data_51);
          SVD_51=(SVD_51+Save_Data_51);
          sv_51=sv_51+((Save_Data_51)*(Save_Data_51));
          if(Save_Data_51>0)
          {
              Samples_U_51++;
              SV_51_U=(SV_51_U+Save_Data_51);
              SVD_51_U=(SVD_51_U+Save_Data_51);
              sv_51_U=sv_51_U+((Save_Data_51)*(Save_Data_51));
          }
          if(Save_Data_51<0)
          {
              Samples_D_51++;
              SV_51_D=(SV_51_D+Save_Data_51);
              SVD_51_D=(SVD_51_D+Save_Data_51);
              sv_51_D=sv_51_D+((Save_Data_51)*(Save_Data_51));
          }
          
          float Save_Data_52 = atof (Save_Data[52]);
          SV_52=(SV_52+Save_Data_52);
          SVD_52=(SVD_52+Save_Data_52);
          sv_52=sv_52+((Save_Data_52)*(Save_Data_52));
          if(Save_Data_52>0)
          {
              Samples_U_52++;
              SV_52_U=(SV_52_U+Save_Data_52);
              SVD_52_U=(SVD_52_U+Save_Data_52);
              sv_52_U=sv_52_U+((Save_Data_52)*(Save_Data_52));
          }
          if(Save_Data_52<0)
          {
              Samples_D_52++;
              SV_52_D=(SV_52_D+Save_Data_52);
              SVD_52_D=(SVD_52_D+Save_Data_52);
              sv_52_D=sv_52_D+((Save_Data_52)*(Save_Data_52));
          }
          float Save_Data_53 = atof (Save_Data[53]);
          SV_53=(SV_53+Save_Data_53);
          SVD_53=(SVD_53+Save_Data_53);
          sv_53=sv_53+((Save_Data_53)*(Save_Data_53));
          if(Save_Data_53>0)
          {
              Samples_U_53++;
              SV_53_U=(SV_53_U+Save_Data_53);
              SVD_53_U=(SVD_53_U+Save_Data_53);
              sv_53_U=sv_53_U+((Save_Data_53)*(Save_Data_53));
          }
          if(Save_Data_53<0)
          {
              Samples_D_53++;
              SV_53_D=(SV_53_D+Save_Data_53);
              SVD_53_D=(SVD_53_D+Save_Data_53);
              sv_53_D=sv_53_D+((Save_Data_53)*(Save_Data_53));
          }
          
          float Save_Data_54 = atof (Save_Data[54]);
          SV_54=(SV_54+Save_Data_54);
          SVD_54=(SVD_54+Save_Data_54);
          sv_54=sv_54+((Save_Data_54)*(Save_Data_54));
          if(Save_Data_54>0)
          {
              Samples_U_54++;
              SV_54_U=(SV_54_U+Save_Data_54);
              SVD_54_U=(SVD_54_U+Save_Data_54);
              sv_54_U=sv_54_U+((Save_Data_54)*(Save_Data_54));
          }
          if(Save_Data_54<0)
          {
              Samples_D_54++;
              SV_54_D=(SV_54_D+Save_Data_54);
              SVD_54_D=(SVD_54_D+Save_Data_54);
              sv_54_D=sv_54_D+((Save_Data_54)*(Save_Data_54));
          }
          
          float Save_Data_55 = atof (Save_Data[55]);
          SV_55=(SV_55+Save_Data_55);
          SVD_55=(SVD_55+Save_Data_55);
          sv_55=sv_55+((Save_Data_55)*(Save_Data_55));
          if(Save_Data_55>0)
          {
              Samples_U_55++;
              SV_55_U=(SV_55_U+Save_Data_55);
              SVD_55_U=(SVD_55_U+Save_Data_55);
              sv_55_U=sv_55_U+((Save_Data_55)*(Save_Data_55));
          }
          if(Save_Data_55<0)
          {
              Samples_D_55++;
              SV_55_D=(SV_55_D+Save_Data_55);
              SVD_55_D=(SVD_55_D+Save_Data_55);
              sv_55_D=sv_55_D+((Save_Data_55)*(Save_Data_55));
          }
          
          float Save_Data_56 = atof (Save_Data[56]);
          SV_56=(SV_56+Save_Data_56);
          SVD_56=(SVD_56+Save_Data_56);
          sv_56=sv_56+((Save_Data_56)*(Save_Data_56));
          if(Save_Data_56>0)
          {
              Samples_U_56++;
              SV_56_U=(SV_56_U+Save_Data_56);
              SVD_56_U=(SVD_56_U+Save_Data_56);
              sv_56_U=sv_56_U+((Save_Data_56)*(Save_Data_56));
          }
          if(Save_Data_56<0)
          {
              Samples_D_56++;
              SV_56_D=(SV_56_D+Save_Data_56);
              SVD_56_D=(SVD_56_D+Save_Data_56);
              sv_56_D=sv_56_D+((Save_Data_56)*(Save_Data_56));
          }
          
          float Save_Data_57 = atof (Save_Data[57]);
          SV_57=(SV_57+Save_Data_57);
          SVD_57=(SVD_57+Save_Data_57);
          sv_57=sv_57+((Save_Data_57)*(Save_Data_57));
          if(Save_Data_57>0)
          {
              Samples_U_57++;
              SV_57_U=(SV_57_U+Save_Data_57);
              SVD_57_U=(SVD_57_U+Save_Data_57);
              sv_57_U=sv_57_U+((Save_Data_57)*(Save_Data_57));
          }
          if(Save_Data_57<0)
          {
              Samples_D_57++;
              SV_57_D=(SV_57_D+Save_Data_57);
              SVD_57_D=(SVD_57_D+Save_Data_57);
              sv_57_D=sv_57_D+((Save_Data_57)*(Save_Data_57));
          }
          
          float Save_Data_58 = atof (Save_Data[58]);
          SV_58=(SV_58+Save_Data_58);
          SVD_58=(SVD_58+Save_Data_58);
          sv_58=sv_58+((Save_Data_58)*(Save_Data_58));
          if(Save_Data_58>0)
          {
              Samples_U_58++;
              SV_58_U=(SV_58_U+Save_Data_58);
              SVD_58_U=(SVD_58_U+Save_Data_58);
              sv_58_U=sv_58_U+((Save_Data_58)*(Save_Data_58));
          }
          if(Save_Data_58<0)
          {
              Samples_D_58++;
              SV_58_D=(SV_58_D+Save_Data_58);
              SVD_58_D=(SVD_58_D+Save_Data_58);
              sv_58_D=sv_58_D+((Save_Data_58)*(Save_Data_58));
          }
          
          float Save_Data_59 = atof (Save_Data[59]);
          SV_59=(SV_59+Save_Data_59);
          SVD_59=(SVD_59+Save_Data_59);
          sv_59=sv_59+((Save_Data_59)*(Save_Data_59));
          if(Save_Data_59>0)
          {
              Samples_U_59++;
              SV_59_U=(SV_59_U+Save_Data_59);
              SVD_59_U=(SVD_59_U+Save_Data_59);
              sv_59_U=sv_59_U+((Save_Data_59)*(Save_Data_59));
          }
          if(Save_Data_59<0)
          {
              Samples_D_59++;
              SV_59_D=(SV_59_D+Save_Data_59);
              SVD_59_D=(SVD_59_D+Save_Data_59);
              sv_59_D=sv_59_D+((Save_Data_59)*(Save_Data_59));
          }
          
          float Save_Data_60 = atof (Save_Data[60]);
          SV_60=(SV_60+Save_Data_60);
          SVD_60=(SVD_60+Save_Data_60);
          sv_60=sv_60+((Save_Data_60)*(Save_Data_60));
          if(Save_Data_60>0)
          {
              Samples_U_60++;
              SV_60_U=(SV_60_U+Save_Data_60);
              SVD_60_U=(SVD_60_U+Save_Data_60);
              sv_60_U=sv_60_U+((Save_Data_60)*(Save_Data_60));
          }
          if(Save_Data_60<0)
          {
              Samples_D_60++;
              SV_60_D=(SV_60_D+Save_Data_60);
              SVD_60_D=(SVD_60_D+Save_Data_60);
              sv_60_D=sv_60_D+((Save_Data_60)*(Save_Data_60));
          }
          
          float Save_Data_61 = atof (Save_Data[61]);
          SV_61=(SV_61+Save_Data_61);
          SVD_61=(SVD_61+Save_Data_61);
          sv_61=sv_61+((Save_Data_61)*(Save_Data_61));
          if(Save_Data_61>0)
          {
              Samples_U_61++;
              SV_61_U=(SV_61_U+Save_Data_61);
              SVD_61_U=(SVD_61_U+Save_Data_61);
              sv_61_U=sv_61_U+((Save_Data_61)*(Save_Data_61));
          }
          if(Save_Data_61<0)
          {
              Samples_D_61++;
              SV_61_D=(SV_61_D+Save_Data_61);
              SVD_61_D=(SVD_61_D+Save_Data_61);
              sv_61_D=sv_61_D+((Save_Data_61)*(Save_Data_61));
          }
          
          float Save_Data_62 = atof (Save_Data[62]);
          SV_62=(SV_62+Save_Data_62);
          SVD_62=(SVD_62+Save_Data_62);
          sv_62=sv_62+((Save_Data_62)*(Save_Data_62));
          if(Save_Data_62>0)
          {
              Samples_U_62++;
              SV_62_U=(SV_62_U+Save_Data_62);
              SVD_62_U=(SVD_62_U+Save_Data_62);
              sv_62_U=sv_62_U+((Save_Data_62)*(Save_Data_62));
          }
          if(Save_Data_62<0)
          {
              Samples_D_62++;
              SV_62_D=(SV_62_D+Save_Data_62);
              SVD_62_D=(SVD_62_D+Save_Data_62);
              sv_62_D=sv_62_D+((Save_Data_62)*(Save_Data_62));
          }
          
          float Save_Data_63 = atof (Save_Data[63]);
          SV_63=(SV_63+Save_Data_63);
          SVD_63=(SVD_63+Save_Data_63);
          sv_63=sv_63+((Save_Data_63)*(Save_Data_63));
          if(Save_Data_63>0)
          {
              Samples_U_63++;
              SV_63_U=(SV_63_U+Save_Data_63);
              SVD_63_U=(SVD_63_U+Save_Data_63);
              sv_63_U=sv_63_U+((Save_Data_63)*(Save_Data_63));
          }
          if(Save_Data_63<0)
          {
              Samples_D_63++;
              SV_63_D=(SV_63_D+Save_Data_63);
              SVD_63_D=(SVD_63_D+Save_Data_63);
              sv_63_D=sv_63_D+((Save_Data_63)*(Save_Data_63));
          }
          
          float Save_Data_64 = atof (Save_Data[64]);
          SV_64=(SV_64+Save_Data_64);
          SVD_64=(SVD_64+Save_Data_64);
          sv_64=sv_64+((Save_Data_64)*(Save_Data_64));
          if(Save_Data_64>0)
          {
              Samples_U_64++;
              SV_64_U=(SV_64_U+Save_Data_64);
              SVD_64_U=(SVD_64_U+Save_Data_64);
              sv_64_U=sv_64_U+((Save_Data_64)*(Save_Data_64));
          }
          if(Save_Data_64<0)
          {
              Samples_D_64++;
              SV_64_D=(SV_64_D+Save_Data_64);
              SVD_64_D=(SVD_64_D+Save_Data_64);
              sv_64_D=sv_64_D+((Save_Data_64)*(Save_Data_64));
          }
    } 
  }
    
    //資料導出 
    fprintf(fd_out,"======================== \n");
    fprintf(fd_out,"All \n");
    fprintf(fd_out_All_AVG,"");
    fprintf(fd_out_All_SD,"");
    fprintf(fd_out,"======================== \n");
    All_AVG_SD();
    fprintf(fd_out,"======================== \n");
    fprintf(fd_out,"Only + \n");
    fprintf(fd_out_Pos_AVG,"");
    fprintf(fd_out_Pos_SD,"");
    fprintf(fd_out,"======================== \n");
    Up_AVG_SD();
    fprintf(fd_out,"======================== \n");
    fprintf(fd_out,"Only - \n");
    fprintf(fd_out_Neg_AVG,"");
    fprintf(fd_out_Neg_SD,"");
    fprintf(fd_out,"======================== \n");
    Down_AVG_SD();
    
    fclose(fd_in);
    fclose(fd_out);
    fclose(fd_out_All_AVG);
    fclose(fd_out_All_SD);
    fclose(fd_out_Pos_AVG);
    fclose(fd_out_Pos_SD);
    fclose(fd_out_Neg_AVG);
    fclose(fd_out_Neg_SD);
     
    system("pause");
    return 0;
}
