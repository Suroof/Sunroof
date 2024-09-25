<!-- <template>
    <div class="container">
        <div class="box">
            <div class="login">用户登录</div>
            <el-form :model="ruleForm" :rules="rules" ref="ruleForm" label-width="100px" class="demo-ruleForm">
                <el-form-item label="" prop="username">
                    <el-input v-model="ruleForm.username" autocomplete="off" placeholder="用户名称"
                              clearable></el-input>
                </el-form-item>
                <el-form-item label="" prop="password">
                    <el-input type="password" v-model="ruleForm.password" autocomplete="off" placeholder="用户密码"
                              clearable></el-input>
                </el-form-item>
                <el-form-item>
                    <div style="margin-bottom: 15px">
                        <el-button type="primary" @click="submitForm('ruleForm')">立即登录</el-button>
                    </div>
                    <div>
                        <el-button @click="resetForm('ruleForm')">重置</el-button>
                    </div>
                    <router-link tag="span" :to="{path:'register'}">
                        <el-button style="margin-top: 10px">跳转到注册</el-button>
                    </router-link>
                </el-form-item>
            </el-form>
        </div>
    </div>
</template> -->

<template>
  <div class="box">
    <el-form
      :model="ruleForm"
      :rules="rules"
      ref="ruleForm"
      label-width="50px"
      class="demo-ruleForm"
    >
      <div class="content">
        <h2>登录</h2>
        <div>
          <input
            v-model="ruleForm.username"
            autocomplete="off"
            placeholder="用户名称"
            clearable
          />
        </div>
        <div>
          <input
            type="password"
            v-model="ruleForm.password"
            autocomplete="off"
            placeholder="用户密码"
            clearable
          />
        </div>
        <div style="margin-bottom: 15px; margin-top: 15px">
          <input type="submit" value="登录" @click="submitForm('ruleForm')" />
        </div>
      </div>
      <div class="btns">
        <a
          href="#"
          @click.prevent="resetForm('ruleForm')"
          style="cursor: pointer; text-decoration: none; color: white"
          >重置</a
        >
      </div>
      <div class="btns register">
        <router-link :to="{ path: 'register' }" tag="span"> 注册 </router-link>
      </div>
    </el-form>
  </div>
</template>

<script>
import { AddRoutes } from "@/router";

export default {
  data() {
    return {
      ruleForm: {
        username: "",
        password: "",
      },
      rules: {
        username: [
          { required: true, message: "请输入用户名称", trigger: "blur" },
          // { min: 3, max: 5, message: '长度在 3 到 5 个字符', trigger: 'blur' }
        ],
        password: [
          { required: true, message: "请输入密码", trigger: "blur" },
          // { min: 3, max: 5, message: '长度在 3 到 5 个字符', trigger: 'blur' }
        ],
      },
    };
  },
  methods: {
    submitForm(formName) {
      this.$refs[formName].validate((valid) => {
        if (valid) {
          console.log(this.ruleForm);
          this.$axios.post("/sysUser/login", this.ruleForm).then((res) => {
            console.log(res);
            if (res.code === 200) {
              this.$message({
                message: "登录成功，正在跳转",
                type: "success",
              });
              let userInfo = res.data;
              localStorage.setItem("systemUser", JSON.stringify(userInfo));
              localStorage.setItem(
                "systemRoleMenu",
                JSON.stringify(userInfo.roleMenu)
              );
              AddRoutes();
              //解决跳转首页后页面404问题
              if (res.data.roleType === "USER") {
                this.$router.push({ path: "/front" });
              } else {
                this.$router.push({ path: "/" });
              }
            }
          });
        } else {
          console.log("error submit!!");
          return false;
        }
      });
    },
    resetForm(formName) {
      this.$refs[formName].resetFields();
    },
  },
};
</script>
<!-- <style scoped>
.container {
    width: 100%;
    height: 100%;
    position: relative;
    background: url("../assets/login.png") 100% 100%;
    background-size: cover;
}

.login {
    text-align: center;
    margin-bottom: 15px;
    font-size: 22px;
    color: #fff;
}

.box {
    overflow: hidden;
    width: 350px;
    padding: 22px 22px 0 22px;
    box-sizing: border-box;
    position: absolute;
    left: 50%;
    top: 50%;
    transform: translateY(-50%) translateX(-50%);
    background-color: skyblue;
    border-radius: 5px;
}

.wx {
    width: 150px;
    height: 150px;
    display: block;
    margin: 0 auto;
}
</style> -->

<style scoped>
* {
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}

body {
  height: 100vh;
  background: #eff0f4;
  overflow: hidden;
}

.box {
  position: relative;
  display: flex;
  justify-content: space-between;
  margin: 150px auto;
  width: 470px;
}

.box .content {
  position: relative;
  display: flex;
  flex-direction: column;
  justify-content: space-around;
  align-items: center;
  width: 350px;
  height: 350px;
  padding: 60px 20px;
  box-shadow: inset 20px 20px 20px rgba(0, 0, 0, 0.05),
    25px 35px 20px rgba(0, 0, 0, 0.05), 25px 30px 30px rgba(0, 0, 0, 0.05),
    inset -20px -20px 25px rgba(255, 255, 255, 0.9);
}

.box .content {
  border-radius: 52% 48% 33% 67% / 38% 45% 55% 62%;
  transition: 0.5s;
}

.box .content:hover {
  border-radius: 50%;
}

.box .content::before {
  content: "";
  position: absolute;
  top: 50px;
  left: 85px;
  width: 35px;
  height: 35px;
  border-radius: 50%;
  background: #fff;
  opacity: 0.9;
}

.box .content::after {
  content: "";
  position: absolute;
  top: 90px;
  left: 110px;
  width: 15px;
  height: 15px;
  border-radius: 50%;
  background: #fff;
  opacity: 0.9;
}

.box .content div {
  position: relative;
  width: 225px;
  border-radius: 25px;
  box-shadow: inset 2px 5px 10px rgba(0, 0, 0, 0.1),
    inset -2px -5px 10px rgba(255, 255, 255, 1),
    15px 15px 10px rgba(0, 0, 0, 0.05), 15px 10px 15px rgba(0, 0, 0, 0.025);
}

.box .content div::before {
  content: "";
  position: absolute;
  top: 8px;
  left: 50%;
  transform: translateX(-50%);
  width: 65%;
  height: 5px;
  background: rgba(255, 255, 255, 0.5);
  border-radius: 5px;
}

.box .content input {
  width: 100%;
  border: none;
  outline: none;
  background: transparent;
  font-size: 16px;
  padding: 10px 15px;
}

.box .content input[type="submit"] {
  color: #fff;
  cursor: pointer;
}

.box .content div:last-child {
  width: 120px;
  background: #ff0f5b;
  box-shadow: inset 2px 5px 10px rgba(0, 0, 0, 0.1),
    15px 15px 10px rgba(0, 0, 0, 0.05), 15px 10px 15px rgba(0, 0, 0, 0.025);
  transition: 0.5s;
}

.box .content div:last-child:hover {
  width: 150px;
}

.btns {
  position: absolute;
  right: 0;
  bottom: 0;
  width: 120px;
  height: 120px;
  background: #c61dff;
  display: flex;
  justify-content: center;
  align-items: center;
  cursor: pointer;
  text-decoration: none;
  color: #fff;
  font-size: 14px;
  box-shadow: inset 10px 10px 10px rgba(190, 1, 254, 0.05),
    15px 25px 10px rgba(190, 1, 254, 0.1), 15px 20px 20px rgba(190, 1, 254, 0.1),
    inset -10px -10px 15px rgba(255, 255, 255, 0.5);
  border-radius: 44% 56% 65% 35% / 57% 58% 42% 43%;
}

.register {
  bottom: 150px;
  right: 0px;
  width: 80px;
  height: 80px;
  border-radius: 49% 51% 52% 48% / 63% 59% 41% 37%;
  background: #01b4ff;
  box-shadow: inset 10px 10px 10px rgba(1, 180, 255, 0.05),
    15px 25px 10px rgba(1, 180, 255, 0.1), 15px 20px 20px rgba(1, 180, 255, 0.1),
    inset -10px -10px 15px rgba(255, 255, 255, 0.5);
}

.btns::before {
  content: "";
  position: absolute;
  top: 15px;
  left: 30px;
  width: 20px;
  height: 20px;
  border-radius: 50%;
  background: #fff;
  opacity: 0.45;
}

.register::before {
  left: 20px;
  width: 15px;
  height: 15px;
}

.btns {
  transition: 0.25s;
}

.btns:hover {
  border-radius: 50%;
}
</style>
