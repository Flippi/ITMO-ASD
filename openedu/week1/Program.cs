using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace week1
{
    class Program
    {
        static void Main(string[] args)
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

            int[] myInts = new int[count];
            for (int i = 0; i < split.Length; i++)
            {
                myInts[i] = int.Parse(split[i]);

            }


            using (StreamWriter sw = new StreamWriter(writePath, false, System.Text.Encoding.Default))
            {
                quicksort(myInts, 0, myInts.Length - 1,sw);
                string output = "";
                sw.WriteLine("No more swaps needed.");
                for (int i = 0; i < myInts.Length; i++)
                {
                    output += myInts[i] + " ";
                }
                sw.WriteLine(output);
            }

            int partition(int[] array, int start, int end, StreamWriter str)
            {
                    int temp;//swap helper
                    int marker = start;//divides left and right subarrays
                    for (int i = start; i <= end; i++)
                    {
                        if (array[i] < array[end]) //array[end] is pivot
                        {
                            temp = array[marker]; // swap
                            if (marker != i)
                                str.WriteLine("Swap elements at indices " + (marker+1) + " and " + (i+1) + ".");
                            array[marker] = array[i];
                            array[i] = temp;
                            marker += 1;
                        }
                    }
                    //put pivot(array[end]) between left and right subarrays
                    temp = array[marker];
                    array[marker] = array[end];
                    array[end] = temp;
                    if (marker != end)
                    str.WriteLine("Swap elements at indices " + (marker+1) + " and " + (end+1) + ".");
                    return marker;
            }

            void quicksort(int[] array, int start, int end, StreamWriter str)
            {
                if (start >= end)
                {
                    return;
                }
                int pivot = partition(array, start, end, str);
                quicksort(array, start, pivot - 1, str);
                quicksort(array, pivot + 1, end, str);
            }


        }
        
    }
}

