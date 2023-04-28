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
    /// Interaction logic for ManualOPeration.xaml
    /// </summary>
    public partial class ManualOPeration : Window
    {
        public ManualOPeration()
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

        #region pumpControl
        #region pumpOffProcess

        //    {
        //        var result = clint.Get("Rooms/" + "01");
        //    Data d1 = result.ResultAs<Data>();
        //    d1.man_pump = "0";
        //        var updater = clint.Update("Rooms/" + "01", d1);
        //    MessageBox.Show("Water pump turned off successfully");
        //    } 
        #endregion

        #region pumpOnProcess
        //{
        //     var result = clint.Get("Rooms/" + "01");
        //     Data d1 = result.ResultAs<Data>();
        //     d1.man_pump = "1";
        //     var updater = clint.Update("Rooms/" + "01", d1);
        //     MessageBox.Show("Water pump turned on successfully");
        // } 
        #endregion
        #endregion

        #region sprikelerDeviceControl

        #region topLeftDirection
        //{
        //    var result = clint.Get("Rooms/" + "01");
        //    Data d1 = result.ResultAs<Data>();
        //    d1.man_quad = "4";
        //    var updater = clint.Update("Rooms/" + "01", d1);

        //} 
        #endregion

        #region topRightDirection
        //{
        //    var result = clint.Get("Rooms/" + "01");
        //    Data d1 = result.ResultAs<Data>();
        //    d1.man_quad = "3";
        //    var updater = clint.Update("Rooms/" + "01", d1);

        //}
        #endregion

        #region bottompLeftDirection
        //{
        //    var result = clint.Get("Rooms/" + "01");
        //    Data d1 = result.ResultAs<Data>();
        //    d1.man_quad = "1";
        //    var updater = clint.Update("Rooms/" + "01", d1);

        //}
        #endregion

        #region bottompRightDirection
        //{
        //    var result = clint.Get("Rooms/" + "01");
        //    Data d1 = result.ResultAs<Data>();
        //    d1.man_quad = "2";
        //    var updater = clint.Update("Rooms/" + "01", d1);

        //} 
        #endregion
        #endregion

        #region mistControl
        #region topLeftDirection
        //{
        //    var result = clint.Get("Rooms/" + "01");
        //    Data d1 = result.ResultAs<Data>();
        //    d1.man_mist = "4";
        //    var updater = clint.Update("Rooms/" + "01", d1);

        //} 
        #endregion

        #region topRightDirection
        //{
        //    var result = clint.Get("Rooms/" + "01");
        //    Data d1 = result.ResultAs<Data>();
        //    d1.man_mist = "3";
        //    var updater = clint.Update("Rooms/" + "01", d1);

        //}
        #endregion

        #region bottompLeftDirection
        //{
        //    var result = clint.Get("Rooms/" + "01");
        //    Data d1 = result.ResultAs<Data>();
        //    d1.man_mist = "1";
        //    var updater = clint.Update("Rooms/" + "01", d1);

        //}
        #endregion

        #region bottompRightDirection
        //{
        //    var result = clint.Get("Rooms/" + "01");
        //    Data d1 = result.ResultAs<Data>();
        //    d1.man_mist = "2";
        //    var updater = clint.Update("Rooms/" + "01", d1);

        //} 
        #endregion


        #endregion

        #region resetProcess
        //{
        //    var result = clint.Get("Rooms/" + "01");
        //    Data d1 = result.ResultAs<Data>();
        //    d1.man_quad = "0";
        //    d1.man_mist="0";
        //    d1.man_pump="0";
        //    var updater = clint.Update("Rooms/" + "01", d1);

        //} 
        #endregion
    }
}
