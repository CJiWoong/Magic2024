using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using Microsoft.Win32;

using Gssoft.Gscad.Runtime;
using Gssoft.Gscad.ApplicationServices;
using Gssoft.Gscad.EditorInput;
using Gssoft.Gscad.PlottingServices;
using Gssoft.Gscad.Publishing;
using Gssoft.Gscad.Windows;
using Gssoft.Gscad.Colors;
using Gssoft.Gscad.DatabaseServices;
using Gssoft.Gscad.DatabaseServices.Filters;
//using Gssoft.Gscad.Export_Import;
using Gssoft.Gscad.Geometry;
using Gssoft.Gscad.GraphicsInterface;
using Gssoft.Gscad.GraphicsSystem;
using Gssoft.Gscad.LayerManager;

namespace gCAD_Calc
{
    public partial class DispCalc : Form
    {
        DispCalc test;
        string magicDir;

        public DispCalc()
        {
            InitializeComponent();

            Gssoft.Gscad.Runtime.RegistryKey registryKey = Gssoft.Gscad.Runtime.Registry.CurrentUser.OpenSubKey("Software\\Magic");
            magicDir = (string)registryKey.GetValue("PATH") + "\\Data\\";
        }

        public void ShowWindow()
        {
            test = new DispCalc();
            test.Show();
        }

        private void radRot0_CheckedChanged(object sender, EventArgs e)
        {
            txtRot.Text = "0";
        }

        private void radRot90_CheckedChanged(object sender, EventArgs e)
        {
            txtRot.Text = "90";
        }

        private void radRot180_CheckedChanged(object sender, EventArgs e)
        {
            txtRot.Text = "180";
        }

        private void radRot270_CheckedChanged(object sender, EventArgs e)
        {
            txtRot.Text = "270";
        }

        private void cmdExtend_Click(object sender, EventArgs e)
        {

            //this.Size = new Size(741, 492);
            if (this.Size.Width > 400)
            {
                this.Size = new Size(320, 592); //366*705 원본, 320*592 수정(201214)
                //this.cmdExtend.Image = ((System.Drawing.Image)(Properties.Resources.확장));
                this.cmdExtend.Text = "옵션확장";
            }
            else
            {
                this.Size = new Size(613, 592); //696*705 원본, 613*592 수정(201214)
                //this.cmdExtend.Image = ((System.Drawing.Image)(Properties.Resources.축소));
                this.cmdExtend.Text = "옵션축소";
            }

        }

        private void DispCalc_Load(object sender, EventArgs e)
        {
            this.TopMost = true;
            this.Size = new Size(320, 592); //366*705 원본, 320*592 수정(201214)
            //this.cmdExtend.Image = ((System.Drawing.Image)(Properties.Resources.확장));
            this.cmdExtend.Text = "옵션확장";

            //-------------------------Layer
            comLayer.Items.Clear();
            string[] lines1 = System.IO.File.ReadAllLines(magicDir + "Layer.out", Encoding.Default);
            foreach (string line in lines1)
            {
                comLayer.Items.Add(line);
            }
            comLayer.SelectedIndex = 0;

            //-------------------------Style
            comStyle.Items.Clear();
            string[] lines2 = System.IO.File.ReadAllLines(magicDir + "Style.out", Encoding.Default);
            foreach (string line in lines2)
            {
                comStyle.Items.Add(line);
            }
            comStyle.SelectedIndex = 0;


            //-------------------------SCALE
            comScale.Items.Clear();
            comScale.Items.Add("1");
            comScale.Items.Add("10");
            comScale.Items.Add("100");
            comScale.Items.Add("1000");
            comScale.SelectedIndex = 0;

            //-------------------------Text Align
            comAlign.Items.Clear();
            comAlign.Items.Add("좌측상단");
            comAlign.Items.Add("좌측중심");
            comAlign.Items.Add("좌측하단");
            comAlign.Items.Add("중앙상단");
            comAlign.Items.Add("중앙중심");
            comAlign.Items.Add("중앙하단");
            comAlign.Items.Add("우측상단");
            comAlign.Items.Add("우측중심");
            comAlign.Items.Add("우측하단");
            comAlign.SelectedIndex = 0;

            //------------------------Color
            comColor.Items.Clear();
            comColor.Items.Add("Bylayer");
            comColor.Items.Add("White");
            comColor.Items.Add("Red");
            comColor.Items.Add("Yellow");
            comColor.Items.Add("Green");
            comColor.Items.Add("Cyan");
            comColor.Items.Add("Blue");
            comColor.Items.Add("Magenta");
            comColor.SelectedIndex = 0;

            //------------------------Unit
            comUnit.Items.Clear();
            comUnit.Items.Add("㎡");
            comUnit.Items.Add("㎢");
            comUnit.Items.Add("PY");
            comUnit.Items.Add("㎡(PY)");
            comUnit.SelectedIndex = 0;

            //------------------------INPUT            
            //SaveDisplay();
            string Filestr = magicDir + "Last.out";
            System.IO.FileInfo fi = new System.IO.FileInfo(Filestr);
            if (fi.Exists)
            {
                int kk = 1;
                string[] inputData = System.IO.File.ReadAllLines(magicDir + "Last.out", Encoding.Default);
                foreach (string tmp in inputData)
                {
                    if (kk == 1)
                    {
                        if (tmp == "1") { rad1.Checked = true; }
                        if (tmp == "2") { rad2.Checked = true; }
                        if (tmp == "3") { rad3.Checked = true; }
                        if (tmp == "4") { rad4.Checked = true; }
                        if (tmp == "5") { rad5.Checked = true; }
                        if (tmp == "6") { rad6.Checked = true; }
                        if (tmp == "7") { rad7.Checked = true; }
                        if (tmp == "8") { rad8.Checked = true; }
                    }

                    if (kk == 2)
                    {
                        if (tmp == "+") { radCal1.Checked = true; }
                        if (tmp == "-") { radCal2.Checked = true; }
                        if (tmp == "*") { radCal3.Checked = true; }
                        if (tmp == "/") { radCal4.Checked = true; }
                    }

                    if (kk == 3) { txtHeig.Text = tmp; }
                    if (kk == 4) { txtPrec.Value = Convert.ToInt32(tmp); }
                    if (kk == 5)
                    {
                        if (tmp == "C") { chk1000.Checked = true; }
                        if (tmp == "N") { chk1000.Checked = false; }
                    }

                    if (kk == 6) { comAlign.SelectedIndex = Convert.ToInt32(tmp); }
                    if (kk == 7)
                    {
                        if (tmp == "1") { radRot0.Checked = true; }
                        if (tmp == "2") { radRot90.Checked = true; }
                        if (tmp == "3") { radRot180.Checked = true; }
                        if (tmp == "4") { radRot270.Checked = true; }
                        if (tmp == "5") { radRot.Checked = true; }
                    }
                    if (kk == 8) { txtRot.Text = tmp; }


                    //if (kk == 9) { comColor.SelectedIndex = Convert.ToInt32(tmp); }

                    if (kk == 10)
                    {
                        if (tmp == "C") { chkColor.Checked = true; }
                        if (tmp == "N") { chkColor.Checked = false; }
                    }
                    if (kk == 11) { txtAddText1.Text = tmp; }
                    if (kk == 12) { txtAddText2.Text = tmp; }

                    if (kk == 13) { comUnit.SelectedIndex = Convert.ToInt32(tmp); }

                    if (kk == 14)
                    {
                        if (tmp == "HAT_USE") { chkUseHatch.Checked = true; }
                        if (tmp == "HAT_NOT") { chkUseHatch.Checked = false; }
                    }

                    if (kk == 15)
                    {
                        if (tmp == "HAT_DEL") { chkDelHatch.Checked = true; }
                        if (tmp == "HAT_NOTDEL") { chkDelHatch.Checked = false; }
                    }
                    if (kk == 16) { txtHatchPattern.Text = tmp; }
                    if (kk == 17) { txtHatchSize.Text = tmp; }
                    if (kk == 18) { txtJARI.Text = tmp; }
                    if (kk == 21) { comScale.Text = tmp; }

                    kk = kk + 1;
                }
            }

            string Filestr1 = magicDir + "Style.out";
            System.IO.FileInfo fi1 = new System.IO.FileInfo(Filestr1);
            if (fi1.Exists)
            {
                System.IO.File.Delete(magicDir + "Style.out");
            }

            string Filestr2 = magicDir + "Layer.out";
            System.IO.FileInfo fi2 = new System.IO.FileInfo(Filestr2);
            if (fi2.Exists)
            {
                System.IO.File.Delete(magicDir + "Layer.out");
            }
        }

        public void SaveDisplay()
        {
            //-----거리옵션
            string out1 = "";
            if (rad1.Checked == true) { out1 = "1"; }
            if (rad2.Checked == true) { out1 = "2"; }
            if (rad3.Checked == true) { out1 = "3"; }
            if (rad4.Checked == true) { out1 = "4"; }
            if (rad5.Checked == true) { out1 = "5"; }
            if (rad6.Checked == true) { out1 = "6"; }
            if (rad7.Checked == true) { out1 = "7"; }
            if (rad8.Checked == true) { out1 = "8"; }
            //-----사칙연산
            string out2 = "";
            if (radCal1.Checked == true) { out2 = "+"; }
            if (radCal2.Checked == true) { out2 = "-"; }
            if (radCal3.Checked == true) { out2 = "*"; }
            if (radCal4.Checked == true) { out2 = "/"; }
            //-----문자높이
            string out3 = txtHeig.Text;
            //-----디스플레이정밀도
            string out4 = txtPrec.Value.ToString();
            //-----1,000단위구분자
            string out5 = "";
            if (chk1000.Checked == true)
            {
                out5 = "C";
            }
            else
            {
                out5 = "N";
            }
            //-----문자정렬
            //string out6 = "";
            string out6 = comAlign.SelectedIndex.ToString();

            //-----문자각도
            string out7 = "";
            if (radRot0.Checked == true) { out7 = "1"; }
            if (radRot90.Checked == true) { out7 = "2"; }
            if (radRot180.Checked == true) { out7 = "3"; }
            if (radRot270.Checked == true) { out7 = "4"; }
            if (radRot.Checked == true) { out7 = "5"; }

            string out8 = txtRot.Text;

            //-----Color
            //string out9 = comColor.SelectedIndex.ToString();
            string out9 = comColor.Text;

            //-----색상변경
            string out10 = "";
            if (chkColor.Checked == true)
            {
                out10 = "C";
            }
            else
            {
                out10 = "N";
            }

            //-----머리말
            string out11 = txtAddText1.Text;
            //-----꼬리말
            string out12 = txtAddText2.Text;

            //-----단위
            string out13 = comUnit.SelectedIndex.ToString();

            //-----Hatch_Use
            string out14 = "";
            if (chkUseHatch.Checked == true)
            {
                out14 = "HAT_USE";
            }
            else
            {
                out14 = "HAT_NOT";
            }

            //-----Hatch_Del
            string out15 = "";
            if (chkDelHatch.Checked == true)
            {
                out15 = "HAT_DEL";
            }
            else
            {
                out15 = "HAT_NOTDEL";
            }
            //-----HATCH PATTERN
            string out16 = txtHatchPattern.Text;

            //-----HATCH SIZE
            string out17 = txtHatchSize.Text;

            //-----문자기입정밀도
            string out18 = txtJARI.Value.ToString();

            //-----문자유형(STYLE)
            string out19 = comStyle.Text;

            //-----문자LAYER
            string out20 = comLayer.Text;

            //-----Scale
            string out21 = comScale.Text;


            string[] lines = { out1, out2, out3, out4, out5, out6, out7, out8, out9, out10, out11, out12, out13, out14, out15, out16, out17, out18, out19, out20, out21 };
            System.IO.File.WriteAllLines(magicDir + "Last.out", lines, Encoding.Default);
        }

        private void cmdExit_Click(object sender, EventArgs e)
        {

            SaveDisplay();

            this.Close();
        }

        private void cmdSel_Click(object sender, EventArgs e)
        {
            //------------------------OUTPUT            
            SaveDisplay();

            Document doc = Gssoft.Gscad.ApplicationServices.Application.DocumentManager.MdiActiveDocument;
            Editor ed = doc.Editor;

            Gssoft.Gscad.ApplicationServices.Application.SetSystemVariable("USERS1", txtDisp.Text);

            if (rad1.Checked == true) { doc.SendStringToExecute("cleng5 ", true, false, false); }  //문자
            if (rad2.Checked == true) { doc.SendStringToExecute("cleng6 ", true, false, false); }  //치수
            if (rad3.Checked == true) { doc.SendStringToExecute("cleng1 ", true, false, false); }  //객체길이
            if (rad4.Checked == true) { doc.SendStringToExecute("cleng2 ", true, false, false); }  //거리
            if (rad5.Checked == true) { doc.SendStringToExecute("carea1 ", true, false, false); }  //면적(점)
            if (rad6.Checked == true) { doc.SendStringToExecute("carea2 ", true, false, false); }  //면적(선택)
            if (rad7.Checked == true) { doc.SendStringToExecute("cleng3 ", true, false, false); }  //수평거리
            if (rad8.Checked == true) { doc.SendStringToExecute("cleng4 ", true, false, false); }  //수직거리
        }

        private void cmdCopy_Click(object sender, EventArgs e)
        {
            txtDisp.SelectAll();
            txtDisp.Copy();
        }

        private void cmdAC_Click(object sender, EventArgs e)
        {
            txtDisp.Text = "";
            txtResult.Text = "";
            Gssoft.Gscad.ApplicationServices.Application.SetSystemVariable("USERS1", "");
            Gssoft.Gscad.ApplicationServices.Application.SetSystemVariable("USERS2", "");
            Gssoft.Gscad.ApplicationServices.Application.SetSystemVariable("USERS3", "");
        }

        public void CancelCommand()
        {
            //-----
            //string tmpValue = GrxCAD.ApplicationServices.Application.GetSystemVariable("USERS4").ToString();
            //if (tmpValue == "S")
            //{
            //    MessageBox.Show("캐드에서 명령을 종료하세요...!");
            //    Document doc = GrxCAD.ApplicationServices.Application.DocumentManager.MdiActiveDocument;
            //    doc.SendStringToExecute("CmdCancel ", true, false, false);
            //    return;
            //}
            return;
        }


        private void rad1_CheckedChanged(object sender, EventArgs e)
        {
            CancelCommand();
            if (rad1.Checked == true) { cmdSel.Text = "문자선택"; }
        }

        private void rad2_CheckedChanged(object sender, EventArgs e)
        {
            CancelCommand();

            if (rad2.Checked == true) { cmdSel.Text = "치수선택"; }
        }

        private void rad3_CheckedChanged(object sender, EventArgs e)
        {
            CancelCommand();
            if (rad3.Checked == true) { cmdSel.Text = "객체선택"; }
        }

        private void rad4_CheckedChanged(object sender, EventArgs e)
        {
            CancelCommand();
            if (rad4.Checked == true) { cmdSel.Text = "거리지정"; }
        }

        private void rad5_CheckedChanged(object sender, EventArgs e)
        {
            CancelCommand();
            if (rad5.Checked == true) { cmdSel.Text = "면적(점 지정)"; }
        }

        private void rad6_CheckedChanged(object sender, EventArgs e)
        {
            CancelCommand();
            if (rad6.Checked == true) { cmdSel.Text = "면적(객체 선택)"; }
        }

        private void rad7_CheckedChanged(object sender, EventArgs e)
        {
            CancelCommand();
            if (rad7.Checked == true) { cmdSel.Text = "점지정(수평거리)"; }
        }

        private void rad8_CheckedChanged(object sender, EventArgs e)
        {
            CancelCommand();
            if (rad8.Checked == true) { cmdSel.Text = "점지정(수직거리)"; }
        }

        private void cmdCalc_Click(object sender, EventArgs e)
        {

            ////////-----계산식
            ///////string tmpValue = GrxCAD.ApplicationServices.Application.GetSystemVariable("USERS4").ToString();
            //////if (tmpValue == "S")
            /////{                
            /////    MessageBox.Show("캐드에서 명령을 종료하세요...!!!");
            /////    return;
            /////}



            ////////-----계산식
            //////string tmpValue1 = GrxCAD.ApplicationServices.Application.GetSystemVariable("USERS2").ToString();
            //////txtDisp.Text = tmpValue1;
            ////////GrxCAD.ApplicationServices.Application.SetSystemVariable("USERS2", "");

            ////////-----계산결과
            //////string tmpValue2 = GrxCAD.ApplicationServices.Application.GetSystemVariable("USERS3").ToString();
            //////txtResult.Text = tmpValue2;
            ////////GrxCAD.ApplicationServices.Application.SetSystemVariable("USERS3", "");
        }




        private void cmdText_Click(object sender, EventArgs e)
        {
            Document doc = Gssoft.Gscad.ApplicationServices.Application.DocumentManager.MdiActiveDocument;

            SaveDisplay();
            Gssoft.Gscad.ApplicationServices.Application.SetSystemVariable("USERS1", txtResult.Text);
            doc.SendStringToExecute("NewText ", true, false, false);

        }

        private void txtMod_Click(object sender, EventArgs e)
        {
            Document doc = Gssoft.Gscad.ApplicationServices.Application.DocumentManager.MdiActiveDocument;
            SaveDisplay();
            Gssoft.Gscad.ApplicationServices.Application.SetSystemVariable("USERS1", txtResult.Text);
            doc.SendStringToExecute("ModText ", true, false, false);
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void chk1000_CheckedChanged(object sender, EventArgs e)
        {
            //int aaa = 123456789;
            //string money = String.Format("{0:#,###}", aaa);
            //writer.WriteLine(money);

        }


        public void Show_result_cal()
        {
            //-----계산식
            string tmpValue1 = Gssoft.Gscad.ApplicationServices.Application.GetSystemVariable("USERS2").ToString();
            txtDisp.Text = tmpValue1;
            //GrxCAD.ApplicationServices.Application.SetSystemVariable("USERS2", "");

            //-----계산결과
            string tmpValue2 = Gssoft.Gscad.ApplicationServices.Application.GetSystemVariable("USERS3").ToString();
            txtResult.Text = tmpValue2;
            //GrxCAD.ApplicationServices.Application.SetSystemVariable("USERS3", "");
        }





    }
}
