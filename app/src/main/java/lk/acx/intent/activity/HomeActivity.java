package lk.acx.intent.activity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import lk.acx.intent.R;

public class HomeActivity extends AppCompatActivity {

    private Button homeBtn, browerBtn, dialBtn, shareBtn;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //layout file configuration and initialization
        setContentView(R.layout.activity_main);
        this.homeBtn = findViewById(R.id.homeBtn);
        this.browerBtn = findViewById(R.id.browserBtn);
        this.dialBtn = findViewById(R.id.dialBtn);
        this.shareBtn = findViewById(R.id.shareBtn);
    }


    @Override
    protected void onResume() {
        super.onResume();
        //calling listeners
        homeBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                moveToSetting();
            }
        });
        browerBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                openWebPage();
            }
        });
        dialBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                dialNumber();
            }

        });
        shareBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                shareAText();

            }
        });
    }

    private void shareAText() {
        Intent intent = new Intent(Intent.ACTION_SEND);
        intent.setType("text/plain");
        intent.putExtra(Intent.EXTRA_TEXT, "Hello Achintha");
        startActivity(Intent.createChooser(intent, "Share via"));
    }

    private void dialNumber() {
        Intent intent = new Intent(Intent.ACTION_CALL);
        intent.setData(Uri.parse("tel:0771234567"));
        startActivity(intent);
    }


    private void openWebPage() {
        Intent intent = new Intent(Intent.ACTION_VIEW);
        intent.setData(Uri.parse("https://www.google.com"));
        startActivity(intent);
    }

    private void moveToSetting() {
        Intent intent = new Intent(HomeActivity.this, SettingActivity.class);
        intent.putExtra("username", "Achintha");
        startActivity(intent);
    }

}


