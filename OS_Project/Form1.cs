using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OS_Project
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            circularProgressBar1.Value = 0;
            timer1.Enabled = true;


        }

        private void timer1_Tick(object sender, EventArgs e)
        {

            circularProgressBar1.Value += 2;
            circularProgressBar1.Text = circularProgressBar1.Value.ToString() + "%";
            if (circularProgressBar1.Value >= 100)
            {
                timer1.Enabled = false;
                Screen2 f = new Screen2();
                f.Show();
                this.Hide();
            }

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void circularProgressBar1_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
