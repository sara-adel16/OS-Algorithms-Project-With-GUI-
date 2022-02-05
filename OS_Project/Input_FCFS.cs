using System;
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
    public partial class Input_FCFS : Form
    {
        public Input_FCFS()
        {
            InitializeComponent();
        }

        private void Input_FCFS_Load(object sender, EventArgs e)
        {

        }

        private void bunifuImageButton2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void bunifuFlatButton1_Click(object sender, EventArgs e)
        {
            bunifuTextBox1.Visible = false;
            bunifuTextBox3.Visible = false;
            bunifuFlatButton4.Visible = true;

            label1.Text = "Result";
            bunifuFlatButton1.Visible = false;
            bunifuFlatButton2.Visible = true;
            //--------------------------------------------------------
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.CreateNoWindow = false;
            startInfo.UseShellExecute = false;
            string a = bunifuTextBox1.Text;
            string c = bunifuTextBox3.Text;
            startInfo.FileName = "F:\\OSProject\\OS Project Test\\FCFS.exe";
            startInfo.WindowStyle = ProcessWindowStyle.Hidden;


            Console.WriteLine(a + " " + c);
            startInfo.Arguments = a  + " " + c;

            try
            {
                // Start the process with the info we specified.
                // Call WaitForExit and then the using statement will close.
                using (Process exeProcess = Process.Start(startInfo))
                {
                    exeProcess.WaitForExit();
                    System.Threading.Thread.Sleep(500);
                    string avg = System.IO.File.ReadAllText(@"F:\\OSProject\\OS Project Test\\OS_Project\\bin\\Debug\\FCFS.txt");
                    bunifuFlatButton4.Text = "Average waiting time = " + avg;
                }
            }
            catch
            {
                // Log error.
            }
        }

        private void bunifuFlatButton2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void bunifuFlatButton4_Click(object sender, EventArgs e)
        {

        }
    }
}
