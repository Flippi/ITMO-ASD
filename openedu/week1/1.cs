using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace week1
{
    class _1
    {
        static void Man21()
        {
            string path = "input.txt";
            string writePath = "output.txt";
            string[] split;
            using (StreamReader sr = new StreamReader(path, System.Text.Encoding.Default))
            {
                string line;
                line = sr.ReadLine();
                split = line.Split(' ');

            }


            using (StreamWriter sw = new StreamWriter(writePath, false, System.Text.Encoding.Default))
            {
                sw.WriteLine(Convert.ToInt32(split[0]) + Convert.ToInt32(split[1]));
            }
        }
    }
}
