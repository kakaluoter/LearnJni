#include<jni.h>
#include<stdio.h>


#ifdef __cplusplus
extern "C" {
#endif
	jstring callfromjava(JNIEnv *env,jobject thiz)
	{
		//jclass clazz = env->FindClass("com/example/ys/learnjni/MainActivity");
		jclass clazz = env->GetObjectClass(thiz);
		if(clazz==NULL)return NULL;
		jmethodID id = env->GetMethodID(clazz,"JavaGet","(ILjava/lang/String;)Ljava/lang/String;");
		jstring string = env->NewStringUTF(" ys ");
		jint mint =23;
		jstring str =(jstring)env->CallObjectMethod(thiz,id,mint,string);
		return str;
		
	}

	jstring Java_com_example_ys_learnjni_MainActivity_get(JNIEnv *env,jobject thiz)
	{
		printf("hello from android app c++ in jni\n");
		return callfromjava(env,thiz);
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
