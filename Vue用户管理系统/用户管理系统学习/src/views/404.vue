<template>
    <div class="exception">
      <img :src="getImageUrl(405)" alt="404 Not Found" />
      <el-button class="btn-home" @click="goHome">回到上一个页面</el-button>
    </div>
  </template>

  <script setup>
  import { useRouter } from 'vue-router'

  const router = useRouter()

  const getImageUrl = (img) => {
    return new URL(`../assets/images/${img}.jpg`, import.meta.url).href
  }

  const goHome = () => {
    // go方法:按指定方向访问历史。如果是正数则是路由记录向前跳转，如果是负数则是向后回退
    // 这里我们回退两个页面到跳转前的页面
    router.go(-2)
  }
  </script>

  <style scoped>
  .exception {
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: center;
    height: 100vh;
    margin: 0;
    background-color: #f4f4f4; /* 可选背景色 */
    position: relative;
  }

  .exception img {
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    object-fit: cover; /* 保持图片比例，覆盖整个容器 */
  }

  .btn-home {
  position: absolute;
  bottom: 80px;
  background-color: #f3b23a; /* 可选按钮颜色 */
  color: rgb(0, 0, 0);
  font-size: 28px; /* 增大字体大小 */
  padding: 35px 50px; /* 增加内边距，增加按钮大小 */
  border-radius: 8px; /* 可选，增加按钮圆角 */
  border: none;
}

  </style>
