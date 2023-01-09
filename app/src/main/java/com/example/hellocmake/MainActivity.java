package com.example.hellocmake;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

import com.example.hellocmake.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'hellocmake' library on application startup.
//    static {
//        System.loadLibrary("hellocmake");
//    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        String signatureParams = SignatureUtils.signatureParams("userName=2333&userPwd=123qwe");
        TextView tv = binding.sampleText;
        tv.setText(signatureParams);
//        tv.setText(stringFromJNI());
    }

    /**
     * A native method that is implemented by the 'hellocmake' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}