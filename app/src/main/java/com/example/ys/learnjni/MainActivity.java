package com.example.ys.learnjni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("jni-test");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView textView = findViewById(R.id.show);
        textView.setText(get()+"");

    }
    public String JavaGet(int a,String str)
    {
        Log.v("ysysys",a+str);
        return "i from java function!+a+str"+a+str;
    }
    public native String get();
    public native void set(String str);
}
