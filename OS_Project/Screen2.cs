using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OS_Project
{
    public partial class Screen2 : Form
    {
        public Screen2()
        {
            InitializeComponent();
            bunifuImageButton2.Visible = true;

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void bunifuImageButton2_Click(object sender, EventArgs e)
        {
            Environment.Exit(0);

        }

        private void bunifuImageButton4_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Minimized;

        }

        private void Screen2_Load(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {
           
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Form2 f = new Form2();
            f.Show();
        }

        private void bunifuFlatButton1_Click(object sender, EventArgs e)
        {
            Input_Page m = new Input_Page();
            m.ShowDialog();
        }

        private void bunifuFlatButton2_Click(object sender, EventArgs e)
        {
            Input_FCFS h = new Input_FCFS();
            h.ShowDialog();
        }

        private void bunifuFlatButton3_Click(object sender, EventArgs e)
        {
            RMA s = new RMA();
            s.ShowDialog();
        }

        private void bunifuFlatButton4_Click(object sender, EventArgs e)
        {
            Input_EDF z = new Input_EDF();
            z.ShowDialog();
        }

        private void bunifuImageButton1_Click(object sender, EventArgs e)
        {
            string filename = "F:\\OSProject\\OS Project Test\\OS-Presentation.pdf";
            System.Diagnostics.Process.Start(filename);
        }
    }
}
