using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

using Gssoft.Gscad.Runtime;
using Gssoft.Gscad.ApplicationServices;
using Gssoft.Gscad.EditorInput;
using Gssoft.Gscad.PlottingServices;
using Gssoft.Gscad.Publishing;
using Gssoft.Gscad.Windows;
using Gssoft.Gscad.Colors;
using Gssoft.Gscad.DatabaseServices;
using Gssoft.Gscad.DatabaseServices.Filters;
//using Gssoft.Gscad.Export_Import;
using Gssoft.Gscad.Geometry;
using Gssoft.Gscad.GraphicsInterface;
using Gssoft.Gscad.GraphicsSystem;
using Gssoft.Gscad.LayerManager;


namespace gCAD_Calc
{
    public class Program
    {
        DispCalc DIspCalcForm;
        [CommandMethod("UI_CALC", CommandFlags.Modal)]
        public void calcformrun()
        {            
            DIspCalcForm = new DispCalc();
            Gssoft.Gscad.ApplicationServices.Application.ShowModelessDialog(DIspCalcForm); 
        }

       

        //================================================
        [CommandMethod("DispResult")]
        public void CAD_ResultShow()
        {              
            DIspCalcForm.Show_result_cal();          
        }







    }
}
