using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OS_Project
{
    public partial class EDF_Result : Form
    {
        public EDF_Result()
        {
            InitializeComponent();
            string[] avg = File.ReadAllLines(@"F:\\OSProject\\OS Project Test\\OS_Project\\bin\\Debug\\EDF_Result.txt");
            string separator = "\r\n";
            textBox1.Text = string.Join(separator, avg); 
        }

        private void bunifuImageButton2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void bunifuFlatButton2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void EDF_Result_Load(object sender, EventArgs e)
        {

        }
    }
}
