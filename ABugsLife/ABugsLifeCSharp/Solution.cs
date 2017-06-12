using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABugsLifeCSharp
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
            int t = Convert.ToInt32(reader.ReadLine());
            int i = 0;
            while (t-- > 0)
            {
                i++;
                var temp = reader.ReadLine().Split(' ').Select(x => Convert.ToInt32(x)).ToArray();
                int n = temp[0];
                int it = temp[1];
                short[] v = new short[n+1];
                while ((it--) > 0)
                {
                    var btemp = reader.ReadLine().Split(' ').Select(x => Convert.ToInt32(x)).ToArray();
                    var b1 = btemp[0];
                    var b2 = btemp[1];
                    short vb1 = v[b1];
                    short vb2 = v[b2];
                    if (vb1 == 0 && vb2 == 0)
                    {
                        v[b1] = -1;
                        v[b2] = 1;
                    }
                    else if (b1 != 0 && b2 != 0)
                    {
                        if (vb1 == vb2)
                            break;
                    }
                    else if (vb1 == 0 && vb2 != 0)
                        v[b1] = (short)(vb2 * (-1));
                    else if (vb2 == 0 && vb1 != 0)
                        v[b2] = (short) (vb1*(-1));

                }
                writer.WriteLine("Scenario #{0}:",i);
                if (t == -1)
                    writer.WriteLine("No suspicious bugs found!");
                else
                {
                    writer.WriteLine("Suspicious bugs found!");
                }
            }

            writer.Flush();
#if DEBUG
            writer.Close();
#endif
        }
    }
}
