namespace gCAD_Calc
{
    partial class DispCalc
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다.
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DispCalc));
            this.rad1 = new System.Windows.Forms.RadioButton();
            this.cmdSel = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.rad4 = new System.Windows.Forms.RadioButton();
            this.rad8 = new System.Windows.Forms.RadioButton();
            this.rad7 = new System.Windows.Forms.RadioButton();
            this.rad6 = new System.Windows.Forms.RadioButton();
            this.rad5 = new System.Windows.Forms.RadioButton();
            this.rad3 = new System.Windows.Forms.RadioButton();
            this.rad2 = new System.Windows.Forms.RadioButton();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.radCal4 = new System.Windows.Forms.RadioButton();
            this.radCal3 = new System.Windows.Forms.RadioButton();
            this.radCal2 = new System.Windows.Forms.RadioButton();
            this.radCal1 = new System.Windows.Forms.RadioButton();
            this.cmdAC = new System.Windows.Forms.Button();
            this.cmdCalc = new System.Windows.Forms.Button();
            this.txtDisp = new System.Windows.Forms.RichTextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.txtJARI = new System.Windows.Forms.NumericUpDown();
            this.label12 = new System.Windows.Forms.Label();
            this.cmdExtend = new System.Windows.Forms.Button();
            this.txtHeig = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.txtPrec = new System.Windows.Forms.NumericUpDown();
            this.label2 = new System.Windows.Forms.Label();
            this.cmdExit = new System.Windows.Forms.Button();
            this.txtMod = new System.Windows.Forms.Button();
            this.cmdText = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.txtAddText2 = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.txtAddText1 = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.chkColor = new System.Windows.Forms.CheckBox();
            this.comColor = new System.Windows.Forms.ComboBox();
            this.label7 = new System.Windows.Forms.Label();
            this.comLayer = new System.Windows.Forms.ComboBox();
            this.label6 = new System.Windows.Forms.Label();
            this.comAlign = new System.Windows.Forms.ComboBox();
            this.comStyle = new System.Windows.Forms.ComboBox();
            this.txtRot = new System.Windows.Forms.TextBox();
            this.radRot = new System.Windows.Forms.RadioButton();
            this.radRot270 = new System.Windows.Forms.RadioButton();
            this.radRot180 = new System.Windows.Forms.RadioButton();
            this.radRot90 = new System.Windows.Forms.RadioButton();
            this.radRot0 = new System.Windows.Forms.RadioButton();
            this.label5 = new System.Windows.Forms.Label();
            this.chk1000 = new System.Windows.Forms.CheckBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.txtHatchSize = new System.Windows.Forms.TextBox();
            this.txtHatchPattern = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.chkDelHatch = new System.Windows.Forms.CheckBox();
            this.chkUseHatch = new System.Windows.Forms.CheckBox();
            this.comUnit = new System.Windows.Forms.ComboBox();
            this.label14 = new System.Windows.Forms.Label();
            this.label16 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.txtResult = new System.Windows.Forms.TextBox();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.groupBox7 = new System.Windows.Forms.GroupBox();
            this.comScale = new System.Windows.Forms.ComboBox();
            this.cmdCopy = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtJARI)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtPrec)).BeginInit();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.groupBox7.SuspendLayout();
            this.SuspendLayout();
            // 
            // rad1
            // 
            this.rad1.AutoSize = true;
            this.rad1.Checked = true;
            this.rad1.Location = new System.Drawing.Point(7, 20);
            this.rad1.Name = "rad1";
            this.rad1.Size = new System.Drawing.Size(58, 19);
            this.rad1.TabIndex = 0;
            this.rad1.TabStop = true;
            this.rad1.Text = "문자";
            this.rad1.UseVisualStyleBackColor = true;
            this.rad1.CheckedChanged += new System.EventHandler(this.rad1_CheckedChanged);
            // 
            // cmdSel
            // 
            this.cmdSel.Location = new System.Drawing.Point(107, 160);
            this.cmdSel.Name = "cmdSel";
            this.cmdSel.Size = new System.Drawing.Size(88, 29);
            this.cmdSel.TabIndex = 4;
            this.cmdSel.Text = "선택";
            this.cmdSel.UseVisualStyleBackColor = true;
            this.cmdSel.Click += new System.EventHandler(this.cmdSel_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.rad4);
            this.groupBox1.Controls.Add(this.rad8);
            this.groupBox1.Controls.Add(this.rad7);
            this.groupBox1.Controls.Add(this.rad6);
            this.groupBox1.Controls.Add(this.rad5);
            this.groupBox1.Controls.Add(this.rad3);
            this.groupBox1.Controls.Add(this.rad2);
            this.groupBox1.Controls.Add(this.rad1);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(279, 89);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // rad4
            // 
            this.rad4.AutoSize = true;
            this.rad4.Location = new System.Drawing.Point(218, 20);
            this.rad4.Name = "rad4";
            this.rad4.Size = new System.Drawing.Size(58, 19);
            this.rad4.TabIndex = 3;
            this.rad4.Text = "거리";
            this.rad4.UseVisualStyleBackColor = true;
            this.rad4.CheckedChanged += new System.EventHandler(this.rad4_CheckedChanged);
            // 
            // rad8
            // 
            this.rad8.AutoSize = true;
            this.rad8.Location = new System.Drawing.Point(129, 64);
            this.rad8.Name = "rad8";
            this.rad8.Size = new System.Drawing.Size(88, 19);
            this.rad8.TabIndex = 7;
            this.rad8.Text = "수직거리";
            this.rad8.UseVisualStyleBackColor = true;
            this.rad8.CheckedChanged += new System.EventHandler(this.rad8_CheckedChanged);
            // 
            // rad7
            // 
            this.rad7.AutoSize = true;
            this.rad7.Location = new System.Drawing.Point(6, 64);
            this.rad7.Name = "rad7";
            this.rad7.Size = new System.Drawing.Size(88, 19);
            this.rad7.TabIndex = 6;
            this.rad7.Text = "수평거리";
            this.rad7.UseVisualStyleBackColor = true;
            this.rad7.CheckedChanged += new System.EventHandler(this.rad7_CheckedChanged);
            // 
            // rad6
            // 
            this.rad6.AutoSize = true;
            this.rad6.Location = new System.Drawing.Point(129, 42);
            this.rad6.Name = "rad6";
            this.rad6.Size = new System.Drawing.Size(135, 19);
            this.rad6.TabIndex = 5;
            this.rad6.Text = "면적(객체 선택)";
            this.rad6.UseVisualStyleBackColor = true;
            this.rad6.CheckedChanged += new System.EventHandler(this.rad6_CheckedChanged);
            // 
            // rad5
            // 
            this.rad5.AutoSize = true;
            this.rad5.Location = new System.Drawing.Point(6, 42);
            this.rad5.Name = "rad5";
            this.rad5.Size = new System.Drawing.Size(120, 19);
            this.rad5.TabIndex = 4;
            this.rad5.Text = "면적(점 선택)";
            this.rad5.UseVisualStyleBackColor = true;
            this.rad5.CheckedChanged += new System.EventHandler(this.rad5_CheckedChanged);
            // 
            // rad3
            // 
            this.rad3.AutoSize = true;
            this.rad3.Location = new System.Drawing.Point(129, 20);
            this.rad3.Name = "rad3";
            this.rad3.Size = new System.Drawing.Size(88, 19);
            this.rad3.TabIndex = 2;
            this.rad3.Text = "객체길이";
            this.rad3.UseVisualStyleBackColor = true;
            this.rad3.CheckedChanged += new System.EventHandler(this.rad3_CheckedChanged);
            // 
            // rad2
            // 
            this.rad2.AutoSize = true;
            this.rad2.Location = new System.Drawing.Point(66, 20);
            this.rad2.Name = "rad2";
            this.rad2.Size = new System.Drawing.Size(58, 19);
            this.rad2.TabIndex = 1;
            this.rad2.Text = "치수";
            this.rad2.UseVisualStyleBackColor = true;
            this.rad2.CheckedChanged += new System.EventHandler(this.rad2_CheckedChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.radCal4);
            this.groupBox2.Controls.Add(this.radCal3);
            this.groupBox2.Controls.Add(this.radCal2);
            this.groupBox2.Controls.Add(this.radCal1);
            this.groupBox2.Location = new System.Drawing.Point(12, 107);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(200, 47);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "계산방식";
            // 
            // radCal4
            // 
            this.radCal4.AutoSize = true;
            this.radCal4.Location = new System.Drawing.Point(147, 20);
            this.radCal4.Name = "radCal4";
            this.radCal4.Size = new System.Drawing.Size(34, 19);
            this.radCal4.TabIndex = 3;
            this.radCal4.Text = "/";
            this.radCal4.UseVisualStyleBackColor = true;
            // 
            // radCal3
            // 
            this.radCal3.AutoSize = true;
            this.radCal3.Location = new System.Drawing.Point(94, 20);
            this.radCal3.Name = "radCal3";
            this.radCal3.Size = new System.Drawing.Size(35, 19);
            this.radCal3.TabIndex = 2;
            this.radCal3.Text = "*";
            this.radCal3.UseVisualStyleBackColor = true;
            // 
            // radCal2
            // 
            this.radCal2.AutoSize = true;
            this.radCal2.Location = new System.Drawing.Point(50, 20);
            this.radCal2.Name = "radCal2";
            this.radCal2.Size = new System.Drawing.Size(36, 19);
            this.radCal2.TabIndex = 1;
            this.radCal2.Text = "-";
            this.radCal2.UseVisualStyleBackColor = true;
            // 
            // radCal1
            // 
            this.radCal1.AutoSize = true;
            this.radCal1.Checked = true;
            this.radCal1.Location = new System.Drawing.Point(6, 20);
            this.radCal1.Name = "radCal1";
            this.radCal1.Size = new System.Drawing.Size(36, 19);
            this.radCal1.TabIndex = 0;
            this.radCal1.TabStop = true;
            this.radCal1.Text = "+";
            this.radCal1.UseVisualStyleBackColor = true;
            // 
            // cmdAC
            // 
            this.cmdAC.Location = new System.Drawing.Point(12, 160);
            this.cmdAC.Name = "cmdAC";
            this.cmdAC.Size = new System.Drawing.Size(88, 29);
            this.cmdAC.TabIndex = 3;
            this.cmdAC.Text = "AC";
            this.cmdAC.UseVisualStyleBackColor = true;
            this.cmdAC.Click += new System.EventHandler(this.cmdAC_Click);
            // 
            // cmdCalc
            // 
            this.cmdCalc.Enabled = false;
            this.cmdCalc.Location = new System.Drawing.Point(313, 480);
            this.cmdCalc.Name = "cmdCalc";
            this.cmdCalc.Size = new System.Drawing.Size(60, 29);
            this.cmdCalc.TabIndex = 13;
            this.cmdCalc.Text = "계산";
            this.cmdCalc.UseVisualStyleBackColor = true;
            this.cmdCalc.Visible = false;
            this.cmdCalc.Click += new System.EventHandler(this.cmdCalc_Click);
            // 
            // txtDisp
            // 
            this.txtDisp.Location = new System.Drawing.Point(11, 195);
            this.txtDisp.Name = "txtDisp";
            this.txtDisp.Size = new System.Drawing.Size(279, 114);
            this.txtDisp.TabIndex = 5;
            this.txtDisp.Text = "";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.txtJARI);
            this.groupBox3.Controls.Add(this.label12);
            this.groupBox3.Controls.Add(this.cmdExtend);
            this.groupBox3.Controls.Add(this.txtHeig);
            this.groupBox3.Controls.Add(this.label1);
            this.groupBox3.Location = new System.Drawing.Point(12, 394);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(279, 80);
            this.groupBox3.TabIndex = 7;
            this.groupBox3.TabStop = false;
            // 
            // txtJARI
            // 
            this.txtJARI.Location = new System.Drawing.Point(83, 49);
            this.txtJARI.Name = "txtJARI";
            this.txtJARI.Size = new System.Drawing.Size(80, 25);
            this.txtJARI.TabIndex = 3;
            this.txtJARI.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(6, 50);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(82, 15);
            this.label12.TabIndex = 2;
            this.label12.Text = "문자소수점";
            // 
            // cmdExtend
            // 
            this.cmdExtend.BackColor = System.Drawing.SystemColors.Control;
            this.cmdExtend.ForeColor = System.Drawing.SystemColors.ControlText;
            this.cmdExtend.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.cmdExtend.Location = new System.Drawing.Point(190, 20);
            this.cmdExtend.Name = "cmdExtend";
            this.cmdExtend.Size = new System.Drawing.Size(83, 48);
            this.cmdExtend.TabIndex = 4;
            this.cmdExtend.Text = "옵션확장";
            this.cmdExtend.UseVisualStyleBackColor = false;
            this.cmdExtend.Click += new System.EventHandler(this.cmdExtend_Click);
            // 
            // txtHeig
            // 
            this.txtHeig.Location = new System.Drawing.Point(83, 20);
            this.txtHeig.Name = "txtHeig";
            this.txtHeig.Size = new System.Drawing.Size(79, 25);
            this.txtHeig.TabIndex = 1;
            this.txtHeig.Text = "10";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(72, 15);
            this.label1.TabIndex = 0;
            this.label1.Text = "문자 높이";
            // 
            // txtPrec
            // 
            this.txtPrec.Location = new System.Drawing.Point(57, 20);
            this.txtPrec.Name = "txtPrec";
            this.txtPrec.Size = new System.Drawing.Size(99, 25);
            this.txtPrec.TabIndex = 1;
            this.txtPrec.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(10, 25);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(52, 15);
            this.label2.TabIndex = 0;
            this.label2.Text = "소수점";
            // 
            // cmdExit
            // 
            this.cmdExit.Location = new System.Drawing.Point(207, 480);
            this.cmdExit.Name = "cmdExit";
            this.cmdExit.Size = new System.Drawing.Size(80, 29);
            this.cmdExit.TabIndex = 12;
            this.cmdExit.Text = "종료";
            this.cmdExit.UseVisualStyleBackColor = true;
            this.cmdExit.Click += new System.EventHandler(this.cmdExit_Click);
            // 
            // txtMod
            // 
            this.txtMod.Location = new System.Drawing.Point(17, 480);
            this.txtMod.Name = "txtMod";
            this.txtMod.Size = new System.Drawing.Size(80, 29);
            this.txtMod.TabIndex = 10;
            this.txtMod.Text = "문자 수정";
            this.txtMod.UseVisualStyleBackColor = true;
            this.txtMod.Click += new System.EventHandler(this.txtMod_Click);
            // 
            // cmdText
            // 
            this.cmdText.Location = new System.Drawing.Point(113, 480);
            this.cmdText.Name = "cmdText";
            this.cmdText.Size = new System.Drawing.Size(80, 29);
            this.cmdText.TabIndex = 11;
            this.cmdText.Text = "문자 쓰기";
            this.cmdText.UseVisualStyleBackColor = true;
            this.cmdText.Click += new System.EventHandler(this.cmdText_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.txtAddText2);
            this.groupBox4.Controls.Add(this.label9);
            this.groupBox4.Controls.Add(this.txtAddText1);
            this.groupBox4.Controls.Add(this.label8);
            this.groupBox4.Controls.Add(this.chkColor);
            this.groupBox4.Controls.Add(this.comColor);
            this.groupBox4.Controls.Add(this.label7);
            this.groupBox4.Controls.Add(this.comLayer);
            this.groupBox4.Controls.Add(this.label6);
            this.groupBox4.Controls.Add(this.comAlign);
            this.groupBox4.Controls.Add(this.comStyle);
            this.groupBox4.Controls.Add(this.txtRot);
            this.groupBox4.Controls.Add(this.radRot);
            this.groupBox4.Controls.Add(this.radRot270);
            this.groupBox4.Controls.Add(this.radRot180);
            this.groupBox4.Controls.Add(this.radRot90);
            this.groupBox4.Controls.Add(this.radRot0);
            this.groupBox4.Controls.Add(this.label5);
            this.groupBox4.Controls.Add(this.chk1000);
            this.groupBox4.Controls.Add(this.label3);
            this.groupBox4.Controls.Add(this.label4);
            this.groupBox4.Location = new System.Drawing.Point(313, 12);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(267, 297);
            this.groupBox4.TabIndex = 8;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "문자옵션";
            // 
            // txtAddText2
            // 
            this.txtAddText2.Location = new System.Drawing.Point(201, 252);
            this.txtAddText2.Name = "txtAddText2";
            this.txtAddText2.Size = new System.Drawing.Size(56, 25);
            this.txtAddText2.TabIndex = 20;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(153, 254);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(52, 15);
            this.label9.TabIndex = 19;
            this.label9.Text = "꼬리말";
            // 
            // txtAddText1
            // 
            this.txtAddText1.Location = new System.Drawing.Point(82, 251);
            this.txtAddText1.Name = "txtAddText1";
            this.txtAddText1.Size = new System.Drawing.Size(56, 25);
            this.txtAddText1.TabIndex = 18;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(20, 254);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(52, 15);
            this.label8.TabIndex = 17;
            this.label8.Text = "머리말";
            // 
            // chkColor
            // 
            this.chkColor.AutoSize = true;
            this.chkColor.Location = new System.Drawing.Point(92, 218);
            this.chkColor.Name = "chkColor";
            this.chkColor.Size = new System.Drawing.Size(144, 19);
            this.chkColor.TabIndex = 16;
            this.chkColor.Text = "수정시 색상 변경";
            this.chkColor.UseVisualStyleBackColor = true;
            // 
            // comColor
            // 
            this.comColor.FormattingEnabled = true;
            this.comColor.Location = new System.Drawing.Point(92, 192);
            this.comColor.Name = "comColor";
            this.comColor.Size = new System.Drawing.Size(165, 23);
            this.comColor.TabIndex = 15;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(19, 194);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(72, 15);
            this.label7.TabIndex = 14;
            this.label7.Text = "문자 색상";
            // 
            // comLayer
            // 
            this.comLayer.FormattingEnabled = true;
            this.comLayer.Location = new System.Drawing.Point(92, 160);
            this.comLayer.Name = "comLayer";
            this.comLayer.Size = new System.Drawing.Size(165, 23);
            this.comLayer.TabIndex = 13;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(19, 162);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(52, 15);
            this.label6.TabIndex = 12;
            this.label6.Text = "레이어";
            // 
            // comAlign
            // 
            this.comAlign.FormattingEnabled = true;
            this.comAlign.Location = new System.Drawing.Point(92, 83);
            this.comAlign.Name = "comAlign";
            this.comAlign.Size = new System.Drawing.Size(165, 23);
            this.comAlign.TabIndex = 4;
            // 
            // comStyle
            // 
            this.comStyle.FormattingEnabled = true;
            this.comStyle.Location = new System.Drawing.Point(92, 54);
            this.comStyle.Name = "comStyle";
            this.comStyle.Size = new System.Drawing.Size(165, 23);
            this.comStyle.TabIndex = 2;
            // 
            // txtRot
            // 
            this.txtRot.Location = new System.Drawing.Point(211, 128);
            this.txtRot.Name = "txtRot";
            this.txtRot.Size = new System.Drawing.Size(46, 25);
            this.txtRot.TabIndex = 11;
            this.txtRot.Text = "0";
            // 
            // radRot
            // 
            this.radRot.AutoSize = true;
            this.radRot.Location = new System.Drawing.Point(191, 129);
            this.radRot.Name = "radRot";
            this.radRot.Size = new System.Drawing.Size(17, 16);
            this.radRot.TabIndex = 10;
            this.radRot.UseVisualStyleBackColor = true;
            // 
            // radRot270
            // 
            this.radRot270.AutoSize = true;
            this.radRot270.Location = new System.Drawing.Point(144, 129);
            this.radRot270.Name = "radRot270";
            this.radRot270.Size = new System.Drawing.Size(52, 19);
            this.radRot270.TabIndex = 9;
            this.radRot270.Text = "270";
            this.radRot270.UseVisualStyleBackColor = true;
            this.radRot270.CheckedChanged += new System.EventHandler(this.radRot270_CheckedChanged);
            // 
            // radRot180
            // 
            this.radRot180.AutoSize = true;
            this.radRot180.Location = new System.Drawing.Point(97, 129);
            this.radRot180.Name = "radRot180";
            this.radRot180.Size = new System.Drawing.Size(52, 19);
            this.radRot180.TabIndex = 8;
            this.radRot180.Text = "180";
            this.radRot180.UseVisualStyleBackColor = true;
            this.radRot180.CheckedChanged += new System.EventHandler(this.radRot180_CheckedChanged);
            // 
            // radRot90
            // 
            this.radRot90.AutoSize = true;
            this.radRot90.Location = new System.Drawing.Point(56, 129);
            this.radRot90.Name = "radRot90";
            this.radRot90.Size = new System.Drawing.Size(44, 19);
            this.radRot90.TabIndex = 7;
            this.radRot90.Text = "90";
            this.radRot90.UseVisualStyleBackColor = true;
            this.radRot90.CheckedChanged += new System.EventHandler(this.radRot90_CheckedChanged);
            // 
            // radRot0
            // 
            this.radRot0.AutoSize = true;
            this.radRot0.Checked = true;
            this.radRot0.Location = new System.Drawing.Point(21, 129);
            this.radRot0.Name = "radRot0";
            this.radRot0.Size = new System.Drawing.Size(36, 19);
            this.radRot0.TabIndex = 6;
            this.radRot0.TabStop = true;
            this.radRot0.Text = "0";
            this.radRot0.UseVisualStyleBackColor = true;
            this.radRot0.CheckedChanged += new System.EventHandler(this.radRot0_CheckedChanged);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(18, 86);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(72, 15);
            this.label5.TabIndex = 3;
            this.label5.Text = "문자 정렬";
            // 
            // chk1000
            // 
            this.chk1000.AutoSize = true;
            this.chk1000.Location = new System.Drawing.Point(21, 20);
            this.chk1000.Name = "chk1000";
            this.chk1000.Size = new System.Drawing.Size(174, 19);
            this.chk1000.TabIndex = 0;
            this.chk1000.Text = "천단위 구분기호 사용";
            this.chk1000.UseVisualStyleBackColor = true;
            this.chk1000.CheckedChanged += new System.EventHandler(this.chk1000_CheckedChanged);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(19, 114);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(72, 15);
            this.label3.TabIndex = 5;
            this.label3.Text = "문자 각도";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(18, 57);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(72, 15);
            this.label4.TabIndex = 1;
            this.label4.Text = "문자 유형";
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.txtHatchSize);
            this.groupBox5.Controls.Add(this.txtHatchPattern);
            this.groupBox5.Controls.Add(this.label10);
            this.groupBox5.Controls.Add(this.chkDelHatch);
            this.groupBox5.Controls.Add(this.chkUseHatch);
            this.groupBox5.Controls.Add(this.comUnit);
            this.groupBox5.Controls.Add(this.label14);
            this.groupBox5.Controls.Add(this.label16);
            this.groupBox5.Location = new System.Drawing.Point(313, 315);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(267, 159);
            this.groupBox5.TabIndex = 9;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "면적산출";
            // 
            // txtHatchSize
            // 
            this.txtHatchSize.Location = new System.Drawing.Point(88, 112);
            this.txtHatchSize.Name = "txtHatchSize";
            this.txtHatchSize.Size = new System.Drawing.Size(117, 25);
            this.txtHatchSize.TabIndex = 7;
            this.txtHatchSize.Text = "1";
            // 
            // txtHatchPattern
            // 
            this.txtHatchPattern.Location = new System.Drawing.Point(88, 82);
            this.txtHatchPattern.Name = "txtHatchPattern";
            this.txtHatchPattern.Size = new System.Drawing.Size(117, 25);
            this.txtHatchPattern.TabIndex = 5;
            this.txtHatchPattern.Text = "ANSI31";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(20, 114);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(72, 15);
            this.label10.TabIndex = 6;
            this.label10.Text = "해치 축척";
            // 
            // chkDelHatch
            // 
            this.chkDelHatch.AutoSize = true;
            this.chkDelHatch.Location = new System.Drawing.Point(133, 54);
            this.chkDelHatch.Name = "chkDelHatch";
            this.chkDelHatch.Size = new System.Drawing.Size(149, 19);
            this.chkDelHatch.TabIndex = 3;
            this.chkDelHatch.Text = "산출 후 해치 삭제";
            this.chkDelHatch.UseVisualStyleBackColor = true;
            // 
            // chkUseHatch
            // 
            this.chkUseHatch.AutoSize = true;
            this.chkUseHatch.Location = new System.Drawing.Point(22, 54);
            this.chkUseHatch.Name = "chkUseHatch";
            this.chkUseHatch.Size = new System.Drawing.Size(114, 19);
            this.chkUseHatch.TabIndex = 2;
            this.chkUseHatch.Text = "산출 시 해치";
            this.chkUseHatch.UseVisualStyleBackColor = true;
            // 
            // comUnit
            // 
            this.comUnit.FormattingEnabled = true;
            this.comUnit.Location = new System.Drawing.Point(117, 22);
            this.comUnit.Name = "comUnit";
            this.comUnit.Size = new System.Drawing.Size(140, 23);
            this.comUnit.TabIndex = 1;
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(19, 84);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(72, 15);
            this.label14.TabIndex = 4;
            this.label14.Text = "해치 패턴";
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(20, 25);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(102, 15);
            this.label16.TabIndex = 0;
            this.label16.Text = "면적산출 단위";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(10, 50);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(52, 15);
            this.label11.TabIndex = 2;
            this.label11.Text = "계산값";
            // 
            // txtResult
            // 
            this.txtResult.Font = new System.Drawing.Font("굴림", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.txtResult.Location = new System.Drawing.Point(57, 47);
            this.txtResult.Name = "txtResult";
            this.txtResult.Size = new System.Drawing.Size(216, 25);
            this.txtResult.TabIndex = 3;
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.txtPrec);
            this.groupBox6.Controls.Add(this.txtResult);
            this.groupBox6.Controls.Add(this.label2);
            this.groupBox6.Controls.Add(this.label11);
            this.groupBox6.Location = new System.Drawing.Point(12, 315);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(279, 73);
            this.groupBox6.TabIndex = 6;
            this.groupBox6.TabStop = false;
            // 
            // groupBox7
            // 
            this.groupBox7.Controls.Add(this.comScale);
            this.groupBox7.Location = new System.Drawing.Point(218, 107);
            this.groupBox7.Name = "groupBox7";
            this.groupBox7.Size = new System.Drawing.Size(73, 47);
            this.groupBox7.TabIndex = 2;
            this.groupBox7.TabStop = false;
            this.groupBox7.Text = "축척";
            // 
            // comScale
            // 
            this.comScale.FormattingEnabled = true;
            this.comScale.Location = new System.Drawing.Point(7, 20);
            this.comScale.Name = "comScale";
            this.comScale.Size = new System.Drawing.Size(60, 23);
            this.comScale.TabIndex = 0;
            // 
            // cmdCopy
            // 
            this.cmdCopy.Location = new System.Drawing.Point(202, 160);
            this.cmdCopy.Name = "cmdCopy";
            this.cmdCopy.Size = new System.Drawing.Size(88, 29);
            this.cmdCopy.TabIndex = 4;
            this.cmdCopy.Text = "복사";
            this.cmdCopy.UseVisualStyleBackColor = true;
            this.cmdCopy.Click += new System.EventHandler(this.cmdCopy_Click);
            // 
            // DispCalc
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
            this.ClientSize = new System.Drawing.Size(597, 553);
            this.Controls.Add(this.groupBox7);
            this.Controls.Add(this.groupBox6);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.cmdExit);
            this.Controls.Add(this.txtMod);
            this.Controls.Add(this.cmdText);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.txtDisp);
            this.Controls.Add(this.cmdCalc);
            this.Controls.Add(this.cmdAC);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.cmdCopy);
            this.Controls.Add(this.cmdSel);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Location = new System.Drawing.Point(30, 100);
            this.MaximizeBox = false;
            this.Name = "DispCalc";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "계산기";
            this.Load += new System.EventHandler(this.DispCalc_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.txtJARI)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.txtPrec)).EndInit();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            this.groupBox7.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.RadioButton rad1;
        private System.Windows.Forms.Button cmdSel;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton rad4;
        private System.Windows.Forms.RadioButton rad8;
        private System.Windows.Forms.RadioButton rad7;
        private System.Windows.Forms.RadioButton rad6;
        private System.Windows.Forms.RadioButton rad5;
        private System.Windows.Forms.RadioButton rad3;
        private System.Windows.Forms.RadioButton rad2;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton radCal4;
        private System.Windows.Forms.RadioButton radCal3;
        private System.Windows.Forms.RadioButton radCal2;
        private System.Windows.Forms.RadioButton radCal1;
        private System.Windows.Forms.Button cmdAC;
        private System.Windows.Forms.Button cmdCalc;
        private System.Windows.Forms.RichTextBox txtDisp;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox txtHeig;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown txtPrec;
        private System.Windows.Forms.Button cmdExtend;
        private System.Windows.Forms.Button cmdExit;
        private System.Windows.Forms.Button txtMod;
        private System.Windows.Forms.Button cmdText;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.TextBox txtAddText2;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox txtAddText1;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.CheckBox chkColor;
        private System.Windows.Forms.ComboBox comColor;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.ComboBox comLayer;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ComboBox comAlign;
        private System.Windows.Forms.ComboBox comStyle;
        private System.Windows.Forms.TextBox txtRot;
        private System.Windows.Forms.RadioButton radRot;
        private System.Windows.Forms.RadioButton radRot270;
        private System.Windows.Forms.RadioButton radRot180;
        private System.Windows.Forms.RadioButton radRot90;
        private System.Windows.Forms.RadioButton radRot0;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.CheckBox chk1000;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.TextBox txtHatchSize;
        private System.Windows.Forms.TextBox txtHatchPattern;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.CheckBox chkDelHatch;
        private System.Windows.Forms.CheckBox chkUseHatch;
        private System.Windows.Forms.ComboBox comUnit;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.TextBox txtResult;
        private System.Windows.Forms.NumericUpDown txtJARI;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.GroupBox groupBox7;
        private System.Windows.Forms.ComboBox comScale;
        private System.Windows.Forms.Button cmdCopy;
    }
}

