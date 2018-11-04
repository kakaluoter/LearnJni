#include<jni.h>
#include<stdio.h>


#ifdef __cplusplus
extern "C" {
#endif
	jstring Java_com_example_ys_learnjni_MainActivity_get(JNIEnv *env,jobject thiz)
	{
		printf("hello from android app c++ in jni\n");
		return env->NewStringUTF("hello world from jni!");
	}

	void Java_com_example_ys_learnjni_MainActivity_set(JNIEnv *env,jobject thiz,jstring string)
	{
	 	char *str=(char*)env->GetStringUTFChars(string,NULL);
		printf("%s\n",str);
		env->ReleaseStringUTFChars(string,str);
	}

#ifdef __cplusplus
}
#endif
