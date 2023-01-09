#include <jni.h>
#include <string>
#include "md5.h"

//static char *EXTRA_SIGNATURE="DARREN";
static char *EXTRA_SIGNATURE = "DARREN";
using namespace std;

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_hellocmake_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_hellocmake_SignatureUtils_signatureParams(JNIEnv *env, jclass clazz,
                                                           jstring params_) {
    const char *params=env->GetStringUTFChars(params_,0);
    string signature_str(params);
    signature_str.insert(0,EXTRA_SIGNATURE);

    signature_str=signature_str.substr(0,signature_str.length()-2);

    MD5_CTX *ctx = new MD5_CTX();
    MD5Init(ctx);
    MD5Update(ctx, (unsigned char *) signature_str.c_str(), signature_str.length());
    unsigned char digest[16] = {0};
    MD5Final(digest, ctx);

    char md5_str[32];
    for (int i = 0; i < 16; i++) {
        // 不足的情况下补0 f = 0f, ab = ab
        sprintf(md5_str, "%s%02x", md5_str, digest[i]);
    }

    env->ReleaseStringUTFChars(params_, params);
    return env->NewStringUTF(md5_str);

//    return env->NewStringUTF(signature_str.c_str());
}






























