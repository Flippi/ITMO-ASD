using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace ItmoAlgos
{
    public class Program
    {
        private static string[] _input;
        private static int _currentLineIndex;

        private static string ReadLine()
        {
            return _input[_currentLineIndex++];
        }

        public static void Main(string[] args)
        {
            _input = File.ReadAllLines("input.txt");

            string map = ReadLine();
            var prefixes = new int[map.Length];
            // Алгоритм Кнута-Морриса-Пратта
            int k = 0;
            for (int i = 1; i < map.Length; ++i)
            {
                while (k > 0 && map[k] != map[i])
                {
                    k = prefixes[k - 1];
                }

                if (map[k] == map[i])
                {
                    k++;
                }

                prefixes[i] = k;
            }

            File.WriteAllText("output.txt", string.Join(" ", prefixes));
        }
    }
}