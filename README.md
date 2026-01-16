# 📱 IntentExplorer

[![Java](https://img.shields.io/badge/Language-Java-FF4088)]()
[![GitHub Stars](https://img.shields.io/github/stars/Achintha-999/IntentExplorer.svg)](https://github.com/Achintha-999/IntentExplorer/stargazers)
[![GitHub Forks](https://img.shields.io/github/forks/Achintha-999/IntentExplorer.svg)](https://github.com/Achintha-999/IntentExplorer/fork)
[![GitHub License](https://img.shields.io/github/license/Achintha-999/IntentExplorer.svg)]()

**Welcome to IntentExplorer!** 🚀  
A simple Android application demonstrating the power of **Intents** for seamless communication between activities and applications.

## ✨ Features 

- 🔗 Demonstrates **explicit intents** between activities.
- 🌐 Shows how to implement **implicit intents** for interactions with external apps (e.g., web browser, email, phone calls).
- 📂 Guides on how to **pass data** safely and efficiently between activities.

## 🔧 Requirements 

To get started with the IntentExplorer project, ensure you have the following:

1. ✅ Android Studio 4.x or above
2. 📱 An Android device or emulator (API level 21 or above)
3. ☕ Java Development Kit (JDK) installed
4. 🔧 Basic knowledge of Android development and Intents

## 📖 How It Works 

### 🏗️ Main Functionalities
1. **Explicit Intents**: Ensures smooth navigation between application components (activities).
   - 🌟 Learn how to start a new activity and exchange data across them.
2. **Implicit Intents**: Integrate with external Android apps effortlessly.
   - 🌐 For example: Open a browser or send an email using the app.

### 🛠️ Implementation Highlights
- `startActivity` and `startActivityForResult` methods
- Passing data with `Bundle` and `Intent.putExtra`
- Handling `Intent` with `ACTION_VIEW`

**Code Example**:  
```java
// Explicit Intent example
Intent intent = new Intent(CurrentActivity.this, TargetActivity.class);
intent.putExtra("EXTRA_KEY", "Value to pass");
startActivity(intent);
```

### 📋 Steps to Build and Run

1. Clone this repository:  
   ```bash
   git clone https://github.com/Achintha-999/IntentExplorer.git
   cd IntentExplorer
   ```

2. Open the project in **Android Studio**.

3. Download and sync the required Gradle dependencies.

4. Connect your Android device or start the emulator.

5. Click on `Run` ▶️ or build the **APK** file.

6. Enjoy exploring Android Intents! 🎉

## 🤝 Contributing

Contributions are welcome! Feel free to fork the project and submit a pull request with your ideas. 💡

1. Fork the repository 🍴
2. Create your feature branch:  
   ```bash
   git checkout -b feature/YourFeatureName
   ```
3. Commit your changes:  
   ```bash
   git commit -m 'Add some feature'
   ```
4. Push to the branch:  
   ```bash
   git push origin feature/YourFeatureName
   ```
5. Open a pull request ✅

## ⚠️ License  
(Awaiting license selection.)

---

⭐ Don't forget to give this repository a star!  
📬 Questions or suggestions? Feel free to reach out via [GitHub](https://github.com/Achintha-999)!