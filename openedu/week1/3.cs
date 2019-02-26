using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace week1
{
    class _3
    {
        static void Second()
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
            int[] index = new int[count];
            index[0] = 1;


            int[] myInts = Array.ConvertAll(split, int.Parse);


            for (int i = 1; i < myInts.Length; i++)
            {
                int cur = myInts[i];
                int j = i;
                while (j > 0 && cur < myInts[j - 1])
                {
                    myInts[j] = myInts[j - 1];
                    j--;
                }
                myInts[j] = cur;

                index[i] = j + 1;
            }


            using (StreamWriter sw = new StreamWriter(writePath, false, System.Text.Encoding.Default))
            {
                string output = "";
                for (int i = 0; i < index.Length; i++)
                {
                    output = output + Convert.ToString(index[i]) + " ";
                }
                sw.WriteLine(output);
                output = "";
                for (int i = 0; i < myInts.Length; i++)
                {
                    output = output + Convert.ToString(myInts[i]) + " ";
                }
                sw.WriteLine(output);

            }
        }
    }
}
