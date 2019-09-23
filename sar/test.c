    //compile me with "gcc main.c -I/usr/include/python2.7 -lpython2.7"
    //original source: "http://python.haas.homelinux.net/python_kapitel_26_003.htm"
    //owner is Peter Kaiser and Johannes Ernesti who published the Book "Python" under Galileo Computing
    //Translation from german with many additional (and very unprofessional) comments and slight adaption by Cupacoffee, 17.02.2015.
    //bugs, grammar mistakes and wrong explainations are my contribution

    #include <Python.h>

    int main (int argc, char *argv[])
    {

    char *result;//This char will receive the return value.

    PyObject *module, *func, *prm, *ret;//These are some helping variables i don't understand.

    Py_Initialize();

    PySys_SetPath(".");//Sets the working path to the current path

    module = PyImport_ImportModule("script");//Import of the script-file, note that the actual script name is "script.py"!

    if (module != 0)//Asks if the script was loaded at all.
    {
        func = PyObject_GetAttrString(module, "compare_function");//Opens a function within the python script. Notice that you must use a function within the python script, because otherwise you can't return anything.
        prm = Py_BuildValue("(ss)", "Hello", "Mars");//The "(ss)" means two strings are passed (replace with "i" for integer for instance), the "Hello" and "Mars" are the strings i pass to the script.
        ret = PyObject_CallObject(func, prm);//Returns some python object i have literally no idea about ...

        result = PyString_AsString(ret);// ... but luckily there's a function to cast it back to a c-compatible char*!
        printf("The Script decdided that '%s' is longer!",result);

        Py_DECREF(module);//cleanup?
        Py_DECREF(func);//cleanup?
        Py_DECREF(prm);//cleanup?
        Py_DECREF(ret);//cleanup?
    }

    else//No script found
    {
        printf("Error: No script file named \"script.py\" was found!\n");
    }

    Py_Finalize();
    return 0;
    }
