using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OS_Project
{
    public partial class Input_Page : Form
    {
        private const HorizontalAlignment center = HorizontalAlignment.Center;

        public Input_Page()
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
            bunifuTextBox2.Visible = false;
            bunifuTextBox3.Visible = false;
            bunifuFlatButton3.Visible = true;
            bunifuFlatButton4.Visible = true;
           
            label1.Text = "Result";
            bunifuFlatButton1.Visible = false;
            bunifuFlatButton2.Visible = true;
            //--------------------------------------------------------
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.CreateNoWindow = false;
            startInfo.UseShellExecute = false;
            string a = bunifuTextBox1.Text;
            string b = bunifuTextBox2.Text;
            string c = bunifuTextBox3.Text;
            startInfo.FileName = "F:\\OSProject\\OS Project Test\\Shortest remaining time first.exe";
            startInfo.WindowStyle = ProcessWindowStyle.Hidden;
            
            
            Console.WriteLine(a + " " + b + " " + c);
            startInfo.Arguments = a + " " + b + " " + c;

            try
            {
                // Start the process with the info we specified.
                // Call WaitForExit and then the using statement will close.
                using (Process exeProcess = Process.Start(startInfo))
                {
                    exeProcess.WaitForExit();
                    System.Threading.Thread.Sleep(500);
                    string avg = System.IO.File.ReadAllText(@"F:\\OSProject\\OS Project Test\\OS_Project\\bin\\Debug\\Average.txt");
                    string turn = System.IO.File.ReadAllText(@"F:\\OSProject\\OS Project Test\\OS_Project\\bin\\Debug\\Turnaround.txt");
                    bunifuFlatButton3.Text = "Average waiting time = " + avg;
                    bunifuFlatButton4.Text = "Turnaround time = " + turn;
                }
            }
            catch
            {
                // Log error.
            }



        }

        private void bunifuFlatButton2_Click(object sender, EventArgs e)
        {
            this.Hide();
        }

        private void bunifuTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void bunifuTextBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void bunifuFlatButton3_Click(object sender, EventArgs e)
        {

        }

        private void bunifuFlatButton4_Click(object sender, EventArgs e)
        {

        }

        private void Input_Page_Load(object sender, EventArgs e)
        {

        }
    }
}
