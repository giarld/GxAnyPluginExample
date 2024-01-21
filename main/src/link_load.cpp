/*
 * Copyright (c) 2023 Gxin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <gx/gany_core.h>

#include <reg_test_plug.h>


using namespace gx;

int main(int argc, char *args[])
{
    initGAnyCore();

    GANY_IMPORT_MODULE(TestPlug);

    auto tStudent = GAny::Import("Plug.Student");
    auto tClassroom = GAny::Import("Plug.Classroom");

    auto classroom = tClassroom();

    auto student1 = tStudent("Alice", 16, "No_2");
    student1.setItem("age", 17);
    std::cout << "Call student1.displayInfo():\n"
              << student1.call("displayInfo") << std::endl;

    classroom.call("addStudent", student1);
    classroom.call("addStudent", tStudent("Bob", 16, "No_1"));
    classroom.call("addStudent", tStudent("Cabot", 18, "No_4"));
    classroom.call("addStudent", tStudent("Dave", 15, "No_3"));
    // Sort by studentID
    classroom.call("sort", [](const GAny &lhs, const GAny &rhs) {
        return lhs.getItem("studentID") < rhs.getItem("studentID");
    });

    std::cout << "Call classroom.display():\n"
    << classroom.call("display") << std::endl;

    return EXIT_SUCCESS;
}