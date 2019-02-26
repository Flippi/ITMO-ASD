using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace week1
{
    class _4
    {
        static void sor(string[] args)
        {
            string path = "input.txt";
            string writePath = "output.txt";
            string[] split;
            int count;
            using (StreamReader sr = new StreamReader(path, System.Text.Encoding.Default))
            {
                string line;
                count = int.Parse(sr.ReadLine());
                line = sr.ReadLine();
                split = line.Split(' ');
            }


            double[] myInts = Array.ConvertAll(split, double.Parse);
            double[] array = Array.ConvertAll(split, double.Parse);

            for (int i = 1; i < myInts.Length; i++)
            {
                double cur = myInts[i];
                int j = i;
                while (j > 0 && cur < myInts[j - 1])
                {
                    myInts[j] = myInts[j - 1];
                    j--;
                }
                myInts[j] = cur;
            }

            using (StreamWriter sw = new StreamWriter(writePath, false, System.Text.Encoding.Default))
            {
                string output = "";

                for (int i = 0; i < array.Length; i++)
                {
                    if (array[i] == myInts[0])
                        output += i + 1 + " ";

                }
                for (int i = 0; i < array.Length; i++)
                {
                    if (array[i] == myInts[(count + 1) / 2 - 1])
                        output += i + 1 + " ";

                }
                for (int i = 0; i < array.Length; i++)
                {
                    if (array[i] == myInts[myInts.Length - 1])
                        output += i + 1;

                }
                sw.WriteLine(output);

            }

        }
    }
}
