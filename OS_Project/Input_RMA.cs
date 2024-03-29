﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OS_Project
{
    public partial class RMA : Form
    {
        public RMA()
        {
            InitializeComponent();
        }

        private void bunifuImageButton2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void bunifuFlatButton1_Click(object sender, EventArgs e)
        {
            bunifuTextBox1.Visible = false;
            bunifuTextBox3.Visible = false;

            label1.Text = "Result";
            bunifuFlatButton1.Visible = false;
            //--------------------------------------------------------
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.CreateNoWindow = false;
            startInfo.UseShellExecute = false;
            string a = bunifuTextBox1.Text;
            string c = bunifuTextBox3.Text;
            startInfo.FileName = "F:\\OSProject\\OS Project Test\\RMA.exe";
            startInfo.WindowStyle = ProcessWindowStyle.Hidden;


            Console.WriteLine(a + " " + c);
            startInfo.Arguments = a + " " + c;


            try
            {
                // Start the process with the info we specified.
                // Call WaitForExit and then the using statement will close.
                using (Process exeProcess = Process.Start(startInfo))
                {
                    exeProcess.WaitForExit();
                    this.Hide();
                    RMA_Result w = new RMA_Result();
                    w.ShowDialog();

                }
            }
            catch
            {
                // Log error.
            }
        }

        private void bunifuFlatButton2_Click(object sender, EventArgs e)
        {
            Environment.Exit(0);
        }

        private void bunifuTextBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void Input_RMA_Load(object sender, EventArgs e)
        {

        }
    }
}
