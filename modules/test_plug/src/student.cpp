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

#include "student.h"

#include <utility>


Student::Student()
        : name(""), age(0), studentID("")
{
}

Student::Student(std::string n, int32_t a, std::string id)
        : name(std::move(n)), age(a), studentID(std::move(id))
{}

void Student::setName(const std::string &n)
{
    name = n;
}

void Student::setAge(int32_t a)
{
    age = a;
}

void Student::setStudentID(const std::string &id)
{
    studentID = id;
}

std::string Student::getName() const
{
    return name;
}

int32_t Student::getAge() const
{
    return age;
}

std::string Student::getStudentID() const
{
    return studentID;
}

void Student::displayInfo() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Student ID: " << studentID << std::endl;
}
