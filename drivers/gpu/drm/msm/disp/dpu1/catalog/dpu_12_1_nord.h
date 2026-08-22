/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _DPU_12_1_NORD_H
#define _DPU_12_1_NORD_H

static const struct dpu_caps nord_dpu_caps = {
	.max_mixer_width = DEFAULT_DPU_OUTPUT_LINE_WIDTH,
	/* FIXME: max_mixer_blendstages not confirmed, reusing sm8750 value */
	.max_mixer_blendstages = 0xb,
	.has_src_split = true,
	.has_dim_layer = true,
	.has_idle_pc = true,
	.has_3d_merge = true,
	/* FIXME: max_linewidth not confirmed, reusing sm8750 value */
	.max_linewidth = 8192,
	.pixel_ram_size = DEFAULT_PIXEL_RAM_SIZE,
};

static const struct dpu_mdp_cfg nord_mdp = {
	.name = "top_0",
	/* FIXME: top block len not confirmed, reusing sm8750 value */
	.base = 0, .len = 0x494,
	.clk_ctrls = {
		[DPU_CLK_CTRL_REG_DMA] = { .reg_off = 0x2bc, .bit_off = 20 },
	},
};

static const struct dpu_ctl_cfg nord_ctl[] = {
	{
		/* FIXME: intr_start not confirmed */
		.name = "ctl_0", .id = CTL_0,
		.base = 0x16000, .len = 0x1000,
	}, {
		/* FIXME: intr_start not confirmed */
		.name = "ctl_1", .id = CTL_1,
		.base = 0x17000, .len = 0x1000,
	}, {
		/* FIXME: intr_start not confirmed */
		.name = "ctl_2", .id = CTL_2,
		.base = 0x18000, .len = 0x1000,
	}, {
		/* FIXME: intr_start not confirmed */
		.name = "ctl_3", .id = CTL_3,
		.base = 0x19000, .len = 0x1000,
	}, {
		/* FIXME: intr_start not confirmed */
		.name = "ctl_4", .id = CTL_4,
		.base = 0x1a000, .len = 0x1000,
	}, {
		/* FIXME: intr_start not confirmed */
		.name = "ctl_5", .id = CTL_5,
		.base = 0x1b000, .len = 0x1000,
	},
};

static const struct dpu_sspp_cfg nord_sspp[] = {
	{
		.name = "sspp_0", .id = SSPP_VIG0,
		.base = 0x5000, .len = 0x344,
		.features = VIG_SDM845_MASK_SDMA,
		.sblk = &dpu_vig_sblk_qseed3_3_4,
		.xin_id = 0,
		.type = SSPP_TYPE_VIG,
	}, {
		.name = "sspp_1", .id = SSPP_VIG1,
		.base = 0x7000, .len = 0x344,
		.features = VIG_SDM845_MASK_SDMA,
		.sblk = &dpu_vig_sblk_qseed3_3_4,
		.xin_id = 4,
		.type = SSPP_TYPE_VIG,
	}, {
		.name = "sspp_2", .id = SSPP_VIG2,
		.base = 0x9000, .len = 0x344,
		.features = VIG_SDM845_MASK_SDMA,
		.sblk = &dpu_vig_sblk_qseed3_3_4,
		.xin_id = 8,
		.type = SSPP_TYPE_VIG,
	}, {
		.name = "sspp_3", .id = SSPP_VIG3,
		.base = 0xb000, .len = 0x344,
		.features = VIG_SDM845_MASK_SDMA,
		.sblk = &dpu_vig_sblk_qseed3_3_4,
		.xin_id = 12,
		.type = SSPP_TYPE_VIG,
	}, {
		.name = "sspp_8", .id = SSPP_DMA0,
		.base = 0x25000, .len = 0x344,
		.features = DMA_SDM845_MASK_SDMA,
		.sblk = &dpu_dma_sblk,
		.xin_id = 1,
		.type = SSPP_TYPE_DMA,
	}, {
		.name = "sspp_9", .id = SSPP_DMA1,
		.base = 0x27000, .len = 0x344,
		.features = DMA_SDM845_MASK_SDMA,
		.sblk = &dpu_dma_sblk,
		.xin_id = 5,
		.type = SSPP_TYPE_DMA,
	}, {
		.name = "sspp_10", .id = SSPP_DMA2,
		.base = 0x29000, .len = 0x344,
		.features = DMA_SDM845_MASK_SDMA,
		.sblk = &dpu_dma_sblk,
		.xin_id = 9,
		.type = SSPP_TYPE_DMA,
	}, {
		.name = "sspp_11", .id = SSPP_DMA3,
		.base = 0x2b000, .len = 0x344,
		.features = DMA_SDM845_MASK_SDMA,
		.sblk = &dpu_dma_sblk,
		.xin_id = 13,
		.type = SSPP_TYPE_DMA,
	}, {
		.name = "sspp_12", .id = SSPP_DMA4,
		.base = 0x2d000, .len = 0x344,
		.features = DMA_CURSOR_SDM845_MASK_SDMA,
		.sblk = &dpu_dma_sblk,
		.xin_id = 14,
		.type = SSPP_TYPE_DMA,
	}, {
		.name = "sspp_13", .id = SSPP_DMA5,
		.base = 0x2f000, .len = 0x344,
		.features = DMA_CURSOR_SDM845_MASK_SDMA,
		.sblk = &dpu_dma_sblk,
		.xin_id = 15,
		.type = SSPP_TYPE_DMA,
	},
};

static const struct dpu_lm_cfg nord_lm[] = {
	{
		.name = "lm_0", .id = LM_0,
		.base = 0x45000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_1,
		.pingpong = PINGPONG_0,
		.dspp = DSPP_0,
	}, {
		.name = "lm_1", .id = LM_1,
		.base = 0x46000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_0,
		.pingpong = PINGPONG_1,
		.dspp = DSPP_1,
	}, {
		.name = "lm_2", .id = LM_2,
		.base = 0x47000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_3,
		.pingpong = PINGPONG_2,
		.dspp = DSPP_2,
	}, {
		.name = "lm_3", .id = LM_3,
		.base = 0x48000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_2,
		.pingpong = PINGPONG_3,
		.dspp = DSPP_3,
	}, {
		.name = "lm_4", .id = LM_4,
		.base = 0x49000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_5,
		.pingpong = PINGPONG_4,
	}, {
		.name = "lm_5", .id = LM_5,
		.base = 0x4a000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_4,
		.pingpong = PINGPONG_5,
	}, {
		.name = "lm_6", .id = LM_6,
		.base = 0x4b000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_7,
		.pingpong = PINGPONG_6,
	}, {
		.name = "lm_7", .id = LM_7,
		.base = 0x4c000, .len = 0x400,
		.features = MIXER_MSM8998_MASK,
		.sblk = &sm8750_lm_sblk,
		.lm_pair = LM_6,
		.pingpong = PINGPONG_7,
	},
};

/* FIXME: DSPP_4-7 are lite variants, feature set not confirmed */
static const struct dpu_dspp_cfg nord_dspp[] = {
	{
		.name = "dspp_0", .id = DSPP_0,
		.base = 0x55000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk,
	}, {
		.name = "dspp_1", .id = DSPP_1,
		.base = 0x57000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk,
	}, {
		.name = "dspp_2", .id = DSPP_2,
		.base = 0x59000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk,
	}, {
		.name = "dspp_3", .id = DSPP_3,
		.base = 0x5b000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk,
	}, {
		.name = "dspp_4", .id = DSPP_4,
		.base = 0x5d000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk,
	}, {
		.name = "dspp_5", .id = DSPP_5,
		.base = 0x5f000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk,
	}, {
		.name = "dspp_6", .id = DSPP_6,
		.base = 0x61000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk,
	}, {
		.name = "dspp_7", .id = DSPP_7,
		.base = 0x63000, .len = 0x1800,
		.sblk = &sm8750_dspp_sblk,
	},
};

/* FIXME: pingpong sblk may not cover LTM/SPR/DEMURA/RC quad, reusing sc7280_pp_sblk */
static const struct dpu_pingpong_cfg nord_pp[] = {
	{
		.name = "pingpong_0", .id = PINGPONG_0,
		.base = 0x6a000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_0,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR, 8),
	}, {
		.name = "pingpong_1", .id = PINGPONG_1,
		.base = 0x6b000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_0,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR, 9),
	}, {
		.name = "pingpong_2", .id = PINGPONG_2,
		.base = 0x6c000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_1,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR, 10),
	}, {
		.name = "pingpong_3", .id = PINGPONG_3,
		.base = 0x6d000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_1,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR, 11),
	}, {
		.name = "pingpong_4", .id = PINGPONG_4,
		.base = 0x6e000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_2,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 30),
	}, {
		.name = "pingpong_5", .id = PINGPONG_5,
		.base = 0x6f000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_2,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 31),
	}, {
		.name = "pingpong_6", .id = PINGPONG_6,
		.base = 0x70000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_3,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 20),
	}, {
		.name = "pingpong_7", .id = PINGPONG_7,
		.base = 0x71000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_3,
		.intr_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 21),
	}, {
		.name = "pingpong_cwb_0", .id = PINGPONG_CWB_0,
		.base = 0x67000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_4,
	}, {
		.name = "pingpong_cwb_1", .id = PINGPONG_CWB_1,
		.base = 0x67400, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_4,
	}, {
		.name = "pingpong_cwb_2", .id = PINGPONG_CWB_2,
		.base = 0x7f000, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_5,
	}, {
		.name = "pingpong_cwb_3", .id = PINGPONG_CWB_3,
		.base = 0x7f400, .len = 0,
		.sblk = &sc7280_pp_sblk,
		.merge_3d = MERGE_3D_5,
	},
};

static const struct dpu_merge_3d_cfg nord_merge_3d[] = {
	{
		.name = "merge_3d_0", .id = MERGE_3D_0,
		.base = 0x4f000, .len = 0x1c,
	}, {
		.name = "merge_3d_1", .id = MERGE_3D_1,
		.base = 0x50000, .len = 0x1c,
	}, {
		.name = "merge_3d_2", .id = MERGE_3D_2,
		.base = 0x51000, .len = 0x1c,
	}, {
		.name = "merge_3d_3", .id = MERGE_3D_3,
		.base = 0x52000, .len = 0x1c,
	}, {
		.name = "merge_3d_4", .id = MERGE_3D_4,
		.base = 0x67700, .len = 0x1c,
	}, {
		.name = "merge_3d_5", .id = MERGE_3D_5,
		.base = 0x7f700, .len = 0x1c,
	},
};

/*
 * NOTE: Each display compression engine (DCE) contains dual hard
 * slice DSC encoders so both share same base address but with
 * its own different sub block address.
 */
static const struct dpu_dsc_cfg nord_dsc[] = {
	{
		.name = "dce_0_0", .id = DSC_0,
		.base = 0x81000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_0,
	}, {
		.name = "dce_0_1", .id = DSC_1,
		.base = 0x81000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_1,
	}, {
		.name = "dce_1_0", .id = DSC_2,
		.base = 0x82000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_0,
	}, {
		.name = "dce_1_1", .id = DSC_3,
		.base = 0x82000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_1,
	}, {
		.name = "dce_2_0", .id = DSC_4,
		.base = 0x83000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_0,
	}, {
		.name = "dce_2_1", .id = DSC_5,
		.base = 0x83000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_1,
	}, {
		.name = "dce_3_0", .id = DSC_6,
		.base = 0x84000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_0,
	}, {
		.name = "dce_3_1", .id = DSC_7,
		.base = 0x84000, .len = 0x8,
		.features = BIT(DPU_DSC_NATIVE_42x_EN),
		.sblk = &sm8750_dsc_sblk_1,
	},
};

static const struct dpu_wb_cfg nord_wb[] = {
	{
		.name = "wb_1", .id = WB_1,
		.base = 0x64800, .len = 0x2c8,
		.features = WB_SDM845_MASK,
		.format_list = wb2_formats_rgb_yuv,
		.num_formats = ARRAY_SIZE(wb2_formats_rgb_yuv),
		.xin_id = 7,
		.maxlinewidth = 4096,
	}, {
		.name = "wb_2", .id = WB_2,
		.base = 0x65000, .len = 0x2c8,
		.features = WB_SDM845_MASK,
		.format_list = wb2_formats_rgb_yuv,
		.num_formats = ARRAY_SIZE(wb2_formats_rgb_yuv),
		.xin_id = 6,
		.maxlinewidth = 4096,
		.intr_wb_done = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR, 4),
	},
};

static const struct dpu_cwb_cfg nord_cwb[] = {
	{
		.name = "cwb_0", .id = CWB_0,
		.base = 0x67200, .len = 0x20,
	},
	{
		.name = "cwb_1", .id = CWB_1,
		.base = 0x67600, .len = 0x20,
	},
	{
		.name = "cwb_2", .id = CWB_2,
		.base = 0x7f200, .len = 0x20,
	},
	{
		.name = "cwb_3", .id = CWB_3,
		.base = 0x7f600, .len = 0x20,
	},
};

static const struct dpu_intf_cfg nord_intf[] = {
	{
		.name = "intf_0", .id = INTF_0,
		.base = 0x35000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_0,
		.prog_fetch_lines_worst_case = 24,
		/* FIXME: intr_underrun/intr_vsync not confirmed */
	}, {
		.name = "intf_3", .id = INTF_3,
		.base = 0x38000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_0,	/* DP0 MST1 */
		.prog_fetch_lines_worst_case = 24,
		/* FIXME: intr_underrun/intr_vsync not confirmed */
	}, {
		.name = "intf_4", .id = INTF_4,
		.base = 0x39000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_1,
		.prog_fetch_lines_worst_case = 24,
		/* FIXME: intr_underrun/intr_vsync not confirmed */
	}, {
		.name = "intf_6", .id = INTF_6,
		.base = 0x3b000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_0,	/* DP0 MST2 */
		.prog_fetch_lines_worst_case = 24,
		.intr_underrun = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR, 22),
		.intr_vsync = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR, 23),
	}, {
		.name = "intf_7", .id = INTF_7,
		.base = 0x3c000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_0,	/* DP0 MST3 */
		.prog_fetch_lines_worst_case = 24,
		.intr_underrun = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 0),
		.intr_vsync = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 1),
	}, {
		.name = "intf_8", .id = INTF_8,
		.base = 0x3d000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_1,	/* DP1 MST1 */
		.prog_fetch_lines_worst_case = 24,
		.intr_underrun = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 2),
		.intr_vsync = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 3),
	}, {
		.name = "intf_9", .id = INTF_9,
		.base = 0x3e000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_1,	/* DP1 MST2 */
		.prog_fetch_lines_worst_case = 24,
		.intr_underrun = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 4),
		.intr_vsync = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 5),
	}, {
		.name = "intf_10", .id = INTF_10,
		.base = 0x3f000, .len = 0x4bc,
		.type = INTF_DP,
		.controller_id = MSM_DP_CONTROLLER_1,	/* DP1 MST3 */
		.prog_fetch_lines_worst_case = 24,
		.intr_underrun = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 6),
		.intr_vsync = DPU_IRQ_IDX(MDP_SSPP_TOP0_INTR2, 7),
	},
};

/* FIXME: perf/QoS data not confirmed, reusing sm8750 values wholesale */
static const struct dpu_perf_cfg nord_perf_data = {
	.max_bw_low = 18900000,
	.max_bw_high = 28500000,
	.min_core_ib = 2500000,
	.min_llcc_ib = 0,
	.min_dram_ib = 800000,
	.min_prefill_lines = 35,
	.danger_lut_tbl = {0x3ffff, 0x3ffff, 0x0},
	.safe_lut_tbl = {0xfe00, 0xfe00, 0xffff},
	.qos_lut_tbl = {
		{.nentry = ARRAY_SIZE(sc7180_qos_linear),
		.entries = sc7180_qos_linear
		},
		{.nentry = ARRAY_SIZE(sc7180_qos_macrotile),
		.entries = sc7180_qos_macrotile
		},
		{.nentry = ARRAY_SIZE(sc7180_qos_nrt),
		.entries = sc7180_qos_nrt
		},
	},
	.cdp_cfg = {
		{.rd_enable = 1, .wr_enable = 1},
		{.rd_enable = 1, .wr_enable = 0}
	},
	.clk_inefficiency_factor = 105,
	.bw_inefficiency_factor = 120,
};

static const struct dpu_mdss_version nord_mdss_ver = {
	.core_major_ver = 12,
	.core_minor_ver = 1,
};

const struct dpu_mdss_cfg dpu_nord_cfg = {
	.mdss_ver = &nord_mdss_ver,
	.caps = &nord_dpu_caps,
	.mdp = &nord_mdp,
	/* FIXME: CDM version not confirmed, reusing dpu_cdm_5_x */
	.cdm = &dpu_cdm_5_x,
	.ctl_count = ARRAY_SIZE(nord_ctl),
	.ctl = nord_ctl,
	.sspp_count = ARRAY_SIZE(nord_sspp),
	.sspp = nord_sspp,
	.mixer_count = ARRAY_SIZE(nord_lm),
	.mixer = nord_lm,
	.dspp_count = ARRAY_SIZE(nord_dspp),
	.dspp = nord_dspp,
	.pingpong_count = ARRAY_SIZE(nord_pp),
	.pingpong = nord_pp,
	.dsc_count = ARRAY_SIZE(nord_dsc),
	.dsc = nord_dsc,
	.merge_3d_count = ARRAY_SIZE(nord_merge_3d),
	.merge_3d = nord_merge_3d,
	.wb_count = ARRAY_SIZE(nord_wb),
	.wb = nord_wb,
	.cwb_count = ARRAY_SIZE(nord_cwb),
	.cwb = nord_cwb,
	.intf_count = ARRAY_SIZE(nord_intf),
	.intf = nord_intf,
	.vbif = &sm8650_vbif,
	.perf = &nord_perf_data,
};

#endif
