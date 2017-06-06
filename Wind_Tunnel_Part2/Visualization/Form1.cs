using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Windows;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        

        int iconSize = 630; //定義畫布長、寬
        //定義所需顏色
        int[,] colorrgb = new int[16, 3] {{0,0,128},{0,0,205},{0,0,255},{30,144,255},
                                            {0,255,255},{200,255,255},{177,255,212},{0,250,154},
                                            {50,205,50},{0,150,0},{0,100,0},{173,255,47},
                                            {255,255,0},{255,165,0},{255,69,0},{255,0,0}};
        public Form1()
        {
            InitializeComponent();                 
        }
        private void button1_Click(object sender, EventArgs e)
        {
            this.label4.Text = "準備中";//將程式執行前狀態定義為準備
            if (openFileDialog1.ShowDialog() == System.Windows.Forms.DialogResult.OK)//判別路徑存在與否
            {
                //讀取所選目錄下之檔案
                string[,] pixNum = new string[iconSize, iconSize];                
                FileInfo f = new FileInfo(openFileDialog1.FileName);
                StreamReader sr = f.OpenText();
                
                this.textBox1.Text = openFileDialog1.FileName.ToString();
               
                //切割字串
                char[] delimiterChars = { '\t', '\n' };
                string text = sr.ReadToEnd();
                string[] words = text.Split(delimiterChars);                

                sr.Close();

                int aliquots = iconSize / 9;//切割區間
                int xAxis, yAxis;
                int Index = 0;

                //將已知資料填入對應陣列位置
                for (yAxis = 0; yAxis < iconSize - 1; yAxis++)
                {
                    if ((yAxis + 1) % aliquots == 0)
                    {
                        for (xAxis = 0; xAxis < iconSize - 1; xAxis++)
                        {
                            if ((xAxis + 1) % aliquots == 0)
                            {
                                pixNum[xAxis, yAxis] = words[Index];
                                Index++;
                            }
                        }
                    }
                }

                //法計算已知點間直線上的所有數據
                int y1, y2;
                float mathematical;
                for (xAxis = 0; xAxis < iconSize - 1; xAxis++)
                {
                    if ((xAxis + 1) % aliquots == 0)
                    {
                        for (yAxis = 0; yAxis < iconSize; yAxis++)
                        {
                            if (pixNum[xAxis, yAxis] == null)
                            {
                                if (yAxis / aliquots > 0 && yAxis / aliquots < 8)
                                {
                                    //以內差法計算已知兩點間直線上的所有數據
                                    y1 = (yAxis / aliquots) * aliquots - 1;
                                    y2 = (yAxis / aliquots + 1) * aliquots - 1;
                                    mathematical = (Convert.ToSingle(pixNum[xAxis, y1]) * (y2 - yAxis) + Convert.ToSingle(pixNum[xAxis, y2]) * (yAxis - y1)) / aliquots;
                                }
                                else if (yAxis / aliquots <= 0)
                                {
                                    //以斜率計算上方已知點外直線上的所有數據
                                    y1 = (yAxis / aliquots + 1) * aliquots - 1;
                                    y2 = (yAxis / aliquots + 2) * aliquots - 1;
                                    mathematical = Convert.ToSingle(pixNum[xAxis, y1]) + (Convert.ToSingle(pixNum[xAxis, y1]) - Convert.ToSingle(pixNum[xAxis, y2])) * (y1 - yAxis) / aliquots;
                                }
                                else
                                {
                                    //以斜率計算下方已知點外直線上的所有數據
                                    y1 = (yAxis / aliquots) * aliquots - 1;
                                    y2 = (yAxis / aliquots - 1) * aliquots - 1;
                                    mathematical = Convert.ToSingle(pixNum[xAxis, y1]) + (Convert.ToSingle(pixNum[xAxis, y1]) - Convert.ToSingle(pixNum[xAxis, y2])) * (yAxis - y1) / aliquots;                                    
                                }
                                pixNum[xAxis, yAxis] = mathematical.ToString();
                            }                           
                        }
                    }
                }

                //計算已橫線上的所有數據
                int x1, x2;
                for (yAxis = 0; yAxis < iconSize; yAxis++)
                {
                    for (xAxis = 0; xAxis < iconSize; xAxis++)
                    {
                        if (pixNum[xAxis, yAxis] == null)
                        {
                            if (xAxis / aliquots > 0 && xAxis / aliquots < 8)
                            {
                                //以內差法計算已知兩點間橫線上的所有數據
                                x1 = (xAxis / aliquots) * aliquots - 1;
                                x2 = (xAxis / aliquots + 1) * aliquots - 1;
                                mathematical = (Convert.ToSingle(pixNum[x1, yAxis]) * (x2 - xAxis) + Convert.ToSingle(pixNum[x2, yAxis]) * (xAxis - x1)) / aliquots;
                            }
                            else if (xAxis / aliquots <= 0)
                            {
                                //以斜率計算左方已知點外橫線上的所有數據
                                x1 = (xAxis / aliquots + 1) * aliquots - 1;
                                x2 = (xAxis / aliquots + 2) * aliquots - 1;
                                mathematical = Convert.ToSingle(pixNum[x1, yAxis]) + (Convert.ToSingle(pixNum[x1, yAxis]) - Convert.ToSingle(pixNum[x2, yAxis])) * (x1 - xAxis) / aliquots;
                            }
                            else
                            {
                                //以斜率計算右方已知點外橫線上的所有數據
                                x1 = (xAxis / aliquots) * aliquots - 1;
                                x2 = (xAxis / aliquots - 1) * aliquots - 1;
                                mathematical = Convert.ToSingle(pixNum[x1, yAxis]) + (Convert.ToSingle(pixNum[x1, yAxis]) - Convert.ToSingle(pixNum[x2, yAxis])) * (xAxis - x1) / aliquots;
                            }
                            pixNum[xAxis, yAxis] = mathematical.ToString();
                        }
                    }
                }

                float maxNum, minNum;
                maxNum = Convert.ToSingle(pixNum[0, 0]);
                minNum = Convert.ToSingle(pixNum[0, 0]);
                   
                //取得該筆資料的最大值與最小值
                for (xAxis = 0; xAxis < iconSize; xAxis++)
                {
                    for (yAxis = 0; yAxis < iconSize; yAxis++)
                    {
                        if (Convert.ToSingle(pixNum[xAxis, yAxis]) < minNum)
                        {
                            minNum = Convert.ToSingle(pixNum[xAxis, yAxis]);
                        }
                        if (Convert.ToSingle(pixNum[xAxis, yAxis]) > maxNum)
                        {
                            maxNum = Convert.ToSingle(pixNum[xAxis, yAxis]);
                        }
                    }
                }

                label1.Text = maxNum.ToString();
                label2.Text = minNum.ToString();

                //定義畫布大小
                Bitmap bmp = new Bitmap(iconSize, iconSize);

                //將Graphics g畫布 畫在bmp上
                Graphics g = Graphics.FromImage(bmp);

                Brush bb;
                
                //繪圖
                if (maxNum == minNum)
                {
                    this.label4.Text = "無法繪製圖片";
                }
                else
                {                           
                    for (xAxis = 0; xAxis < iconSize; xAxis++)
                    {
                        for (yAxis = 0; yAxis < iconSize; yAxis++)
                        {

                            int colorNum = Convert.ToInt16((Convert.ToSingle(pixNum[xAxis, yAxis]) - minNum) / (maxNum - minNum) * 15);                                
                            bb = new SolidBrush(Color.FromArgb(colorrgb[colorNum , 0], colorrgb[colorNum, 1], colorrgb[colorNum , 2]));
                            g.FillRectangle(bb, xAxis, yAxis, xAxis, yAxis);
                        }
                    }
                    pictureBox1.Image = bmp;
                    this.label4.Text = "完成";
                }            
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //定義畫布大小
            Bitmap bmp2 = new Bitmap(30, 512);

            //將Graphics g畫布 畫在bmp上
            Graphics g2 = Graphics.FromImage(bmp2);



            //繪圖
            for (int i = 0; i < 16; i++)
            {
                Brush bb;
                bb = new SolidBrush(Color.FromArgb(colorrgb[i, 0], colorrgb[i, 1], colorrgb[i, 2]));
                g2.FillRectangle(bb, 0, (15 - i) * 16, 30, ((15 - i) * 16) + 16);
            }
            pictureBox2.Image = bmp2;
        }
    }
}
