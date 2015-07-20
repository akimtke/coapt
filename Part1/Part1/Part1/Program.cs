using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.IO;

/// Created by Aaron Kim for CoApt
/// This program is Part 1 of the mini project for CoApt.
/// The purpose of this program is to search a text file and count how many times a certain string occurs within the file
/// Yes, this is just one file. I didn't think it necessary to break it out all the way since it is so simple.

namespace Part1
{
    class Program
    {
        static int Main(string[] args)
        {
            // Check to see if the correct number of arguments are included. Otherwise, show the user the correct usage.
            if (args.Length < 2)
            {
                System.Console.WriteLine("Incorrect usage.");
                System.Console.WriteLine("Usage: Part2 filename search_string");
            }
            else
            {
                int counter = 0;
                string line;
                bool error = false;
                // Catch all the exceptions!!!
                try
                {
                    // StreamReader opens the file for reading. It also allows me to keep the file open
                    // while counting line by line. The using statement ensures the StreamReader object
                    // gets disposed of properly.
                    using (System.IO.StreamReader file = new System.IO.StreamReader(@args[0]))
                    {
                        while ((line = file.ReadLine()) != null && !error)
                        {
                            try
                            {
                                // Chose to use Regex because it seemed more elegant than searching piece by piece.
                                // The downside to this is that the Regex matching only matches exact case but that
                                // can be remedied by telling the user that the search string can be a regex string.
                                counter += Regex.Matches(line, args[1]).Count;
                            }
                            catch (ArgumentException ex)
                            {
                                System.Console.WriteLine("The search_string argument is not valid");
                                // This is put in so the loop exits. That way the error message doesn't spam the console.
                                // Better than a return command because it makes sure the using block is exited gracefully
                                error = true;
                            }
                            catch (Exception ex)
                            {
                                System.Console.WriteLine("ERROR: " + ex.Message);
                                error = true;
                            }
                        }

                        // Output the result of the program.
                        System.Console.WriteLine("The word \"" + args[1] + "\" occurs " + counter + " times");
                    }
                }
                catch (ArgumentException ex)
                {
                    // Originally I did a blanket Exception but those messages are cryptic. As a result,
                    // I augmented the catch statements so they display better messages and put the catch all
                    // at the bottom.
                    System.Console.WriteLine("Check the path. It appears something is wrong with it.");
                }
                catch (FileNotFoundException ex)
                {
                    System.Console.WriteLine("File cannot be found!");
                }
                catch (DirectoryNotFoundException ex)
                {
                    System.Console.WriteLine("Check to make sure the directory path exists");
                }
                catch (IOException ex)
                {
                    System.Console.WriteLine("Double check the path. Something is wonky about it.");
                }
                catch (UnauthorizedAccessException ex)
                {
                    System.Console.WriteLine("You don't have permissions to access the file");
                }
                catch (Exception ex)
                {
                    System.Console.WriteLine("ERROR: " + ex.Message);
                }
            }

            // Put in so the program doesn't shut down the console window immediately.
            System.Console.ReadLine();
            return 0;
        }
    }
}

