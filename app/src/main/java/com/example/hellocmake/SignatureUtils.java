package com.example.hellocmake;

public class SignatureUtils {

    // Used to load the 'hellocmake' library on application startup.
    static {
        System.loadLibrary("hellocmake");
    }

    public static native String signatureParams(String params);
}
