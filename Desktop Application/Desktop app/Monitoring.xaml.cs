using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using FireSharp.Config;
using FireSharp.Interfaces;
using FireSharp.Response;

namespace Graduation_1
{
    /// <summary>
    /// Interaction logic for Monitoring.xaml
    /// </summary>
    public partial class Monitoring : Window
    {
        public Monitoring()
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

        #region monitoringProcess
        //while (true)
        //{
        //    var result = clint.Get("Rooms/" + roomBox.Text);
        //    Data d1 = result.ResultAs<Data>();
        //    if (d1.fire=="1")
        //    {
        //        if (d1.human=="1")
        //        {
        //            MessageBox.Show("there is fire in room 1 Floor 0 and there is human in there it's an emergency case");

        //        }
        //        else
        //        {
        //            MessageBox.Show("there is fire in room 1 Floor 0 and there is no human ");

        //        }
        //    }
        //    else
        //    {

        //        Button which stop that loop and end monitoring process.

        //    }
        //}; 
        #endregion
    }
}
