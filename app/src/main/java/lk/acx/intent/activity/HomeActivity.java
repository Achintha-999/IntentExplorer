package lk.acx.intent.activity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import lk.acx.intent.R;

public class HomeActivity extends AppCompatActivity{

    private Button homeBtn;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        //layout file configuration and initialization
        setContentView(R.layout.activity_main);
        this.homeBtn = findViewById(R.id.homeBtn);

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
    }

    private void moveToSetting(){
        Intent intent = new Intent(HomeActivity.this, SettingActivity.class);
        intent.putExtra("username", "Achintha");
        startActivity(intent);
    }
}
