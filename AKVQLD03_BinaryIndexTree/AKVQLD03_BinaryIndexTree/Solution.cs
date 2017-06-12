using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AKVQLD03_BinaryIndexTree
{
    class Solution
    {
        protected static TextReader reader;
        protected static TextWriter writer;

        static void Main(string[] args)
        {
#if DEBUG
            reader = new StreamReader("..\\..\\input.txt");
            writer = Console.Out;
            // writer = new StreamWriter("..\\..\\output.txt");
#else
            reader = Console.In;
            writer = new StreamWriter(Console.OpenStandardOutput());
#endif
            Solve();
#if DEBUG
            Console.WriteLine("Completed");
            Console.ReadLine();
#endif
        }

        static void Solve()
        {
            var temp = reader.ReadLine().Split(' ').Select(x => Convert.ToInt32(x)).ToArray();
            int n = temp[0];
            int q = temp[1];

          //  var arr = reader.ReadLine().Split(' ').Select(x => Convert.ToInt32(x)).ToArray();
            var barr = new int[n + 1];
            //for (int i = 0; i < arr.Length; i++)
            //    Add(i + 1, arr[i], barr);
            while (q-- > 0)
            {
                var temp2 = reader.ReadLine().Split(' ');
                if (temp2[0] == "add")
                    Add(int.Parse(temp2[1]), int.Parse(temp2[2]), barr);
                else
                {
                    var sum1 = Sum(int.Parse(temp2[1])-1, barr);
                    var sum2 = Sum(int.Parse(temp2[2]), barr);
                    writer.WriteLine(sum2 - sum1);
                }
            }


            writer.Flush();
#if DEBUG
            writer.Close();
#endif
        }

        static void Add(int pos, int val, int[] barr)
        {
            while (pos < barr.Length)
            {
                barr[pos] += val;
                pos = pos + (pos & -pos);
            }
        }

        static int Sum(int pos, int[] barr)
        {
            int sum = 0;
            while (pos >= 1)
            {
                sum += barr[pos];
                pos = pos - (pos & -pos);
            }

            return sum;
        }


    }
}
