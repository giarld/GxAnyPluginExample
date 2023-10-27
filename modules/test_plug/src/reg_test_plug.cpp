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

#include "reg_test_plug.h"

#include <gx/gany.h>

#include "classroom.h"


using namespace gx;

REGISTER_GANY_MODULE(TestPlug)
{
    Class<Student>("Plug", "Student", "Class Student.")
            .construct<>()
            .construct<std::string, int32_t, std::string>()
            .func("setName", &Student::setName)
            .func("setAge", &Student::setAge)
            .func("setStudentID", &Student::setStudentID)
            .func("getName", &Student::getName)
            .func("getAge", &Student::getAge)
            .func("getStudentID", &Student::getStudentID)
            .func("displayInfo", &Student::displayInfo)
            .property("name", &Student::getName, &Student::setName)
            .property("age", &Student::getAge, &Student::setAge)
            .property("studentID", &Student::getStudentID, &Student::setStudentID);

    Class<Classroom>("Plug", "Classroom", "Class Classroom.")
            .construct<>()
            .func("addStudent", &Classroom::addStudent)
            .func("sort", [](Classroom &self, const GAny& compareFunc) {
                if (compareFunc.isFunction()) {
                    self.sort([compareFunc](const Student &lhs, const Student &rhs) {
                        return compareFunc(lhs, rhs).toBool();
                    });
                }
            })
            .func("display", &Classroom::display);
}
