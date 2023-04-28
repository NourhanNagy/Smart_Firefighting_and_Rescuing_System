using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using FireSharp.Config;
using FireSharp.Interfaces;
using FireSharp.Response;

namespace Graduation_1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        IFirebaseConfig fBase = new FirebaseConfig()
        {
            AuthSecret = "xeGUt0lSHNaP1aVyBGztv9jgMIF3MwU171imjPca",
            BasePath = "https://test1-eee56-default-rtdb.firebaseio.com/"
        };
        IFirebaseClient clint;
        
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            try
            {
                clint = new FireSharp.FirebaseClient(fBase);
            }
            catch
            {
                MessageBox.Show("there is a problem with the internet connection");
            }

        }

        private void manOpBtn_Click(object sender, RoutedEventArgs e)
        {

            var result = clint.Get("Rooms/" + roomBox.Text);
            Data d1 = result.ResultAs<Data>();
            d1.man_op = "1";
            var updater = clint.Update("Rooms/" + roomBox.Text, d1);
            ManualOPeration manualOperation = new ManualOPeration();
            manualOperation.Show();
        }

        private void sytemOnBtn_Click(object sender, RoutedEventArgs e)
        {

            var result = clint.Get("Rooms/" + roomBox.Text);
            Data d1 = result.ResultAs<Data>();
            d1.system_status = "1";
            var updater = clint.Update("Rooms/" + roomBox.Text, d1);
            MessageBox.Show("System turned on successfully");
        }

        private void sytemOffBtn_Click(object sender, RoutedEventArgs e)
        {

            var result = clint.Get("Rooms/" + roomBox.Text);
            Data d1 = result.ResultAs<Data>();
            d1.system_status = "0";
            var updater = clint.Update("Rooms/" + roomBox.Text, d1);
            MessageBox.Show("System turned off successfully");
        }

        private void monitoringBtn_Click(object sender, RoutedEventArgs e)
        {
            Monitoring monitoring = new Monitoring();
            monitoring.Show();
       
        }
    }
}
