using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.Odbc;

namespace ManageShopOnlineDB
{
    public partial class Form1 : Form
    {
        OdbcConnection con = new OdbcConnection("Driver={Sql Server};Server=DESKTOP-2BHEL1M\\SQLEXPRESS;Databse=ManageShopOnline;");
        OdbcDataAdapter dat;
        DataSet ds;
        OdbcCommand cmd;
        


        public Form1()
        {
            InitializeComponent();
            this.ControlBox = false;

        }
        #region Movable Evenet
        #endregion



        private void Form1_Load(object sender, EventArgs e)
        {
            try
            {
                con.Open();
                ds = new DataSet();
                



            }
            catch (OdbcException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void DataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void ADD_Click(object sender, EventArgs e)
        {
            string Sql = "insert into Product(ProdID,ProdName,ProdDescription,ProdPrice,Stock) values('" + textBox6.Text + "','" + textBox7.Text + "','" + textBox10.Text + "','" + double.Parse(textBox8.Text) + "','" + int.Parse(textBox9.Text) + "')";
            try
            {
                cmd = new OdbcCommand(Sql, con);
                cmd.ExecuteNonQuery();
                con.Close();
                Form1_Load(null, null);

            }
            catch (OdbcException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void TextBox6_TextChanged(object sender, EventArgs e)
        {

        }


        private void DataGridView2_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (dataGridView2.RowCount > 0)
            {
                int i = e.RowIndex;
                if (i < 0) return;
                textBox6.Text = dataGridView2.CurrentRow.Cells[0].Value.ToString();
                textBox7.Text = dataGridView2.CurrentRow.Cells[1].Value.ToString();
                textBox8.Text = dataGridView2.CurrentRow.Cells[3].Value.ToString();
                textBox9.Text = dataGridView2.CurrentRow.Cells[4].Value.ToString();
                textBox10.Text = dataGridView2.CurrentRow.Cells[2].Value.ToString();
            }


        }

        private void DELETE_Click(object sender, EventArgs e)
        {
            string sql = "delete from Product where ProdID='" + textBox6.Text + "'";
            try
            {
                cmd = new OdbcCommand(sql, con);
                cmd.ExecuteNonQuery();
                con.Close();
                Form1_Load(null, null);
            }
            catch (OdbcException ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void GroupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void Button1_Click(object sender, EventArgs e)
        {
            if (radioButton7.Checked)
            {
                dataGridView2.DataSource = null;
                con.Close();
                Form1_Load(null, null);
                dat = new OdbcDataAdapter("select * from Product", con);
                dat.Fill(ds);
                dataGridView2.DataSource = ds.Tables[0];
                dataGridView2.Update();
                dataGridView2.Refresh();
            }
            else if (radioButton6.Checked)
            {
                dataGridView2.DataSource = null;
                con.Close();
                Form1_Load(null, null);
                dat = new OdbcDataAdapter("select * from ManageAccount", con);
                dat.Fill(ds);
                dataGridView2.DataSource = ds.Tables[0];
                dataGridView2.Update();
                dataGridView2.Refresh();
            }
            else if (radioButton5.Checked)
            {
                dataGridView2.DataSource = null;
                con.Close();
                Form1_Load(null, null);
                dat = new OdbcDataAdapter("select * from Invoice_Product", con);
                dat.Fill(ds);
                dataGridView2.DataSource = ds.Tables[0];
                dataGridView2.Update();
                dataGridView2.Refresh();
            }
            else if (radioButton4.Checked)
            {
                dataGridView2.DataSource = null;
                con.Close();
                Form1_Load(null, null);
                dat = new OdbcDataAdapter("select * from Invoice", con);
                dat.Fill(ds);
                dataGridView2.DataSource = ds.Tables[0];
                dataGridView2.Update();
                dataGridView2.Refresh();
            }
            else if (radioButton3.Checked)
            {
                dataGridView2.DataSource = null;
                con.Close();
                Form1_Load(null, null);
                dat = new OdbcDataAdapter("select * from Feedback", con);
                dat.Fill(ds);
                dataGridView2.DataSource = ds.Tables[0];
                dataGridView2.Update();
                dataGridView2.Refresh();
            }
            else if (radioButton2.Checked)
            {
                dataGridView2.DataSource = null;
                con.Close();
                Form1_Load(null, null);
                dat = new OdbcDataAdapter("select * from Customer", con);
                dat.Fill(ds);
                dataGridView2.DataSource = ds.Tables[0];
                dataGridView2.Update();
                dataGridView2.Refresh();
            }
            else if (radioButton1.Checked)
            {
                dataGridView2.DataSource = null;
                con.Close();
                Form1_Load(null, null);
                dat = new OdbcDataAdapter("select * from Categories", con);
                dat.Fill(ds);
                dataGridView2.DataSource = ds.Tables[0];
                dataGridView2.Update();
                dataGridView2.Refresh();

            }
        }
    }
}
